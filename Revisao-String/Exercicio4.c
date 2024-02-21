#include <stdio.h>
#include <string.h>

main() {
	int i, contador = 0;
	char palavra1[20], palavra2[20], concatenacao[40] = "";
	printf("Digite uma palavra: ");
	gets(palavra1);
	printf("Digite outra palavra: ");
	gets(palavra2);
	// Exibir tamanho das palavras
	printf("Tamanho da primeira palavra: %d\n", strlen(palavra1));
	printf("Tamanho da segunda palavra: %d\n", strlen(palavra2));
	// Concatenar as duas palavras
	strcat(concatenacao, palavra1);
	strcat(concatenacao, palavra2);
	// Exibir a concatenacao
	puts(concatenacao);
}
