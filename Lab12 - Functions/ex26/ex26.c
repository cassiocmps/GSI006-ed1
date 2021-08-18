#include <stdio.h>
#include <stdlib.h>

void imprime_vet_int (int n[], int tamanho);
void imprime_vet_double (double n[], int tamanho);
double *to_double (int vetor_de_int[], int tamanho);

int main(){
    
    int tamanho, *vetorInt;
    double *vetorD;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    vetorInt = (int *) malloc(tamanho*sizeof(int));

    for (int i=0; i<tamanho; i++){
        printf("Digite o valor %d: ", i+1);
        scanf("%d", &vetorInt[i]);
    }

    printf("O vetor de origem eh: ");
    imprime_vet_int(vetorInt, tamanho);

    printf("O vetor convertido para double eh: ");
    vetorD = to_double(vetorInt, tamanho);
    imprime_vet_double(vetorD, tamanho);    

    free(vetorInt);
    free(vetorD);
    return 0;
}

void imprime_vet_int (int n[], int tamanho){
    for (int i=0; i<tamanho; i++){
        if (i==0) printf("%d", n[i]);
        else printf(", %d", n[i]);
    }
    printf("\n");
}

void imprime_vet_double (double n[], int tamanho){
    for (int i=0; i<tamanho; i++){
        if (i==0) printf("%.2lf", n[i]);
        else printf(", %.2lf", n[i]);
    }
    printf("\n");
}

double *to_double (int vetor_de_int[], int tamanho){
    double *vetorNovo = (double *) malloc(tamanho*sizeof(double));
    for (int i=0; i<tamanho; i++){
        vetorNovo[i] = vetor_de_int[i];
    }
    return vetorNovo;
}

/*
=> Faça a função to_double, que recebe um vetor de inteiro e 
retorna um vetor com o mesmo conteúdo, mas convertido para 
double.

Chamada:
vet_double = to_double(vet_int,n);

-------------------------------------------------------------------------------
Exemplo de Saída:

Digite o tamanho do vetor: 4
Digite o valor 1: 1
Digite o valor 2: 3
Digite o valor 3: 5
Digite o valor 4: 4

O vetor de origem eh: 1, 3, 5, 4
O vetor convertido para double eh: 1.00, 3.00, 5.00, 4.00
-------------------------------------------------------------------------------
*/