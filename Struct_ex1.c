/*Defina um registro empregado para guardar os dados 
(nome, sobrenome, data de nascimento, RG, data de admiss�o, sal�rio) 
de um empregado de sua empresa. Defina um vetor de empregados para armazenar 
todos os empregados de sua empresa.*/

#include <stdio.h>
#include <conio.h>
#include <locale.h>
#define tam 1

struct empEmpresa {
	char nome[tam][15];
	char sobrenome[tam][30];
	int dataNascimento[tam];
    int rg[tam];
    int dataAdmissao[tam];
    float salario[tam];
} Empregados;

int main () {
	setlocale(LC_ALL,"Portuguese");
	int a;
	for (a=0;a<tam;a++) {
		fflush(stdin);
		printf ("Digite o nome do empregado que ser� armazenado na posi��o %d\n", a);
		fgets(Empregados.nome[a], 15, stdin);
		fflush(stdin);
		printf ("Digite o sobrenome do empregado que ser� armazenado na posi��o %d\n", a);
		fgets(Empregados.sobrenome[a], 30, stdin);
		fflush(stdin);
		printf ("Digite a data de nascimento do empregado no formato DDMMAAAA que ser� armazenada na posi��o %d\n", a);
		scanf ("%d", &Empregados.dataNascimento[a]);
		fflush(stdin);
		printf ("Digite o RG do empregado no formado NNNNNNNNN que ser� armazenado na posi��o %d", a);
		scanf ("%d", &Empregados.rg[a]);
		fflush(stdin);
		printf ("Digite a data de admiss�o do empregado no formado DDMMAAAA que ser� armazenada na posi��o %d", a);
		scanf ("%d", &Empregados.dataAdmissao[a]);
		fflush(stdin);
		printf ("Digite o sal�rio do empregado que ser� armazenado na posi��o %d", a);
		scanf ("%f", &Empregados.salario[a]);
		fflush(stdin);
		fflush(stdout);
		//printf("%s", Empregados.nome[0]);
	}
	for (a=0;a<tam;a++) {
		printf("%s\n", Empregados.nome[a]);
		printf("%s\n", Empregados.sobrenome[a]);
		printf("%d\n", Empregados.dataNascimento[a]);
		//printf("%d%d/%d%d/%d%d%d%d\n", Empregados.dataNascimento[a][0], Empregados.dataNascimento[a][1], Empregados.dataNascimento[a][2], Empregados.dataNascimento[a][3], Empregados.dataNascimento[a][4], Empregados.dataNascimento[a][5], Empregados.dataNascimento[a][6], Empregados.dataNascimento[a][7]);
		
	}
}

