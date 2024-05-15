/* 
10442324176 - DEBORA JANAINE LAGOS SOARES
10442324069 - DIOGO SEIDI KITAHARA
10442324247 - HUGO DE SOUZA DIAS
10442324612 - YURI MARQUES PILONI
*/

#include <stdio.h>
#include <string.h>
#include <windows.h>
#define TF 100

typedef struct {
	int crm;
	char nome[20], especialidade[20];
}medico;

typedef struct {
	int crm;
	char nome[20], especialidade[20];
}paciente;

typedef struct {
	int crm;
	char nome[20], especialidade[20];
}procedimento;

typedef struct {
	int crm;
	char nome[20], especialidade[20];
}relatorio;

typedef struct {
	int crm;
	char nome[20], especialidade[20];
}lancamento;

void menuInicial() {
    printf("=-=-=-=- Menu =-=-=-=-\n\n");
    printf("1 - Cadastrar\n");
    printf("2 - Exclusao\n");
    printf("3 - Agendamento\n");
    printf("4 - Relatorio\n");
    printf("0 - Finalizar\n\n");
    printf("=-=-=-=-=-=-=-=-=-=-=-\n");
}

void menuCadastro() {
    printf("=-=-=-=- Cadastro =-=-=-=-\n\n");
    printf("1 - Medico\n");
    printf("2 - Paciente\n");
    printf("3 - Procedimento\n");
    printf("0 - Retornar\n\n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
}

void menuExclusao() {
	printf("=-=-=-=- Exclusao =-=-=-=-\n\n");
    printf("1 - Medico\n");
    printf("2 - Paciente\n");
    printf("3 - Procedimento\n");
    printf("4 - Agendamento\n");
	printf("0 - Retornar\n\n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-\n");          
}

void menuAgendamento() {
	printf("=-=-=-=- Agendamento =-=-=-=-\n\n");
}

void menuRelatorio() {
    printf("=-=-=-=- Relatorio =-=-=-=-\n\n");
    printf("1 - Medico\n");
    printf("2 - Paciente\n");
    printf("3 - Procedimento\n");
    printf("4 - Agendamento\n");
    printf("0 - Retornar\n\n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
}

void cadastrarMedico

main() {
	int op;
	do {
		menuInicial();
		printf("Operacao: ");
		scanf("%d", &op);
		switch(op) {
			case 1:
				menuCadastro();
				printf("Opcao: ");
				scanf("%d", &op);
				switch (op_cadastro) {
					case 1:
						cadastrarMedico();
						break;
				}
				break;
			case 2:
				menuExclusao();
				printf("Opcao: ");
				scanf("%d", &op_exclusao);
				//exclusao(op_exclusao);
				break;
			case 3:
				menuAgendamento();
				printf("Opcao: ");
				scanf("%d", &op_lancamento);
				//lancamento(op_lancamento);
				break;
			case 4:
				menuRelatorio();
				printf("Opcao: ");
				scanf("%d", &op_relatorio);
				//relatorio(op_relatorio);
				break;
			case 5:
				//menuAlterar();
				printf("Opcao: ");
				scanf("%d", &op_alterar);
				//alterar(op_alterar);
			case 0:
				break;
		}
	}while (op != 0);
}
