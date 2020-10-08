/* 2) Um racional � qualquer n�mero da forma p/q, sendo p inteiro e q inteiro n�o nulo. � conveniente representar um racional por um registro:
typedef struct {
  int p, q;
} racional;
Suponha que o campo q de todo racional � estritamente positivo e que o m�ximo divisor comum dos campos p e q � 1. Escreva:
a) uma fun��o reduz que receba inteiros a e b e devolva o racional que representa a/b;
b) uma fun��o neg que receba um racional x e devolva o racional -x;
c) uma fun��o soma que receba racionais x e y e devolva o racional que representa a soma de x e y;
d) uma fun��o mult que receba racionais x e y e devolva o racional que representa o produto de x por y;
e) uma fun��o div que receba racionais x e y e devolva o racional que representa o quociente de x por y; */

#include <stdio.h>
#include <math.h>

struct racionais {
  int p, q;
} racional;

void reduz(a, b) {
	printf ("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf ("Os valores digitados foram: %d/%d\n\n", a,b);
}

void negar(a, b) {
	printf ("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	if (a < 0) {
		printf ("O valor negado eh: %d/%d\n\n", -a, b);
	}
	else {
		printf ("O valor negado eh: -%d/%d\n\n", a, b);
	}
}


void contSomar(int mmc, int a, int b, int c, int d, int num1, int num2) {
	int primeiro, segundo;
	primeiro = (mmc/b)*a;
	segundo = (mmc/d)*c;
	printf ("A soma entre %d/%d+%d/%d e igual a: %d/%d\n\n", a, b, c, d, primeiro+segundo, mmc);
}

void mmc(int num1, int num2, int a, int c) {
    int resto, b, d, mmc, aux, i;
    b = num1;
    d = num2;
    for (i = 2; i <= num2; i++) {
        aux = num1 * i;
        if ((aux % num2) == 0) {
            mmc = aux;
            i = num2 + 1;
        }
    }
    contSomar(mmc, a, b, c, d, num1, num2);
}

void somar(a, b) {
	printf ("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	int c, d;
	printf ("Digite a outra fracao que deseja somar por %d/%d: ", a, b);
	scanf("%d %d", &c, &d);
	mmc(b, d, a, c);
	
}

void mult(a, b) {
	printf ("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	int c, d;
	printf ("Digite a outra fracao que deseja multiplicar por %d/%d: ", a, b);
	scanf("%d %d", &c, &d);
	printf ("Voce digitou %d/%d\n", c, d);
	printf ("A multiplicacao entre %d/%d*%d/%d e igual a: %d/%d\n\n", a, b, c, d, a*c, b*d);
}

void quoc(a, b) {
	printf ("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	int c, d;
	printf ("Digite a outra fracao que deseja dividir por %d/%d: ", a, b);
	scanf("%d %d", &c, &d);
	printf ("Voce digitou %d/%d\n", c, d);
	printf ("A divisao entre %d/%d/%d/%d e igual a: %d/%d\n\n", a, b, c, d, a*d, b*c);
}

int main () {
	printf ("Digite o numerador e o denominador, respectivamente: ");
	scanf ("%d %d", &racional.p,&racional.q);
	reduz(racional.p,racional.q);
	negar(racional.p,racional.q);
	somar(racional.p,racional.q);
	mult(racional.p,racional.q);
	quoc(racional.p,racional.q);
}
