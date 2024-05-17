/* 
10442324176 - DEBORA JANAINE LAGOS SOARES
10442324069 - DIOGO SEIDI KITAHARA
10442324247 - HUGO DE SOUZA DIAS
10442324612 - YURI MARQUES PILONI
*/

#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <ctype.h>
#define TF 100

typedef struct {
	int crm;
	char nome[20], especialidade[20];
}medico;

typedef struct {
	int codigo;
	char nome[20], cpf[15], nascimento[15];
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
	int hora, minuto;
}agendamento;

void menuInicial() {
    printf("\n=-=-=-=- Menu =-=-=-=-\n\n");
    printf("1 - Cadastrar\n");
    printf("2 - Exclusao\n");
    printf("3 - Alterar\n");
    printf("4 - Agendamento\n");
    printf("5 - Relatorio\n");
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

void menuAlterar() {
    printf("=-=-=-=- Alterar =-=-=-=-\n\n");
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

int buscaAgendamento(FILE *arquivo,int codigo){
	agendamento age;
	rewind(arquivo);
	fread(&age,sizeof(agendamento),1,arquivo);
	while(!feof(arquivo)&& codigo != age.med.crm)
		fread(&age,sizeof(agendamento),1,arquivo);
	if(!feof(arquivo))
		return(ftell(arquivo)-sizeof(agendamento));
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
		printf("Medico cadastrado com sucesso!\n");
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
		printf("Data de nascimento [dd/mm/aaaa]: ");
		fflush(stdin);
		gets(pac.nascimento);
		fwrite(&pac, sizeof(paciente), 1, fp);
		printf("Paciente cadastrado com sucesso!\n");
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
		printf("Procedimento cadastrado com sucesso!\n");
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
			printf("CRM: %d\n", med.crm);
			printf("Nome: %s\n", med.nome);
			printf("Especialidade: %s\n", med.especialidade);
			printf("____________________________\n");
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
			printf("Nome: %s\n", pac.nome);
			printf("Codigo: %d\n", pac.codigo);
			printf("CPF: %s\n", pac.cpf);
			printf("Data de nascimento: %s\n", pac.nascimento);
			printf("____________________________\n");
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
		printf("____________________________\n");
		}
	}
	fclose(fp);
}

void exclusaoMedico() {
	medico med;
	agendamento age;
	FILE* fp;
	FILE* fp2;
	int crm, pos, posm;
	fp = fopen("medico.bin", "rb+");
	if (fp == NULL) {
		printf("Erro na abertura do arquivo\n");
	}
	fp2 = fopen("agendamento.bin", "rb");
	if (fp2 == NULL) {
		printf("Erro na abertura do arquivo\n");
	}
	printf("CRM do medico: ");
	scanf("%d", &crm);
	pos = buscaAgendamento(fp2, crm);
	if (pos == -1) {
		posm = buscaMedico(fp, crm);
		if (posm == -1) {
			printf("Medico nao cadastrado\n");
		}
		else {
			fseek(fp, posm, 0);
			fread(&med, sizeof(medico), 1, fp);
			printf("CRM: %d\n", med.crm);
			printf("Nome: %s\n", med.nome);
			printf("Especialidade: %s\n", med.especialidade);
			printf("____________________________\n");
			printf("Deseja excluir? (s/n): ");
			if (tolower(getche()) == 's') {
				FILE* temp;
				temp = fopen("auxiliar.bin", "wb");
				rewind(fp);
				fread(&med, sizeof(medico), 1, fp);
				while(!feof(fp)) {
					if (crm != med.crm){
						fwrite(&med, sizeof(medico), 1, temp);
					}
					fread(&med, sizeof(medico), 1, fp);
				}
				fclose(fp);
				fclose(temp);
				remove("medico.bin");
				rename("auxiliar.bin", "medico.bin");
				printf("\nMedico excluido com sucesso!\n");
			}
		}
	}
	else {
		printf("Medico com agendamento marcado nao pode ser excluido.\n");
	}
	fclose(fp2);
}

void exclusaoPaciente() {
	paciente pac;
	agendamento age;
	FILE* fp;
	FILE* fp2;
	int codigo_paciente, pos, posm;
	fp = fopen("paciente.bin", "rb+");
	if (fp == NULL) {
		printf("Erro na abertura do arquivo\n");
	}
	fp2 = fopen("agendamento.bin", "rb");
	if (fp2 == NULL) {
		printf("Erro na abertura do arquivo\n");
	}
	printf("Codigo do Paciente: ");
	scanf("%d", &codigo_paciente);
	pos = buscaAgendamento(fp2, codigo_paciente);
	if (pos == -1) {
		posm = buscaPaciente(fp, codigo_paciente);
		if (posm == -1) {
			printf("Paciente nao cadastrado\n");
		}
		else {
			fseek(fp, posm, 0);
			fread(&pac, sizeof(paciente), 1, fp);
			printf("Nome: %s\n", pac.nome);
			printf("Codigo: %d\n", pac.codigo);
			printf("CPF: %s\n", pac.cpf);
			printf("Data de nascimento: %s\n", pac.nascimento);
			printf("____________________________\n");
			printf("Deseja excluir? (s/n): ");
			if (tolower(getche()) == 's') {
				FILE* temp;
				temp = fopen("auxiliar.bin", "wb");
				rewind(fp);
				fread(&pac, sizeof(paciente), 1, fp);
				while(!feof(fp)) {
					if (codigo_paciente != pac.codigo){
						fwrite(&pac, sizeof(paciente), 1, temp);
					}
					fread(&pac, sizeof(paciente), 1, fp);
				}
				fclose(fp);
				fclose(temp);
				remove("paciente.bin");
				rename("auxiliar.bin", "paciente.bin");
				printf("\nPaciente excluido com sucesso!\n");
			}
		}
	}
	else {
		printf("Paciente com agendamento marcado nao pode ser excluido.\n");
	}
	fclose(fp2);
}

void exclusaoProcedimento() {
	procedimento proc;
	agendamento age;
	FILE* fp;
	FILE* fp2;
	int codigo_procedimento, pos, posm;
	fp = fopen("procedimento.bin", "rb+");
	if (fp == NULL) {
		printf("Erro na abertura do arquivo\n");
	}
	fp2 = fopen("agendamento.bin", "rb");
	if (fp2 == NULL) {
		printf("Erro na abertura do arquivo\n");
	}
	printf("Codigo do Procedimento: ");
	scanf("%d", &codigo_procedimento);
	pos = buscaAgendamento(fp2, codigo_procedimento);
	if (pos == -1) {
		posm = buscaProcedimento(fp, codigo_procedimento);
		if (posm == -1) {
			printf("Procedimento nao cadastrado\n");
		}
		else {
			fseek(fp, posm, 0);
			fread(&proc, sizeof(procedimento), 1, fp);
			printf("Codigo: %d\n", proc.codigo);
			printf("Nome: %s\n", proc.nome);
			printf("____________________________\n");
			printf("Deseja excluir? (s/n): ");
			if (tolower(getche()) == 's') {
				FILE* temp;
				temp = fopen("auxiliar.bin", "wb");
				rewind(fp);
				fread(&proc, sizeof(procedimento), 1, fp);
				while(!feof(fp)) {
					if (codigo_procedimento != proc.codigo){
						fwrite(&proc, sizeof(procedimento), 1, temp);
					}
					fread(&proc, sizeof(procedimento), 1, fp);
				}
				fclose(fp);
				fclose(temp);
				remove("procedimento.bin");
				rename("auxiliar.bin", "procedimento.bin");
				printf("\nProcedimento excluido com sucesso!\n");
			}
		}
	}
	else {
		printf("Procedimento com agendamento marcado nao pode ser excluido.\n");
	}
	fclose(fp2);
}

void exclusaoAgendamento() {
	agendamento age;
	FILE* fp2;
	int crm, pos;
	fp2 = fopen("agendamento.bin", "rb");
	if (fp2 == NULL) {
		printf("Erro na abertura do arquivo\n");
	}
	printf("CRM: ");
	scanf("%d", &crm);
	pos = buscaAgendamento(fp2, crm);
	if (pos == -1) {
		printf("Agendamento inexistente.\n");
	}
	else {
		fseek(fp2, pos, 0);
		fread(&age, sizeof(agendamento), 1, fp2);
		printf("___________Medico___________\n\n");
		printf("Nome do Medico: %s\n", age.med.nome);
		printf("CRM: %d\n", age.med.crm);
		printf("Especialidade: %s\n\n", age.med.especialidade);
		printf("__________Paciente__________\n\n");
		printf("Nome do Paciente: %s\n", age.pac.nome);
		printf("Codigo: %d\n", age.pac.codigo);
		printf("CPF: %s\n", age.pac.cpf);
		printf("Data de nascimento: %s\n\n", age.pac.nascimento);
		printf("________Procedimento_________\n\n");
		printf("Nome do Procedimento: %s\n", age.proc.nome);
		printf("Codigo: %d\n", age.proc.codigo);
		printf("Data: %s\n", age.data);
		printf("Horario: %d:%d\n", age.hora, age.minuto);
		printf("____________________________\n\n");
		printf("Deseja excluir? (s/n): ");
		if (tolower(getche()) == 's') {
			FILE* temp;
			temp = fopen("auxiliar.bin", "wb");
			rewind(fp2);
			fread(&age, sizeof(agendamento), 1, fp2);
			while(!feof(fp2)) {
				if (crm != age.med.crm){
					fwrite(&age, sizeof(agendamento), 1, temp);
				}
				fread(&age, sizeof(agendamento), 1, fp2);
			}
			fclose(temp);
			fclose(fp2);
			remove("agendamento.bin");
			rename("auxiliar.bin", "agendamento.bin");
			printf("\nAgendamento excluido com sucesso!\n");
		}
		else
		fclose(fp2);
	}
}

void alterarMedico(){
	medico med;
	int pos,op,crm,posa;
	FILE* arquivo;
	FILE* fp;
	arquivo=fopen("medico.bin","rb+");
	if (arquivo==NULL){
		printf("Erro no arquivo!");
		return;
	}
	fp = fopen("agendamento.bin", "rb");
	if (fp == NULL) {
		printf("Erro na abertura do arquivo\n");
	}
	printf("CRM: ");
	scanf("%d", &crm);
	posa = buscaAgendamento(fp, crm);
	if (posa == -1) {
		pos=buscaMedico(arquivo, crm);
		if(pos==-1)
			printf("\nMedico nao cadastrado!");
		else{
			fseek(arquivo,pos,0);
			fread(&med,sizeof(medico),1,arquivo);
			printf("Nome: %s\n", med.nome);
			printf("Especialidade: %s\n", med.especialidade);
			printf("__________________");
			printf("\nDeseja alterar: \n1 - Nome \n2 - Especialidade\n");
			scanf("%d",&op);
			if( op==1){
				printf("\n NOVO nome: ");
				fflush(stdin);
				gets(med.nome);
				fseek(arquivo,pos,0);
				fwrite(&med,sizeof(medico),1,arquivo);
				printf("Registro Atualizado!\n");
			}
			if( op==2){
				printf("\n NOVA especialidade: ");
				fflush(stdin);
				gets(med.especialidade);
				fseek(arquivo,pos,0);
				fwrite(&med,sizeof(medico),1,arquivo);
				printf("Registro Atualizado!\n");
			}
		}
	}
	else {
		printf("Medico com agendamento marcado nao pode ser alterado.\n");
	}
	fclose(arquivo);
}

void alterarPaciente(){
	paciente pac;
	int pos,op,codigo_paciente,posa;
	FILE* arquivo;
	FILE* fp;
	arquivo=fopen("paciente.bin","rb+");
	if (arquivo==NULL){
		printf("Erro no arquivo!");
		return;
	}
	fp = fopen("agendamento.bin", "rb");
	if (fp == NULL) {
		printf("Erro na abertura do arquivo\n");
	}
	printf("Codigo: ");
	scanf("%d", &codigo_paciente);
	posa = buscaPaciente(fp, codigo_paciente);
	if (posa == -1) {
		pos=buscaPaciente(arquivo, codigo_paciente);
		if(pos==-1)
			printf("\nPaciente nao cadastrado!");
		else{
			fseek(arquivo,pos,0);
			fread(&pac,sizeof(paciente),1,arquivo);
			printf("Nome: %s\n", pac.nome);
			printf("CPF: %s\n", pac.cpf);
			printf("Data de nascimento: %s\n", pac.nascimento);
			printf("__________________");
			printf("\nDeseja alterar: \n1 - Nome \n2 - CPF\n3 - Data de Nascimento\n");
			scanf("%d",&op);
			if(op==1){
				printf("\n NOVO nome: ");
				fflush(stdin);
				gets(pac.nome);
				fseek(arquivo,pos,0);
				fwrite(&pac,sizeof(paciente),1,arquivo);
				printf("Registro Atualizado!\n");
			}
			if(op==2){
				printf("\n NOVO CPF: ");
				fflush(stdin);
				gets(pac.cpf);
				fseek(arquivo,pos,0);
				fwrite(&pac,sizeof(paciente),1,arquivo);
				printf("Registro Atualizado!\n");
			}
			if(op==3){
				printf("\n NOVA Data de Nascimento: ");
				fflush(stdin);
				gets(pac.nascimento);
				fseek(arquivo,pos,0);
				fwrite(&pac,sizeof(paciente),1,arquivo);
				printf("Registro Atualizado!\n");
			}
		}
	}
	else {
		printf("Paciente com agendamento marcado nao pode ser alterado.\n");
	}
	fclose(arquivo);
}

void alterarProcedimento(){
	procedimento proc;
	int pos,op,codigo_procedimento,posa;
	FILE* arquivo;
	FILE* fp;
	arquivo=fopen("procedimento.bin","rb+");
	if (arquivo==NULL){
		printf("Erro no arquivo!");
		return;
	}
	fp = fopen("agendamento.bin", "rb");
	if (fp == NULL) {
		printf("Erro na abertura do arquivo\n");
	}
	printf("Codigo: ");
	scanf("%d", &codigo_procedimento);
	posa = buscaProcedimento(fp, codigo_procedimento);
	if (posa == -1) {
		pos=buscaProcedimento(arquivo, codigo_procedimento);
		if(pos==-1)
			printf("\nProcedimento nao cadastrado!");
		else{
			fseek(arquivo,pos,0);
			fread(&proc,sizeof(procedimento),1,arquivo);
			printf("Nome: %s\n", proc.nome);
			printf("__________________");
			printf("\nDeseja alterar: \n1 - Nome\n");
			scanf("%d",&op);
			if(op==1){
				printf("\n NOVO nome: ");
				fflush(stdin);
				gets(proc.nome);
				fseek(arquivo,pos,0);
				fwrite(&proc,sizeof(procedimento),1,arquivo);
				printf("Registro Atualizado!\n");
			}
		}
	}
	else {
		printf("Procedimento com agendamento marcado nao pode ser alterado.\n");
	}
	fclose(arquivo);
}

void agendar() {
	agendamento age;
	medico med;
	paciente pac;
	procedimento proc;
	int crm, codigo_paciente, codigo_procedimento, posm, pospac,posproc;
	char r;
	FILE* fp;
	FILE* fp2;
	FILE* fp3;
	FILE* fp4;
	fp = fopen("agendamento.bin", "ab");
	if (fp == NULL) {
		printf("Erro na abertura do arquivo\n");
		return;
	}
	fp2 = fopen("medico.bin", "rb");
	if (fp2 == NULL) {
		printf("Erro na abertura do arquivo\n");
		return;
	}
	fp3 = fopen("paciente.bin", "rb");
	if (fp3 == NULL) {
		printf("Erro na abertura do arquivo\n");
		return;
	}
	fp4 = fopen("procedimento.bin", "rb");
	if (fp4 == NULL) {
		printf("Erro na abertura do arquivo\n");
		return;
	}
	do {
		printf("Crm: ");
		scanf("%d", &crm);
		posm = buscaMedico(fp2, crm);
		if (posm == -1 ) {
			printf("Medico nao cadastrado\n");
			return;
		}
		printf("Codigo do paciente: ");
		scanf("%d", &codigo_paciente);
		pospac = buscaPaciente(fp3, codigo_paciente);
		if (pospac == -1 ) {
			printf("Paciente nao cadastrado\n");
			return;
		}
		printf("Codigo do procedimento: ");
		scanf("%d", &codigo_procedimento);
		posproc = buscaProcedimento(fp4, codigo_procedimento);
		if (posproc == -1 ) {
			printf("Procedimento nao cadastrado\n");
			return;
		}
		else {
			fseek(fp2, posm, 0);
			fread(&med, sizeof(medico), 1, fp2);
			strcpy(age.med.nome, med.nome);
			age.med.crm = med.crm;
			strcpy(age.med.especialidade, med.especialidade);
			fseek(fp3, pospac, 0);
			fread(&pac, sizeof(paciente), 1, fp3);
			age.pac.codigo = pac.codigo;
			strcpy(age.pac.nome, pac.nome);
			strcpy(age.pac.cpf, pac.cpf);
			strcpy(age.pac.nascimento, pac.nascimento);
			fseek(fp4, posproc, 0);
			fread(&proc, sizeof(procedimento), 1, fp4);
			age.proc.codigo = proc.codigo;
			strcpy(age.proc.nome, proc.nome);
			printf("Infome a data [dd/mm/aaaa]: ");
			fflush(stdin);
			gets(age.data);
			printf("Informe a hora: ");
			scanf("%d", &age.hora);
			printf("Informe o minuto: ");
			scanf("%d", &age.minuto);
			fwrite(&age, sizeof(agendamento), 1, fp);
		}
		printf("Deseja continuar[s - n]? ");
		fflush(stdin);
		scanf("%c", &r);
		r = tolower(r);
	} while (r == 's');
	fclose(fp);
	fclose(fp2);
	fclose(fp3);
	fclose(fp4);
}

void relatorioAgendamento() {
	agendamento age;
	FILE* fp;
	fp = fopen("agendamento.bin", "rb");
	if (fp == NULL) {
		printf("Erro na abertura do arquivo\n");
	}
	else {
		while (fread(&age, sizeof(agendamento), 1, fp) == 1) {
			printf("___________Medico___________\n\n");
			printf("Nome do Medico: %s\n", age.med.nome);
			printf("CRM: %d\n", age.med.crm);
			printf("Especialidade: %s\n\n", age.med.especialidade);
			printf("__________Paciente__________\n\n");
			printf("Nome do Paciente: %s\n", age.pac.nome);
			printf("Codigo: %d\n", age.pac.codigo);
			printf("CPF: %s\n", age.pac.cpf);
			printf("Data de nascimento: %s\n\n", age.pac.nascimento);
			printf("________Procedimento_________\n\n");
			printf("Nome do Procedimento: %s\n", age.proc.nome);
			printf("Codigo: %d\n", age.proc.codigo);
			printf("Data: %s\n", age.data);
			printf("Horario: %d:%d\n", age.hora, age.minuto);
			printf("____________________________\n\n");
		}
	}
	fclose(fp);
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
				switch(op) {
					case 1:
						exclusaoMedico();
						break;
					case 2:
						exclusaoPaciente();
						break;
					case 3:
						exclusaoProcedimento();
						break;
					case 4:
						exclusaoAgendamento();
						break;
				}
				break;
			case 3:
				menuAlterar();
				printf("Opcao: ");
				scanf("%d", &op);
				switch(op) {
			case 1:
				alterarMedico();
				break;
			case 2:
				alterarPaciente();
				break;
			case 3:
				alterarProcedimento();
				break;
			/*case 4:
				alterarAgendamento();
				break;*/
				}
				break;
			case 4:
				menuAgendamento();
				agendar();
				break;
			case 5:
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
					case 4:
						relatorioAgendamento();
						break;
				}
				break;
			case 0:
				break;
		}
	}while (op != 0);
}

