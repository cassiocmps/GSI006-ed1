#include <stdio.h>
#include <stdlib.h>

void imprime_vet_double (double n[], int tamanho);
void maior_e_menor (double n[], int tamanho, double *maior, double *menor);

int main(){
    
    double *vetor, maior, menor;
    int tamanho;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    vetor = (double *) malloc(tamanho*sizeof(double));

    for (int i=0; i<tamanho; i++){
        printf("Digite o valor %d: ", i+1);
        scanf("%lf", &vetor[i]);
    }

    printf("O vetor principal eh: ");
    imprime_vet_double(vetor, tamanho);

    maior_e_menor(vetor, tamanho, &maior, &menor);

    printf("O maior valor eh %.2lf\nO menor valor eh %.2lf\n", maior, menor);

    free(vetor);
    return 0;
}

void imprime_vet_double (double n[], int tamanho){
    for (int i=0; i<tamanho; i++){
        printf("%.2lf ", n[i]);
    }
    printf("\n");
}

void maior_e_menor (double n[], int tamanho, double *maior, double *menor){
    *maior = n[0];
    *menor = n[0];
    for (int i=1; i<tamanho; i++){
        if (n[i] > *maior) *maior = n[i];
        if (n[i] < *menor) *menor = n[i];
    }
}


/*
=> Crie um procedimento que recebe um vetor de double como 
entrada e devolve o maior e o menor elemento do vetor. Mostre no 
programa principal o vetor, o maior e o menor elemento.


No programa principal, solicite ao usuário o tamanho do vetor, e os
valores a serem computados.

-------------------------------------------------------------------------------
Exemplo de Saída:

Digite o tamanho do vetor: 3
Digite o valor 1: -1
Digite o valor 2: 0.02
Digite o valor 3: 3

O vetor principal eh: -1.00, 0.02, 3.00
O maior valor eh 3.00
O menor valor eh -1.00
-------------------------------------------------------------------------------
Obs: note que para este caso, foram consideradas duas casas após o ponto. 
*/