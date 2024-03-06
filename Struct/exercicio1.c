#include <stdio.h>
#include <string.h>

struct data {
	int dia, mes, ano;
};

struct data informaData() {
	struct data dma;
	printf("Informe o dia: ");
	scanf("%d", &dma.dia);
	printf("Informe o mes: ");
	scanf("%d", &dma.mes);
	printf("Informe o ano: ");
	scanf("%d", &dma.ano);
	return dma;
}

int retornaAno (struct data dma) {
	return dma.ano;
}

int main() {
	struct data dma;
	printf("Ano = %d", retornaAno(informaData()));
}
