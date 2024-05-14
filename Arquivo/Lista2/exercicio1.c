#include <stdio.h>
#include <string.h>

main() {
	FILE* fp;
	char nome_curso[20] = "";
	fp = fopen("curso.txt", "w");
	if (fp == NULL) {
		printf("Erro na abertura do arquivo\n");
	}
	printf("Nome do curso: ");
	fflush(stdin);
	gets(nome_curso);
	fputs(nome_curso, fp);
	fclose(fp);
}
