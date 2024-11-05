//MÉTODO DE GAUSS JORDAN

#include <stdio.h>
#include <stdlib.h>

int main(){

int n;

printf("Digite a ordem da matriz: ");
scanf("%d", &n);

float a[n][n];      //matriz dos coeficientes
float b[n];          //matriz dos termos independentes
float result[n];     //matriz das incognitas 

//colocar os valores em um matriz
for( int i = 0 ; i < n ; i++){
    printf("\n\nDigite os valores dos coeficientes na linha %d:\n", i+1);
    for(int j = 0 ; j < n ; j++){
        printf("a[%d][%d]:", i+1, j+1);
        scanf("%f", &a[i][j]);
    }
    printf("termo independente: ");
    scanf("%f",&b[i]);
}

//////////////////////////////jordan///////////////////////////////////
float m; //multiplicador

for(int k = 0; k < n; k++){//etapas
    for(int i = 0; i < n; i++){ //linhas
        m = (a[i][k] * -1) / a[k][k];
        if(i != k){
            for(int j = k; j < n; j++){ //colunas
                a[i][j] = a[i][j] + (m * a[k][j]); 
            }
        b[i] += b[k] * m;
         }
}
} 

//imprimir triangular equivalente 
printf("Trangular equivalente: \n");
for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
        printf("%.2f        ", a[i][j]);
    }
    printf("=   %.2f", b[i]);
    printf("\n");
}

//retro solução 
for(int i = (n-1) ; i >= 0 ; i--){ //rodar as linhas
    result[i] = b[i];
    for( int j = (i + 1) ; j < n ; j++){ //rodar as colunas
        result[i] -= a[i][j] * result[j];
    }
    result[i] /= a[i][i];
}

//resposta
for(int i = 0 ; i < n ; i++){
    result[i] = b[i] / a[i][i];
}
     

//imprimir 
printf("resposta: \n");
    for(int i = 0 ; i < n ; i++){
        printf("%.2f\n", result[i]);

    }

    return 0;
}
