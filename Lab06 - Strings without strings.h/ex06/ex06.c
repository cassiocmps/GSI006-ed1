#include <stdio.h>

int main(){
    
    printf("<< Nomes >>\n");

    char completo[40], nome[40], sobrenome[40], j;

    printf("Digite o primeiro nome e último nome: ");

    for (int i=0; completo[i-1]!='\n'; i++){
        completo[i]=getchar();
    }

    printf("nome completo: ");

    for (int i=0; completo[i-1]!='\n'; i++){
        printf("%c", completo[i]);
    }

    printf("Nome: ");
    for (int i=0; completo[i]!=32; i++){
        nome[i]=completo[i];
        nome[i+1]=10;
        j=i+2;
    }
    
    for (int i=0; nome[i-1]!='\n'; i++){
        printf("%c", nome[i]);
    }

    printf("Sobrenome: ");
    for (int i=0; completo[j]!='\n'; i++, j++){
        sobrenome[i]=completo[j];
        sobrenome[i+1]=10;
    }
    
    for (int i=0; sobrenome[i-1]!='\n'; i++){
        printf("%c", sobrenome[i]);
    }

    return 0;
}
