#include <stdio.h>

int main() {
    printf("<< Conversor de numeros binarios >>\n");

    int a, b, c, d, decimal;
    printf("Digite o 1o bit: ");
    scanf("%d", &a);
    printf("Digite o 2o bit: ");
    scanf("%d", &b);
    printf("Digite o 3o bit: ");
    scanf("%d", &c);
    printf("Digite o 4o bit: ");
    scanf("%d", &d);

    decimal = 8*a + 4*b + 2*c + 1*d;

    printf("O numero binario %d%d%d%d corresponde ao numero decimal %d\n", a, b, c, d, decimal);
    return 0;
}

/*
=> Faça um conversor de número binário para decimal (inteiro). 
O número deve ter 4 bits, sendo o bit mais significativo digitado primeiro. 
Mostrar na resposta o número binário e o número decimal.

-------------------------------------------------------------------------------
Exemplo de saída:

<< Conversor de numeros binarios >>
Digite o 1o. bit: 1
Digite o 2o. bit: 0
Digite o 3o. bit: 1
Digite o 4o. bit: 1
O numero binario 1011 corresponde ao numero decimal 11
-------------------------------------------------------------------------------
*/