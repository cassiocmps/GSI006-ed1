#include <stdio.h>

void Incremento(double *n, double p);

int main(){
    
    double numero, porcento;

    printf("Digite o valor de y: ");
    scanf("%lf", &numero);
    printf("Digite o percentual de alteração x: ");
    scanf("%lf", &porcento);

    Incremento(&numero, porcento);

    printf("O valor alterado eh: %.lf\n", numero);

    return 0;
}

void Incremento(double *n, double p){
    double adicional;
    adicional=(*n)*p;
    *n+=adicional;
}
/*
=> Faça uma função que altere um valor de um número real em x%. 
Se o valor de x for negativo ele deve ser decrementado, se for
positivo aumente. O valor da variável deve ser passada por parâmetro,
ou seja, o retorno deve  ser void.


-------------------------------------------------------------------------------
Exemplo de Saída 1:

Digite o valor de y: 100
Digite o percentual de alteracao: 0.10 // 0.10 equivale a 10%
O valor alterado eh: 110
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
Exemplo de Saída 2:

Digite o valor de y: -100
Digite o percentual de alteração: .10
O valor alterado eh: -110
-------------------------------------------------------------------------------
*/