#include <stdio.h>

int main(){
    printf("<< Pares e Ímpares >>\n");

    int valor[5], par[5], impar[5], auxP=0, auxI=0;

    for (int i=0; i<5; i++){
        printf("Digite o valor %d: ", i+1);
        scanf("%d", &valor[i]);

        if (valor[i]%2==0) {
            par[auxP]=valor[i];
            auxP++;
        }
        else {
            impar[auxI]=valor[i];
            auxI++;
        }
    }

    printf("\nImpares: ");
    for (int i=0; i<auxI; i++){
        printf("%d ", impar[i]);
    }
    
    printf("\nPares: ");
    for (int i=0; i<auxP; i++){
        printf("%d ", par[i]);
    }

    printf("\n");
    
    return 0;
}

/*
Leia 5 números inteiros e armazene em um vetor v. Crie dois novos vetores v1 e v2.
Copie os valores ímpares de v para v1, e os valores pares de v para v2. 
Note que cada um dos vetores v1 e v2 tem no máximo 5 elementos, mas nem 
todos os elementos são utilizados. No final escreva os elementos UTILIZADOS de v1 e v2. 

Exemplo de saída:
<< Pares e Ímpares >>
Digite o valor 1: 51
Digite o valor 2: 60
Digite o valor 3: 70
Digite o valor 4: 80
Digite o valor 5: 60

Ímpares: 51
Pares: 60, 70, 80, 60
*/