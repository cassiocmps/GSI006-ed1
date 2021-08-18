#include <stdio.h>
#include <stdlib.h>

void imprime_vet (double vetor[]);
double *copiarvet(double origem[], int tamanho);


int main(){
    
    int  tamanho;
    double vetorOrigem[5]={1.20,2.00,3.20,4.00,5.10};
    double *vetorDestino;

    printf("O vetor de origem eh: ");
    imprime_vet(vetorOrigem);
    
    vetorDestino = copiarvet(vetorOrigem, 5);
    
    printf("O vetor de destino eh: ");
    imprime_vet(vetorDestino);
    
    free(vetorDestino);
    return 0;
}

void imprime_vet (double vetor[]){
    for (int i=0; i<5; i++){
        if (i==0) printf("%.2lf", vetor[i]);
        else printf(", %.2lf", vetor[i]);
    }
    printf("\n");
}

double *copiarvet(double vetor[], int tamanho){
    double *alocado;
    alocado = (double *) malloc(tamanho*sizeof(double));
    for (int i=0; i<tamanho; i++){
        alocado[i] = vetor[i];
    }
    return alocado;
}
/*
=> Faça uma função que copia um vetor de double para um 
outro vetor. Esse outro vetor é alocado dentro da função que faz a 
cópia. Mostre os dois vetores.

Chamada:
vet_destino  = copiarvet(vet_origem,  n);

-------------------------------------------------------------------------------
Exemplo de Saída:

O vetor de origem eh: 1.20, 2.00, 3.20, 4.00, 5.10
O vetor de destino eh: 1.20, 2.00, 3.20, 4.00, 5.10
-------------------------------------------------------------------------------
*/