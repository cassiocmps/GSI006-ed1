#include <stdio.h>

int main(){
    printf("<< Pointers >>\n");
    printf("A resposta da questão 6 esta comentada no codigo.\n");

    /* a adição à um ponteiro simboliza a "mobilização" para o proximo endereço de memoria, e a subtração para o anterior. 
    Mas essa movimentação tbm dedpened do tipo de dado que o ponteiro aponta. Por exemplo, caso seja um inteiro, que ocupa 4 bytes,
    a proxima posição fica 4 bytes a frente e a anterior fica 4 bytes para trás. No caso de um char, a movimentação é de 1 em 1 byte, e um double é de 8 em 8.*/

    return 0;
}