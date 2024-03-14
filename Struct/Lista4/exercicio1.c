#include <stdio.h>
#define TF 3

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
        gets(s[i].titulo);
        printf("Instrutor: ");
        gets(s[i].instrutor);
        printf("Preco: ");
        scanf("%f", &s[i].preco);
        printf("Quantidade de horas: ");
        scanf("%d", &s[i].quantidade_horas);
        printf("-------------------------------\n");
    }
}

void procurar(curso s[]) {
    int i, codigo;
    printf("Digite o codigo do curso: ");
    scanf("%d", &codigo);
    for(i = 0; i < TF; i++) {
        if (s[i].codigo == codigo){
            printf("Titulo: ");
            puts(s[i].titulo);
            printf("Instrutor: ");
            puts(s[i].instrutor);
            printf("Preco: %.2f", s[i].preco);
            printf("Quantidade de hotas: %d", s[i].quantidade_horas);
            printf("-------------------------------\n");
            return;
        }
    }
    printf("Codigo nao encontrado\n");
}

float media_preco(curso s[]) {
    int i;
    float soma = 0;
    for (i = 0; i < TF; i++) {
        soma += s[i].preco;
    }
    return (float) soma / TF;
}

float media_tempo(curso s[]) {
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