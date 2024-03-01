#include <stdio.h> 

void operacao(int* a, int* b) {
	*a -= 1;
	*b += 1;
}

int main() {
	int a, b;
	printf("Valor de a: ");
	scanf("%d", &a);
	printf("Valor de b: ");
	scanf("%d", &b);
	operacao(&a, &b);
	printf("a: %d\n", a);
	printf("b: %d\n", b);
}
