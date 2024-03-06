#include <stdio.h>

struct peca {
    int quantidade, codigo;
    float preco;
};

struct peca informaPeca() {
    struct peca pe1;
    printf("Codigo: ");
    scanf("%d", &pe1.codigo);
    printf("Quantidade: ");
    scanf("%d", &pe1.quantidade);
    printf("Preco: ");
    scanf("%f", &pe1.preco);
    return pe1;
}

int main() {
    struct peca p1 = informaPeca();
    printf("Codigo: %d\n", p1.codigo);
    printf("Quantidade: %d\n", p1.quantidade);
    printf("Preco: R$%.2f\n", p1.preco);
}