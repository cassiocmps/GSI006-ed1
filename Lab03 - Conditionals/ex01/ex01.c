#include <stdio.h>

int main(){
    float nota1, nota2, nota3, media;
    char inicial;

    printf("<< Calculo da Media >>\n");

    printf("Digite o nome do aluno: ");
    inicial = getchar();

    printf("Digite a nota da prova 1: ");
    scanf("%f", &nota1);
    printf("Digite a nota da prova 2: ");
    scanf("%f", &nota2);
    printf("Digite a nota da prova 3: ");
    scanf("%f", &nota3);

    media = (nota1*1+nota2*1+nota3*2)/4;
    printf("A nota media do aluno %c eh %.1f ", inicial, media);
    if (media>=60) printf(" => APROVADO!\n");
    if (media<60) printf(" => REPROVADO\n");
    return 0;
}