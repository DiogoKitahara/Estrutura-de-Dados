#include <stdio.h> 

float reajuste (float salario) {
	return salario * 1.09;
}

float dolarParaReal (float dolar) {
	return dolar * 4.93;
}

int fatorial (int n) {
	int i, fatorial = 0;
	for (i = n; i > 1; i--) {
		fatorial = fatorial * i - 1;
	}
	return fatorial;
}

cosumoCombustivel (float km, float litro) {
	float consumo = km / litro (float);
	if (consumo < 8){
		printf("Venda o carro!\n");
	}
	else if (consumo >= 8 && consumo <= 14){
		printf("Economico!\n");
	}
	else{
		printf("Super economico!\n");
	}
}
