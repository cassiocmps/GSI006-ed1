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
    printf("A nota media do aluno %c eh %.1f\n", inicial, media);
    return 0;
}

/*
=> Faça um algoritmo que calcule a média ponderada das notas de 3 provas. 
A primeira e a segunda prova têm peso 1 e a terceira tem peso 2. Antes de o usuário 
entrar com as notas do aluno ele deve informar a letra inicial do nome do aluno. 
Ao final, mostrar o a letra inicial do nome do aluno juntamente com a sua média.

-------------------------------------------------------------------------------
Exemplo de saída:

<< Calculo da Media >>
Digite o nome do aluno: T
Digite a nota da prova 1: 40
Digite a nota da prova 2: 40
Digite a nota da prova 3: 80
A nota media do aluno C. eh 60
-------------------------------------------------------------------------------
*/