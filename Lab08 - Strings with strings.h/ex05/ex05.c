#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    printf("<< Vetor de Char >>\n");

    char nome[50];
    char *sobrenome; // pq nao precisa de tamanho?
    
    printf("Digite um nome e sobrenome: ");
    fgets(nome, 50, stdin);

    strtok_r (nome, " ", &sobrenome); // entender melhor a funcao

    printf("Nome: %s\n", nome);
    printf("Sobrenome: %s\n", sobrenome);

    return 0;

}