#include <stdio.h>

int main(){
    
    printf("<< Contador regressivo >>\n");

    int contador;
    printf("Qual eh o numero inicial? ");
    scanf("%d", &contador);
    
    while (contador >= 0){        
        printf("%d...\n",contador);
        contador--;
    }

    printf("FIM!\n");

    return 0;
}
