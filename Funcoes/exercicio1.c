#include <stdio.h>

int multiplicacao(int n1, int n2) {
    return n1 * n2;
}

int main() {
    int n1, n2, resultado;
    printf("Numero 1: ");
    scanf("%d", &n1);
    printf("Numero 2: ");
    scanf("%d", &n2);
    resultado = multiplicacao(n1, n2);
    printf("%d x %d = %d\n", n1, n2, resultado);
}