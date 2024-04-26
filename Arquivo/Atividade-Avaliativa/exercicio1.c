#include <stdio.h>

main () {
	FILE* fp;
	fp = fopen("conta.txt", "r");
	int v[9], i;
	for (i = 0; i < 9; i++) {
		fscanf(fp, "%d\n", &v[i]);
		v[i] = v[i] * v[i] * v[i];
		printf("%d\n", v[i]);
	}
	fclose(fp);
	fp = fopen("conta.txt", "w");
	for (i = 0; i < 9; i++) {
		fprintf(fp, "%d\n", v[i]);
	}
	fclose(fp);
}
