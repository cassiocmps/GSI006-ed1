#include <stdio.h>

int main(){
    float salario;
    printf("<< Aumento Salarial >>\n");
    printf("Digite o valor do salario R$: ");
    scanf("%f", &salario);
    printf("Apos 25%% de aumento o salario fica em R$ %.2f\n", salario+(salario/4));
    return 0;
}