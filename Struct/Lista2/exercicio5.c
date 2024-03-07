/*O comando typedef permite definir um novo nome para um determinado tipo, particularmente útil com structs,
pois simplifica a declaração de variáveis e parâmetros de tipo struct*/

#include <stdio.h>

typedef struct {
    char nome[30];
    long ra;
} estudante;

int main() {
    estudante e1 = {"Diogo Kitahara", 10442324069};
    printf("Nome: ");
    puts(e1.nome);
    printf("RA: %li\n", e1.ra);
}