#include <stdio.h>

int main(){
    
    int valor, metade, auxiliar=0;
    
    printf("<< Numeros primos >>\n");

    printf("Entre com o valor: ");
    scanf("%d", &valor);
    metade=valor/2;

    for (int i=2; i<=metade; i++){

        if (valor%i==0) {
            printf("O numero %d NAO eh primo\n", valor);
            auxiliar=1;
            break;
        }

        if (auxiliar==0) {
            printf("O numero %d eh primo\n", valor);
            break;
        }
    }

    return 0;
}
