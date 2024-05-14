#include <stdio.h>

typedef struct {
	int codigo;
	float preco;
	char nome[20], pao[20];
}lanche;

void menu() {
	printf("=-=-=-=- Menu =-=-=-=-\n");
	printf("1 - Inserir\n");
	printf("2 - Consultar todos lanches\n");
	printf("3 - Consultar lanche pelo nome\n");
	printf("4 - Consultar lanche por tipo de pao\n");
	printf("0 - Sair\n");
	printf("=-=-=-=-=-=-=-=-=-=-=-=-\n");
}

void cadastrar () {
	lanche l;
	FILE* fp;
	fp = fopen("lanche.txt", "ab");
	if (fp == NULL) {
		printf("Erro na abertura do arquivo\n");
	}
	else {
		printf("Codigo do lanche: ");
		scanf("%d", &l.codigo);
		printf("Nome: ");
		fflush(stdin);
		gets(l.nome);
		printf("Preco: ");
		scanf("%f", &l.preco);
		printf("Tipo de pao: ");
		fflush(stdin);
		gets(l.pao);
		fwrite(&l, sizeof(l), 1, fp);
	}
	fclose(fp);
}

void listar() {
	lanche l;
	FILE* fp;
	fp = fopen("lanche.txt", "rb");
	if (fp == NULL) {
		printf("Erro na abertura do arquivo\n");
	}
	else {
		while (fread(&l, sizeof(l), 1, fp) == 1) {
		printf("Codigo do pedido: %d\n", l.codigo);
		printf("Nome: %s\n", l.nome);
		printf("Preco: %.2f\n", l.preco);
		printf("Tipo de pao: %s\n", l.pao);
		printf("--------------------------------\n");
		}
	}
	fclose(fp);
}

void consultar_nome() {
	lanche l;
	char nome_lanche[20];
	printf("Nome: "); 
	fflush(stdin);
	gets(nome_lanche);
	FILE* fp;
	fp = fopen("lanche.txt", "rb");
	if (fp == NULL) {
		printf("Erro na abertura do arquivo\n");
	}
	else {
		while(fread(&l, sizeof(l), 1, fp) == 1) {
			if(strcmp(nome_lanche, l.nome) == 0) {
				printf("Codigo do pedido: %d\n", l.codigo);
				printf("Preco: %.2f\n", l.preco);
				printf("Tipo de pao: %s\n", l.pao);
			}
		}
	}
	fclose(fp);
}

void consultar_pao() {
	lanche l;
	char tipo_pao[20];
	printf("Tipo do pao: "); 
	fflush(stdin);
	gets(tipo_pao);
	FILE* fp;
	fp = fopen("lanche.txt", "rb");
	if (fp == NULL) {
		printf("Erro na abertura do arquivo\n");
	}
	else {
		while(fread(&l, sizeof(l), 1, fp) == 1) {
			if(strcmp(tipo_pao, l.pao) == 0) {
				printf("Nome: %s\n", l.nome);
				printf("Codigo do pedido: %d\n", l.codigo);
				printf("Preco: %.2f\n", l.preco);
			}
		}
	}
}

main() {
	int op;
	do {
		menu();
		printf("Operacao: ");
		scanf("%d", &op);
		switch(op) {
			case 1:
				cadastrar();
				break;
			case 2:
				listar();
				break;
			case 3:
				consultar_nome();
				break;
			case 4:
				consultar_pao();
				break;
			case 0:
				break;
		}
	}while (op != 0);
}
