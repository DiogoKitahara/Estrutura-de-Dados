#include <stdio.h>

typedef struct {
	int numero_endereco;
	char rua[20], bairro[20], cep[20];
}endereco;

typedef struct {
	int hora_pedido, hora_entrega, minuto_pedido, minuto_entrega;
}horario;

typedef struct {
	endereco e;
	horario h;
	int numero_pedido;
	char nome[20];
}pedido;

void menu() {
	printf("=-=-=-=- Menu =-=-=-=-\n");
	printf("1 - Cadastrar pedido\n");
	printf("2 - Listar pedidos pelo seu numero\n");
	printf("0 - Sair\n");
	printf("=-=-=-=-=-=-=-=-=-=-=-=-\n");
}

void cadastrar () {
	pedido p;
	FILE* fp;
	fp = fopen("pedidos.bin", "wb");
	if (fp == NULL) {
		printf("Erro na abertura do arquivo\n");
	}
	else {
		printf("Numero do pedido: ");
		scanf("%d", &p.numero_pedido);
		printf("Nome: ");
		fflush(stdin);
		gets(p.nome);
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
		printf("Horario da realizacao do pedido: ");
		scanf("%d%d", &p.h.hora_pedido, &p.h.minuto_pedido);
		printf("Horario da entrega do pedido: ");
		scanf("%d%d", &p.h.hora_entrega, &p.h.minuto_entrega);
		fwrite(&p, sizeof(p), 1, fp);
	}
	fclose(fp);
}

void listar_numero() {
	pedido p;
	int num;
	printf("Numero do pedido: ");
	scanf("%d", &num);
	FILE* fp;
	fp = fopen("pedidos.bin", "rb");
	if (fp == NULL) {
		printf("Erro na abertura do arquivo\n");
	}
	else {
		while (fread(&p, sizeof(p), 1, fp) == 1) {
			if(num == p.numero_pedido) {
				printf("Nome: %s\n", p.nome);
				printf("Rua: %s\n", p.e.rua);
				printf("Numero: %d\n", p.e.numero_endereco);
				printf("Bairro: %s\n", p.e.bairro);
				printf("CEP: %s\n", p.e.cep);
				printf("Horario da realizacao do pedido: %d:%d\n", p.h.hora_pedido, p.h.minuto_pedido);
				printf("Horario da entrega do pedido: %d:%d\n", p.h.hora_entrega, p.h.minuto_entrega);
				printf("--------------------------------\n");
			}
		}
	}
	fclose(fp);
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
				listar_numero();
				break;
			case 0:
				break;
		}
	}while (op != 0);
}
