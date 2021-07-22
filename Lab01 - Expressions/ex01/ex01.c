#include <stdio.h>

int main(){
    float numero;
    printf("<< Calculo do Quadrado de n >>\n");
    printf("Digite um número: ");
    scanf("%f", &numero);
    printf("O valor de %f ao quadrado é %f\n", numero, numero*numero);
    return 0;
}
