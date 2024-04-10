#include <stdio.h>

main() {
	FILE* arq;
	char car;
	arq = fopen("arq.txt", "w");
	if (arq == NULL) {
		printf("Erro no arquivo\n");
	}
	do {
		printf("Digite um caractere: ");
		scanf(" %c", &car);
		fputc(car,arq);
	} while (car != '0');
	fclose(arq);
	arq = fopen("arq.txt", "r");
	if (arq == NULL) {
		printf("Erro no arquivo\n");
	}
	printf("Lendo e mostrando os dados do aquivo...\n");
	do {
		car = fgetc(arq);
		printf("%c", car);
	} while(car != EOF);
}
