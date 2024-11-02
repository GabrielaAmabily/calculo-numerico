//MÉTODO DE ELIMINAÇÃO DE GAUSS COMPLETO
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

    int posicao[n];
    for(int i = 0; i < n; i++){
        posicao[i] = i;
    }

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

    //////////////////////////////gaus completo///////////////////////////////////
    float m; //multiplicador

    for(int k = 0; k < n-1; k++){//etapas for supremo
        
        int maxLinha = k;
        int maxColunas = k;
        float maxValor = fabs(a[k][k]);

        // Busca pelo maior valor na matriz 
        for (int i = k; i < n; i++) {
            for (int j = k; j < n; j++) {
                if (fabs(a[i][j]) > maxValor){
                    maxValor = fabs(a[i][j]);
                    maxLinha = i;
                    maxColunas = j;
                }
            }
        }

        // Troca de linha se necessário
        if (maxLinha != k) {
            for (int j = 0; j < n; j++) {
                float temp = a[k][j];
                a[k][j] = a[maxLinha][j];
                a[maxLinha][j] = temp;
            }
            float temp = b[k];
            b[k] = b[maxLinha];
            b[maxLinha] = temp;
        }

        // Troca de coluna se necessário
        if (maxColunas != k) {
            for (int i = 0; i < n; i++) {
                float temp = a[i][k];
                a[i][k] = a[i][maxColunas];
                a[i][maxColunas] = temp;
            }
            int tempIdx = posicao[k];     //para imprimir certo depois       
            posicao[k] = posicao[maxColunas];   
            posicao[maxColunas] = tempIdx;      
        }

        //parte do gaus simples para deixar tringular 
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
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(posicao[j] == i) {          // posiçao original
                printf("%.2f\n", result[j]);
                break;
            }
        }
    }

        return 0;
}
