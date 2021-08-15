#include <stdio.h>

int main(){
    printf("<< Pointers >>\n");

    int n1;
    double n2;
    void *p;

    p = &n1;
    printf("Digite o numero inteiro: ");
    scanf("%d", p);

    p = &n2;
    printf("Digite o numero real: ");
    scanf("%lf", p);
    
    p = &n1;
    printf("Inteiro: %d\n", *(int *)p);

    p = &n2;
    printf("Real: %lf\n", *(double *)p);

    return 0;
}