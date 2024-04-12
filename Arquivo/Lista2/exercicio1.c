#include <stdio.h>

main() {
	FILE* arq;
	char curso[20];
	arq = fopen("curso.txt", "w");
	if (arq == NULL) {
		printf("Erro no arquivo\n");
	}
	printf("Curso: ");
	gets(curso);
	fputs(curso, arq);
	//fprintf(arq, "%s", curso);
}
