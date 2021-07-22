#include <stdio.h>

int main() {
    printf("== Operadores Booleanos ==\n");

    int A, B, x=0, y=0, z=0, w=0;
    printf("Digite 0 para falso e nao 0 para verdadeiro\n");
    printf("Entre com o primeiro valor (A): ");
    scanf("%d", &A);
    printf("Entre com o segundo valor (B): ");
    scanf("%d", &B);

    if (A!=0 && B!=0) x = 1;
    if (A!=0 || B!=0) y = 1;
    if ((A!=0 && B==0) || (A==0 && B!=0)) z = 1;
    if (A==0) w = 1;

    printf("A and B: %d\n", x);
    printf("A or B: %d\n", y);
    printf("A xor B: %d\n", z);
    printf("not A: %d\n", w);
    
    return 0;
}

/*
=> Faça um algoritmo que mostre o funcionamento dos operadores lógicos. Peça para o usuário entrar com dois valores inteiros,, 
onde 0 implica em FALSO e qualquer outro número implica em VERDADEIRO.
Obs: z = (p || q) && !(p && q)

-------------------------------------------------------------------------------
Exemplo de saída:

== Operadores Booleanos ==
Digite 0 para falso e nao 0 para verdadeiro
Entre com o primeiro valor (A): -1
Entre com o segundo valor (B): 3
A x B: 1
A y B: 1
A z B: 0
not A: 0
-------------------------------------------------------------------------------
*/