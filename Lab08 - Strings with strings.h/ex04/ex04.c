#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    printf("<< Compara nomes >>\n");

    char nome1[50], nome2[50];
    int diferentes;
    
    printf("Digite o nome1: ");
    fgets(nome1, 50, stdin);

    printf("Digite o nome2: ");
    fgets(nome2, 50, stdin);

    diferentes=strcasecmp(nome1, nome2); // strcasecmp compara uma string ignorando o case das letras (nao funciona com UTF-8)

    if (diferentes==0) printf("Os nomes digitados sao iguais\n");
    else printf("Os nomes digitados sao diferentes\n");

    return 0;
}
