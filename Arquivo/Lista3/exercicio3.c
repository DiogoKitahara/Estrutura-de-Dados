#include <stdio.h>
#include <string.h>

main() {
	char aniversario[11];
	FILE* fp;
	fp = fopen("aniversario.txt", "w");
	if (fp == NULL) {
		printf("Erro na abertura do arquivo\n");
	}
	printf("Aniversario[dd/mm/aaaa]: ");
	gets(aniversario);
	fprintf(fp, "%s", aniversario);
	fclose(fp);
}
