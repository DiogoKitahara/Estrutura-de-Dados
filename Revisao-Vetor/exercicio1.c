#include <stdio.h>
#include <stdbool.h>
#define TF 5

main() {
    int vetor[TF], i, contador_menor = 0, contador_maior = 0, contador_igual = -1, numero;
    bool inicio = true;
    for (i = 0; i < TF; i++){
        printf("Vetor[%d]: ", i);
        scanf("%d", &vetor[i]);
        if (inicio == true) {
            numero = vetor[i];
            inicio = false;
        }
        if (vetor[i] == numero) {
            contador_igual++;
        }
        if (vetor[i] > numero) {
            contador_maior++;
        }
        if (vetor[i] < numero) {
            contador_menor++;
        }
    }
    printf("Quantidade de elementos iguais ao primeiro: %d\n", contador_igual);
    printf("Quantidade de elementos maiores que primeiro: %d\n", contador_maior);
    printf("Quantidade de elementos menores que primeiro: %d\n", contador_menor);
}