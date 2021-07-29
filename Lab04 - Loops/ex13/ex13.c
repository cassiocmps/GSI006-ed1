#include <stdio.h>

int main(){
    
    printf("<< Multiplos >>\n");
    int n, i, j;

    printf("Entre com o valor de n: ");
    scanf("%d", &n);

    printf("Entre com o valor de i: ");
    scanf("%d", &i);

    printf("Entre com o valor de j: ");
    scanf("%d", &j);

    printf("Os multiplos de i ou j são:");
    
    for (int indice=0, contador=0; contador < n; indice++){
        if (indice%i==0 || indice%j==0){
            printf(" %d", indice);
            contador++;
        }
    }

    printf("\n");

    return 0;
}
