#include <stdio.h>
#include <string.h>

main() {
	char aniversario[11];
	FILE* fp;
	fp = fopen("aniversario.txt", "r");
	if (fp == NULL){
		printf("Erro na abertura do arquivo\n");
	}
	fscanf(fp, "%s", aniversario);
	if (aniversario[3] == '1' && aniversario[4] == '0') {
		printf("O mes do aniversariante e outubro\n");
	}
	else {
		printf("O mes do aniversariante nao e outubro\n");
	}
	fclose(fp);
}
