#include <stdio.h>

void Troque(int *x, int *y);

int main(){
    
    int A, B;

    printf("Digite o número A: ");
    scanf("%d", &A);
    printf("Digite o número B: ");
    scanf("%d", &B);

    Troque(&A, &B);

    printf("O número A eh: %d\n", A);
    printf("O número B eh: %d\n", B);

    return 0;
}

void Troque(int *x, int *y){
    int auxiliar;
    auxiliar=*x;
    *x=*y;
    *y=auxiliar;
}

/*
=> Faça um procedimento “Troque”, que recebe duas variáveis reais A e B
e troca o valor delas (i.e., A recebe o valor de B e B recebe o valor de A).
Mostre no programa principal o resultado da troca. 


No programa principal, solicite ao usuário o número A e o número B.

-------------------------------------------------------------------------------
Exemplo de Saída:

Digite o número A: 2
Digite o número B: 5
O número A eh: 5
O número B eh: 2
-------------------------------------------------------------------------------
*/