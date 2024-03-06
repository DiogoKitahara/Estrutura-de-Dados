#include <stdio.h>

struct data {
	int dia, mes, ano;
};

struct horario {
	int hora, minuto;
};

struct data informaData(){
	struct data d;
	printf("Dia: ");
	scanf("%d", &d.dia);
	printf("Mes: ");
	scanf("%d", &d.mes);
	printf("Ano: ");
	scanf("%d", &d.ano);
	return d;
}

struct horario informaHorario() {
	struct horario h;
	printf("Hora: ");
	scanf("%d", &h.hora);
	printf("Minuto: ");
	scanf("%d", &h.minuto);
	return h;
}

int main() {
	struct data d = informaData();
	struct horario h = informaHorario();
	char disciplina[30];
	printf("Disciplina: ");
	fflush(stdin);
	gets(disciplina);
	printf("Foi marcada para %d/%d/%d, as %d:%d a prova de ", d.dia, d.mes, d.ano, h.hora, h.minuto);
	puts(disciplina);
}
