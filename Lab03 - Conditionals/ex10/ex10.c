#include <stdio.h>
#include <stdbool.h>

int main() {
    
    printf("== Operadores Booleanos ==\n");
    int a=0, b=0;
    bool A=false, B=false, x=false, y=false, z=false, w=false;

    printf("Digite 0 para falso e nao 0 para verdadeiro\n");
    printf("Entre com o primeiro valor (A): ");
    scanf("%d", &a);
    printf("Entre com o segundo valor (B): ");
    scanf("%d", &b);
    
    if (a!=0) A = true;
    else A = false;

    if (b!=0) B = true;
    else B = false;

    if (A!=false && B!=false) x = true;
    if (A!=false || B!=false) y = true;
    if ((A!=false && B==false) || (A==false && B!=false)) z = true;
    if (A==false) w = true;

    if (x==true) printf("A and B: VERDADEIRO\n");
    else printf("A and B: FALSO\n");
    
    if (y==true) printf("A or B: VERDADEIRO\n");
    else printf("A or B: FALSO\n");

    if (z==true) printf("A xor B: VERDADEIRO\n");
    else printf("A xor B: FALSO\n");

    if (w==true) printf("not A: VERDADEIRO\n");
    else printf("not A: FALSO\n");
    
    return 0;
}