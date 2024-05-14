#include <stdio.h>

typedef struct {
	int dia, mes, ano;
}nascimento;

typedef struct {
	nascimento n;
	char nome[20], email[30], telefone[20], cpf[15];
}cliente;

main() {
	cliente c;
	char continuar;
	FILE* fp;
	fp = fopen("cliente.txt", "wb");
	if (fp == NULL) {
		printf("Erro na abertura do \n");
	}
	do {
		printf("Nome: ");
		fflush(stdin);
		gets(c.nome);
		printf("E-mail: ");
		fflush(stdin);
		gets(c.email);
		printf("Telefone: ");
		fflush(stdin);
		gets(c.telefone);
		printf("CPF: ");
		fflush(stdin);
		gets(c.cpf);
		printf("Data de nascimento: ");
		scanf("%d%d%d", &c.n.dia, &c.n.mes, &c.n.ano);
		fwrite(&c, sizeof(c), 1, fp);
		printf("Deseja continuar[s / n]? ");
		fflush(stdin);
		scanf("%c", &continuar);
		printf("------------------------------\n");
	} while (continuar != 'n');
	fclose(fp);
	fp = fopen("cliente.txt", "rb");
	if (fp == NULL) {
		printf("Erro na abertura do arquivo\n");
	}
	while(fread(&c, sizeof(c), 1, fp) == 1 ){
		printf("Nome: %s\n", c.nome);
		printf("E-mail: %s\n", c.email);
		printf("Telefone: %s\n", c.telefone);
		printf("CPF: %s\n", c.cpf);
		printf("Data de nascimento: %d/%d/%d\n", c.n.dia, c.n.mes, c.n.ano);
		printf("------------------------------\n");
	}
	fclose(fp);
}
