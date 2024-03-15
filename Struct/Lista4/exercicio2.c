#include <stdio.h>
#define TF 200

typedef struct
{
    int mes, ano;
} validade;

typedef struct
{
    int mes, ano;
} fabricacao;

typedef struct
{
    int codigo;
    char tipo[30], descricao[50];
    float preco;
    fabricacao f;
    validade v;
} produto;

void ler(produto p[])
{
    int i;
    for (i = 0; i < TF; i++)
    {
        printf("Codigo: ");
        scanf("%d", &p[i].codigo);
        printf("Tipo");
        gets(p[i].tipo);
        printf("Descricao");
        gets(p[i].descricao);
        printf("Preco: ");
        scanf("%f", &p[i].preco);
        printf("Ano da validade: ");
        scanf("%d", &p[i].v.ano);
        printf("Mes da validade: ");
        scanf("%d", &p[i].v.mes);
        printf("Ano da fabricacao: ");
        scanf("%d", &p[i].f.ano);
        printf("Mes da validade: ");
        scanf("%d", &p[i].f.mes);
    }
}

void relatorioTipo(produto p[])
{
}

void relatorioValidade(produto p[])
{
    int i, j, ano = 2024, contador = 0;
    printf("Relatorio por mes e ano de validade\n");
    while (contador < TF)
    {
        for (j = 0; j < 12; j++);
        
    }
}

int main()
{
    produto p[TF];
    int i;
    ler(p);
    relatorioTipo(p);
    relatorioValidade(p);
}