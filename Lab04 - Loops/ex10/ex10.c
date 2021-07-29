#include <stdio.h>

int main(){
    
    printf("<< Soma de n valores naturais >>\n");
    int entrada, contador=0, soma=0;

    printf("Quantos numeros deseja somar? ");
    scanf("%d", &entrada);

    while (contador<=entrada){
        soma+=contador;
        contador++;
    }

    printf("A soma dos %d primeiros numeros naturais eh: %d\n", entrada, soma);

    return 0;
}
