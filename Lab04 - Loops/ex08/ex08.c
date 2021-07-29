#include <stdio.h>

int main(){
    
    printf("<< Contagem progressiva até zero >>\n");

    int contador;
    printf("Qual eh o numero inicial? ");
    scanf("%d", &contador);
    
    do {        
        printf("%d...\n",contador);
        contador++;
    } while (contador <= 0);

    printf("FIM!\n");

    return 0;
}
