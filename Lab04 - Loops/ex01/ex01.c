#include <stdio.h>

int main(){
    
    printf("<< Contador de 10 a 0 >>\n");
    int contador = 10;
    
    while (contador >= 0){
        
        printf("%d...\n",contador);
        contador--;
    }

    printf("FIM!\n");

    return 0;
}
