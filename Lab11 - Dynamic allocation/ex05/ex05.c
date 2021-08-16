#include <stdio.h>
#include <stdlib.h>
//lembre-se de incluir as bibliotecas adequadas

int main(){

    printf("<< Vetor de pontos alocados dinamicamente >>\n");
    
    typedef struct{
        int x, y;
    }ponto;

    ponto *pontos;
    int *esquerda, *direita, *cima, *baixo;
    int n;
    
    printf("Quantos pontos deseja digitar: ");
    scanf("%d", &n);
    pontos = (ponto *) malloc(n*sizeof(ponto));

    for (int i=0; i<n; i++){
        printf("entre com a coordenada x do ponto %d: ", i+1);
        scanf("%d", &pontos[i].x);
        for (int j=i; j>=0; j--){
            if (i==0){
                esquerda = &pontos[j].x;
                direita = &pontos[j].x;
            }
            else {
                if (pontos[j].x < *esquerda){
                    esquerda = &pontos[j].x;
                }
                if (pontos[j].x > *direita){
                    direita = &pontos[j].x;
                }
            }
        }

        printf("entre com a coordenada y do ponto %d: ", i+1);
        scanf("%d", &pontos[i].y);
        for (int j=i; j>=0; j--){
            if (i==0){
                cima = &pontos[j].y;
                baixo = &pontos[j].y;
            }
            else {
                if (pontos[j].y < *baixo){
                    baixo = &pontos[j].y;
                }
                if (pontos[j].y > *cima){
                    cima = &pontos[j].y;
                }
            }
        }
        printf("\n");
    }

    printf("\nPontos digitados: ");

    for (int i=0; i<n; i++){
        printf(" (%d, %d)", pontos[i].x, pontos[i].y);
    }

    printf("\n\n");

    printf("Ponto mais a esquerda: (%d, %d)\n", *esquerda, *(esquerda+1));
    printf("Ponto mais a direita: (%d, %d)\n", *direita, *(direita+1));
    printf("Ponto mais a cima: (%d, %d)\n", *(cima-1), *cima);
    printf("Ponto mais a baixo: (%d, %d)\n", *(baixo-1), *baixo);

    free(pontos);

    return 0;
}

/*
5) Modifique o programa anterior incluindo quatro ponteiros, que apontarão para
os seguintes pontos: mais a esquerda, mais a direita, mais acima, mais abaixo.
Mostre quem são esses pontos utilizando esses ponteiros.

Exemplo de saída:
<< Vetor de pontos alocados dinamicamente >>
Digite a quantidade de pontos a serem armazenados: 5

Digite o valor da coordenada x do ponto 1: 2
Digite o valor da coordenada y do ponto 1: 5

Digite o valor da coordenada x do ponto 2: 4
Digite o valor da coordenada y do ponto 2: 8

Digite o valor da coordenada x do ponto 3: 3
Digite o valor da coordenada y do ponto 3: 4

Digite o valor da coordenada x do ponto 4: 6
Digite o valor da coordenada y do ponto 4: 7

Digite o valor da coordenada x do ponto 5: 23
Digite o valor da coordenada y do ponto 5: 25


Os pontos digitados sao: (2,5); (4,8); (3,4); (6,7); (23,25)

Ponto mais a esquerda: (2,5)
Ponto mais a direita: (23,25)
Ponto mais acima: (23,25)
Ponto mais abaixo: (3,4)

*/