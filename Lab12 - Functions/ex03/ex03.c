#include <stdio.h>

long int Fatorial(int x);
void DesenhaLinha(int x);

int main(){
    
    int linhas, numero;

    printf("Digite o tamanho da linha: ");
    scanf("%d", &linhas);
    printf("Digite o numero que deseja calcular o fatorial: ");
    scanf("%d", &numero);

    DesenhaLinha(linhas);
    printf("O fatorial de %d eh %ld\n", numero, Fatorial(numero));
    DesenhaLinha(linhas);

    return 0;
}

long int Fatorial (int x){
    if (x==0){
        return 1;
    }
    else {
        return (x * Fatorial(x-1));
    }
}

void DesenhaLinha(int x){
    for (int i=0; i<x; i++){
        printf("=");
    }
    printf("\n");
}

/*
=> Faça uma função para calcular o fatorial de um número. Use essa função
para calcular o fatorial de um número que o usuário digitar.
Colocar todas as funções E/S (entrada e saída) no programa principal.
(use também a função DesenhaLinha – esta pode conter comandos de saída fora do programa principal). 

Ex: Fatorial(5) tem como saída 120 
    DesenhaLinha(10) tem  como saída ==========

No programa principal, solicite ao usuário o tamanho da linha a ser desenhada e o número que se
deseja calcular o fatorial.

-------------------------------------------------------------------------------
Exemplo de Saída:

Digite o tamanho da linha: 10
Digite o numero que deseja calcular o fatorial: 5
==========
O fatorial de 5 eh 120
==========
-------------------------------------------------------------------------------
*/