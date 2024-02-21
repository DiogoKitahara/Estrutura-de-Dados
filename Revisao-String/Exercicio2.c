#include <stdio.h>
#include <string.h>

main() {
	int i;
	char frase[60];
	printf("Digite uma frase: ");
	gets(frase);
	// Exibir a frase em maiusculo
	puts(strupr(frase));
	// Quantidade de caracteres
	printf("A frase possui %d caracteres\n", strlen(frase));
	// Caracteres na posição impar
	for(i = 1; i < strlen(frase); i+=2) {
		printf("%c", frase[i]);
	}
}
