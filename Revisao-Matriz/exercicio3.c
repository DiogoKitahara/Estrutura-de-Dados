#include <stdio.h>
#define TF 3

int main() {
    // Declarar variaveis
    int i, j, contador = 0, matriz[TF][TF];
    // Loop linha
    for(i = 0; i < TF; i++) {
        // Loop coluna
        for(j = 0; j < TF; j ++) {
            printf("Matriz [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
            // Verificar se é uma matriz identidade
            if (i == j) {
                if (matriz[i][j] != 1)
                    contador++;
            }
            else {
                if(matriz[i][j] != 0) {
                    contador++;
                }
            }
        }
    }
    if (contador == 0) {
        printf("E uma matriz identidade\n");
    }
    else {
        printf("Nao e uma matriz identidade\n");
    }
}