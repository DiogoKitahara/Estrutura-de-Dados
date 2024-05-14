#include <stdio.h>
#include <string.h>

main() {
	FILE* fp;
	int contador_vogais = 0, i = 0;
	char nome[41];
	fp = fopen("alfa.txt", "r");
	if (fp == NULL) {
		printf("Erro na leitura do arquivo\n");
	}
	nome[0] = getc(fp);
	while (nome[i] != EOF) {
		if (nome[i] == 'a' || nome[i] == 'e' || nome[i] == 'i' || nome[i] == 'o' || nome[i] == 'u' || nome[i] == 'A' || nome[i] == 'E' || nome[i] == 'I' || nome[i] == 'O' || nome[i] == 'U'){
			contador_vogais++;
		}
		i++;
		nome[i] = getc(fp);
	}
	printf("%d", contador_vogais);
	fclose(fp);
}
