#include <stdio.h>
#include <stdlib.h>

void multvet(int vetor[], int tamanho, int escalar);
void imprime_vet_int (int n[], int tamanho);

int main(){
    
    int *vetor;
    int tamanho, escalar;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    vetor = (int *) malloc(tamanho*sizeof(int));
    
    for (int i=0; i<tamanho; i++){
        printf("Digite o valor %d: ", i+1);
        scanf("%d", &vetor[i]);
    }

    printf("Digite o valor do escalar: ");
    scanf("%d", &escalar);

    printf("O vetor de origem eh: ");
    imprime_vet_int(vetor, tamanho);

    printf("O vetor final eh: ");
    multvet(vetor, tamanho, escalar);
    imprime_vet_int(vetor, tamanho);
    
    free(vetor);
    return 0;
}

void multvet(int vetor[], int tamanho, int escalar){
    for (int i=0; i<tamanho; i++){
        vetor[i]*=escalar;
    }    
}

void imprime_vet_int (int n[], int tamanho){
    for (int i=0; i<tamanho; i++){
        printf("%d ", n[i]);
    }
    printf("\n");
}

/*
=> Faça uma função para multiplicar um vetor por um escalar 
(um número). Mostre, no programa principal, o vetor antes e depois 
da multiplicação.

Chamada:
multvet(vetor, n, escalar);


No programa principal, solicite ao usuário o tamanho do vetor, os valores
a serem computados e o valor do escalar.

-------------------------------------------------------------------------------
Exemplo de Saída:

Digite o tamanho do vetor: 5
Digite o valor 1: 2
Digite o valor 2: 4
Digite o valor 3: 10
Digite o valor 4: 6
Digite o valor 5: 5
Digite o valor do escalar: 3

O vetor de origem eh: 2, 4, 10, 6, 5
O vetor final eh: 6, 12, 30, 18, 15
-------------------------------------------------------------------------------
*/