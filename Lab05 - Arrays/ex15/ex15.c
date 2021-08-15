#include<stdio.h>

int main() {
    
    int numero[8], repetido[8], contador=0;
    int salvo;

    for (int i=0; i<8; i++){
        printf("Entre com o numero %d: ", i+1);
        scanf("%d", &numero[i]);
    }

    for(int i=0; i<8; i++){
        //para cada numero
       for(int j=0; j<8; j++){
           //compara com cada um do vetor
           salvo=0;
           if(i!=j && numero[i]==numero[j]){
               //se forem numeros de indidice diferentes e valores iguais
               for(int k=0; k<contador; k++){ //passar pelo vetor novamente
                   if(repetido[k]==numero[j]){ //procurando se o valor já foi gravado
                       salvo=1; // se sim, salvo recebe 1
                   }
                }
               
               if(salvo != 1){ // caso ele seja zero, ainda não foi salvo, então é salvo no proximo indice
                   repetido[contador++] = numero[j];
                }
            }
        }
    }
    
    printf("Valores repetidos: ");
    for(int i=0; i<contador; i++){
        printf("%d ",repetido[i]);
    }
    printf("\n");

    return 0;
}

/*
Faça um programa que leia um numero de 8 posições e verifique se existem 
valores iguais e os escreva (cada número repetido deve aparecer somente 
uma vez na resposta)

Exemplo de saída:
<< Valores iguais >>
Entre com o numero 1: 5
Entre com o numero 2: 6
Entre com o numero 3: 4
Entre com o numero 4: 5
Entre com o numero 5: -3 
Entre com o numero 6: -3
Entre com o numero 7: -3
Entre com o numero 8: 6

Valores repetidos: 5, 6, -3
*/