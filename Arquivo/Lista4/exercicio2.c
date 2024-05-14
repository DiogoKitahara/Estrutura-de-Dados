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
	FILE* fp;
	char encontrar_cpf[15];
	printf("CPF da pessoa que deseja obter informacoes: ");
	gets(encontrar_cpf);
	fp = fopen("cliente.txt", "rb");
	if (fp == NULL) { 
		printf("Erro na abertura\n");
	}
	else {
		while (fread(&c, sizeof(c), 1, fp) == 1) {
			if (strcmp(encontrar_cpf, c.cpf) == 0) {
				printf("Nome: %s\n", c.nome);
				printf("Email: %s\n", c.email);
				printf("Telefone: %s\n", c.telefone);
				printf("Aniversario: %d/%d/%d\n", c.n.dia, c.n.mes, c.n.ano);
			}
		}
	}
}
