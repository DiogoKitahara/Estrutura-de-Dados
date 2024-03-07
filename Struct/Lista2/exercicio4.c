#include <stdio.h>

struct bolsa_de_valores {
    char nome[30], area[30];
    float valor_acao;
};

void imprimirDados(struct bolsa_de_valores b) {
    printf("------------------------------\n");
    printf("Nome: ");
    puts(b.nome);
    printf("Area de atuacao: ");
    puts(b.area);
    printf("Valor da acao: R$%.2f\n", b.valor_acao);
}

float comprar(struct bolsa_de_valores b, int quantidade) {
    return b.valor_acao * quantidade;
}

int main() {
    struct bolsa_de_valores b;
    float valor_pagar;
    int quantidade_acao;
    printf("Nome da empresa: ");
    gets(b.nome);
    printf("Area de atuacao: ");
    gets(b.area);
    printf("Valor atual da acao em reais: R$");
    scanf("%f", &b.valor_acao);
    imprimirDados(b);
    printf("Quantidade de acoes que deseja comprar: ");
    scanf("%d", &quantidade_acao);
    valor_pagar = comprar(b, quantidade_acao);
    printf("O valor sera de R$%.2f\n", valor_pagar);
}