#include <stdio.h>

typedef struct {
    double x, y;
} ponto;

void imprime_ponto(ponto p);
void Soma(ponto p1, ponto p2, ponto *soma);

int main(){
    
    ponto p1, p2, *s, soma;
    s=&soma;

    printf("Digite o valor de x1: ");
    scanf("%lf", &p1.x);
    printf("Digite o valor de y1: ");
    scanf("%lf", &p1.y);

    printf("Digite o valor de x2: ");
    scanf("%lf", &p2.x);
    printf("Digite o valor de y2: ");
    scanf("%lf", &p2.y);

    Soma(p1, p2, s);

    printf("A soma de ");
    imprime_ponto(p1);
    printf("com ");
    imprime_ponto(p2);
    printf("eh ");
    imprime_ponto(soma);
    printf("\n");

    return 0;
}

void imprime_ponto(ponto p){
    printf("(%.0lf,%.0f) ", p.x, p.y);
}

void Soma(ponto p1, ponto p2, ponto *soma){
    soma->x = p1.x + p2.x;
    soma->y = p1.y + p2.y;
}

/*
Observação: Lembre-se de utilizar a struct chamada ponto, que 
armazena dois números reais que representam coordenadas cartesianas.

=> Crie um procedimento idêntico ao exercício anterior, mas que 
agora retorne void e coloque o resultado da soma no terceiro 
argumento da função.


-------------------------------------------------------------------------------
Exemplo de Saída:

Digite o valor de x1: 1
Digite o valor de y1: 2
Digite o valor de x2: 3
Digite o valor de y2: 4
A soma de (1,2) com (3,4) eh (4,6)
-------------------------------------------------------------------------------
*/