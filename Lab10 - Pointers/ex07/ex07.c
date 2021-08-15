#include <stdio.h>
#include <string.h>

int main(){
    printf("<< Pointers >>\n");

    char nome[] = "José Augusto";

    for (int i=0; i<strlen(nome); i++){
        printf("%c", *(nome+i));
    }


    return 0;
}