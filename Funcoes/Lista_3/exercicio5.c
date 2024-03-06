#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int jogo_advinhacao (int tentativa, int n) {
	if (tentativa < n) {
		printf("O numero e maior\n");
		return 0;
	}
	else if (tentativa > n) {
		printf("O numero e menor\n");
		return 0;
	}
	else {
		return 1;
	}
}

int main() {
	// Declarar variaveis 
	int n, i, tentativa, resultado, contador = 0;
	srand(time(NULL));
	n = rand() % 101;
	// Loop para tentativa de ate 10 vezes
	while(contador < 10) {
		// Perguntar o numero
		printf("Numero: ");
		scanf("%d", &tentativa);
		// Funcao para comparar
		resultado = jogo_advinhacao(tentativa, n);
		if (resultado == 1){
			printf("Acertou!\n");
			return 0;
		}
		else {
			printf("Errou!\n");
		}
		contador++;
	}
}
