#include <stdio.h>

typedef struct {
    double x, y;
} ponto;

void imprime_ponto(ponto p);

int main(){
    
    ponto p;

    printf("Digite o valor de x: ");
    scanf("%lf", &p.x);
    printf("Digite o valor de y: ");
    scanf("%lf", &p.y);

    imprime_ponto(p);

    return 0;
}

void imprime_ponto(ponto p){
    printf("O ponto digitado eh: (%.0lf,%.0lf)\n", p.x, p.y);
}

/*
Observação: Para os próximos exercícios, crie uma struct chamada ponto, que 
armazena dois números reais que representam coordenadas cartesianas.

=> Faça uma função chamada imprime_ponto, que recebe uma 
struct do tipo ponto e mostra na tela o ponto no seguinte formato 
(ponto.x, ponto.y)

Exemplo de chamada da função:
imprime_ponto(p)

-------------------------------------------------------------------------------
Exemplo de Saída:

Digite o valor de x: 10
Digite o valor de y: 5
O ponto digitado eh: (10,5)
-------------------------------------------------------------------------------
*/