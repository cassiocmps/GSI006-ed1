#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, y;
} ponto ;


void imprime_vet (ponto n[], int tamanho);
ponto *aloca_pontos(int n);

int main(){
    
    ponto *ponteiro;
    int tamanho;
    
    printf("Digite quantos pontos (x,y) voce deseja: ");
    scanf("%d", &tamanho);
    
    ponteiro = aloca_pontos(tamanho);

    imprime_vet(ponteiro, tamanho);

    free(ponteiro);
    return 0;
}

void imprime_vet (ponto n[], int tamanho){
    for (int i=0; i<tamanho; i++){
        if (i==0) printf("(%d,%d)", n[i].x, n[i].y);
        else printf(" , (%d,%d)", n[i].x, n[i].y);
    }
    printf("\n");
}

ponto *aloca_pontos(int n){
    ponto *alocado;
    alocado = (ponto *) malloc(n*sizeof(ponto));
    for (int i=0; i<n; i++){
        alocado[i].x = 0;
        alocado[i].y = 0;
    }
    return alocado;
}

/*
=> Crie uma função para alocar dinamicamente um vetor de n 
pontos e inicialize esses pontos como (0,0).

No programa principal, solicite ao usuário quantos pontos deseja.
-------------------------------------------------------------------------------
Exemplo de Saída:

Digite quantos pontos(x,y) você deseja: 2
(0,0) , (0,0) 
-------------------------------------------------------------------------------
*/