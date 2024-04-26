#include <stdio.h>
#include <string.h>

typedef struct {
	int cod, hh, mm, num_aulas;
	float valor;
	char nome[40], aula[40];
}academia;

int menu() {
	int o;
	printf("1 - Cadastrar alunos\n");
	printf("2 - Listar todos os alunos\n");
	printf("3 - Pesquisar por aluno\n");
	printf("4 - Pesquisar por aula\n");
	printf("0 - Sair\n");
	scanf("%d", &o);
	return o;
}

void cadastro (academia a) {
	FILE* fp;
	int c;
	fp = fopen("fitness.bin", "ab");
	if (fp == NULL) {
		printf("Erro no arquivo");
	}
	printf("Codigo: ");
	scanf("%d", &c);
	while (fread(&a, sizeof(academia),1,fp) == 1) {
			a.cod = c;
			printf("Nome: ");
			fflush(stdin);
			gets(a.nome);
			printf("Hora: ");
			scanf("%d", a.hh);
			printf("Minuto: ");
			scanf("%d", a.mm);
			printf("Numero de aulas: ");
			scanf("%d", a.num_aulas);
			printf("Valor da mensalidade: ");
			scanf("%f", a.valor);
			printf("Aula: ");
			fflush(stdin);
			gets(a.aula);
			fwrite(&a, sizeof(academia), 1, fp);
			printf("Codigo: ");
			scanf("%d", &c);
	}
}

void listar(academia a) {
	FILE *fp;
	fp = fopen("fitness.bin", "rb");
	while(fread(&a, sizeof(academia),1,fp) == 1) {
		printf("Codigo: %d\n", a.cod);
		printf("Nome: %s\n", a.nome);
		printf("Hora: %d\n", a.hh);
		printf("Minuto: %d\n", a.mm);
		printf("Numero de aulas: %d\n", a.num_aulas);
		printf("Valor da mensalidade: %.2f\n", a.valor);
		printf("Aula: %s\n", a.aula);
		printf("------------------------------------------\n");
	}
	fclose(fp);
}

void pesquisaAluno(academia a) {
	FILE* fp;
	char n[40];
	fp = fopen("fitness.bin", "ab");
	if (fp == NULL) {
		printf("Erro no arquivo");
	}
	printf("Aluno a pesquisar? ");
	fflush(stdin);
	gets(n);
	while (fread(&a, sizeof(academia),1,fp) == 1) {
		if (stricmp(n,a.nome) == 0 ) {
		printf("Codigo: %d\n", a.cod);
		printf("Nome: %s\n", a.nome);
		printf("Hora: %d\n", a.hh);
		printf("Minuto: %d\n", a.mm);
		printf("Numero de aulas: %d\n", a.num_aulas);
		printf("Valor da mensalidade: %.2f\n", a.valor);
		printf("Aula: %s\n", a.aula);
		printf("------------------------------------------\n");
		}
	}
	fclose(fp);
}

void pesquisaAula(academia a) {
	FILE* fp;
	char n[40];
	fp = fopen("fitness.bin", "ab");
	if (fp == NULL) {
		printf("Erro no arquivo");
	}
	printf("Aula a pesquisar? ");
	fflush(stdin);
	gets(n);
	while (fread(&a, sizeof(academia),1,fp) == 1) {
		if (stricmp(n,a.aula) == 0 ) {
		printf("Codigo: %d\n", a.cod);
		printf("Nome: %s\n", a.nome);
		printf("Hora: %d\n", a.hh);
		printf("Minuto: %d\n", a.mm);
		printf("Numero de aulas: %d\n", a.num_aulas);
		printf("Valor da mensalidade: %.2f\n", a.valor);
		printf("------------------------------------------\n");
		}
	}
	fclose(fp);
}

main() {
	academia a;
	int op = menu();
	while (op != 0) {
		switch(op) {
			case 1: cadastro(a);
				break;
			case 2: listar(a);
				break;
			case 3: pesquisaAluno(a);
				break;
			case 4: pesquisaAula(a);
				break;
			case 0:
				break;
		}
		menu();
	}
}
