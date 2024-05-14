#include <stdio.h>

main() {
	FILE* fp;
	int i;
	char letra = 'a';
	fp = fopen("dados.txt", "w");
	if (fp == NULL) {
		printf("Erro na abertura do arquivo\n");
	}
	for (i = 0; i < 26; i++) {
		putc(letra, fp);
		letra++;
	}
	fclose(fp);
}
