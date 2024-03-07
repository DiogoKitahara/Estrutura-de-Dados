#include <stdio.h>

struct data {
	int dia, mes, ano;
};

struct boleto {
	char nome[30];
	struct data d;
	float preco;
};

struct boleto informar() {
    struct boleto b;
	printf("Nome: ");
	gets(b.nome);
	printf("Preco: ");
	scanf("%f", &b.preco);
	printf("Dia: ");
	scanf("%d", &b.d.dia);
	printf("Mes: ");
	scanf("%d", &b.d.mes);
	printf("Ano: ");
	scanf("%d", &b.d.ano);
    return b;
}

int main() {
    struct boleto b = informar();
    printf("---------------------------------\n");
	printf("Nome: ");
	puts(b.nome);
	printf("Preco: %.2f\n", b.preco);
	printf("Data: %d/%d/%d\n", b.d.dia, b.d.mes, b.d.ano);
}