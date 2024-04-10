#include <stdio.h>

int main() {
	FILE *f;
	int i;
	char letra = 'a';
	f = fopen("dados.txt", "w");
	if (f == NULL) {
		printf("Nao foi possivel abrir o arquivo\n");
	}
	else {
		for(i = 0; i < 26; i++) {
			putc(letra, f);
			letra++;
		}
	}
}
