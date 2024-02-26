#include <stdio.h>
#include <math.h>

float raizQuadrada(float n1, float n2) {
    float soma_quadrados, resultado;
    soma_quadrados = (n1 * n1) + (n2 * n2);
    resultado = sqrt(soma_quadrados);
    return resultado;
}

int main() {
    float n1, n2, resultado;
    printf("Numero 1: ");
    scanf("%f", &n1);
    printf("Numero 2: ");
    scanf("%f", &n2);
    resultado = raizQuadrada(n1, n2);
    printf("Resultado: %.2f\n", resultado);
}