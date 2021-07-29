#include <stdio.h>

int main(){
    printf("<< Five Values >>\n");

    int num[5], maior, menor;
    float media, total=0;

    for (int i=0; i<5; i++){
        
        printf("Input #%d: ", i+1);
        scanf("%d", &num[i]);
        
        if (i==0) {
            maior=num[i];
            menor=num[i];
        }

        if (num[i]>maior) maior=num[i];
        if (num[i]<menor) menor=num[i];

        total+=num[i];

    }

    media=total/5;

    printf("Valores lidos: ");
    for (int i=0; i<5; i++){ printf(" %d", num[i]);}
    printf("\n");

    printf("Max. Value: %d\n", maior);
    printf("Min. Value: %d\n", menor);
    printf("Mean: %.2f\n", media);

    return 0;
}


/*
Fazer um programa para ler 5 valores, e, em seguida, mostrar todos os valores
lidos juntamente com o maior (Max), o menor (Min) e a média (Mean) dos valores

Exemplo de saída:
<< Five Values >>
Input #1: 5
Input #2: 6
Input #3: 4
Input #4: 0
Input #5: 3

The numbers entered are: 5 6 4 0 3
Max. Value: 6
Min. Value: 0
Mean: 3.6
*/