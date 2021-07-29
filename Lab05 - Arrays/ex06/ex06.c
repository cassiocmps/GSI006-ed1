#include <stdio.h>

int main(){
    printf("<< Five Values with index >>\n");

        int num[5], maior, menor, indexMaior, indexMenor;
    float media, total=0;

    for (int i=0; i<5; i++){
        
        printf("Input #%d: ", i+1);
        scanf("%d", &num[i]);
        
        if (i==0) {
            maior=num[i];
            indexMaior=i;
            menor=num[i];
            indexMenor=i;
        }

        if (num[i]>maior) {
            maior=num[i];
            indexMaior=i;
        }
        if (num[i]<menor) {
            menor=num[i];
            indexMenor=i;
        }

        total+=num[i];

    }

    media=total/5;

    printf("Valores lidos: ");
    for (int i=0; i<5; i++){ printf(" %d", num[i]);}
    printf("\n");

    printf("Max. Value: %d, index %d of the array\n", maior, indexMaior);
    printf("Min. Value: %d index %d of the array\n", menor, indexMenor);
    printf("Mean: %.2f\n", media);

    return 0;
}

/*
Fazer um programa para ler 5 valores, e, em seguida, mostrar todos os valores
lidos juntamente com o maior (Max), o menor (Min) e a média (Mean) dos valores
Mostrar o índice (index) do vetor associado ao maior número e ao menor número 

Exemplo de saída:
<< Five Values with index >>
Input #1: 5
Input #2: 6
Input #3: 4
Input #4: 0
Input #5: 3

The numbers entered are: 5 6 4 0 3
Max. Value: 6, index 1 of the array
Min. Value: 0, index 3 of the array
Mean: 3.6
*/