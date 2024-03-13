#include <stdio.h>
#define TF 5

typedef struct {
	char sexo, cor_olho, cor_cabelo
	int idade;
}habitante;

int main() {
	habitante h[TF];
	float media;
	int maior;
	ler(h);
	media = mediaOlho(h);
	maior_idade = maiorIdade(h);
	maior_feminino = maiorFeminino(h);
	printf("Media de idade das pessoas co olhos castanhos e cabelos pretos: %.2f", media);
	printf("Maior idade entre os habitantes: %d", maior_idade);
	printf("Quantidade de individuos do sexo feminino cja idade esta entre 18 e 35: %d", maior_feminino);
}
