#include <stdio.h>
#define TF 10

main () {
    // Declarar variaveis
    float vetor1[TF], vetor2[TF], resultado[TF];
    int i;
    char operacao[TF];
    // Loop para armazenar valores nos vetores
    for(i = 0; i < TF; i++) {
        printf("Valor para o primeiro vetor: ");
        scanf("%f", &vetor1[i]);
        printf("Valor para o segundo vetor: ");
        scanf("%f", &vetor2[i]);
        printf("Operacao basica a ser realizada: ");
        scanf(" %c", &operacao[i]);
        // Verificar, realizar a operacao e armazenar o resultado em outro vetor 
        switch (operacao[i]){
            case '+':
                resultado[i] = vetor1[i] + vetor2[i];
                printf("Resultado: %.2f\n", resultado[i]);
                break;
            case '-':
                resultado[i] = vetor1[i] - vetor2[i];
                printf("Resultado: %.2f\n", resultado[i]);
                break;
            case '*':
                resultado[i] = vetor1[i] * vetor2[i];
                printf("Resultado: %.2f\n", resultado[i]);
                break;
            case '/':
                resultado[i] = vetor1[i] / vetor2[i];
                printf("Resultado: %.2f\n", resultado[i]);
                break;
        }  
        printf("-------------------------------\n");
    }
}