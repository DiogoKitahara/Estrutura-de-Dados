#include <stdio.h>
#define TF 5

main(){
    float soma = 0, media, nota[TF], maior_nota = 0;
    int i, aluno_maior_nota;
    // Loop para ler as notas dos alunos
    for (i = 0; i < TF; i++) {
        printf("Nota do aluno %d: ", i + 1);
        scanf("%f", &nota[i]);
        // Comparar nota, armazenar o aluno q obteve a maior nota e sua nota
        if (nota[i] > maior_nota) {
            maior_nota = nota[i];
            aluno_maior_nota = i;
        }
        soma += nota[i];
    }
    // Realizar a media
    media = (float) soma / TF;
    // Imprimir media, aluno com maior nota e sua nota
    printf("A media da turma e de %.2f\n", media);
    printf("A maior nota foi de %.2f, obtida pelo aluno %d\n", maior_nota, aluno_maior_nota + 1);
}   