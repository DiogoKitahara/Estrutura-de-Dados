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
	int codigo;
	char nome[20], cpf[15], aniversario[15];
}paciente;

typedef struct {
	int codigo;
	char nome[40];
}procedimento;

typedef struct {
	medico med;
	paciente pac;
	procedimento proc;
	char data[20];
}agendamento;

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

int buscaMedico(FILE *arquivo,int codigo){
	medico med;
	rewind(arquivo);
	fread(&med,sizeof(medico),1,arquivo);
	while(!feof(arquivo)&& codigo != med.crm)
		fread(&med,sizeof(medico),1,arquivo);
	if(!feof(arquivo))
		return(ftell(arquivo)-sizeof(medico));
	else
		return -1;
}

int buscaPaciente(FILE *arquivo,int codigo){
	paciente pac;
	rewind(arquivo);
	fread(&pac,sizeof(paciente),1,arquivo);
	while(!feof(arquivo)&& codigo != pac.codigo)
		fread(&pac,sizeof(paciente),1,arquivo);
	if(!feof(arquivo))
		return(ftell(arquivo)-sizeof(paciente));
	else
		return -1;
}

int buscaProcedimento(FILE *arquivo,int codigo){
	procedimento proc;
	rewind(arquivo);
	fread(&proc,sizeof(procedimento),1,arquivo);
	while(!feof(arquivo)&& codigo != proc.codigo)
		fread(&proc,sizeof(procedimento),1,arquivo);
	if(!feof(arquivo))
		return(ftell(arquivo)-sizeof(procedimento));
	else
		return -1;
}

void cadastrarMedico() {
	medico med;
	FILE* fp;
	fp = fopen("medico.bin", "ab");
	if (fp == NULL) {
		printf("Erro na abertura do arquivo\n");
	}
	else {
		printf("CRM: ");
		scanf("%d", &med.crm);
		printf("Nome: ");
		fflush(stdin);
		gets(med.nome);
		printf("Especialidade: ");
		fflush(stdin);
		gets(med.especialidade);
		fwrite(&med, sizeof(medico), 1, fp);
	}
	fclose(fp);
}

void cadastrarPaciente() {
	paciente pac;
	FILE* fp;
	fp = fopen("paciente.bin", "ab");
	if (fp == NULL) {
		printf("Erro na abertura do arquivo\n");
	}
	else {
		printf("Codigo: ");
		scanf("%d", &pac.codigo);
		printf("Nome: ");
		fflush(stdin);
		gets(pac.nome);
		printf("CPF: ");
		fflush(stdin);
		gets(pac.cpf);
		printf("Aniversario [dd/mm/aaaa]: ");
		fflush(stdin);
		gets(pac.aniversario);
		fwrite(&pac, sizeof(paciente), 1, fp);
	}
	fclose(fp);
}

void cadastrarProcedimento() {
	procedimento proc;
	FILE* fp;
	fp = fopen("procedimento.bin", "ab");
	if (fp == NULL) {
		printf("Erro na abertura do arquivo\n");
	}
	else {
		printf("Codigo: ");
		scanf("%d", &proc.codigo);
		printf("Nome: ");
		fflush(stdin);
		gets(proc.nome);
		fwrite(&proc, sizeof(procedimento), 1, fp);
	}
	fclose(fp);
}

void relatorioMedico() {
	medico med;
	FILE* fp;
	fp = fopen("medico.bin", "rb");
	if (fp == NULL) {
		printf("Erro na abertura do arquivo\n");
	}
	else {
		while (fread(&med, sizeof(medico), 1, fp) == 1) {
		printf("Codigo do pedido: %d\n", med.crm);
		printf("Nome: %s\n", med.nome);
		printf("Especialidade: %s\n", med.especialidade);
		printf("--------------------------------\n");
		}
	}
	fclose(fp);
}

void relatorioPaciente() {
	paciente pac;
	FILE* fp;
	fp = fopen("paciente.bin", "rb");
	if (fp == NULL) {
		printf("Erro na abertura do arquivo\n");
	}
	else {
		while (fread(&pac, sizeof(paciente), 1, fp) == 1) {
		printf("Codigo do pedido: %d\n", pac.codigo);
		printf("Nome: %s\n", pac.nome);
		printf("CPF: %s\n", pac.cpf);
		printf("Aniversario: %s\n", pac.aniversario);
		printf("--------------------------------\n");
		}
	}
	fclose(fp);
}

void relatorioProcedimento() {
	procedimento proc;
	FILE* fp;
	fp = fopen("procedimento.bin", "rb");
	if (fp == NULL) {
		printf("Erro na abertura do arquivo\n");
	}
	else {
		while (fread(&proc, sizeof(procedimento), 1, fp) == 1) {
		printf("Codigo: %d\n", proc.codigo);
		printf("Nome: %s\n", proc.nome);
		printf("--------------------------------\n");
		}
	}
	fclose(fp);
}

void agendamento() {
	medico med;
	int crm, codigo_paciente, codigo_procedimento;
	paciente pac;
	procedimento proc;
	FILE* fp, fp2, fp3, fp4;
	fp = fopen("agendamento.bin", "ab");
	fp2 = fopen("medico.bin", "rb");
	fp3 = fopen("paciente.bin", "rb");
	fp4 = fopen("procedimento.bin", "rb");
}

main() {
	medico med;
	paciente pac;
	procedimento proc;
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
				switch (op) {
					case 1:
						cadastrarMedico();
						break;
					case 2:
						cadastrarPaciente();
						break;
					case 3:
						cadastrarProcedimento();
						break;
				}
				break;
			case 2:
				menuExclusao();
				printf("Opcao: ");
				scanf("%d", &op);
				//exclusao(op);
				break;
			case 3:
				menuAgendamento();
				//agendamento(op);
				break;
			case 4:
				menuRelatorio();
				printf("Opcao: ");
				scanf("%d", &op);
				switch (op) {
					case 1:
						relatorioMedico();
						break;
					case 2:
						relatorioPaciente();
						break;
					case 3:
						relatorioProcedimento();
						break;
				}
				break;
			case 5:
				//menuAlterar();
				printf("Opcao: ");
				scanf("%d", &op);
				//alterar(op);
			case 0:
				break;
		}
	}while (op != 0);
}
