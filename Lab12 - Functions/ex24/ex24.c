#include <stdio.h>
#include <stdlib.h>

void imprime_vet (int n[], int tamanho);
int *aloca_inteiro(int n);

int main(){
    
    int *ponteiro, tamanho;
    
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);
    
    ponteiro = aloca_inteiro(10);
    printf("O vetor eh: ");
    imprime_vet(ponteiro, tamanho);

    free(ponteiro);
    return 0;
}

void imprime_vet (int n[], int tamanho){
    for (int i=0; i<tamanho; i++){
        if (i==0) printf("%d", n[i]);
        else printf(", %d", n[i]);
    }
    printf("\n");
}

int *aloca_inteiro(int n){
    int *alocado;
    alocado = (int *) malloc(n*sizeof(int));
    for (int i=0; i<n; i++){
        alocado[i] = 0;
    }
    return alocado;
}

/*
=> Alocação dinâmica em funções: sabemos que as variáveis 
locais de uma função (e também seus parâmetros) são alocadas na 
memória no momento da execução da função. Ao término da 
função, essas variáveis são destruídas da memória. Entretanto, 
quando fazemos uma alocação dinâmica dentro de uma função, o 
vetor alocado permanece na memória, mesmo após o término da 
função.

Crie uma função aloca_inteiro, que faz a alocação de um vetor 
inteiro de tamanho n e que inicialize os elementos desse vetor com 
o valor zero. Retorne o ponteiro para o vetor alocado. Imprima no 
programa principal o vetor alocado.

Protótipo:
int *aloca_inteiro(int n);

Chamada:
int *p;
p = aloca_inteiro(10);
imprime_vet(p,n);

No programa principal, solicite ao usuário o tamanho do vetor e
lembre-se de imprimir o vetor alocado.

-------------------------------------------------------------------------------
Exemplo de Saída:

Digite o tamanho do vetor: 8
O vetor eh: 0, 0, 0, 0, 0, 0, 0, 0
-------------------------------------------------------------------------------
*/