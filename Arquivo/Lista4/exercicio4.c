#include <stdio.h>

typedef struct {
	int dia, mes, ano;
}data;

typedef struct {
	data d;
	int codigo;
	char palestrante[20], nome_palestra[30], local[20], minicurriculo[40];
}palestra;

main() {
	palestra p;
	char continuar, encontrar[20];
	FILE* fp;
	fp = fopen("palestra.txt","wb");
	if (fp == NULL) {
		printf("Erro na abertura do arquivo\n");
	}
	else {
		do {
			printf("Codigo: ");
			scanf("%d", &p.codigo);
			printf("Palestrante: ");
			fflush(stdin);
			gets(p.palestrante);
			printf("Nome da palestra: ");
			fflush(stdin);
			gets(p.nome_palestra);
			printf("Local: ");
			fflush(stdin);
			gets(p.local);
			printf("minicurriculo: ");
			fflush(stdin);
			gets(p.minicurriculo);
			printf("Data: ");
			fflush(stdin);
			scanf("%d%d%d", &p.d.dia, &p.d.mes, &p.d.ano);
			fwrite(&p, sizeof(p), 1, fp);
			printf("Deseja continuar[s / n]: ");
			fflush(stdin);
			scanf("%c", &continuar);
			printf("------------------------------\n");
		}while (continuar != 'n');
	}
	fclose(fp);
	printf("Palestrante que deseja encontrar o minicurriculo: ");
	fflush(stdin);
	gets(encontrar);
	fp = fopen("palestra.txt","rb");
	if (fp == NULL) {
		printf("Erro na abertura do arquivo\n");
	}
	else {
		while (fread(&p, sizeof(p), 1, fp) == 1) {
			if (strcmp(p.palestrante, encontrar) == 0) {
				printf("Minicurriculo: %s\n", p.minicurriculo);
			}
		}
	}
	fclose(fp);
}
