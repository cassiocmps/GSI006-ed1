#include <stdio.h>

int main(){
    
    printf("<< Vetor de char >>\n");

    char nome[50];

    printf("Digite um nome: ");

    for (int i=0; nome[i-1]!='\n'; i++){
        nome[i]=getchar();
    }

    printf("O nome digitado eh: ");

    for (int i=0; nome[i-1]!='\n'; i++){
        if (nome[i]>96){
            printf("%c", nome[i]-32);
        }
        else printf("%c", nome[i]);
    }

    return 0;
}
