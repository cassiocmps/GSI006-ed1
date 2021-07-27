#include <stdio.h>

int main() {

    double mensal, comissao;
    printf ("<< Comissão do vendedor >>\n");

    printf ("Digite a venda total mensal: ");
    scanf ("%lf", &mensal);

    if (mensal<20000) comissao = 400 + mensal*0.14;
    else if (mensal>=20000 && mensal<40000) comissao = 500 + mensal*0.14;
    else if (mensal>=40000 && mensal<60000) comissao = 550 + mensal*0.14;
    else if (mensal>=60000 && mensal<80000) comissao = 600 + mensal*0.14;
    else if (mensal>=80000 && mensal<100000) comissao = 650 + mensal*0.14;
    else if (mensal>=100000) comissao = 700 + mensal*0.16;

    printf ("A comissao do vendedor é %.2f\n", comissao);

    return 0;
}