//MÉTODO DE ELIMINAÇÃO DE GAUSS PARCIAL
#include <stdio.h>
#include <stdlib.h>
#include <math.h>  // para usar fabs()

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

//////////////////////////////gaus parcial///////////////////////////////////
float m; //multiplicador
float maior;

for(int k = 0; k < n-1; k++){//etapas
    int maxIndex = k;
    maior = fabs(a[k][k]); //abs para float

       for(int u = k + 1; u < n; u++) { // busca o maior abaixo da principal
            if(fabs(a[u][k]) > maior) {
                maior = fabs(a[u][k]);
                maxIndex = u;  // guarda o índice da linha com o maior
            }
        }

        if(maxIndex != k) { //troca se necessario
            for(int j = 0; j < n; j++) {
                float aux = a[k][j];
                a[k][j] = a[maxIndex][j];
                a[maxIndex][j] = aux;
            }
            float aux = b[k];
            b[k] = b[maxIndex];
            b[maxIndex] = aux;
        }

        for(int i = k+1; i < n; i++){ //linhas
            m = (a[i][k] * -1) / a[k][k];
            for(int j = k; j < n; j++){ //colunas
                a[i][j] = a[i][j] + (m * a[k][j]); 
            }
        b[i] += b[k] * m;
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

//imprimir 
printf("resposta: \n");
    for(int i = 0 ; i < n ; i++){
        printf("%.2f\n", result[i]);

    }

    return 0;
}
