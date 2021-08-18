#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void abs_vet(int vetor[], int tamanho);
void imprime_vet_int (int n[], int tamanho);

int main(){
    
    int *vetor;
    int tamanho;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    vetor = (int *) malloc(tamanho*sizeof(int));
    
    for (int i=0; i<tamanho; i++){
        printf("Digite o valor %d: ", i+1);
        scanf("%d", &vetor[i]);
    }

    printf("O vetor de origem eh: ");
    imprime_vet_int(vetor, tamanho);

    printf("O vetor com valores absolutos eh: ");
    abs_vet(vetor, tamanho);
    imprime_vet_int(vetor, tamanho);
    
    free(vetor);
    return 0;
}

void abs_vet(int vetor[], int tamanho){
    for (int i=0; i<tamanho; i++){
        vetor[i]=abs(vetor[i]);
    }    
}

void imprime_vet_int (int n[], int tamanho){
    for (int i=0; i<tamanho; i++){
        printf("%d ", n[i]);
    }
    printf("\n");
}

/*
=> Faça uma função para transformar os números de um vetor 
de inteiros em seu valor absoluto (use a função abs (math.h)).

Chamada:
    abs_vet(vet);

No programa principal, solicite ao usuário o tamanho do vetor e os valores
a serem computados. Imprima o vetor de origem e o vetor com valores absolutos.

-------------------------------------------------------------------------------
Exemplo de Saída:

Digite o tamanho do vetor: 3
Digite o valor 1: 1
Digite o valor 2: -1
Digite o valor 3: 2

O vetor de origem eh: 1, -1, 2
O vetor com valores absolutos eh: 1, 1, 2
-------------------------------------------------------------------------------
*/