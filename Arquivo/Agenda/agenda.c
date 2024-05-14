#include<stdio.h>
#include<string.h>
#include<windows.h>
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
	printf("\n3 - Sair\n");
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
		}while(getche()=='s');// le um caracter imediatamente sem o enter
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
			case 3: printf("Obrigada! Saindo...");
				break;
			default: printf("Opcao invalida!");
				break;
		}		
	}while(opcao!=3);
	
}
