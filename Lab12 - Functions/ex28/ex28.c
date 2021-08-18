#include <stdio.h>
#include <stdlib.h>

void imprime_vet (double vetor[]);
void copiarvet(double origem[], double destino[], int tamanho);


int main(){
    
    int  tamanho;
    double vetorOrigem[5]={1.20,2.00,3.20,4.00,5.10};
    double *vetorDestino;

    printf("O vetor de origem eh: ");
    imprime_vet(vetorOrigem);
    
    copiarvet(vetorOrigem, vetorDestino, 5);
    
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

void copiarvet(double origem[], double destino[], int tamanho){
    
    destino = (double *) malloc(tamanho*sizeof(double));
    for (int i=0; i<tamanho; i++){
        destino[i] = origem[i];
    }
    // for (int i=0; i<5; i++){
    //     if (i==0) printf("%.2lf", destino[i]);
    //     else printf(", %.2lf", destino[i]);
    // }
}

/*
=> Tente fazer uma função que copia um vetor de double para 
um outro vetor. Esse outro vetor é alocado dentro da função que 
faz a cópia.  Mostre vet_destino no programa principal.

Chamada:
copiarvet(vet_origem, vet_destino, n);

Explique porque a função não funciona. Faça o mapa de memória 
(antes, durante, e depois da chamada da função). Qual seria a 
solução para uma função deste tipo?

    O vetor recebe um endereço de memoria referente à função, e então ela termina de ser executada o endereço é perdido, apesar dos valores continuarem salvos lá. 
    Uma solução é passar o endereço alocado como um retorno da função a um ponteiro na função main.

-------------------------------------------------------------------------------
Observação:

Utilize o excel para fazer o mapa de memória (Modelo disponível nos
arquivos do Teams).
-------------------------------------------------------------------------------
*/