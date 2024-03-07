#include <stdio.h>

struct paciente {
	float peso, altura;
};

float calcularImc(struct paciente p) {
	float resultado = p.peso / (p.altura * p.altura);
	return resultado;
}

void imprimirResultado(float imc) {
	if (imc < 18.5) {
		printf("Baixo peso\n");
	}
	else if (imc < 24.9) {
		printf("Peso normal\n");
	}
	else if (imc < 29.9) {
		printf("Sobrepeso\n");
	}
	else if (imc < 34.9) {
		printf("Obesidade grau I\n");
	}
	else if (imc < 39.9) {
		printf("Obesidade grau II\n");
	}
	else{
		printf("Obesidade grau III\n");
	}
}

int main() {
	struct paciente p;
	float imc;
	printf("Peso: ");
	scanf("%f", &p.peso);
	printf("Altura: ");
	scanf("%f", &p.altura);
	imc = calcularImc(p);
	imprimirResultado(imc);
}
