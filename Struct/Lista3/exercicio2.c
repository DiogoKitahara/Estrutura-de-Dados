#include <stdio.h>
#define TF 3

typedef struct {
	int dia, mes, ano;
}data;

typedef struct {
	char nome[30], sexo, cpf[30], cargo[30];
	int codigo, idade;
	float salario;
	data d;
}funcionario;

void ler(funcionario f[]) {
	int i;
	for(i = 0; i < TF; i++) {
		printf("Nome: ");
		fflush(stdin);
		gets(f[i].nome);
		printf("Sexo[M / F]: ");
		fflush(stdin);
		scanf(" %c", &f[i].sexo);
		printf("CPF: ");
		fflush(stdin);
		gets(f[i].cpf);
		printf("Cargo: ");
		fflush(stdin);
		gets(f[i].cargo);
		printf("Codigo: ");
		scanf("%d", &f[i].codigo);
		printf("Idade: ");
		scanf("%d", &f[i].idade);
		printf("Salario: ");
		scanf("%f", &f[i].salario);
	}
}

void imprimir (funcionario f[]) {
	int i;
	for (i = 0; i < TF; i++) {
		printf("-------------------------------\n");
		printf("Nome: ");
		puts(f[i].nome);
		printf("Sexo: %c\n", f[i].sexo);
		printf("CPF: ");
		puts(f[i].cpf);
		printf("Cargo: ");
		puts(f[i].cargo);
		printf("Codigo: %d\n", f[i].codigo);
		printf("Idade: %d\n", f[i].idade);
		printf("Salario: %.2f\n", f[i].salario);
	}
}

int main() {
	funcionario f[TF];
	ler(f);
	imprimir(f);
}
