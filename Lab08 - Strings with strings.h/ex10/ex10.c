#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    printf("<< Palindromo >>\n");

    char string[50];
    int tamanho, diferentes=0;
    
    printf("Digite a string: ");
    fgets(string, 50, stdin);

    tamanho=strlen(string)-1; // tamanho é menor que o ultimo indice

    for (int i=0, j=tamanho-1; i<tamanho; i++, j--){ // -1 de novo para tirar a ultimo caracter \0
        printf("%c - %c \n", string[i], string[j]);
        if (string[i]!=string[j]){
            if (string[i]-string[j]==32 || string[i]-string[j]==-32){}
            else diferentes++;
        }
    }

    if (diferentes==0) printf("Eh um palindromo");
    else printf("Nao eh um palindromo");

    printf("\n");

    return 0;
    
    
}
