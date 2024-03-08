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
		gets(f.nome);
		printf("Sexo: ");
		fflush(stdin);
		scanf("%c", f.sexo);
		printf("CPF: ");
		fflush(stdin);
		gets(f.cpf);
		printf("Cargo: ");
		fflush(stdin);
		gets(f.cargo);
		printf("Codigo: ");
		scanf("%d", f.codigo);
		printf("Idade: ");
		scanf("%d", f.idade);
		printf("Salario: ");
		scanf("%f", f.salario);
	}
}

int main() {
	funcionario f[TF];
	ler(f);
	imprimir(f);
}
