#include <stdio.h>

void DesenhaLinha(int n);

int main(){
    int x;
    printf("Digite a quantidade de linhas a serem impressas: ");
    scanf("%d", &x);

    DesenhaLinha(x);

    return 0;
}

void DesenhaLinha(int n){
    for (int i=0; i<n; i++){
        printf("========\n");
    }
}

/*
=> Faça um procedimento chamado DesenhaLinha. Ele deve desenhar 
uma linha na tela usando vários caracteres "=" (Ex: ========). 
No programa principal execute várias chamadas a esse procedimento (use um loop).

Ex: DesenhaLinha(3) tem como saída:
    ========
    ========
    ======== 

No programa principal, solicite ao usuário quantas vezes a linha deverá ser desenhada.

-------------------------------------------------------------------------------
Exemplo de Saída:

Digite a quantidade de linhas a serem impressas: 3
========
========
========
-------------------------------------------------------------------------------
*/