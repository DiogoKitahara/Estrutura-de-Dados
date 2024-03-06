#include <stdio.h>

int jogo_advinhacao (int tentativa) {
	int n = 74;
	if (tentativa < 74) {
		printf("O numero e maior\n");
		return 0;
	}
	else if (tentativa > 74) {
		printf("O numero e menor\n");
		return 0;
	}
	else {
		return 1;
	}
}

int main() {
	// Declarar variaveis 
	int i, tentativa, resultado, contador = 0;
	// Loop para tentativa de ate 10 vezes
	while(contador < 10) {
		// Perguntar o numero
		printf("Numero: ");
		scanf("%d", &tentativa);
		// Funcao para comparar
		resultado = jogo_advinhacao(tentativa);
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
