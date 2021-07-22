#include <stdio.h>

int main() {
    printf("== Troca do conteudo de variaveis ==\n");

    int A, B, auxiliar;
    printf("Entre com o valor de A: ");
    scanf("%d", &A);
    printf("Entre com o valor de B: ");
    scanf("%d", &B);

    auxiliar = A;
    A = B;
    B = auxiliar;

    printf("Apos a troca, o valor de A eh %d e o de B eh %d\n", A, B);
    return 0;

}

/*
=> Faça um algoritmo que leia o valor de duas variáveis A e B e 
troque os valores dessas variáveis.

-------------------------------------------------------------------------------
Exemplo de saída:

== Troca do conteudo de variaveis ==
Entre com o valor de A: 5
Entre com o valor de B: 6
Apos a troca, o valor de A eh 6 e o de B eh 5
-------------------------------------------------------------------------------
*/