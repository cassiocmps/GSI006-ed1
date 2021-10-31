/* ex03
Crie uma função que faz a junção de dois vetores inteiros. 
A função deve ter como entrada os dois vetores e seus
respectivos tamanhos. A alocação de espaço necessário para
o vetor concatenado deve ser feita dentro da função 
(a função então deve devolver para o programa principal 
o vetor alocado e também o tamanho desse novo vetor). 
A função deve retornar um valor inteiro: (0 - zero)
se a junção ocorreu de forma correta; (-1) em caso de erro.
Mostre o uso da função no programa principal. Não é
permitido criar novos tipos de dados para a solução
do exercício (ou seja, sem uso de structs).


Vetor 1: [1, 5, 2]
Vetor 2: [10, 30] 
Concatenção Vetor 1, Vetor 2

Vetor Concatenado = [ 1, 5, 2, 10, 30]

*/

#include <stdio.h>
#include <stdlib.h>

// check:<<<erro: vetor resultante deve ser passado como ponteiro de ponteiro>>>>


// int concatena_vetor(int vet1[], int vet2[], int *vet_concat){
int concatena_vetor(int v1[], int v2[], int t1, int t2, int *novo_v, int *novo_t){
    if (t1<=0 || t2<=0){
        return -1;
    }
    int *vetor_funcao;
    int tam_funcao = t1+t2;
    *novo_t = tam_funcao;
    vetor_funcao = malloc(sizeof(int)*tam_funcao);
    if (vetor_funcao == NULL){
        return -1;
    }
    int j=0;
    for (int i=0; i<t1; i++, j++){
        vetor_funcao[j] = v1[i];
    }
    for (int i=0; i<t2; i++, j++){
        vetor_funcao[j] = v2[i];
    }
    printf("\nO VETOR FORMADO EH: ");
    for (int i=0; i<tam_funcao; i++){
        printf(" %d", vetor_funcao[i]);
    }
    novo_v = vetor_funcao; // nem sei q q tá dando errado :(
    return 0;
}

int main(){
    int vet1[3] = {1, 5, 2};
    int vet2[2] = {10, 30};
    int *vet_concat, tam_c;
    
    int tam_vet1 = *(&vet1+1) - vet1;// check:<<<erro: ?>>>>
    printf("\nNumber of elements in arr[1] is %d\n", tam_vet1);
    int tam_vet2 = *(&vet2+1) - vet2;
    printf("\nNumber of elements in arr[2] is %d\n", tam_vet2);

    concatena_vetor(vet1, vet2, tam_vet1, tam_vet2, vet_concat, &tam_c);
    printf("\nO VETOR FORMADO EH: ");
    for (int i=0; i<tam_c; i++){
        printf(" %d", vet_concat[i]);
    }
    printf("\n");


    return 0;
}
