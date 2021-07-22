#include <stdio.h>

int main() {
    int nota[4];
    
    printf("<< Media Aritmetica >>\n");
    for (int i=0; i<4; i++){
        printf("Digite a %da nota: ", i+1);
        scanf("%d", &nota[i]);
    }

    printf("===Notas===\n");
    for (int i=0; i<4; i++){
        printf("Nota %d: %d; ", i+1, nota[i]);
    }

    printf("\nMedia: %d\n", (nota[0]+nota[1]+nota[2]+nota[3])/4);
    return 0;
}
