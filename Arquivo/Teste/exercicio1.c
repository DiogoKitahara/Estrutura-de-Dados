#include <stdio.h>

main() {
	FILE* fp;
	int i, v[9];
	fp = fopen("conta.txt", "r");
	if (fp == NULL) {
		printf("Erro na abertura do arquivo\n");
	}
	else {
		for(i = 0; i < 9; i++) {
			fscanf(fp, "%d\n", &v[i]);
			v[i] = v[i] * v[i] * v[i];
		}
	}
	fclose(fp);
	fp = fopen("conta.txt", "w");
	if (fp == NULL) {
		printf("Erro na abertura do arquivo\n");
	}
	else {
		for(i = 0; i < 9; i++) {
			fprintf(fp, "%d\n", v[i]);
		}
	}
	fclose(fp);
}
