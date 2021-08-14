#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    printf("<< Sem vogais >>\n");

    char string[50];
    
    printf("Digite a string: ");
    fgets(string, 50, stdin);

    printf("Saida sem vogais: ");

    for (int i=0; string[i]!='\n'; i++){
        if (string[i]=='A' || string[i]=='E' || string[i]=='I' || string[i]=='O' || string[i]=='U' ||
            string[i]=='a' || string[i]=='e' || string[i]=='i' || string[i]=='o' || string[i]=='u' ) {}
        else printf("%c", string[i]);
    }

    printf("\n");

    return 0;
}
