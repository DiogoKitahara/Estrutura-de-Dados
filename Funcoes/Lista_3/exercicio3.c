#include <stdio.h>

float calcular_investimento(float capital, float juros, int tempo) {
	float lucro;
	int i;
	for (i = 0; i < tempo; i++) {
		lucro = capital * (juros / 100);
		capital += lucro;
	}
	return capital;
}

int main() {
	float capital_inicial, juros_anual, montante_acumulado;
	int tempo_anos;
	printf("Capital inicial: ");
	scanf("%f", &capital_inicial);
	printf("Juros anual: ");
	scanf("%f", &juros_anual);
	printf("Tempo em anos: ");
	scanf("%d", &tempo_anos);
	montante_acumulado = calcular_investimento(capital_inicial, juros_anual, tempo_anos);
	printf("Montante acumulado de %.2f", montante_acumulado);
}
