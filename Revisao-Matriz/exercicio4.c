#include <stdio.h>
#define TFL 3 
#define TFC 5 
#define TF 3

main() {
    // Declarar variaveis
    float soma = 0, matriz[TFL][TFC], vetor[TF];
    int i, j;
    // Atribuir valores para a matriz
    for(i = 0; i < TFL; i++) {
        for(j = 0; j < TFC; j++) {
            printf("Matriz[%d][%d]: ", i, j);
            scanf("%f", &matriz[i][j]);
            soma += matriz[i][j];
        }
        // Realizar a soma de cada linha da matriz e colocar num vetor
        vetor[i] = soma;
        printf("Vetor[%d] = %.2f\n", i, vetor[i]);
        printf("------------------------------\n");
        soma = 0;
    }
}