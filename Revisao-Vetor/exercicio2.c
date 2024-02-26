#include <stdio.h>
#define TF 10

main() {
    float vetor[TF], numero;
    int achou = 0, i, posicao;
    printf("Digite um numero: ");
    scanf("%f", &numero);
    for(i = 0; i < TF; i++) {
        printf("Vetor[%d]: ", i);
        scanf("%f", &vetor[i]);
        if (vetor[i] == numero) {
            posicao = i;
            achou = 1;
        }
    }
    if (achou != 1) {
        printf("O numero nao foi encontrado no vetor\n");
    }
    else {
        printf("O numero esta na posicao %d do vetor\n", posicao);
    }
}