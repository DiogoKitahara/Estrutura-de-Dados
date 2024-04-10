#include <stdio.h>

main() {
	FILE* arq;
	char nomearq[20];
	int atdc = 0;
	printf("Digite o nome do arquivo: ");
	gets(nomearq);
	arq = fopen(nomearq, "r");
	if arq == NULL) {
		printf("Erro no arquivo\n");
	}
	while (getc(arq) != EOF) {
		qtdc++;
	}
	printf("A quantidade de caracteres e %d", qtdc);
	fclose(arq);
}
