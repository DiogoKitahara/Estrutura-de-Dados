#include <stdio.h>
#include <string.h>

main() {
	int i;
	char frase[60];
	printf("Digite uma frase: ");
	gets(frase);
	if (strlen(frase) >=4) {
		for(i = 0; i < 4; i++){
			printf("%c", frase[i]);
		}
	}
}
