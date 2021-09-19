#include <stdio.h>
#include "TVarSeqList.h"
#include <string.h>

int main() {
    
    int t;
    scanf("%d", &t);

    Lista* alunos = cria_lista(t - 1);

    int matricula;
    char nome[30];
    float n1, n2, n3;

    struct aluno aluno;
    
    for (int i=0; i<t; i++){
        
        printf("Dados do alunos:");
        scanf("%d", &matricula);
        getchar();
        // fgets(nome, 30, stdin);
        if(fgets(nome, 30, stdin) == NULL) {
        } else nome[strcspn(nome, "\n")] = '\0';
        
        scanf("%f", &n1);
        scanf("%f", &n2);
        scanf("%f", &n3);

        aluno.matricula = matricula;
        strcpy(aluno.nome, nome);
        aluno.n1 = n1;
        aluno.n2 = n2;
        aluno.n3 = n3;

        insere_lista_final(alunos, aluno);
                
    }

    // struct aluno a;
    // consulta_lista_pos(alunos,1,&a);
    // printf("\nm: %d ", a.matricula);
    // printf("nome: %s ", a.nome);
    // printf("n1: %.1f ", a.n1);
    // printf("n2: %.1f ", a.n2);
    // printf("n3: %.1f ", a.n3);

    // consulta_lista_pos(alunos,2,&a);
    // printf("\nm: %d ", a.matricula);
    // printf("nome: %s ", a.nome);
    // printf("n1: %.1f ", a.n1);
    // printf("n2: %.1f ", a.n2);
    // printf("n3: %.1f ", a.n3);

    // consulta_lista_pos(alunos,3,&a);
    // printf("\nm: %d ", a.matricula);
    // printf("nome: %s ", a.nome);
    // printf("n1: %.1f ", a.n1);
    // printf("n2: %.1f ", a.n2);
    // printf("n3: %.1f ", a.n3);

    printf("\nLista de alunos salvos:\n");
    imprime_lista(alunos);

    printf("\ntam_max: %d\n", tamanho_max_lista(alunos));
    printf("\nqtd: %d\n", tamanho_lista(alunos));

    libera_lista(alunos);
    return 0;
}