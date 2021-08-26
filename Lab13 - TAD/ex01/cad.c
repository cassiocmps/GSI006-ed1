#include <stdio.h>
#include <stdlib.h>
#include <cad.h>

void cadastraAluno(int tamanho, aluno *vetor){
    
    printf("Informe o nome: ");
    getchar();
    fgets(vetor->nome, 50, stdin);
    
    printf("Informe a matricula: ");
    fgets(vetor->matricula, 50, stdin);

    printf("Informe o CRA: ");
    scanf("%lf", &vetor->cra);
}