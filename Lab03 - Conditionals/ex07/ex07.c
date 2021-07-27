#include <stdio.h>

int main() {
    int a, b, c, qa, qb, qc;
    
    printf("<< Tipos de triangulos >>\n");
    
    printf("Lado A: ");
    scanf("%d",&a);
    qa=a*a;
    
    printf("Lado B: ");
    scanf("%d",&b);
    qb=b*b;

    printf("Lado C: ");
    scanf("%d",&c);
    qc=c*c;

    if (a<0 || b<0 || c<0) printf("Uma das medidas eh invalida\n");
    else if (a>b+c || b>c+a || c>a+b) printf("Um triangulo nao pode ser formado\n");
    else if (qa==qb+qc || qb==qa+qc || qc==qa+qb) printf("Triangulo retangulo\n");
    else if (qa>qb+qc || qb>qa+qc || qc>qa+qb) printf("Triangulo obtusangulo\n");
    else printf("Triangulo acutangulo\n");
        
    return 0;
}