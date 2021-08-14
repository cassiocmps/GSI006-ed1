#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    printf("<< Invertendo >>\n");

    char string[50];
    
    printf("Digite a string: ");
    fgets(string, 50, stdin);

    printf("Saida invertida: ");

    for (int i=strlen(string)-2; i>=0; i--){ // -2 para tirar o \0 e a diferenca do indice e do tamanho do vetor
        printf("%c", string[i]);
    }

    printf("\n");

    return 0;
}
