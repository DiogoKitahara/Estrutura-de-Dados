#include <stdio.h>

main() {
	FILE* fp;
	char letra;
	fp = fopen("arq.txt", "w");
	if (fp == NULL) {
		printf("Erro na abertura do arquivo\n");
	}
	printf("Caractere [0 - cancelar]: ");
	fflush(stdin);
	scanf("%c", &letra);
	while(letra != '0') {
		putc(letra, fp);
		printf("Caractere [0 - cancelar]: ");
		fflush(stdin);
		scanf("%c", &letra);
	}
	fclose(fp);
	fp = fopen("arq.txt", "r");
	if (fp == NULL ) {
		printf("Erro na abertura do arquivo\n");
	}
	letra = getc(fp);
	while (letra != EOF) {
		printf("%c", letra);
		letra = getc(fp);
	}
	fclose(fp);
}
