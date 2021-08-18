#include <stdio.h>
#include <stdlib.h>

void imprime_vet_int (int n[], int tamanho);
void imprime_vet_double (double n[], int tamanho);
void imprime_vet_float (float n[], int tamanho);

int main(){
    
    // int n;
    // int *vetori;
    // double *vetord;
    // float *vetorf;
    int n=5;
    int vetori[5]={1,2,3,4,5};
    double vetord[5]={1.20,2.30,3.40,4.50,5.50};
    float vetorf[5]={1.20,2.30,3.40,4.50,5.50};

    printf("Os valores inseridos neste vetor de inteiros eh: ");
    imprime_vet_int(vetori,n);
    printf("\n");

    printf("Os valores inseridos neste vetor de float eh: ");
    imprime_vet_float(vetorf,n);
    printf("\n");

    printf("Os valores inseridos neste vetor de double eh: ");
    imprime_vet_double(vetord,n);
    printf("\n");

    return 0;
}

void imprime_vet_int (int n[], int tamanho){
    for (int i=0; i<tamanho; i++){
        printf("%d ", n[i]);
    }
    printf("\n");
}

void imprime_vet_double (double n[], int tamanho){
    for (int i=0; i<tamanho; i++){
        printf("%.2lf ", n[i]);
    }
    printf("\n");
}

void imprime_vet_float (float n[], int tamanho){
    for (int i=0; i<tamanho; i++){
        printf("%.2f ", n[i]);
    }
    printf("\n");
}

/*
=> Crie três funções chamadas imprime_vet_int, 
imprime_vet_double, imprime_vet_float que mostra o conteúdo de 
um vetor de inteiros, double, e float, respectivamente. Use essas 
funções sempre que precisar mostrar um vetor.


Exemplo de Chamada:

    imprime_vet_int(vetori,n);
    imprime_vet_double(vetord,n);
    imprime_vet_float(vetorf,n);

-------------------------------------------------------------------------------
Exemplo de Saída:

Os valores inseridos neste vetor de inteiros eh: 1 2 3 4 5 
Os valores inseridos neste vetor de float eh: 1.20 2.30 3.40 4.50 5.50 
Os valores inseridos neste vetor de double eh: 1.20 2.30 3.40 4.50 5.50 
-------------------------------------------------------------------------------
*/