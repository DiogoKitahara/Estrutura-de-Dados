#include <stdio.h>

void triplo (int* x) {
	*x = *x * 3;
}

int main() {
	int x;
	printf("Valor de x: ");
	scanf("%d", &x);
	triplo(&x);
	printf("Triplo de x: %d\n", x);
}
