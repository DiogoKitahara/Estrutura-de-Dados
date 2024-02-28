#include <stdio.h>
#define TF 5

int soma_vetor(int vetor[], int n) {
	int i, soma;
	for(i = 0; i < n; i++) {
		soma += vetor[i];
	}
	return soma;
}

int main() {
	int i, soma, vetor[TF];
	for(i = 0; i < TF; i++) {
		printf("Vetor %d: ", i + 1);
		scanf("%d", &vetor[i]);
	}
	soma = soma_vetor(vetor, TF);
	printf("A soma de todos os elementos do vetor: %d", soma);
}
