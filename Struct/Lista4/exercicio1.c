#include <stdio.h>
#define TF 10

typedef struct {
    int codigo, quantidade_horas;
    float preco;
    char titulo[30], instrutor[30];
} curso;

void ler(curso s[]) {
    int i;
    for(i = 0; i < TF; i++) {
        printf("Codigo: ");
        scanf("%d", &s[i].codigo);
        printf("Titulo: ");
        fflush(stdin);
        gets(s[i].titulo);
        printf("Instrutor: ");
        fflush(stdin);
        gets(s[i].instrutor);
        printf("Preco: ");
        scanf("%f", &s[i].preco);
        printf("Quantidade de horas: ");
        scanf("%d", &s[i].quantidade_horas);
        printf("-------------------------------\n");
    }
}

void procurarCurso(curso s[]) {
    int i, codigo;
    printf("Digite o codigo do curso que deseja saber: ");
    scanf("%d", &codigo);
    for(i = 0; i < TF; i++) {
        if (s[i].codigo == codigo){
            printf("Titulo: ");
            puts(s[i].titulo);
            printf("Instrutor: ");
            puts(s[i].instrutor);
            printf("Preco: %.2f\n", s[i].preco);
            printf("Quantidade de hotas: %d\n", s[i].quantidade_horas);
            printf("-------------------------------\n");
            return;
        }
    }
    printf("Codigo nao encontrado\n");
    printf("-------------------------------\n");
}

float mediaPreco(curso s[]) {
    int i;
    float soma = 0;
    for (i = 0; i < TF; i++) {
        soma += s[i].preco;
    }
    return (float) soma / TF;
}

float mediaTempo(curso s[]) {
    int i;
    float soma = 0;
    for (i = 0; i < TF; i++) {
        soma += s[i].quantidade_horas;
    }
    return (float) soma / TF;
}

int main() {
    curso s[TF];
    float media_preco, media_tempo;
    ler(s);
    procurarCurso(s);
    media_preco = mediaPreco(s);
    media_tempo = mediaTempo(s);
    printf("Media de preco dos cursos: %.2f\n", media_preco);
    printf("Media de tempo dos cursos: %.2f\n", media_tempo);
}
