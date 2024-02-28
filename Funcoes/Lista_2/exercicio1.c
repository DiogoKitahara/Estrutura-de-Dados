#include <stdio.h>

float segundoParaMinuto(float segundo) {
	return segundo / 60;
}

int main() {
	float segundo, minuto;
	printf("Segundo: ");
	scanf("%f", &segundo);
	minuto = segundoParaMinuto(segundo);
	printf("%.2f segundos equivale a %.2f minutos\n", segundo, minuto);
}
