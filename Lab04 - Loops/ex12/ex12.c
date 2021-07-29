#include <stdio.h>

int main(){
    
    printf("<< Soma de n valores naturais >>\n");
    int entrada, soma=0;

    printf("Quantos numeros deseja somar? ");
    scanf("%d", &entrada);

    for (int contador=0; contador<=entrada; contador++) {
        soma+=contador;
    }

    printf("A soma dos %d primeiros numeros naturais eh: %d\n", entrada, soma);

    return 0;
}
