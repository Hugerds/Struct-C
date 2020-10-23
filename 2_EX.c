#include <stdio.h>
#include <locale.h>

#define MAX 50

struct Ponto{
	int x;
	int y;
} ponto;

void menu() {
	int p, rep;
	system("cls");
	printf("Insira o primeiro valor do ret�ngulo: ");
	scanf("%d", &ponto.x);
	printf("%d e ", ponto.x);
	scanf("%d", &ponto.y);
	system("cls");
	printf("Voc� digitou %d e %d\n", ponto.x, ponto.y);
	printf("Digite agora o ponto que voc� deseja saber se est� dentro ou fora do tri�ngulo: ");
	scanf("%d", &p);
	if(p<=(ponto.x*ponto.y)) {
		printf("O ponto %d est� localizado dentro do ret�ngulo %dx%d", p, ponto.x, ponto.y);
	}
	else {
		printf("O ponto %d est� localizado fora do ret�ngulo %dx%d", p, ponto.x, ponto.y);
	}
	do {
		printf("\n\nDeseja reutilizar o programa?\n1- Sim\n2- N�o\nSua op��o: ");
		scanf("%d", &rep);
	} while(rep<=0 || rep>2);
	if (rep==1) {
		menu();
	}
	else {
		system("exit");
	}
}

int main () {
	setlocale(LC_ALL, "Portuguese");
	menu();
}
