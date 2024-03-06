#include <stdio.h>
#include <string.h>

struct cao {
    char nome[30], sexo, raca[30];
    int idade;
};

struct cao informaCao() {
    struct cao c1;
    printf("Nome: ");
    gets(c1.nome);
    printf("Sexo [M - masculino / F - Feminino]: ");
    scanf("%c", &c1.sexo);
    printf("Raca: ");
    gets(c1.raca);
    printf("Idade: ");
    scanf("%d", &c1.idade);
};

int main() {
    struct cao c1 = informaCao();
    printf("------------------------------\n");
    puts(c1.nome);
    printf("Sexo: %c\n", c1.sexo);
    puts(c1.raca);
    printf("Idade: %d", c1.idade);
}