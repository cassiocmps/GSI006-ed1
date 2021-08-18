#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void imprime_vet_int (int n[], int tamanho);
void maior_e_menor (int n[], int tamanho, int *maior, int *menor);
int negativos(int *vetor, int tamanho);
void abs_vet(int vetor[], int vetorNovo[], int tamanho);
void copiarvet(int origem[], int destino[], int tamanho);
void multvet(int vetor[], int tamanho, int escalar);

int main(){
    
    int *vetor, *vetorAbs, *vetorColado, maior, menor, escalar;
    int tamanho;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    vetor = (int *) malloc(tamanho*sizeof(int));

    for (int i=0; i<tamanho; i++){
        printf("Digite o valor %d: ", i+1);
        scanf("%d", &vetor[i]);
    }
    // ---------------------------------------------------------------------------------------
    printf("Vetor: ");
    imprime_vet_int(vetor, tamanho);
    // ---------------------------------------------------------------------------------------
    maior_e_menor(vetor, tamanho, &maior, &menor);
    printf("Maior: %d Menor: %d\n", maior, menor);
    // ---------------------------------------------------------------------------------------
    printf("Numero de negativos: %d\n", negativos(vetor,tamanho));
    // ---------------------------------------------------------------------------------------
    vetorAbs = (int *) malloc(tamanho*sizeof(int));
    (printf("Vetor absoluto: "));
    abs_vet(vetor, vetorAbs, tamanho);
    imprime_vet_int(vetorAbs, tamanho);
    // ---------------------------------------------------------------------------------------
    printf("Copiando para outro vetor (alocado dinamicamente)\n");
    printf("Vetor original: ");
    imprime_vet_int(vetor, tamanho);
    
    printf("Vetor copiado: ");
    vetorColado = (int *) malloc(tamanho*sizeof(int));
    copiarvet(vetor, vetorColado, tamanho);
    imprime_vet_int(vetorColado, tamanho);
    // ---------------------------------------------------------------------------------------
    printf("Entre com o valor escalar para multiplicar o vetor original: ");
    scanf("%d", &escalar);
    multvet(vetor, tamanho, escalar);
    printf("Vetor original: ");
    imprime_vet_int(vetor, tamanho);
    printf("Vetor copiado: ");
    imprime_vet_int(vetorColado, tamanho);
    // ---------------------------------------------------------------------------------------
    free(vetor);
    free(vetorAbs);
    free(vetorColado);
    return 0;
}

void imprime_vet_int (int n[], int tamanho){
    for (int i=0; i<tamanho; i++){
        printf("%d ", n[i]);
    }
    printf("\n");
}

void maior_e_menor (int n[], int tamanho, int *maior, int *menor){
    *maior = n[0];
    *menor = n[0];
    for (int i=1; i<tamanho; i++){
        if (n[i] > *maior) *maior = n[i];
        if (n[i] < *menor) *menor = n[i];
    }
}

int negativos(int *vetor, int tamanho){
    
    int negativos=0;
    
    for (int i=0; i<tamanho; i++){
        if (vetor[i] < 0){
            negativos++;
        }
    }
    return negativos;
}

void abs_vet(int vetor[], int vetorNovo[], int tamanho){
    for (int i=0; i<tamanho; i++){
        vetorNovo[i]=abs(vetor[i]);
    }    
}

void copiarvet(int origem[], int destino[], int tamanho){
    for (int i=0; i<tamanho; i++){
        destino[i] = origem[i];
    }    
}

void multvet(int vetor[], int tamanho, int escalar){
    for (int i=0; i<tamanho; i++){
        vetor[i]*=escalar;
    }    
}

/*
=> Use as funções criadas nos exercícios anteriores em um único 
programa, mas agora trabalhe com vetores alocados 
dinamicamente no programa principal. Lembre-se de liberar a 
memória depois de usar os vetores.


No programa principal, solicite ao usuário o tamanho do vetor, os valores
a serem computados e posteriormente, o valor escalar para multiplicação do vetor.

-------------------------------------------------------------------------------
Exemplo de Saída:

Entre com o tamanho do vetor: 4
Entre com o elemento 1: 50
Entre com o elemento 2: 20
Entre com o elemento 3: 10
Entre com o elemento 4: -30

Vetor: 50, 20, 10, -30
Maior: 50   Menor: -30
Numero de negativos: 1
Vetor absoluto: 50, 20, 10, 30

Copiando para outro vetor (alocado dinamicamente)

Vetor original: 50, 20, 10, -30
Vetor copiado: 50, 20, 10, -30

Entre com o valor escalar para multiplicar o vetor original: 10

Vetor original: 500, 200, 100, -300
Vetor copiado: 50, 20, 10, -30
-------------------------------------------------------------------------------
*/