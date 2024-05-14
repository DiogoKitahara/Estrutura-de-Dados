#include <stdio.h>

typedef struct {
	char rua[20], bairro[20], cep[15];
	int numero_endereco;
}endereco;

typedef struct {
	endereco e;
	int quantidade, numero_pedido;
	float valor;
	char descricao[20], marca[20];
}peca;

void menu() {
	printf("=-=-=-=- Menu =-=-=-=-\n");
	printf("1 - Cadastrar pedido\n");
	printf("2 - Listar todos os pedidos\n");
	printf("3 - Consultar pecas pela descricao\n");
	printf("4 - Listar pecas pela marca e sair\n");
	printf("0 - Sair\n");
	printf("=-=-=-=-=-=-=-=-=-=-=-=-\n");
}

void cadastrar () {
	peca p;
	FILE* fp;
	fp = fopen("pedido.txt", "ab");
	if (fp == NULL) {
		printf("Erro na abertura do arquivo\n");
	}
	else {
		printf("Numero do pedido: ");
		scanf("%d", &p.numero_pedido);
		printf("Quantidade: ");
		scanf("%d", &p.quantidade);
		printf("Valor: ");
		scanf("%f", &p.valor);
		printf("Descricao: ");
		fflush(stdin);
		gets(p.descricao);
		printf("Marca: ");
		fflush(stdin);
		gets(p.marca);
		printf("Rua: ");
		fflush(stdin);
		gets(p.e.rua);
		printf("Numero: ");
		fflush(stdin);
		scanf("%d", &p.e.numero_endereco);
		printf("Bairro: ");
		fflush(stdin);
		gets(p.e.bairro);
		printf("CEP: ");
		fflush(stdin);
		gets(p.e.cep);
		fwrite(&p, sizeof(p), 1, fp);
	}
	fclose(fp);
}

void listar() {
	peca p;
	FILE* fp;
	fp = fopen("pedido.txt", "rb");
	if (fp == NULL) {
		printf("Erro na abertura do arquivo\n");
	}
	else {
		while (fread(&p, sizeof(p), 1, fp) == 1) {
		printf("Numero do pedido: %d\n", p.numero_pedido);
		printf("Quantidade: %d\n", p.quantidade);
		printf("Valor: %.2f\n", p.valor);
		printf("Descricao: %s\n", p.descricao);
		printf("Marca: %s\n", p.marca);
		printf("Rua: %s\n", p.e.rua);
		printf("Numero: %d\n", p.e.numero_endereco);
		printf("Bairro: %s\n", p.e.bairro);
		printf("CEP: %s\n", p.e.cep);
		}
	}
}

void consultar_descricao() {
	peca p;
	FILE* fp;
	fp = fopen("pedido.txt", "rb");
	if (fp == NULL) {
		printf("Erro na abertura do arquivo\n");
	}
}

void listar_marca() {
	peca p;
	FILE* fp;
	fp = fopen("pedido.txt", "rb");
	if (fp == NULL) {
		printf("Erro na abertura do arquivo\n");
	}
}

main() {
	peca p;
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
			/*case 3:
				consultar_descricao();
				break;
			case 4:
				listar_marca();
				break;
			case 0:
				break;*/
		}
	}while (op != 0);
}
