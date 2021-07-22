#include <stdio.h>

int main() {
    float valor;
    printf("<< Loteria >>\n");
    printf("Valor total do premio: ");
    scanf("%f", &valor);
    printf("Primeiro vencedor: %.2f\n", valor*0.46);
    printf("Segundo vencedor: %.2f\n", valor*0.32);
    printf("Terceiro vencedor: %.2f\n", valor*0.22);
    return 0;
}
