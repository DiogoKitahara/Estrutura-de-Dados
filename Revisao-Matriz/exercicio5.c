#include <stdio.h>
#define TFL 5
#define TFC 3

main() {
    // Declarar variaveis
    float notas[TFL][TFC], media, media_total, soma = 0, soma_total = 0;
    int i, j;
    // Loop linha
    for (i = 0; i < TFL; i++) {
        // Loop coluna
        for(j = 0; j < TFC; j++){
            printf("Nota %d do aluno %d: ", j + 1, i + 1);
            scanf("%f", &notas[i][j]);
            // Realizar a soma das notas do aluno
            soma += notas[i][j];
            // Realizar a somatoria total das notas
            soma_total += notas[i][j];
        }
        // Calcular media por aluno
        media = (float) soma / 3;
        printf("Media do aluno %d: %.2f\n", i + 1, media);
        printf("-------------------------\n");
        soma = 0;
    }
    // Realizar a media total das notas
    media_total = (float) soma_total / 15;
    printf("Media total: %.2f\n",media_total);
}