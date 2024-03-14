#include <stdio.h>
#define TF 5

typedef struct {
	char sexo, cor_olho, cor_cabelo;
	int idade;
}habitante;

void ler(habitante h[]) {
	int i;
	for (i = 0; i < TF; i++) {
		printf("Sexo[M / F]: ");
		scanf(" %c", &h[i].sexo);
		printf("Cor dos olhos [A - Azuis / C - Castanhos]: ");
		scanf(" %c", &h[i].cor_olho);
		printf("Cor dos cabelos [L - Louros / P - Pretos / C - Castanhos]: ");
		scanf(" %c", &h[i].cor_cabelo);
		printf("Idade: ");
		scanf("%d", &h[i].idade);
		printf("-----------------------------\n");
	}
}

float mediaOlho(habitante h[]) {
	float media;
	int i, soma = 0, contador;
	for(i = 0; i < TF; i++) {
		if (h[i].cor_olho == 'C' && h[i].cor_cabelo =='P') {
			contador++;
			soma += h[i].idade;
		}
	}
	media = (float) soma / contador;
	return media;
}

int maiorIdade(habitante h[]) {
	int i, maior = 0;
	for(i = 0; i < TF; i++) {
		if (h[i].idade > maior) {
			maior = h[i].idade;
		}
	}
	return maior;
}

int maiorFeminino(habitante h[]) {
	int i, quantidade = 0;
	for (i = 0; i < TF; i++) {
		if (h[i]. idade >= 18 && h[i].idade <= 35 && h[i].sexo == 'F') {
			quantidade++;
		}
	}
	return quantidade;
}

int main() {
	habitante h[TF];
	float media;
	int maior_idade, maior_feminino;
	ler(h);
	media = mediaOlho(h);
	maior_idade = maiorIdade(h);
	maior_feminino = maiorFeminino(h);
	printf("Media de idade das pessoas com olhos castanhos e cabelos pretos: %.2f\n", media);
	printf("Maior idade entre os habitantes: %d\n", maior_idade);
	printf("Quantidade de individuos do sexo feminino cuja idade esta entre 18 e 35: %d\n", maior_feminino);
}
