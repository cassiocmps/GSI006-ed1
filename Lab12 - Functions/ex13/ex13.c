#include <stdio.h>

typedef struct {
    double x, y;
} ponto;

double CalculaArea(ponto p1, ponto p2);

int main(){
    
    ponto p1, p2;
    double area;

    printf("Digite a coordenada x do ponto 1: ");
    scanf("%lf", &p1.x);
    printf("Digite a coordenada y do ponto 1: ");
    scanf("%lf", &p1.y);

    printf("Digite a coordenada x do ponto 2: ");
    scanf("%lf", &p2.x);
    printf("Digite a coordenada y do ponto 2: ");
    scanf("%lf", &p2.y);

    area = CalculaArea(p1,p2);

    printf ("A area do retangulo definido por (%.2lf, %.2lf) e (%.2lf, %.2lf) eh %.2lf\n", p1.x, p1.y, p2.x, p2.y, area);

    return 0;
}

double CalculaArea(ponto p1, ponto p2){
    double base, altura, area;
    base = p1.x - p2.x;
    altura = p1.y - p2.y;
    
    area = base * altura;
    if (area<0) {
        area+=2*area;
    }

    return area;
}

/*
Observação: Lembre-se de utilizar a struct chamada ponto, que 
armazena dois números reais que representam coordenadas cartesianas.

=> Faça uma função que calcule a área do retângulo definido por 
dois pontos. 

Cabeçalho: area = calc_area(p1,p2)


-------------------------------------------------------------------------------
Exemplo de Saída:

<< Calculo de Area >>
Digite a coordenada x do ponto 1: 1
Digite a coordenada y do ponto 1: 4
Digite a coordenada x do ponto 2: 4
Digite a coordenada y do ponto 2: 2

A area do retangulo definido por (1.00, 4.00) e (4.00, 2.00) eh 6.00
-------------------------------------------------------------------------------
*/
