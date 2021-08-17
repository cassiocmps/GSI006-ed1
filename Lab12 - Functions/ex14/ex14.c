#include <stdio.h>

typedef struct {
    double x, y;
} ponto;

void Multiplica(ponto *p, double c);

int main(){
    
    ponto p;
    ponto *ponteiro;
    double constante;
    
    printf("Digite o ponto: ");
    scanf("%lf,%lf", &p.x, &p.y);
    printf("Digite a constante: ");
    scanf("%lf", &constante);
    
    ponteiro = &p;

    printf("Resultado: (%.0lf,%.0lf) * %.0lf = ", p.x, p.y, constante);
    Multiplica(ponteiro, constante);
    printf("(%.0lf,%.0lf)\n", p.x, p.y);

    return 0;
}

void Multiplica(ponto *p, double c){
    p->x *= c;
    p->y *= c;
}

/*
=> Faça um procedimento que multiplique o valor de um ponto 
por uma constante e altere o valor do ponto. Deve ser usada 
passagem por referência e retorno void.


-------------------------------------------------------------------------------
Exemplo de Saída:

Digite o ponto: 1,2
Digite a constante: 5
Resultado: (1,2) * 5 = (5,10)
-------------------------------------------------------------------------------
*/