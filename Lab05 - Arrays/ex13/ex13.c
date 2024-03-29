#include <stdio.h>

int main(){
    printf("<< Zerando negativos >>\n");

    int valor[5];

    for (int i=0; i<5; i++){
        printf("Entre com um numero %d: ", i+1);
        scanf("%d", &valor[i]);
        if (valor[i]<0) valor[i]=0;
    }
    printf("\n");

    printf("Negativos zerados:");
    for (int i=0; i<5; i++){
        printf(" %d", valor[i]);
    }
    printf("\n");

    return 0;
}

/*
Leia um vetor de 5 posições e atribua valor 0 para todos os elementos
que possuírem valores negativos. Mostre o vetor final.

Exemplo de saída:
<< Zerando negativos >>
Entre com o numero 1: 5
Entre com o numero 2: -6
Entre com o numero 3: 4
Entre com o numero 4: 0
Entre com o numero 5: -3

Negativo zerados: 5 0 4 0 0 
*/