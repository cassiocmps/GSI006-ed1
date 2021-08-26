#include <stdio.h>
#include <stdlib.h>
#include "cad.h"

int main () {
    int n;
    aluno *a;

    printf("Digite quantos alunos deseja cadastrar: \n");
    scanf("%d", &n);
    a = (aluno *) malloc(n*sizeof(aluno));

    for (int i=0; i<n; i++){
        printf("\n=== Aluno %d ===\n", i+1);
        cadastraAluno(n, &a[i]);
        printf("\n");
    }
    
    printf("\n--- Alunos cadastrados ---\n");
    for (int i=0; i<n; i++){
        printf("Nome: %s", a[i].nome);
        printf("Matricula: %s", a[i].matricula);
        printf("CRA: %.2f\n\n", a[i].cra);
    }

    free(a);
    return 0;
    
}
