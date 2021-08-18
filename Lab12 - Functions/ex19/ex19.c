#include <stdio.h>
#include <stdlib.h>

void imprime_vet_float (float vetor[], int tamanho);
int negativos(float *vetor, int tamanho);

int main(){

    float *vetor;
    int tamanho;
    
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    vetor = (float *) malloc(tamanho*sizeof(float));
    
    for (int i=0; i<tamanho; i++){
        printf("Digite o valor %d: ", i+1);
        scanf("%f", &vetor[i]);
    }

    printf("O vetor principal eh: ");
    imprime_vet_float(vetor, tamanho);

    printf("O vetor tem %d numero(s) negativo(s)\n", negativos(vetor,tamanho));
    
    free(vetor);
    return 0;
}

void imprime_vet_float (float vetor[], int tamanho){
    for (int i=0; i<tamanho; i++){
        printf("%.2f ", vetor[i]);
    }
    printf("\n");
}

int negativos(float *vetor, int tamanho){
    
    int negativos=0;
    
    for (int i=0; i<tamanho; i++){
        if (vetor[i] < 0){
            negativos++;
        }
    }
    return negativos;
}

/*
=> Implemente uma função que receba como parâmetro um 
vetor de n números reais (VET) de tamanho N e retorne quantos 
números negativos há a nesse vetor. Use o seguinte protótipo:

int negativos(float *vet, int N); 

No programa principal, solicite ao usuário o tamanho do vetor, e os
valores a serem computados.
-------------------------------------------------------------------------------
Exemplo de Saída:

Digite o tamanho do vetor: 3
Digite o valor 1: -1
Digite o valor 2: 3
Digite o valor 3: -2

O vetor principal eh: -1.00, 3.00, -2.00
O vetor tem 2 numero(s) negativo(s)
-------------------------------------------------------------------------------
*/