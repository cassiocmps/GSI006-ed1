#include <stdio.h>

int QuadradoPerfeito (int x);

int main(){
    
    int numero;
    
    printf("Digite o valor de n: ");
    scanf("%d", &numero);

    if (QuadradoPerfeito(numero)==1){
        printf("O numero %d eh um quadrado perfeito\n", numero);
    }
    else {
        printf("O numero %d nao eh um quadrado perfeito\n", numero);
    }

    return 0;
}

int QuadradoPerfeito (int x){
    
    int qp=0;
    
    for (int i=0; i<x; i++){ //talvez o loop corra muito...
        if (i*i==x) {
            qp=1;
        }
    }

    return qp;
}

/*
=> Faça uma função para verificar se um número 
é um quadrado perfeito (retorne Verdadeiro caso seja).   

Ex: QuadradoPerfeito(4) retorna verdadeiro; 
    QuadradoPerfeito(10) retorna falso; 

obs: Pode-se retornar os valores 0 (para verdadeiro) e 1 (para falso).

No programa principal, solicite ao usuário o valor de n.

-------------------------------------------------------------------------------
Exemplo de Saída 1:

Digite o valor de n: 4
O numero 4 eh um quadrado perfeito
-------------------------------------------------------------------------------
-------------------------------------------------------------------------------
Exemplo de Saída 2:

Digite o valor de n: 10
O numero 10 não eh um quadrado perfeito
-------------------------------------------------------------------------------
*/