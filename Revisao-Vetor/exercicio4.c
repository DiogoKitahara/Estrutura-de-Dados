#include <stdio.h>
#include <string.h>
#define TF 3

int main() {
    char senha[9] = {"psswd123"}, tentativa[9];
    float valor_menor_cotacao = 999999, cotacao[TF];
    int i, dia_menor_cotacao;
    // Tentativa de acertar a senha
    printf("Senha: ");
    gets(tentativa);
    if (strcmp(tentativa, senha) == 0) {
        // Loop preencher cotacao
        for (i = 0; i < TF; i++) {
            // Armazenar cotacoes
            printf("Dia %d: ", i + 1);
            scanf("%f", &cotacao[i]);
            // Comparar cotacoes, armazenar menor cotacao e dia
            if(cotacao[i] < valor_menor_cotacao) {
                valor_menor_cotacao = cotacao[i];
                dia_menor_cotacao = i;
            }
        }
    }
    else {
        printf("Senha incorreta\n");
        return 0;
    }
    // Imprimir menor cotacao e o dia
    printf("A menor cotacao do dolar em Janeiro foi de %.2f, no dia %d de Janeiro\n", valor_menor_cotacao, dia_menor_cotacao + 1);
    return 0;
}
