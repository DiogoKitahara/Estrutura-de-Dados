#include <stdio.h>
#include <string.h>

main() {
	char descricao[30];
	float preco;
	FILE* fp;
	fp = fopen("produto.txt", "w");
	if (fp == NULL) {
		printf("Erro na abertura do arquivo\n");
	}
	printf("Descricao: ");
	gets(descricao);
	printf("Preco: ");
	scanf("%f", &preco);
	fprintf(fp, "%s\n", descricao);
	fprintf(fp, "%f", preco);
	fclose(fp);
}
