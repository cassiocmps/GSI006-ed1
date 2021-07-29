#include <stdio.h>

int main(){
    
    char correta='q', resposta='a';

    printf("<< Forca de uma letra só >>\n");

    for (int i=5; i>0; i--){
        printf("Qual a letra? ");
        scanf(" %c", &resposta);

        if (resposta==correta){
            printf("ACERTOU!\n");
            break;
        }
        else printf("Errado. Voce tem mais %d chances\n", i-1);
    }

    return 0;
}
