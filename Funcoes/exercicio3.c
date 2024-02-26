#include <stdio.h>

void verificarVogal(char letra) {
    if (letra == 'a' || letra == 'A' || letra == 'e' || letra == 'E' || letra == 'i' || letra == 'I' || letra == 'o' || letra == 'O' || letra == 'u' || letra == 'U') {
        printf("A letra e uma vogal\n");
    }
    else {
        printf("A letra nao e uma vogal\n");
    }
}

int main() {
    char letra;
    printf("Informe uma letra: ");
    scanf("%c", &letra);
    verificarVogal(letra);
}