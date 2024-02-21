#include <stdio.h>

main() {
	int numero, matriz[3][3], i, j, contador = 0;
	printf("Numero: ");
	scanf("%d", &numero);
	for(i = 0; i < 3; i++) {
		for(j = 0; j < 3; j++) {
			printf("[%d][%d] = ", i + 1, j + 1);
			scanf("%d", &matriz[i][j]);
		}
	}
	for(i = 0; i < 3; i++) {
		for(j = 0; j < 3; j++) {
			if (matriz[i][j] == numero) {
				contador++;
			}
		}
	}
	printf("O numero %d apareceu %d vezes na matriz", numero, contador);
}
