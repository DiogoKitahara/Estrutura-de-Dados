#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<ctype.h>
typedef struct{
	int d,m,a;
}DATA;

typedef struct{
	char nome[50],fone[15];
	DATA aniv;
}CONTATO;

void cabecalho(){
	int i;
	system ("cls");
	for(i=1;i<40;i++)
		printf("-");
	printf("****AGENDA ELETRONICA****");
	for(i=1;i<40;i++)
		printf("-");
}
int menu(){
	int opcao;
	printf("\n1 - Inserir\n");
	printf("\n2 - Exibir\n");
	// outras opções do menu
	printf("\n3 - Alterar Fone\n");
	printf("\n4 - Sair\n");
	printf("Opcao: ");
	scanf("%d",&opcao);
	return opcao;
}
void inserir(){
	FILE *arquivo;
	CONTATO ctt;
	arquivo=fopen("agenda.bin","ab");
	if (arquivo==NULL)
		printf("Erro no arquivo!");
	else{
		do{
			system("cls");
			cabecalho();
			printf("\nInforme nome completo:");fflush(stdin);
			gets(ctt.nome);
			printf("\nInforme o telefone:");fflush(stdin);
			gets(ctt.fone);
			printf("\nInforme a data de aniversario dd mm aaaa: ");
			scanf("%d %d %d", &ctt.aniv.d,&ctt.aniv.m,&ctt.aniv.a);
			fwrite(&ctt,sizeof(CONTATO),1,arquivo);
			printf("Deseja continuar? (s)(n)");
		}while(toupper(getche())=='S');// le um caracter imediatamente sem o enter
	}
	fclose(arquivo);
	
}
void exibir(){
	FILE *arquivo;
	CONTATO ctt;
	cabecalho();
	arquivo=fopen("agenda.bin","rb");
	if (arquivo==NULL)
		printf("Erro no arquivo!");
	else{
		while(fread(&ctt,sizeof(CONTATO),1,arquivo)==1){
			printf("\n Nome: %s", ctt.nome);
			printf("\n Telefone: %s", ctt.fone);
			printf("\n Aniversario: %d/%d/%d", ctt.aniv.d,ctt.aniv.m,ctt.aniv.a);
			printf("\n___________________");
			printf("\n");
		}
		fclose(arquivo);
	}	
	system("pause");
	system("cls");
	
	
}
int busca(FILE *arquivo,char nome[]){
	CONTATO ctt;
	rewind(arquivo);
	fread(&ctt,sizeof(CONTATO),1,arquivo);
	while(!feof(arquivo)&&stricmp(nome,ctt.nome)!=0)
		fread(&ctt,sizeof(CONTATO),1,arquivo);
	if(!feof(arquivo))
		return(ftell(arquivo)-sizeof(CONTATO));
	else
		return -1;
}

void alterar(){
	CONTATO ctt;
	int pos;
	FILE *arquivo;
	arquivo=fopen("agenda.bin","rb+");
	system("cls");
	printf("+++++++Alteracao pelo NOME+++++++\n");
	printf("Alterar Nome: ");
	fflush(stdin);
	gets(ctt.nome);
	while(stricmp(ctt.nome,"\0")!=0){
		pos=busca(arquivo,ctt.nome);
		if(pos==-1)
			printf("\n Nao cadastrado!");
		else{
			fseek(arquivo,pos,0);
			fread(&ctt,sizeof(CONTATO),1,arquivo);
			printf("\nNome: %s",ctt.nome);
			printf("\nFone: %s\n",ctt.fone);
			printf("\n Deseja alterar? (s/n)");
			if( toupper(getche())=='S'){
				printf("\n NOVO telefone: ");
				fflush(stdin);
				gets(ctt.fone);
				fseek(arquivo,pos,0);
				fwrite(&ctt,sizeof(CONTATO),1,arquivo);
				printf("Registro Atualizado!\n");
				system("pause");
			}
		}
	getch();
	printf("\nAlterar Nome: ");
	fflush(stdin);
	gets(ctt.nome);		
	}	
	fclose(arquivo);
}

main(){
	int opcao;
	do{
		cabecalho();
		opcao=menu();
		switch (opcao){
			case 1: inserir();
				break;
			case 2: exibir();
				break;
			case 3: alterar();
				system("pause");
				break;	
			case 4: printf("Obrigada! Saindo...");
				break;
			default: printf("Opcao invalida!");
				break;
		}		
	}while(opcao!=4);
	
}
