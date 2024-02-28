#include <stdio.h> 

int soma_multiplos(int n) {
	int multiplo3 = 0, contador3 = 0, multiplo5 = 0, contador5 = 0;
	while (multiplo3 < n){
		multiplo3 += 3;
		contador3 += multiplo3;
	}
	while (multiplo5 < n) {
		multiplo5 += 5;
		contador5 += multiplo5;
	}
	return contador3 + contador5;
}

int main() {
	int n, resultado;
	printf("Digite um valor: ");
	scanf("%d", &n);
	resultado = soma_multiplos(n);
	printf("Resultado: %d", resultado);
}
