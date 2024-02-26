#include <stdio.h>

float calcularMediaComRetorno (int n1, int n2) {
    return ((float)(n1 + n2) / 2);
}

void calcularMediaSemRetorno (int n1, int n2) {
    printf("Media: %.2f\n", (float)(n1 + n2) / 2);
}

int main() {
    int n1, n2;
    float media;
    printf("Numero 1: ");
    scanf("%d", &n1);
    printf("Numero 2: ");
    scanf("%d", &n2);
    /*media = calcularMediaComRetorno(n1, n2);
    printf("Media: %.2f\n", media);*/
    calcularMediaSemRetorno(n1, n2);
}