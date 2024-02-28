#include <stdio.h> 

float calcularMedia(float n1, float n2, float n3, char tipo_media) {
	float media;
	if (tipo_media == 'a') {
		media = (n1 + n2 + n3) / 3;
	}
	else if(tipo_media == 'p') {
		media = ((n1 * 5) + (n2 * 3) + (n3 * 2)) / 10;
	}
	return media;
}

int main() {
	float media, n1, n2, n3, nota[3];
	char tipo_media;
	int i;
	printf("Nota 1: ");
	scanf("%f", &n1);
	printf("Nota 2: ");
	scanf("%f", &n2);
	printf("Nota 3: ");
	scanf("%f", &n3);
	printf("Tipo de media [a = media aritmetica / p = media ponderada]: ");
	scanf(" %c", &tipo_media);
	fflush(stdin);
	media = calcularMedia(n1, n2, n3, tipo_media);
	printf("Media = %.2f", media);
}
