#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100
 /*Declare uma estrutura chamada TipoReg contendo os seguintes campos: Nome, RG,
Salario, Idade, Sexo, DataNascimento; onde Nome e RG s�o strings, Salario � real, Idade � inteiro, Sexo � char e DataNascimento
 � uma estrutura contendo tr�s inteiros,
dia, m�s e ano. Declare uma estrutura chamada TipoCadastro que cont�m dois campos: um campo funcion�rio, contendo um vetor com 100 posi��es do tipo TipoReg e
outro campo inteiro, Quant, que indica a quantidade de funcion�rios no cadastro.
*/
typedef struct {
	int dia;
	int mes;
	int ano;
} data;

struct TipoReg{
	char nome[20];
	char rg[20];
	float salario;
	char sexo[20];
	int idade;
	data nasc;
};

struct tipoCadastro{
	struct TipoReg funcionario[100];
	int quant;
	float v1, v2;
} TipoCadastro;

void organizaDados(int a, int b) {
	char auxNome[20], copiaDoc[20], copiaSexo[20], copiaEnd[20];
	int auxDatdia, auxDatmes, auxDatano, auxIdade;
	float auxSalario;
	// Nome
	strcpy(auxNome, TipoCadastro.funcionario[a].nome);
	strcpy(TipoCadastro.funcionario[a].nome, TipoCadastro.funcionario[b].nome);
	strcpy(TipoCadastro.funcionario[b].nome, auxNome);
	// Ano Nasc Func
	auxDatano = TipoCadastro.funcionario[a].nasc.ano;
	TipoCadastro.funcionario[a].nasc.ano = TipoCadastro.funcionario[b].nasc.ano;
	TipoCadastro.funcionario[b].nasc.ano = auxDatano;
	// Mes Nasc Func
	auxDatmes = TipoCadastro.funcionario[a].nasc.mes;
	TipoCadastro.funcionario[a].nasc.mes = TipoCadastro.funcionario[b].nasc.mes;
	TipoCadastro.funcionario[b].nasc.mes = auxDatmes;
	// Dia Nasc Func
	auxDatdia = TipoCadastro.funcionario[a].nasc.dia;
	TipoCadastro.funcionario[a].nasc.dia = TipoCadastro.funcionario[b].nasc.dia;
	TipoCadastro.funcionario[b].nasc.dia = auxDatdia;
	// RG
	strcpy(copiaDoc, TipoCadastro.funcionario[a].rg);
	strcpy(TipoCadastro.funcionario[a].rg, TipoCadastro.funcionario[b].rg);
	strcpy(TipoCadastro.funcionario[b].rg, copiaDoc);
	// Sexo
	strcpy(copiaSexo, TipoCadastro.funcionario[a].sexo);
	strcpy(TipoCadastro.funcionario[a].sexo, TipoCadastro.funcionario[b].sexo);
	strcpy(TipoCadastro.funcionario[b].sexo, copiaSexo);
	// Ano Nasc Func
	auxIdade = TipoCadastro.funcionario[a].nasc.ano;
	TipoCadastro.funcionario[a].nasc.ano = TipoCadastro.funcionario[b].nasc.ano;
	TipoCadastro.funcionario[b].nasc.ano = auxIdade;
	// Salario Funcion�rio
	auxSalario = TipoCadastro.funcionario[a].salario;
	TipoCadastro.funcionario[a].salario = TipoCadastro.funcionario[b].salario;
	TipoCadastro.funcionario[b].salario = auxSalario;
}

void mostrarFuncionarios(int a) {
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	printf("Nome do funcion�rio: %s\n", TipoCadastro.funcionario[a].nome);
	printf("RG do funcion�rio: %s\n",TipoCadastro.funcionario[a].rg);
	printf("Sal�rio do funcion�rio: %.4f\n", TipoCadastro.funcionario[a].salario);
	printf("Idade do funcion�rio: %d anos\n", TipoCadastro.funcionario[a].idade);
	printf("Sexo do funcion�rio: %s\n", TipoCadastro.funcionario[a].sexo);
	printf("Data de nascimento do funcion�rio(DD MM AAAA): %d/%d/%d\n", TipoCadastro.funcionario[a].nasc.dia, TipoCadastro.funcionario[a].nasc.mes, TipoCadastro.funcionario[a].nasc.ano);
}

void mostrarFuncionariosImposto(int a, float s) {
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	printf("Nome do funcion�rio: %s\n", TipoCadastro.funcionario[a].nome);
	printf("RG do funcion�rio: %s\n",TipoCadastro.funcionario[a].rg);
	printf("Sal�rio do funcion�rio: %.4f\n", TipoCadastro.funcionario[a].salario);
	printf("Idade do funcion�rio: %d anos\n", TipoCadastro.funcionario[a].idade);
	printf("Sexo do funcion�rio: %s\n", TipoCadastro.funcionario[a].sexo);
	printf("Data de nascimento do funcion�rio(DD MM AAAA): %d/%d/%d\n", TipoCadastro.funcionario[a].nasc.dia, TipoCadastro.funcionario[a].nasc.mes, TipoCadastro.funcionario[a].nasc.ano);
	printf("Imposto retido: %f\n", s);
}

void listaNiversexo(int dia, int mes, int ano, char sexo[]) {
	int a, b=0, tam;
	float s=0;
	tam = TipoCadastro.quant;
	for (a=0;a<tam;a++) {
		if(TipoCadastro.funcionario[a].nasc.mes==mes && TipoCadastro.funcionario[a].nasc.dia==dia && TipoCadastro.funcionario[a].nasc.ano==ano && TipoCadastro.funcionario[a].sexo==sexo) {
			mostrarFuncionarios(a);
		}
	}
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	system("pause");
	system("cls");
}

void listaNivermes(int mes) {
	int a, b=0, tam;
	float s=0;
	tam = TipoCadastro.quant;
	for (a=0;a<tam;a++) {
		if(TipoCadastro.funcionario[a].nasc.mes==mes) {
			mostrarFuncionarios(a);
		}
	}
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	system("pause");
	system("cls");
}

void removeFuncionario(char rg[]) {
	int a, b, tam, pos;
	tam = TipoCadastro.quant;
	for (a=0;a<tam;a++) {
		if(TipoCadastro.funcionario[a].rg==rg) {
			pos = a;
		}
		else {
			
		}
	}
	for(a=pos;a<tam-1;a++) {
		organizaDados(a, a+1);
	}
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	system("pause");
	system("cls");
}

void listaMaraja() {
	int a, b, tam;
	tam = TipoCadastro.quant;
	for (a=0;a<(tam-1);a++) {
		for(b=a+1;b<tam;b++) {
			if(TipoCadastro.funcionario[a].salario>TipoCadastro.funcionario[b].salario) {
				organizaDados(a, b);
			}
		}
	}
	for(a=0;a<50;a++) {
		if (a==tam) {
			break;
		}
		mostrarFuncionarios(a);
	}
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	system("pause");
	system("cls");
}

void atualizarSalario(char rg[]) {
	int a, b=0, tam;
	float s=0;
	tam = TipoCadastro.quant;
	for (a=0;a<tam;a++) {
		if(TipoCadastro.funcionario[a].rg==rg) {
			printf("Insira o novo sal�rio que deseja inserir para %s: ", TipoCadastro.funcionario[a].nome);
			TipoCadastro.funcionario[a].salario=(float)0;
			scanf("%f", &TipoCadastro.funcionario[a].salario);
		}
	}
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	system("pause");
	system("cls");
}

void buscaNome(char nome[]) {
	int a, b=0, tam;
	float s=0;
	tam = TipoCadastro.quant;
	for (a=0;a<tam;a++) {
		if(TipoCadastro.funcionario[a].nome==nome) {
			mostrarFuncionarios(a);
		}
	}
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	printf("M�dia dos sal�rios listados: %f", s/b);
	system("pause");
	system("cls");
}

void imposto() {
	int a, b=0, tam;
	float sP, s;
	tam = TipoCadastro.quant;
	for (a=0;a<tam;a++) {
		if(TipoCadastro.funcionario[a].salario>=(float)1000) {
			s = TipoCadastro.funcionario[a].salario;
			mostrarFuncionariosImposto(a, s);
		}
		else if(TipoCadastro.funcionario[a].salario>(float)1000 && TipoCadastro.funcionario[a].salario<=(float)2000) {
			sP = TipoCadastro.funcionario[a].salario/0.10;
			s=TipoCadastro.funcionario[a].salario-sP;
			mostrarFuncionariosImposto(a, s);
		}
		else if(TipoCadastro.funcionario[a].salario>(float)2000 && TipoCadastro.funcionario[a].salario<=(float)3500) {
			sP = TipoCadastro.funcionario[a].salario/0.15;
			s=TipoCadastro.funcionario[a].salario-sP;
			mostrarFuncionariosImposto(a, s);
		}
		else if(TipoCadastro.funcionario[a].salario>(float)3500) {
			sP = TipoCadastro.funcionario[a].salario/0.25;
			s=TipoCadastro.funcionario[a].salario-sP;
			mostrarFuncionariosImposto(a, s);
		}
	}
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	system("pause");
	system("cls");
}

void salarioIntervalo(float v1, float v2) {
	int a, b=0, tam;
	float s=0;
	tam = TipoCadastro.quant;
	for (a=0;a<tam;a++) {
		if(TipoCadastro.funcionario[a].salario>= v1 && TipoCadastro.funcionario[a].salario<=v2) {
			s+=TipoCadastro.funcionario[a].salario;
			b++;
			mostrarFuncionarios(a);
		}
	}
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	printf("M�dia dos sal�rios listados: %f", s/b);
	system("pause");
	system("cls");
}

void ordenaSalario() {
	int a, b, tam;
	tam = TipoCadastro.quant;
	for (a=0;a<(tam-1);a++) {
		for(b=a+1;b<tam;b++) {
			if(TipoCadastro.funcionario[a].salario>TipoCadastro.funcionario[b].salario) {
				organizaDados(a, b);
			}
		}
	}
	for(a=0;a<tam;a++) {
		mostrarFuncionarios(a);
	}
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	system("pause");
	system("cls");
}

void ordenaNome() {
	int a, b, tam;
	tam = TipoCadastro.quant;
	for (a=0;a<(tam-1);a++) {
		for(b=a+1;b<tam;b++) {
			if(strcmp(TipoCadastro.funcionario[a].nome, TipoCadastro.funcionario[b].nome)==1) {
				organizaDados(a, b);
			}
		}
	}
	for(a=0;a<tam;a++) {
		mostrarFuncionarios(a);
	}
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	system("pause");
	system("cls");
}

void listaFuncionarios() {
	int a, c;
	c = TipoCadastro.quant;
	for(a=0;a<c;a++) {
		mostrarFuncionarios(a);
	}
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	system("pause");
	system("cls");
}

void leFuncionarios() {
	int a, op;
	do {
		for(a=0;a<100;a++) {
			if (op==2) {
				TipoCadastro.quant = a;
				break;
			}
			printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
			printf("Insira o nome do funcion�rio: ");
			fflush(stdin);
			gets(TipoCadastro.funcionario[a].nome);
			fflush(stdout);
			printf("Insira o RG do funcion�rio: ");
			fflush(stdin);
			gets(TipoCadastro.funcionario[a].rg);
			fflush(stdout);
			printf("Insira o sal�rio do funcion�rio: ");
			scanf("%f", &TipoCadastro.funcionario[a].salario);
			printf("Insira a idade do funcion�rio: ");
			scanf("%d", &TipoCadastro.funcionario[a].idade);
			printf("Insira o sexo do funcion�rio(M/F): ");
			fflush(stdin);
			gets(TipoCadastro.funcionario[a].sexo);
			fflush(stdout);
			printf("Insira a data de nascimento do funcion�rio(DD MM AAAA): ");
			scanf("%d %d %d", &TipoCadastro.funcionario[a].nasc.dia, &TipoCadastro.funcionario[a].nasc.mes, &TipoCadastro.funcionario[a].nasc.ano);
			printf("Deseja registrar outro funcion�rio?(1/2)\nSua op��o: ");
			do {
         		scanf("%d", &op);
     		} while (op != 1 && op != 2);
		}
	} while (op == 1);
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	system("pause");
	system("cls");
}

void iniciaCadastro() {
	TipoCadastro.quant=0; int op;
	leFuncionarios();
	system("cls");
	do {
		printf("O que voc� deseja fazer?\n1- Listar os funcion�rios\n2- Ordenar pelo nome\n3- Ordenar pelo sal�rio\n4- Mostrar um sal�rio de acordo com um intervalo\n5- Mostrar o quanto � descontado de imposto\n6- Buscar pelo nome\n7- Atualizar o sal�rio de algu�m\n8- Mostrar os maiores sal�rios(TOP 50)\n 9- Remover um funcion�rio\n10- Mostrar quem faz de acordo com o m�s inserido\n11- Listar a data de anivers�rio e o sexo inserido\nSua op��o: ");
		scanf("%d", &op);
	}while(op<=0 || op>11);
	if(op==1) {
		system("cls");
		listaFuncionarios();
	}
	else if(op==2) {
		ordenaNome();
	}
	else if(op==3) {
		ordenaSalario();
	}
	else if(op==4) {
		printf("Insira o intervalo que deseja, dois n�meros: ");
		scanf("%f %f", &TipoCadastro.v1, &TipoCadastro.v2);
		ordenaNome(TipoCadastro.v1, TipoCadastro.v2);
	}
	else if(op==5) {
		imposto();
	}
	else if(op==6) {
		char nome[20];
		printf("Insira o nome que deseja buscar: ");
		fflush(stdin);
		gets(nome);
		fflush(stdout);
		ordenaSalario(nome);
	}
	else if(op==7) {
		char rg[20];
		printf("Insira o rg que deseja buscar para alterar sal�rio: ");
		fflush(stdin);
		gets(rg);
		fflush(stdout);
		atualizarSalario(rg);
	}
	else if(op==8) {
		listaMaraja();
	}
	else if(op==9) {
		char rg[20];
		printf("Insira o rg que deseja buscar para remov�-lo: ");
		fflush(stdin);
		gets(rg);
		fflush(stdout);
		removeFuncionario(rg);
	}
	else if(op==10) {
		int mes;
		printf("Insira o m�s para buscar os aniversariantes correspondentes: ");
		fflush(stdin);
		scanf("%d", &mes);	
		fflush(stdout);
		removeFuncionario(mes);
	}
	else if(op==11) {
		int dia, mes, ano;
		char sexo[20];
		printf("Insira o dia, mes, ano e sexo para buscar os aniversariantes do sexo correspondentes: ");
		fflush(stdin);
		scanf("%d %d %d", &dia, &mes, &ano);
		gets(sexo);	
		fflush(stdout);
		listaNiversexo(dia, mes, ano, sexo);
	}
	
}

int main () {
	setlocale(LC_ALL, "Portuguese");
	iniciaCadastro();
	
}
