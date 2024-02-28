#include <stdio.h>

int maiorNumero(int n1, int n2){
    if (n1 >= n2) {
        return n1;
    }
    else {
        return n2;
    }
}

int main() {
    int n1, n2, resultado;
    printf("Numero 1: ");
    scanf("%d", &n1);
    printf("Numero 2: ");
    scanf("%d", &n2);
    resultado = maiorNumero(n1, n2);
    printf("Maior numero: %d\n",resultado);
}