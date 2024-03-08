#include <stdio.h>
#define TF 2

typedef struct{
	char modelo[20];
	int potencia, ano, numero_portas;
}carro;

void ler(carro c[]) {
	int i;
	for(i = 0; i < TF; i++) {
		printf("Modelo: ");
		fflush(stdin);
		gets(c[i].modelo);
		printf("Potencia: ");
		scanf("%d", &c[i].potencia);
		printf("Ano: ");
		scanf("%d", &c[i].ano);
		printf("Numero de portas: ");
		scanf("%d", &c[i].numero_portas);
		printf("---------------------------\n");	
	}
}

void imprimir (carro c[]) {
	int i;
	for (i = 0; i < TF; i++) {
		printf("Carro %d\n", i + 1);
		printf("Potencia: %d | Ano: %d | Numero de portas: %d | Modelo: ", c[i].potencia, c[i]. ano, c[i].numero_portas);
		puts(c[i].modelo);
	}
}

int main() {
	carro c[TF];
	ler(c);
	imprimir(c);
}
