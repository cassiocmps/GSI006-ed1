#include <stdio.h>

int main(){
    
    printf("<< Contador de 10 a 0 >>\n");
    int contador = 10;
    
    do {        
        printf("%d...\n",contador);
        contador--;
    } while (contador >= 0);

    printf("FIM!\n");

    return 0;
}
