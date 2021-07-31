#include <stdio.h>

int main(){
    
    printf("<< Compara nomes >>\n");

    char nome1[50]={}, nome2[50]={};
    int diferentes=0;

    printf("Digite o nome 1: ");
    for (int i=0; nome1[i-1]!='\n'; i++){
        nome1[i]=getchar();
    }

    printf("Digite o nome 2: ");
    for (int i=0; nome2[i-1]!='\n'; i++){
        nome2[i]=getchar();
    }

    for (int i=0; nome1[i-1]!='\n'; i++){
        if (nome1[i]!=nome2[i]) diferentes=1;
    }

    if (diferentes==1) printf("Os nomes digitados são diferentes\n");
    else printf("Os nomes digitados são iguais\n");

    return 0;
}
