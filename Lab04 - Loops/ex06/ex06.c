#include <stdio.h>

int main(){
    
    printf("<< Contador regressivo >>\n");

    int contador;
    printf("Qual eh o numero inicial? ");
    scanf("%d", &contador);
    
    for (;contador>=0; contador--) {        
        printf("%d...\n",contador);        
    }

    printf("FIM!\n");

    return 0;
}
