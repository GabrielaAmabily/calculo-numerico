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


//resolver 
for( int i = (n-1) ; i >= 0 ; i--){
    result[i] = b[i];
    for( int j = (i + 1) ; j < n ; j++){
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
