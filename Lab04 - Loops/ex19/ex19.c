#include <stdio.h>

int main(){
    
    int jose=50000, carlos=25000, i;
        
    for (i=0; jose>carlos; i++, jose+=800, carlos+=3000){
        printf("<< Mes %d >>\n", i);
        printf("Saldo de Jose: %d\n", jose);
        printf("Saldo de Carlos: %d\n\n", carlos);

        // jose+=800;
        // carlos+=3000;
    }

    printf("Levou %d meses para Carlos ter mais dinheiro que Jose.\n", i);
    printf("Saldo de Jose: %d\n", jose);
    printf("Saldo de Carlos: %d\n", carlos);

    return 0;
}
