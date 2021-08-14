#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    printf("<< Separa letras >>\n");

    char nome[50];
    
    printf("Digite o nome: ");
    fgets(nome, 50, stdin);

    for (int i=0; nome[i]!='\n'; i++){
        printf("%da letra: %c\n", i+1, nome[i]);
    }

    return 0;
}
