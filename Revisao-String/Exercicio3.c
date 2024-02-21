#include <stdio.h>
#include <string.h> 

main() {
	int i, j, k = 0, contador = 0;
	char frase[60], frase2[60], frase3[60], frase4[60] = "";
	printf("Digite uma frase: ");
	gets(frase);
	// Ir caracter por caracter para encontrar o espaco
	for(i = 0; i < strlen(frase); i++){
		if (frase[i] == ' '){
			contador++;
			// Loop para regredir uma casa do vetor depois do espaco
            for (j = i; j < strlen(frase); j++) {
                frase[j] = frase[j + 1];
            }
		}
	}
	printf("Quantidade de caracteres em branco %d\n", contador);
	puts(frase);
}
