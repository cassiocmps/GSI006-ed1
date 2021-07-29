#include <stdio.h>

int main(){
    printf("<< Listando um vetor de numeros pares>>\n");

    int num[6], numero, i=0;
    
    while(i<6){
        
        printf("Entre com um numero: ");
        scanf("%d", &numero);

        if (numero%2==0){
            num[i]=numero;
            i++;
        }
        else printf("Erro: Valor invalido\n");
    }

    printf("\nOs numeros pares digitados foram:");
    for (int i=0; i<6; i++){
        printf(" %d", num[i]);
    }
    printf("\n");
    return 0;
}

/*
Crie um programa que lê 6 valores inteiros e em seguida mostra na tela os 
valores lidos. Utilize loops e utilize vetores para armazenar os números.
O programa deve somente aceitar números pares. 
Dica: é melhor usar loop *while* para ler os números

Exemplo de saída:
<< Listando um vetor de numeros pares>>
Entre com o numero 1: 5
Erro: Valor invalido

Entre com o numero 1: 6
Entre com o numero 2: 4
Entre com o numero 3: 0
Entre com o numero 4: 3
Erro: Valor invalido

Entre com o numero 4: 6
Entre com o numero 5: -1
Erro: Valor invalido

Entre com o numero 5: 2
Entre com o numero 6: 50

Os numeros pares digitados foram: 6 4 0 6 2 50
*/
