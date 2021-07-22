#include <stdio.h>

int main() {
    int dias;
    float bruto, liquido, iss, ir;
    printf("<< Pagamento encanador >>\n");
    printf("Digite o numero de dias trabalhados: ");
    scanf("%d", &dias);
    bruto = dias*30;
    printf("Valor bruto R$: %.2f\n", bruto);
    iss = bruto*0.04;
    bruto = bruto - iss;
    ir = bruto*0.08;
    liquido = bruto - ir;
    printf("Valor liquido R$: %.2f\n", liquido);
    printf("ISS R$: %.2f\n", iss);
    printf("IR R$: %.2f\n", ir);
    return 0;
}
/*
=> Um contador percebeu que o cálculo de IR do encanador estava errado, pois estava sendo calculado sobre o valor bruto que ele recebeu. 
Refaça o programa anterior, considerando que o IR é sobre o valor bruto após o desconto do ISS.

-------------------------------------------------------------------------------
Exemplo de saída:

<< Pagamento encanador >>
Digite o numero de dias trabalhados: 30
Valor bruto R$: 900
Valor liquido R$: 794.88
ISS R$: 36
IR R$: 68.12
-------------------------------------------------------------------------------
*/