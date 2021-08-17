#include <stdio.h>

double Elevado (double x, double n);

int main(){
    
    double x, n;

    printf("Digite o valor de x: ");
    scanf("%lf", &x);

    printf("Digite o valor de n: ");
    scanf("%lf", &n);

    printf("O valor de %lf elevado a %lf eh %lf\n", x, n, Elevado(x, n));

    return 0;
}

double Elevado (double x, double n){
    
    double resultado=1;

    if (n>0){
        for (int i=0; i<n; i++){
        resultado*=x;
        }
    }
    if (n<0){
        for (int i=n; i<0; i++){
        resultado*=x;
        }
        resultado=(1/resultado);
    }

    return resultado;
}

/*
=> Faça uma função para calcular xn. Não utilizar o operador pow (nem ^ - que não existe em C).
No programa principal permita ao usuário informar o valor de x e de n (inteiro). 
Lembre que n pode assumir valor negativo.

Ex: Elevado(2,4) tem como saída 16; 
    

No programa principal, solicite ao usuário o valor de x e o valor de n.

-------------------------------------------------------------------------------
Exemplo de Saída:

Digite o valor de x: 2
Digite o valor de n: 4
O valor de 2 elevado a 4 eh 16
-------------------------------------------------------------------------------
*/