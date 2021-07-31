#include <stdio.h>

int main(){
    
    int i,tamanho = 6;
    char nome[10]="012345678"; //nao cabia o 9, pois para uma string é necessario o \0 (erro no compilador: initializer-string for array of chars is too long [-fpermissive])
    nome[0] = 'B';
    nome[1] = 'r';
    nome[2] = 'a';
    nome[3] = 's';
    nome[4] = 'i';
    nome[5] = 'l';
    nome[6] = '\0'; //necessario adicionar o \0 se não há a leitura de lixo de memoria, umas vez q %s le até encontrar um \0
    
    printf("Usando %%c: ");
    for (i=0; i < tamanho; i++){
        printf("%c",nome[i]);
    }
    printf("\n");

    printf("Usando %%s: %s\n", nome);

    return 0;
}
