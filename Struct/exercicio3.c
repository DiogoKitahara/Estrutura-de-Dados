#include <stdio.h>

struct paciente {
	int codigo, idade;
	float altura, peso;
};

struct paciente informaDados() {
	struct paciente p1;
	printf("Codigo: ");
	scanf("%d", &p1.codigo);
	printf("Idade: ");
	scanf("%d", &p1.idade);
	printf("Altura: ");
	scanf("%f", &p1.altura);
	printf("Peso: ");
	scanf("%f", &p1.peso);
	return p1;
}

int main() {
	struct paciente p1 = informaDados();
	printf("Codigo: %d\n", p1.codigo);
	printf("Idade: %d\n", p1.idade);
	printf("Altura: %.2f\n", p1.altura);
	printf("Peso: %.2f\n", p1.peso);
}
