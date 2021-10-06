#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "TStack.h"

int main(){
    TStack *st;
    char nome[6]="cassio", test;
    st = stack_create(5);

    printf("\npilha vazia: %d\n", stack_empty(st));
    printf("\npilha cheia: %d\n", stack_full(st));

    for (int i=0; i<6; i++){
        printf("\nPUSHING #%d", i+1);
        stack_push(st, nome[i]);
        stack_top(st, &test);
        printf("\n%c PUSHED. ", nome[i]);
        printf("pilha cheia: %d / ", stack_full(st));
        printf("pilha vazia: %d", stack_empty(st));
    }

    stack_print(st);

    for (int i=0; i<6; i++){
        test = '@';
        stack_top(st, &test);
        printf("\nPOPING #%c", test);
        stack_pop(st);
        printf("\npilha cheia: %d / ", stack_full(st));
        printf("pilha vazia: %d", stack_empty(st));
    }

    printf("\npilha vazia: %d\n", stack_empty(st));

    stack_free;
    return 0;
}
