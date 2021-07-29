#include <stdio.h>

int main(){
    printf("<< Probabilidades >>\n");

    int bola[4];
    double total, prob[4];

    printf("Digite a quantidade de bolinhas\n");
    printf("Verde: ");
    scanf("%d", &bola[0]);
    printf("Azul: ");
    scanf("%d", &bola[1]);
    printf("Amarela: ");
    scanf("%d", &bola[2]);
    printf("Vermelha: ");
    scanf("%d", &bola[3]);

    total=bola[0]+bola[1]+bola[2]+bola[3];

    printf("\nProbabilidades\n");

    for (int i=0; i<4; i++){
        prob[i]=(bola[i]/total)*100;
    }

    printf("\nVerde: %.1lf", prob[0]);
    if (prob[0]>prob[1] && prob[0]>prob[2] && prob[0]>prob[3]) printf(" << Maior probabilidade");
    printf("\nAzul: %.1lf", prob[1]);
    if (prob[1]>prob[0] && prob[1]>prob[2] && prob[1]>prob[3]) printf(" << Maior probabilidade");
    printf("\nAmarela: %.1lf", prob[2]);
    if (prob[2]>prob[1] && prob[2]>prob[0] && prob[2]>prob[3]) printf(" << Maior probabilidade");
    printf("\nVermelha: %.1lf", prob[3]);
    if (prob[3]>prob[1] && prob[3]>prob[2] && prob[3]>prob[0]) printf(" << Maior probabilidade");

    printf("\n");

    return 0;
}

/*
Uma piscina de bolinhas possui bolas azuis, verdes, amarelas e vermelhas. 
Faça um programa em que o usuário digita a quantidade de bolinhas de cada
cor existente em uma piscina e mostra a probabilidade de ocorrência de cada 
cor, indicando qual possui a maior probabilidade

Exemplo de saída:
<< Probabilidades >>

Digite a quantidade de bolinhas
Verde: 51
Azul: 60
Amarela: 70
Vermelha: 80

Probabilidades
Verde: 19.5%
Azul: 22.9%
Amarela: 26.8%
Vermelha: 30.6% << Maior probabilidade
*/