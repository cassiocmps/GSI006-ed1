#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    printf("<< Vetor de Char >>\n");

    char nome[50];
    
    printf("Digite um nome: ");
    fgets(nome, 50, stdin);

    printf("O nome digitado eh: %s", nome);

    return 0;
}
