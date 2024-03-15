#include <stdio.h>
#define TF 30

typedef struct
{
    char plataforma[30], filme[30], genero[30], ator_principal[30];
    int duracao_minutos;
} filme;

void cadastrar(filme f[], int c)
{
    printf("Filme: ");
    gets(f[c].filme);
    printf("Duracao em minutos: ");
    scanf("%d", &f[c].duracao_minutos);
    printf("Plataforma: ");
    gets(f[c].plataforma);
    printf("Genero: ");
    gets(f[c].genero);
    printf("Ator principal: ");
    gets(f[c].ator_principal);
    printf("---------------------------------\n");
}

void ListarTodos(filme f[], int c)
{
    int i;
    for (i = 0; i < c; i++)
    {
        printf("Filme: ");
        puts(f[i].filme);
        printf("Duracao em minutos: %d", f[i].duracao_minutos);
        printf("Plataforma: ");
        puts(f[i].plataforma);
        printf("Genero: ");
        puts(f[i].genero);
        printf("Ator principal: ");
        puts(f[i].ator_principal);
        printf("---------------------------------\n");
    }
}

void listarGenero(filme f[], int c) {

}

void listarDuracao(filme f[], int c) {
    
}

void listarPlataforma(filme f[], int c) {

}

int main()
{
    filme f[30];
    int operacao, contador = 0;
    while (operacao != 6)
    {
        printf("1 - Cadatrar filme/serie\n");
        printf("2 - Listar todos os cadastrasdos\n");
        printf("3 - Listar Filme/Serie por genero\n");
        printf("4 - Listar Filme/Serie com duraca entre 90 e 120 minutos\n");
        printf("5 - Listar Filme/Serie por plataforma\n");
        printf("6 - Sair\n");
        printf("---------------------------------\n");
        printf("Operacao: ");
        scanf("%d", &operacao);
        switch (operacao)
        {
        case 1:
            cadastrar(f, contador);
            contador++;
            break;
        case 2:
            listarTodos(f, contador);
            break;
        case 3:
            listarGenero(f, contador);
            break;
        case 4:
            listarDuracao(f, contador);
            break;
        case 5:
            listarPlataforma(f, contador);
            break;
        case 6:
            break;
        default:
            printf("Operacao inexistente\n");
            break;
        }
    }
}