#include <stdio.h>
#include <string.h>

main() {
	FILE* fp;
	char nome[20], aniversario[20];
	fp = fopen("aniversario.txt", "w");
	printf("Nome: ");
	fflush(stdin);
	gets(nome);
	printf("Aniversario: ");
	fflush(stdin);
	gets(aniversario);
	fputs(nome, fp);
	putc(' ', fp);
	fputs(aniversario, fp);
	fclose(fp);
}
