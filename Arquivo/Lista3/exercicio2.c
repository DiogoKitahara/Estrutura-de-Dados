#include <stdio.h>
#include <string.h>

main() {
	FILE* fp;
	char descricao[30];
	float preco;
	fp = fopen("produto.txt", "r");
	if (fp == NULL) {
		printf("Erro na abertura do arquivo\n");
	}
	fscanf(fp, "%s %f", descricao, &preco);
	if (preco > 50) {
		printf("O preco do produto e maior que 50 reais\n");
	}
	else {
		printf("O preco do produto e menor ou igual que 50 reais\n");
	}
	fclose(fp);
}
