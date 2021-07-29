#include <stdio.h>

int main(){
    
    printf("<< Contador de 10 a 0 >>\n");
        
    for (int contador=10; contador>=0; contador--) {        
        printf("%d...\n",contador);        
    }

    printf("FIM!\n");

    return 0;
}
