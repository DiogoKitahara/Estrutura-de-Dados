#include <stdio.h>
#define TF 5

main() {
    float nota[TF], media, soma = 0;
    int i, contador = 0;
    // Armazenar valores
    for (i = 0; i < TF; i++){
        printf("Nota do %d aluno: ", i + 1);
        scanf("%f", &nota[i]);
        soma += nota[i];
    }
    // Calcular media
    media = soma / TF;
    // Calcular quantos alunos obtiveram nota acima da media
    for (i = 0; i < TF; i++) {
        if (nota[i] >= media) {
            contador++;
        }
    }
    printf("%d alunos obtiveram nota acima da media geral da turma\n", contador);
}