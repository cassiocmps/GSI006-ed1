#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    printf("<< Palindromo >>\n");

    char string[50], inverso[50];
    int diferentes;
    
    printf("Digite a string: ");
    fgets(string, 50, stdin);

    for(int i = 0; i<strlen(string)-1; i++){
        string[i] = toupper(string[i]);
    }
    printf("upper: %s", string);

    for (int i=strlen(string)-2, j=0; i>=0; i--, j++){ // -2 para tirar o \0 e a diferenca do indice e do tamanho do vetor
        inverso[j]=string[i];
        // inverso[j+1]=string[strlen(string)-1];
        inverso[j+1]='\0';
    }
    printf("inverso: %s", inverso);

    diferentes=strcmp(string, inverso);

    printf("\ndiferentes: %d\n", diferentes);

    if (diferentes==0) printf("Eh um palindromo");
    else printf("Nao eh um palindromo");

    printf("\n");

    return 0;
    a
}
