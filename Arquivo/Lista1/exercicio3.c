#include <stdio.h>
#include <string.h>

main() {
	FILE* fp;
	char nome_arquivo[20], letra;
	int contador = 0;
	printf("Contar quantidade de caracteres no arquivo: ");
	gets(nome_arquivo);
	fp = fopen(nome_arquivo, "r");
	if (fp == NULL)	{
		printf("Erro na abertura do arquivo\n");
	}
	letra = getc(fp);
	while (letra != EOF) {
		contador++;
		letra = getc(fp);
	}
	fclose(fp);
	printf("%d caracteres\n", contador);
}
