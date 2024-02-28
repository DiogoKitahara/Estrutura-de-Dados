#include <stdio.h> 

void desenhar(int linha) {
	int i;
	for(i = 0; i < linha; i++) {
		printf("=");
	}
	printf("\n");
}

int main() {
	int linha;
	printf("Quantas simbolos de igual desenhar: ");
	scanf("%d", &linha);
	desenhar(linha);
}
