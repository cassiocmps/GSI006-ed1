#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "TStack.h"

int main(){
    struct aluno al[5], test;
    TStack *st = stack_create();

    al[3].matricula = 10;
    strcpy(al[3].nome, "cassio");
    al[3].n1 = 7;
    al[3].n2 = 7;
    al[3].n3 = 7;

    al[2].matricula = 20;
    strcpy(al[2].nome, "joao");
    al[2].n1 = 8;
    al[2].n2 = 8;
    al[2].n3 = 8;

    al[0].matricula = 30;
    strcpy(al[0].nome, "gustavo");
    al[0].n1 = 9;
    al[0].n2 = 9;
    al[0].n3 = 9;

    al[1].matricula = 40;
    strcpy(al[1].nome, "lucas");
    al[1].n1 = 6;
    al[1].n2 = 6;
    al[1].n3 = 6;

    al[4].matricula = 50;
    strcpy(al[4].nome, "bruno");
    al[4].n1 = 6.5;
    al[4].n2 = 6.5;
    al[4].n3 = 6.5;

    printf("\npilha vazia: %d\n", stack_empty(st));

    for (int i=0; i<5; i++){
        printf("\nPUSHING #%d", i+1);
        stack_push(st, al[i]);
        stack_top(st, &test);
        printf("\nMatricula: %d", test.matricula);
        printf("\nNome: %s", test.nome);
        printf("\nNotas: %.1f;%.1f;%.1f\n", test.n1, test.n2, test.n3);
        printf("pilha vazia: %d\n", stack_empty(st));
        // printf("pilha cheia: %d\n\n", stack_full(st));
    }

    stack_print(st);

    for (int i=0; i<5; i++){
        printf("\npilha vazia: %d\n", stack_empty(st));
        // printf("pilha cheia: %d", stack_full(st));
        stack_top(st, &test);
        printf("\nPOPING #%d", i+1);
        printf("\nMatricula: %d", test.matricula);
        printf("\nNome: %s", test.nome);
        printf("\nNotas: %.1f;%.1f;%.1f\n", test.n1, test.n2, test.n3);
        
        stack_pop(st);
    }

    printf("\npilha vazia: %d\n", stack_empty(st));

    stack_free;
    return 0;
}
