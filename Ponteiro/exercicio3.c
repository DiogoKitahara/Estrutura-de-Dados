#include <stdio.h>

int soma(int* x, int* y){
 	return *x + *y;
}
 
int main() {
	int x, y, soma_valores;
	printf("Valor de x: ");
	scanf("%d", &x);
	printf("Valor de y: ");
	scanf("%d", &y);
	soma_valores = soma(&x, &y);
	printf("A soma dos valores e: %d", soma_valores);
}
