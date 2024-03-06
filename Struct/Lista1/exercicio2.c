#include <stdio.h>

struct produto {
	int codigo;
	float preco;
};

struct produto informaProduto() {
	struct produto p1;
	printf("Codigo: ");
	scanf("%d", &p1.codigo);
	printf("Preco: ");
	scanf("%f", &p1.preco);
	return p1;
}

int main() {
	struct produto p1 = informaProduto();
	printf("Codigo: %d\n", p1.codigo);
	printf("Preco: %.2f\n", p1.preco);
}
