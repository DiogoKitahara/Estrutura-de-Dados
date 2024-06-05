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

typedef struct {
	int codigo, quantidade;
	char nome[20];
	float valor;
}material;

void menuInicial();
void menuCadastro();
void menuExclusao();
void menuAgendamento(); 
void menuRelatorio();
void menuAlterar();
void menuOrdenar();
int buscaMedico(FILE *arquivo,int codigo);
int buscaPaciente(FILE *arquivo,int codigo);
int buscaProcedimento(FILE *arquivo,int codigo);
int buscaAgendamento(FILE *arquivo,int codigo);
int buscaMaterial(FILE *arquivo,int codigo);
void cadastrarMedico();
void cadastrarPaciente(); 
void cadastrarProcedimento();
void cadastrarMaterial();
void exclusaoMedico(); 
void exclusaoPaciente(); 
void exclusaoProcedimento(); 
void exclusaoAgendamento(); 
void exclusaoMaterial();
void alterarMedico();
void alterarPaciente();
void alterarProcedimento();
void alterarAgendamento();
void alterarMaterial();
void agendar(); 
void relatorioMedico(); 
void relatorioPaciente();
void relatorioProcedimento(); 
void relatorioAgendamento(); 
void relatorioMaterial();
void metodo_bolha_medico();
void metodo_bolha_paciente();
void metodo_bolha_procedimento();
void metodo_bolha_material();

main() {
	medico med;
	paciente pac;
	procedimento proc;
	int op, op2;
	do {
		menuInicial();
		printf("Operacao: ");
		scanf("%d", &op);
        system("cls");
		switch(op) {
			case 1:
				menuCadastro();
				printf("Operacao: ");
				scanf("%d", &op2);
				system("cls");
				switch (op2) {
					case 1:
						cadastrarMedico();
						system("cls");
						break;
					case 2:
						cadastrarPaciente();
						system("cls");
						break;
					case 3:
						cadastrarProcedimento();
						system("cls");
						break;
					case 4:
						cadastrarMaterial();
						system("cls");
						break;
						break;
					case 0:
						system("cls");
						break;
					default:
						printf("Operacao invalida, tente novamente!\n");
						system("pause");
						system("cls");
				}
				break;
			case 2:
				menuExclusao();
				printf("Operacao: ");
				scanf("%d", &op2);
				system("cls");
				switch(op2) {
					case 1:
						exclusaoMedico();
						system("cls");
						break;
					case 2:
						exclusaoPaciente();
						system("cls");
						break;
					case 3:
						exclusaoProcedimento();
						system("cls");
						break;
					case 4:
						exclusaoAgendamento();						
						system("cls");
						break;
					case 5:
						exclusaoMaterial();
						system("cls");
						break;
					case 0:
						system("cls");
						break;
					default:
						printf("Operacao Invalida, tente novamente\n");
						system("pause");
						system("cls");
				}
				break;
			case 3:
				menuAlterar();
				printf("Operacao: ");
				scanf("%d", &op2);
				system("cls");
				switch(op2) {
					case 1:
						alterarMedico();
						system("cls");
						break;
					case 2:
						alterarPaciente();
						system("cls");
						break;
					case 3:
						alterarProcedimento();
						system("cls");
						break;
					case 4:
						alterarAgendamento();
						system("cls");
						break;
					case 5:
						alterarMaterial();
						system("cls");
						break;
					case 0:
						system("cls");
						break;
					default:
						printf("Operacao Invalida, tente novamente\n");
						system("pause");
						system("cls");
				}
				break;
			case 4:
				menuAgendamento();
				agendar();
				system("pause");
				system("cls");
				break;
			case 5:
				menuRelatorio();
				printf("Operacao: ");
				scanf("%d", &op2);
				system("cls");
				switch (op2) {
					case 1:
						relatorioMedico();
						system("pause");
						system("cls");
						break;
					case 2:
						relatorioPaciente();
						system("pause");
						system("cls");
						break;
					case 3:
						relatorioProcedimento();
						system("pause");
						system("cls");
						break;
					case 4:
						relatorioAgendamento();
						system("pause");
						system("cls");
						break;
					case 5:
						relatorioMaterial();
						system("pause");
						system("cls");
						break;
					case 0:
						break;
					default:
						printf("Operacao Invalida, tente novamente\n");
						system("pause");
						system("cls");
				}
				break;
			case 6:
				menuOrdenar();
				printf("Operacao: ");
				scanf("%d", &op2);
				system("cls");
				switch(op2) {
					case 1:
						metodo_bolha_medico();
						system("pause");
						system("cls");
						break;
					case 2:
						metodo_bolha_paciente();
						system("pause");
						system("cls");
						break;
					case 3:
						metodo_bolha_procedimento();
						system("pause");
						system("cls");
						break;
					case 4:
						metodo_bolha_material();
						system("pause");
						system("cls");
						break;
					case 0:
						break;
				}
			case 0:
				break;
		}
	}while (op != 0);
}

void menuInicial() {
    printf("=-=-=-=- Menu =-=-=-=-\n\n");
    printf("1 - Cadastrar\n");
    printf("2 - Excluir\n");
    printf("3 - Alterar\n");
    printf("4 - Agendar\n");
    printf("5 - Relatorio\n");
    printf("6 - Ordenar\n");
    printf("0 - Finalizar\n\n");
    printf("=-=-=-=-=-=-=-=-=-=-=-\n");
}

void menuCadastro() {
    printf("=-=-=-=- Cadastro =-=-=-=-\n\n");
    printf("1 - Medico\n");
    printf("2 - Paciente\n");
    printf("3 - Procedimento\n");
    printf("4 - Material\n");
    printf("0 - Retornar\n\n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
}

void menuExclusao() {
	printf("=-=-=-=- Exclusao =-=-=-=-\n\n");
    printf("1 - Medico\n");
    printf("2 - Paciente\n");
    printf("3 - Procedimento\n");
    printf("4 - Agendamento\n");
    printf("5 - Material\n");
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
    printf("5 - Material\n");
    printf("0 - Retornar\n\n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
}

void menuAlterar() {
    printf("=-=-=-=- Alterar =-=-=-=-\n\n");
    printf("1 - Medico\n");
    printf("2 - Paciente\n");
    printf("3 - Procedimento\n");
    printf("4 - Agendamento\n");
    printf("5 - Material\n");
    printf("0 - Retornar\n\n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
}

void menuOrdenar() {
    printf("=-=-=-=- Ordenar =-=-=-=-\n\n");
    printf("1 - Medico\n");
    printf("2 - Paciente\n");
    printf("3 - Procedimento\n");
    printf("4 - Material\n");
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

int buscaMaterial(FILE *arquivo,int codigo) {
	material mat;
	rewind(arquivo);
	fread(&mat,sizeof(material),1,arquivo);
	while(!feof(arquivo)&& codigo != mat.codigo)
		fread(&mat,sizeof(material),1,arquivo);
	if(!feof(arquivo))
		return(ftell(arquivo)-sizeof(material));
	else
		return -1;
}

void cadastrarMedico() {
	medico med;
	FILE* fp;
	int pos, crm;
	char r;
	do {
		fp = fopen("medico.bin", "rb+");
		printf("=-=-=-=- Cadastro de Medico =-=-=-=-\n\n");
		if (fp == NULL) {
			printf("Erro na abertura do arquivo\n");
		}
		else {
			printf("CRM: ");
			scanf("%d", &crm);
			pos = buscaMedico(fp, crm);
			if (pos != -1) {
				printf("Medico ja cadastrado!\n");
			}
			else {
				med.crm = crm;
				printf("Nome: ");
				fflush(stdin);
				gets(med.nome);
				printf("Especialidade: ");
				fflush(stdin);
				gets(med.especialidade);
				fwrite(&med, sizeof(medico), 1, fp);
				printf("Medico cadastrado com sucesso!\n\n");
			}
		}
		fclose(fp);
		printf("Deseja continuar[s - n]: ");
		fflush(stdin);
		scanf("%c", &r);
		r = tolower(r);
		system("cls");
	} while (r == 's');
}

void cadastrarPaciente() {
	paciente pac;
	FILE* fp;
	int pos, codigo_paciente;
	char r;
	do {
		fp = fopen("paciente.bin", "rb+");
		printf("=-=-=-=- Cadastro de Paciente =-=-=-=-\n\n");
		if (fp == NULL) {
			printf("Erro na abertura do arquivo\n");
		}
		else {
			printf("Codigo: ");
			scanf("%d", &codigo_paciente);
			pos = buscaPaciente(fp, codigo_paciente);
			if (pos != -1) {
				printf("Paciente ja cadastrado!\n");
			}
			else {
				pac.codigo = codigo_paciente;
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
				printf("Paciente cadastrado com sucesso!\n\n");
			}
		}
		fclose(fp);
		printf("Deseja continuar[s - n]: ");
		fflush(stdin);
		scanf("%c", &r);
		r = tolower(r);
		system("cls");
	} while (r == 's');
}

void cadastrarProcedimento() {
	procedimento proc;
	FILE* fp;
	int pos, codigo_procedimento;
	char r;
	do {
		fp = fopen("procedimento.bin", "rb+");
		printf("=-=-=-=- Cadastro de Procedimento =-=-=-=-\n\n");
		if (fp == NULL) {
			printf("Erro na abertura do arquivo\n");
		}
		else {
			printf("Codigo: ");
			scanf("%d", &codigo_procedimento);
			pos = buscaProcedimento(fp, codigo_procedimento);
			if (pos != -1) {
				printf("Procedimento ja cadastrado!\n");
			}
			else {
				proc.codigo = codigo_procedimento;
				printf("Nome: ");
				fflush(stdin);
				gets(proc.nome);
				fwrite(&proc, sizeof(procedimento), 1, fp);
				printf("Procedimento cadastrado com sucesso!\n\n");
			}
		}
		fclose(fp);
		printf("Deseja continuar[s - n]: ");
		fflush(stdin);
		scanf("%c", &r);
		r = tolower(r);
		system("cls");
	} while (r == 's');
}

void cadastrarMaterial() {
	material mat;
	FILE* fp;
	int pos, crm;
	char r;
	do {
		fp = fopen("material.bin", "rb+");
		printf("=-=-=-=- Cadastro de Material =-=-=-=-\n\n");
		if (fp == NULL) {
			printf("Erro na abertura do arquivo\n");
		}
		else {
			printf("Codigo: ");
			scanf("%d", &crm);
			pos = buscaMaterial(fp, crm);
			if (pos != -1) {
				printf("Material ja cadastrado!\n");
			}
			else {
				mat.codigo = crm;
				printf("Nome: ");
				fflush(stdin);
				gets(mat.nome);
				printf("Quantidade: ");
				scanf("%d", &mat.quantidade);
				printf("Valor: ");
				scanf("%f", &mat.valor);
				fwrite(&mat, sizeof(material), 1, fp);
				printf("Material cadastrado com sucesso!\n\n");
			}
		}
		fclose(fp);
		printf("Deseja continuar[s - n]: ");
		fflush(stdin);
		scanf("%c", &r);
		r = tolower(r);
		system("cls");
	} while (r == 's');
}

void exclusaoMedico() {
	medico med;
	agendamento age;
	FILE* fp;
	FILE* fp2;
	int crm, pos, posm;
	char r;
	do {
		printf("=-=-=-=- Exclusao de Medico =-=-=-=-\n\n");
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
				printf("Medico nao cadastrado\n\n");
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
					printf("\nMedico excluido com sucesso!\n\n");
				}
			}
			fclose(fp);
		}
		else {
			printf("Medico com agendamento marcado nao pode ser excluido.\n");
		}
		fclose(fp);
		fclose(fp2);
		printf("Deseja continuar[s - n]: ");
		fflush(stdin);
		scanf("%c", &r);
		r = tolower(r);
		system("cls");
	} while (r == 's');
}

void exclusaoPaciente() {
	paciente pac;
	agendamento age;
	FILE* fp;
	FILE* fp2;
	int codigo_paciente, pos, posm;
	char r;
	do {
		printf("=-=-=-=- Exclusao de Paciente =-=-=-=-\n\n");
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
				printf("Paciente nao cadastrado\n\n");
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
					printf("\nPaciente excluido com sucesso!\n\n");
				}
			}
			fclose(fp);
		}
		else {
			printf("Paciente com agendamento marcado nao pode ser excluido.\n");
		}
		fclose(fp);
		fclose(fp2);
		printf("Deseja continuar[s - n]: ");
		fflush(stdin);
		scanf("%c", &r);
		r = tolower(r);
		system("cls");
	} while (r == 's');
}

void exclusaoProcedimento() {
	procedimento proc;
	agendamento age;
	FILE* fp;
	FILE* fp2;
	int codigo_procedimento, pos, posm;
	char r;
	do {
		printf("=-=-=-=- Exclusao de Procedimento =-=-=-=-\n\n");
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
				printf("Procedimento nao cadastrado\n\n");
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
					printf("\nProcedimento excluido com sucesso!\n\n");
				}
			}
			fclose(fp);
		}
		else {
			printf("Procedimento com agendamento marcado nao pode ser excluido.\n");
		}
		fclose(fp);
		fclose(fp2);
		printf("Deseja continuar[s - n]: ");
		fflush(stdin);
		scanf("%c", &r);
		r = tolower(r);
		system("cls");
	} while (r == 's');
}



void exclusaoAgendamento() {
	agendamento age;
	FILE* fp2;
	int crm, pos;
	char r;
	do {
		printf("=-=-=-=- Exclusao de Agendamento =-=-=-=-\n\n");
		fp2 = fopen("agendamento.bin", "rb");
		if (fp2 == NULL) {
			printf("Erro na abertura do arquivo\n");
		}
		printf("CRM: ");
		scanf("%d", &crm);
		pos = buscaAgendamento(fp2, crm);
		if (pos == -1) {
			printf("Agendamento nao cadastrado.\n\n");
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
				printf("\nAgendamento excluido com sucesso!\n\n");
			}
			else
			fclose(fp2);
		}
		fclose(fp2);
		printf("Deseja continuar[s - n]: ");
		fflush(stdin);
		scanf("%c", &r);
		r = tolower(r);
		system("cls");
	} while (r == 's');
}

void exclusaoMaterial() {
	material mat;
	agendamento age;
	FILE* fp;
	int codigo_material, posm;
	char r;
	do {
		printf("=-=-=-=- Exclusao de Material =-=-=-=-\n\n");
		fp = fopen("material.bin", "rb+");
		if (fp == NULL) {
			printf("Erro na abertura do arquivo\n");
		}
		printf("Codigo do Material: ");
		scanf("%d", &codigo_material);
		posm = buscaMaterial(fp, codigo_material);
		if (posm == -1) {
			printf("Material nao cadastrado\n\n");
		}
		else {
			fseek(fp, posm, 0);
			fread(&mat, sizeof(material), 1, fp);
			printf("Codigo: %d\n", mat.codigo);
			printf("Nome: %s\n", mat.nome);
			printf("Quantidade %d\n", mat.quantidade);
			printf("Quantidade %.2f\n", mat.valor);
			printf("____________________________\n");
			printf("Deseja excluir? (s/n): ");
			if (tolower(getche()) == 's') {
				FILE* temp;
				temp = fopen("auxiliar.bin", "wb");
				rewind(fp);
				fread(&mat, sizeof(material), 1, fp);
				while(!feof(fp)) {
					if (codigo_material != mat.codigo){
						fwrite(&mat, sizeof(material), 1, temp);
					}
					fread(&mat, sizeof(material), 1, fp);
				}
				fclose(fp);
				fclose(temp);
				remove("material.bin");
				rename("auxiliar.bin", "material.bin");
				printf("\nMaterial excluido com sucesso!\n\n");
			}
		}
		fclose(fp);
		printf("Deseja continuar[s - n]: ");
		fflush(stdin);
		scanf("%c", &r);
		r = tolower(r);
		system("cls");
	} while (r == 's');
}

void alterarMedico(){
	medico med;
	int pos,op,crm,posa;
	char r;
	do {
		FILE* arquivo;
		FILE* fp;
		printf("=-=-=-=- Alteracao de Medico =-=-=-=-\n\n");
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
				printf("Medico nao cadastrado!\n");
			else{
				fseek(arquivo,pos,0);
				fread(&med,sizeof(medico),1,arquivo);
				printf("Nome: %s\n", med.nome);
				printf("Especialidade: %s\n", med.especialidade);
				printf("__________________");
				printf("\n1 - Nome \n2 - Especialidade\n\nDeseja alterar: ");
				scanf("%d",&op);
				if( op==1){
					printf("\n NOVO nome: ");
					fflush(stdin);
					gets(med.nome);
					fseek(arquivo,pos,0);
					fwrite(&med,sizeof(medico),1,arquivo);
					printf("Registro Atualizado!\n\n");
				}
				if( op==2){
					printf("\n NOVA especialidade: ");
					fflush(stdin);
					gets(med.especialidade);
					fseek(arquivo,pos,0);
					fwrite(&med,sizeof(medico),1,arquivo);
					printf("Registro Atualizado!\n\n");
				}
			}
		}
		else {
			printf("Medico com agendamento marcado nao pode ser alterado.\n");
		}
		fclose(arquivo);
		fclose(fp);
		printf("Deseja continuar[s - n]: ");
		fflush(stdin);
		scanf("%c", &r);
		r = tolower(r);
		system("cls");
	} while (r == 's');
}

void alterarPaciente(){
	paciente pac;
	int pos,op,codigo_paciente,posa;
	char r;
	do {
		FILE* arquivo;
		FILE* fp;
		printf("=-=-=-=- Alteracao de Paciente =-=-=-=-\n\n");
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
				printf("Paciente nao cadastrado!\n");
			else{
				fseek(arquivo,pos,0);
				fread(&pac,sizeof(paciente),1,arquivo);
				printf("Nome: %s\n", pac.nome);
				printf("CPF: %s\n", pac.cpf);
				printf("Data de nascimento: %s\n", pac.nascimento);
				printf("__________________");
				printf("\n1 - Nome \n2 - CPF\n3 - Data de Nascimento\n\nDeseja alterar: ");
				scanf("%d",&op);
				if(op==1){
					printf("\n NOVO nome: ");
					fflush(stdin);
					gets(pac.nome);
					fseek(arquivo,pos,0);
					fwrite(&pac,sizeof(paciente),1,arquivo);
					printf("Registro Atualizado!\n\n");
				}
				if(op==2){
					printf("\n NOVO CPF: ");
					fflush(stdin);
					gets(pac.cpf);
					fseek(arquivo,pos,0);
					fwrite(&pac,sizeof(paciente),1,arquivo);
					printf("Registro Atualizado!\n\n");
				}
				if(op==3){
					printf("\n NOVA Data de Nascimento: ");
					fflush(stdin);
					gets(pac.nascimento);
					fseek(arquivo,pos,0);
					fwrite(&pac,sizeof(paciente),1,arquivo);
					printf("Registro Atualizado!\n\n");
				}
			}
		}
		else {
			printf("Paciente com agendamento marcado nao pode ser alterado.\n");
		}
		fclose(arquivo);
		fclose(fp);
		printf("Deseja continuar[s - n]: ");
		fflush(stdin);
		scanf("%c", &r);
		r = tolower(r);
		system("cls");
	} while(r == 's');
}

void alterarProcedimento(){
	procedimento proc;
	int pos,op,codigo_procedimento,posa;
	char r;
	do {
		FILE* arquivo;
		FILE* fp;
		printf("=-=-=-=- Alteracao de Procedimento =-=-=-=-\n\n");
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
				printf("Procedimento nao cadastrado!\n");
			else{
				fseek(arquivo,pos,0);
				fread(&proc,sizeof(procedimento),1,arquivo);
				printf("Nome: %s\n", proc.nome);
				printf("__________________");
				printf("\n1 - Nome\n\nDeseja alterar: ");
				scanf("%d",&op);
				if(op==1){
					printf("\n NOVO nome: ");
					fflush(stdin);
					gets(proc.nome);
					fseek(arquivo,pos,0);
					fwrite(&proc,sizeof(procedimento),1,arquivo);
					printf("Registro Atualizado!\n\n");
				}
			}
		}
		else {
			printf("Procedimento com agendamento marcado nao pode ser alterado.\n");
		}
		fclose(arquivo);
		fclose(fp);
		printf("Deseja continuar[s - n]: ");
		fflush(stdin);
		scanf("%c", &r);
		r = tolower(r);
		system("cls");
	} while (r == 's');
}

void alterarAgendamento(){
	agendamento age;
	int pos,op,posa, crm;
	char r;
	FILE* fp;
	do {
		fp = fopen("agendamento.bin", "rb+");
		printf("=-=-=-=- Alteracao de Agendamento =-=-=-=-\n\n");
		if (fp == NULL) {
		printf("Erro na abertura do arquivo\n");
		}
		printf("CRM: ");
		scanf("%d", &crm);
		pos=buscaAgendamento(fp, crm);
		if(pos==-1)
			printf("\nAgendamento nao cadastrado!");
		else{
			fseek(fp,pos,0);
			fread(&age,sizeof(agendamento),1,fp);
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
			printf("_________Agendamento_________\n");
			printf("Data: %s\n", age.data);
			printf("Horario: %d:%d\n", age.hora, age.minuto);
			printf("____________________________\n\n");
			printf("\n1 - Data\n2 - Horario\n\nDeseja alterar: ");
			scanf("%d",&op);
			if(op==1){
				printf("\n NOVA data[dd/mm/aaaa]: ");
				fflush(stdin);
				gets(age.data);
				fseek(fp,pos,0);
				fwrite(&age,sizeof(agendamento),1,fp);
				printf("Registro Atualizado!\n\n");
				fclose(fp);
			}
			if(op==2){
				printf("\n NOVO Horario\n");
				printf("\n NOVA hora: ");
				scanf("%d", &age.hora);
				printf("\n NOVO minuto: ");
				scanf("%d", &age.minuto);
				fseek(fp,pos,0);
				fwrite(&age,sizeof(agendamento),1,fp);
				printf("Registro Atualizado!\n\n");
				fclose(fp);
			}
		}
		fclose(fp);
		printf("Deseja continuar[s - n]: ");
		fflush(stdin);
		scanf("%c", &r);
		r = tolower(r);
		system("cls");
	} while (r == 's');
}

void alterarMaterial(){
	material mat;
	int pos,op,codigo_material,posa;
	char r;
	do {
		FILE* arquivo;
		FILE* fp;
		printf("=-=-=-=- Alteracao de Material =-=-=-=-\n\n");
		arquivo=fopen("material.bin","rb+");
		if (arquivo==NULL){
			printf("Erro no arquivo!");
			return;
		}
		fp = fopen("agendamento.bin", "rb");
		if (fp == NULL) {
			printf("Erro na abertura do arquivo\n");
		}
		printf("Codigo: ");
		scanf("%d", &codigo_material);
		posa = buscaMaterial(fp, codigo_material);
		if (posa == -1) {
			pos=buscaMaterial(arquivo, codigo_material);
			if(pos==-1)
				printf("Material nao cadastrado!\n");
			else{
				fseek(arquivo,pos,0);
				fread(&mat,sizeof(material),1,arquivo);
				printf("Nome: %s\n", mat.nome);
				printf("Quantidade %d\n", mat.quantidade);
				printf("Valor: %.2f\n", mat.valor);
				printf("__________________");
				printf("\n1 - Nome \n2 - Quantidade \n3 - Valor\n\nDeseja alterar: ");
				scanf("%d",&op);
				if(op==1){
					printf("\n NOVO nome: ");
					fflush(stdin);
					gets(mat.nome);
					fseek(arquivo,pos,0);
					fwrite(&mat,sizeof(material),1,arquivo);
					printf("Registro Atualizado!\n\n");
				}
				if(op==2){
					printf("\n NOVA quantidade: ");
					scanf("%d", &mat.quantidade);
					fseek(arquivo,pos,0);
					fwrite(&mat,sizeof(material),1,arquivo);
					printf("Registro Atualizado!\n\n");
				}
				if(op==3){
					printf("\n NOVO valor: ");
					scanf("%f", &mat.valor);
					fseek(arquivo,pos,0);
					fwrite(&mat,sizeof(material),1,arquivo);
					printf("Registro Atualizado!\n\n");
				}
			}
		}
		else {
			printf("Material com agendamento marcado nao pode ser alterado.\n");
		}
		fclose(arquivo);
		fclose(fp);
		printf("Deseja continuar[s - n]: ");
		fflush(stdin);
		scanf("%c", &r);
		r = tolower(r);
		system("cls");
	} while (r == 's');
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
	printf("CRM: ");
	scanf("%d", &crm);
	posm = buscaMedico(fp2, crm);
	if (posm == -1 ) {
		printf("Medico nao cadastrado\n");
		fclose(fp);
		fclose(fp2);
		fclose(fp3);
		fclose(fp4);
		return;
	}
	printf("Codigo do paciente: ");
	scanf("%d", &codigo_paciente);
	pospac = buscaPaciente(fp3, codigo_paciente);
	if (pospac == -1 ) {
		printf("Paciente nao cadastrado\n");
		fclose(fp);
		fclose(fp2);
		fclose(fp3);
		fclose(fp4);
		return;
	}
	printf("Codigo do procedimento: ");
	scanf("%d", &codigo_procedimento);
	posproc = buscaProcedimento(fp4, codigo_procedimento);
	if (posproc == -1 ) {
		printf("Procedimento nao cadastrado\n");
		fclose(fp);
		fclose(fp2);
		fclose(fp3);
		fclose(fp4);
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
	fclose(fp);
	fclose(fp2);
	fclose(fp3);
	fclose(fp4);
}

void relatorioMedico() {
	medico med;
	FILE* fp;
	printf("=-=-=-=- Relatorio de Medico =-=-=-=-\n\n");
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
	printf("=-=-=-=- Relatorio de Paciente =-=-=-=-\n\n");
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
	printf("=-=-=-=- Relatorio de Procedimento =-=-=-=-\n\n");
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

void relatorioAgendamento() {
	agendamento age;
	FILE* fp;
	fp = fopen("agendamento.bin", "rb");
	printf("=-=-=-=- Relatorio de Agendamento =-=-=-=-\n\n");
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
			printf("Codigo: %d\n\n", age.proc.codigo);
			printf("_________Agendamento_________\n\n");
			printf("Data: %s\n", age.data);
			printf("Horario: %d:%d\n", age.hora, age.minuto);
			printf("____________________________\n\n");
		}
	}
	fclose(fp);
}

void relatorioMaterial() {
	material mat;
	FILE* fp;
	printf("=-=-=-=- Relatorio de Material =-=-=-=-\n\n");
	fp = fopen("material.bin", "rb");
	if (fp == NULL) {
		printf("Erro na abertura do arquivo\n");
	}
	else {
		while (fread(&mat, sizeof(material), 1, fp) == 1) {
			printf("Codigo: %d\n", mat.codigo);
			printf("Nome: %s\n", mat.nome);
			printf("Quantidade %d\n", mat.quantidade);
			printf("Valor %.2f\n", mat.valor);
		printf("____________________________\n");
		}
	}
	fclose(fp);
}

void metodo_bolha_medico() {
    FILE *arquivo;
    medico ctti, ctti_1;
    int i, qtde = 0;
    arquivo = fopen("medico.bin", "rb+");
    if (arquivo == NULL) {
        printf("Erro no arquivo\n");
        return;
    }
    fseek(arquivo, 0, SEEK_END);
    qtde = ftell(arquivo) / sizeof(medico);
    while (qtde > 1) {
        for (i = 0; i < qtde - 1; i++) {
            fseek(arquivo, i * sizeof(medico), SEEK_SET);
            fread(&ctti, sizeof(medico), 1, arquivo);
            fread(&ctti_1, sizeof(medico), 1, arquivo);

            if (strcmp(ctti.nome, ctti_1.nome) > 0) {
                fseek(arquivo, i * sizeof(medico), SEEK_SET);
                fwrite(&ctti_1, sizeof(medico), 1, arquivo);
                fwrite(&ctti, sizeof(medico), 1, arquivo);
            }
        }
        qtde--;
    }
    fclose(arquivo);
    printf("Medico ordenado com sucesso!\n");
}

void metodo_bolha_paciente() {
    FILE *arquivo;
    paciente ctti, ctti_1;
    int i, qtde = 0;
    arquivo = fopen("paciente.bin", "rb+");
    if (arquivo == NULL) {
        printf("Erro no arquivo\n");
        return;
    }
    fseek(arquivo, 0, SEEK_END);
    qtde = ftell(arquivo) / sizeof(paciente);
    while (qtde > 1) {
        for (i = 0; i < qtde - 1; i++) {
            fseek(arquivo, i * sizeof(paciente), SEEK_SET);
            fread(&ctti, sizeof(paciente), 1, arquivo);
            fread(&ctti_1, sizeof(paciente), 1, arquivo);

            if (strcmp(ctti.nome, ctti_1.nome) > 0) {
                fseek(arquivo, i * sizeof(paciente), SEEK_SET);
                fwrite(&ctti_1, sizeof(paciente), 1, arquivo);
                fwrite(&ctti, sizeof(paciente), 1, arquivo);
            }
        }
        qtde--;
    }
    fclose(arquivo);
    printf("Paciente ordenado com sucesso!\n");
}

void metodo_bolha_procedimento() {
    FILE *arquivo;
    procedimento ctti, ctti_1;
    int i, qtde = 0;
    arquivo = fopen("procedimento.bin", "rb+");
    if (arquivo == NULL) {
        printf("Erro no arquivo\n");
        return;
    }
    fseek(arquivo, 0, SEEK_END);
    qtde = ftell(arquivo) / sizeof(procedimento);
    while (qtde > 1) {
        for (i = 0; i < qtde - 1; i++) {
            fseek(arquivo, i * sizeof(procedimento), SEEK_SET);
            fread(&ctti, sizeof(procedimento), 1, arquivo);
            fread(&ctti_1, sizeof(procedimento), 1, arquivo);

            if (strcmp(ctti.nome, ctti_1.nome) > 0) {
                fseek(arquivo, i * sizeof(procedimento), SEEK_SET);
                fwrite(&ctti_1, sizeof(procedimento), 1, arquivo);
                fwrite(&ctti, sizeof(procedimento), 1, arquivo);
            }
        }
        qtde--;
    }
    fclose(arquivo);
    printf("Procedimento ordenado com sucesso!\n");
}

void metodo_bolha_material() {
    FILE *arquivo;
    material ctti, ctti_1;
    int i, qtde = 0;
    arquivo = fopen("material.bin", "rb+");
    if (arquivo == NULL) {
        printf("Erro no arquivo\n");
        return;
    }
    fseek(arquivo, 0, SEEK_END);
    qtde = ftell(arquivo) / sizeof(material);
    while (qtde > 1) {
        for (i = 0; i < qtde - 1; i++) {
            fseek(arquivo, i * sizeof(material), SEEK_SET);
            fread(&ctti, sizeof(material), 1, arquivo);
            fread(&ctti_1, sizeof(material), 1, arquivo);

            if (strcmp(ctti.nome, ctti_1.nome) > 0) {
                fseek(arquivo, i * sizeof(material), SEEK_SET);
                fwrite(&ctti_1, sizeof(material), 1, arquivo);
                fwrite(&ctti, sizeof(material), 1, arquivo);
            }
        }
        qtde--;
    }
    fclose(arquivo);
    printf("Material ordenado com sucesso!\n");
}
