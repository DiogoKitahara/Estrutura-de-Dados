#include <stdio.h>

main() {
	FILE* arq;
	char nome[20], nome_professora[20];
	int i = 0;
	arq = fopen("alfa.txt", "w");
	if (arq == NULL) {
		printf("Erro no arquivo\n");
	}
	printf("Nome: ");
	gets(nome);
	while(nome[i] != '\0') {
		if (nome[i] == 'a' || nome[i] == 'e' || nome[i] == 'i' || nome[i] == 'o' || nome[i] == 'u' || nome[i] == 'A' || nome[i] == 'E' || nome[i] == 'I' || nome[i] == 'O' || nome[i] == 'U') {
			putc(nome[i], arq);
		}
		i++;
	}
	i = 0;
	fclose(arq);
	arq = fopen("alfa.txt", "a");
	if (arq == NULL) {
		printf("Erro no arquivo\n");
	}
	printf("Nome da professora: ");
	gets(nome_professora);
	while(nome_professora[i] != '\0') {
		if (nome_professora[i] == 'a' || nome_professora[i] == 'e' || nome_professora[i] == 'i' || nome_professora[i] == 'o' || nome_professora[i] == 'u' || nome_professora[i] == 'A' || nome_professora[i] == 'E' || nome_professora[i] == 'I' || nome_professora[i] == 'O' || nome_professora[i] == 'U') {
			putc(nome_professora[i], arq);
		}
		i++;
	}
}
