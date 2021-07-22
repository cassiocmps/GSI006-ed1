#include <stdio.h>

int main() {
    int numero;
    printf("<< Sucessor e Antecessor >>\n");
    printf("Digite um numero: ");
    scanf("%d", &numero);
    printf("Antecessor: %d\n", numero-1);
    printf("Numero: %d\n", numero);
    printf("Sucessor: %d\n", numero+1);
    return 0;
}
