#include <stdio.h>
#include <stdbool.h>

#define TF 3
main() {
	int i, j, matriz[TF][TF], menor_valor, menor_posicao, menor_posicao2;
	bool inicio = false;
	for (i = 0; i < TF; i++){
		for(j = 0; j < TF; j++) {
			printf("[%d][%d]: ", i, j);
			scanf("%d", &matriz[i][j]);
			if (inicio == false) {
				menor_valor = matriz[i][j];
				inicio = true;
			}
			if (matriz[i][j] < menor_valor){
				menor_valor = matriz[i][j];
				menor_posicao = i;
				menor_posicao2 = j;
			}
		}
	}
	printf("O menor elemento e: %d\n", menor_valor);
	printf("Na posicao [%d][%d]", menor_posicao, menor_posicao2);
}
