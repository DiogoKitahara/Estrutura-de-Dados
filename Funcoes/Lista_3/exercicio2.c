#include <stdio.h> 

int soma_multiplos(int n) {
	int multiplo3 = 3, contador3 = 0, multiplo5 = 5, contador5 = 0;
	while (multiplo3 <= n){
		contador3 += multiplo3;
		multiplo3 += 3;
	}
	while (multiplo5 <= n) {
		contador5 += multiplo5;
		multiplo5 += 5;
	}
	return contador3 + contador5;
}

int main() {
	int n, resultado;
	printf("Digite um valor: ");
	scanf("%d", &n);
	resultado = soma_multiplos(n);
	printf("Resultado: %d\n", resultado);
}
