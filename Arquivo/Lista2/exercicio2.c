#include <stdio.h>
#include <string.h>

main() {
	FILE* fp; 
	char nome[20], nome_vogais[20];
	int i = 0, j = 0;
	fp = fopen("alfa.txt", "a");
	if (fp == NULL) {
		printf("Erro na abertura do arquivo\n");
	}
	printf("Nome: ");
	fflush(stdin);
	gets(nome);
	while(nome[i] != '\0') {
		if (nome[i] == 'a' || nome[i] == 'e' || nome[i] == 'i' || nome[i] == 'o' || nome[i] == 'u' || nome[i] == 'A' || nome[i] == 'E' || nome[i] == 'I' || nome[i] == 'O' || nome[i] == 'U') {
			nome_vogais[j] = nome[i];
			j++;
		}
		i++;
	}
	fputs(nome_vogais, fp);
	putc('\n', fp);
	fclose(fp);
}
