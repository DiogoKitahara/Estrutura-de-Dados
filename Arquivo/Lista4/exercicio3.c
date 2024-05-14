#include <stdio.h>

typedef struct {
	int dia,mes,ano;
}data;

typedef struct {
	data d;
	char atividade[20], local[20], responsavel[20];
}programa;

main() {
	programa p;
	char continuar;
	FILE* fp;
	fp = fopen("comemoracao.txt", "wb");
	if (fp == NULL) {
		printf("Erro na abertura do arquivo\n");
	}
	else {
		do {
			printf("Atividade: ");
			fflush(stdin);
			gets(p.atividade);
			printf("Local: ");
			fflush(stdin);
			gets(p.local);
			printf("Responsavel: ");
			fflush(stdin);
			gets(p.responsavel);
			printf("Data: ");
			scanf("%d%d%d", &p.d.dia, &p.d.mes, &p.d.ano);
			fwrite(&p, sizeof(p), 1, fp);
			printf("Deseja continuar[s / n]? ");
			fflush(stdin);
			scanf("%c", &continuar);
			printf("------------------------------\n");
		} while(continuar != 'n');
	}
	fclose(fp);
	fp = fopen("comemoracao.txt", "rb");
	if (fp == NULL) {
		printf("Erro na abertura do arquivo");
	}
	else {
		printf("========Listagem das atividades cadastradas para o dia das maes========\n");
		while(fread(&p, sizeof(p), 1, fp) == 1) {
			printf("Atividade: %s\n", p.atividade);
			printf("Local: %s\n", p.local);
			printf("Responsavel: %s\n", p.responsavel);
			printf("Data: %d/%d/%d\n", p.d.dia, p.d.mes, p.d.ano);
			printf("------------------------------\n");
		}
	}
	fclose(fp);
}
