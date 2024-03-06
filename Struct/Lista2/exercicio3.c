#include <stdio.h>

struct paciente {
	float peso, altura;
};

calcularImc(struct paciente* p) {
	
}

int main() {
	struct paciente p;
	float imc;
	printf("Peso: ");
	scanf("%f", &p.peso);
	printf("Altura: ");
	scanf("%f", &p.altura);
	imc = calcularImc(&p);
	imprimirResultado(imc);
}
