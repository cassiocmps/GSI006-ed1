#include <stdio.h>
#include <stdlib.h>

void imprime_vet_int (int n[], int tamanho);
void copiarvet(int origem[], int destino[], int tamanho);

int main(){

    int vetor1[5]={1,2,3,4,5}, vetor2[5]={1,2,3,3,6};
    int tamanho=5;
    
    printf("O vetor de origem eh: ");
    imprime_vet_int(vetor1, tamanho);

    printf("O vetor de destino eh: ");
    imprime_vet_int(vetor2, tamanho);

    copiarvet(vetor1, vetor2, tamanho);    
    
    printf("O vetor de destino apos a copia eh: ");
    imprime_vet_int(vetor2, tamanho);

    return 0;
}

void imprime_vet_int (int n[], int tamanho){
    for (int i=0; i<tamanho; i++){
        printf("%d ", n[i]);
    }
    printf("\n");
}

void copiarvet(int origem[], int destino[], int tamanho){
    for (int i=0; i<tamanho; i++){
        destino[i] = origem[i];
    }    
}
/*
=> Faça uma função para copiar um vetor inteiro para outro 
vetor. Ambos vetores devem ter o mesmo tamanho. Mostre no 
programa principal os dois vetores.

Chamada:
copiarvet(vet_origem, vet_destino, n);


Os valores são definidos na função principal.
-------------------------------------------------------------------------------
Exemplo de Saída:

O vetor de origem eh: 1, 2, 3, 4, 5
O vetor de destino eh: 1, 2, 3, 3, 6
O vetor de destino apos a copia eh: 1, 2, 3, 4, 5
-------------------------------------------------------------------------------
*/