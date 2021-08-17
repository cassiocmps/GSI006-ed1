#include <stdio.h>

void DesenhaLinha(int c, int n);

int main(){
    int x, y;
    printf("Digite a quantidade de linhas a serem impressas: ");
    scanf("%d", &x);
    printf("Digite tamanho da linha: ");
    scanf("%d", &y);

    DesenhaLinha(y,x);

    return 0;
}

void DesenhaLinha(int c, int n){
    for (int i=0; i<n; i++){
        for (int j=0; j<c; j++){
            printf("=");
        }
        printf("\n");
    }
}
/*
=> Faça um procedimento chamado DesenhaLinha. Ele deve desenhar 
uma linha na tela usando vários caracteres "=" (Ex: ========). 
O procedimento deve ter como argumento um valor que indica
quantos caracteres "=" serão mostrados. 

Ex: DesenhaLinha(4) tem como saída ====; 
    DesenhaLinha(10) tem  como saída ==========

No programa principal, solicite ao usuário quantas vezes a função 
deverá ser executada e qual o tamanho da linha a ser desenhada.

-------------------------------------------------------------------------------
Exemplo de Saída:

Digite a quantidade de linhas a serem impressas: 3
Digite o tamanho da linha: 5
=====
=====
=====
-------------------------------------------------------------------------------
*/