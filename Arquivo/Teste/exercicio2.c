#include <stdio.h>

typedef struct {
	int hora, minuto;
}horario;

typedef struct {
	horario h;
	int codigo, aulas_semana;
	char nome[20], aula[30];
	float mensalidade;
}aluno;

void menu() {
	printf("=-=-=-=- Menu =-=-=-=-\n");
	printf("1 - Cadastrar aluno\n");
	printf("2 - Listar todos os alunos cadastrados\n");
	printf("3 - Pesquisar por aluno\n");
	printf("4 - Pesquisar por aula\n");
	printf("0 - Sair\n");
	printf("=-=-=-=-=-=-=-=-=-=-=-=-\n");
}

void cadastrar () {
	aluno a;
	FILE* fp;
	fp = fopen("fitness.bin", "ab");
	if (fp == NULL) {
		printf("Erro na abertura do arquivo\n");
	}
	else {
		printf("Codigo do aluno: ");
		scanf("%d", &a.codigo);
		printf("Nome: ");
		fflush(stdin);
		gets(a.nome);
		printf("Horario da aula: ");
		scanf("%d%d", &a.h.hora, &a.h.minuto);
		printf("Aula: ");
		fflush(stdin);
		gets(a.aula);
		printf("Numero de aulas na semana: ");
		scanf("%d", &a.aulas_semana);
		printf("Valor da mensalidade: ");
		scanf("%f", &a.mensalidade);
		fwrite(&a, sizeof(a), 1, fp);
	}
	fclose(fp);
}

void listar() {
	aluno a;
	FILE* fp;
	fp = fopen("fitness.bin", "rb");
	if (fp == NULL) {
		printf("Erro na abertura do arquivo\n");
	}
	else {
		while (fread(&a, sizeof(a), 1, fp) == 1) {
		printf("Codigo do aluno: %d\n", a.codigo);
		printf("Nome: %s\n", a.nome);
		printf("Horario da aula: %d/%d\n", a.h.hora, a.h.minuto);
		printf("Aula: %s\n", a.aula);
		printf("Numero de aulas na semana: %d\n", a.aulas_semana);
		printf("Valor da mensalidade: %.2f\n", a.mensalidade);
		printf("--------------------------------\n");
		}
	}
	fclose(fp);
}

void pesquisar_aluno() {
	aluno a;
	char nome_aluno[20];
	printf("Nome: "); 
	fflush(stdin);
	gets(nome_aluno);
	FILE* fp;
	fp = fopen("fitness.bin", "rb");
	if (fp == NULL) {
		printf("Erro na abertura do arquivo\n");
	}
	else {
		while(fread(&a, sizeof(a), 1, fp) == 1) {
			if(strcmp(nome_aluno, a.nome) == 0) {
				printf("Codigo do aluno: %d\n", a.codigo);
				printf("Horario da aula: %d/%d\n", a.h.hora, a.h.minuto);
				printf("Aula: %s\n", a.aula);
				printf("Numero de aulas na semana: %d\n", a.aulas_semana);
				printf("Valor da mensalidade: %.2f\n", a.mensalidade);
			}
		}
	}
	fclose(fp);
}

void pesquisar_aula() {
	aluno a;
	char nome_aula[20];
	printf("Aula: "); 
	fflush(stdin);
	gets(nome_aula);
	FILE* fp;
	fp = fopen("fitness.bin", "rb");
	if (fp == NULL) {
		printf("Erro na abertura do arquivo\n");
	}
	else {
		while(fread(&a, sizeof(a), 1, fp) == 1) {
			if(strcmp(nome_aula, a.aula) == 0) {
				printf("Codigo do aluno: %d\n", a.codigo);
				printf("Nome: %s\n", a.nome);
				printf("Horario da aula: %d/%d\n", a.h.hora, a.h.minuto);
				printf("Numero de aulas na semana: %d\n", a.aulas_semana);
				printf("Valor da mensalidade: %.2f\n", a.mensalidade);
			}
		}
	}
	fclose(fp);
}

main() {
	int op;
	do {
		menu();
		printf("Operacao: ");
		scanf("%d", &op);
		switch(op) {
			case 1:
				cadastrar();
				break;
			case 2:
				listar();
				break;
			case 3:
				pesquisar_aluno();
				break;
			case 4:
				pesquisar_aula();
				break;
			case 0:
				break;
		}
	}while (op != 0);
}
