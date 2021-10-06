#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "TStack.h"

struct TStack{
    int qtd, size;
    char *symbols;
};


TStack *stack_create(int size){
    TStack *st;
    st = malloc(sizeof(struct TStack));
    
    if (st != NULL){
        st->symbols = malloc (sizeof(char)*size);
        st->qtd = 0;
        st->size = size;
    }

    return st;
}

int stack_free(TStack *st){
    if (st == NULL){
        return INVALID_NULL_POINTER;
    }
    free(st->symbols);
    free(st);
    return SUCCESS;
}

int stack_push(TStack *st, char symbol){
    if (st == NULL){
        return INVALID_NULL_POINTER;
    }
    
    if (st->qtd == st->size){
        return OUT_OF_MEMORY;
    }

    st->symbols[st->qtd] = symbol;
    st->qtd++;
    return SUCCESS;

}

int stack_pop(TStack *st){
    if (st == NULL){
        return INVALID_NULL_POINTER;
    }
    if(st->qtd == 0){
        return ELEM_NOT_FOUND;
    }
    st->qtd--;
    return SUCCESS;
}

int stack_top(TStack *st, char *symbol){
    if (st == NULL){
        return INVALID_NULL_POINTER;
    }
    if(st->qtd == 0){
        return ELEM_NOT_FOUND;
    }
    *symbol = st->symbols[st->qtd-1];
    return SUCCESS;
}

int stack_empty(TStack *st){
    if (st == NULL){
        return INVALID_NULL_POINTER;
    }
    return (st->qtd == 0);
}

int stack_full(TStack *st){
    if (st == NULL){
        return INVALID_NULL_POINTER;
    }
    return (st->qtd == st->size);
}

int stack_print(TStack *st){
    if (st == NULL){
        return INVALID_NULL_POINTER;
    }
    if (st->qtd == 0){
        printf("\n--- EMPTY STACK ---\n");
    }else {
        printf("\nPRINTING STACK...\n");
        for (int i=0; i< st->qtd; i++){
            printf("\n%c", st->symbols[i]);
        }
        printf("\nEND OF STACK.\n");    
    }
    return SUCCESS;
}

int well_formed(char *string){
    TStack *st;
    st = stack_create(strlen(string));
    char c;

    for (int i = 0; string[i] != '\0'; ++i) {
        switch (string[i]) {
            case ')': if (stack_empty(st) == 1) return 0;
                stack_top(st, &c);
                if (c == '(') {
                    stack_pop(st);
                    break;
                }else {
                    return 0;
                    break;
                }
            case ']': if (stack_empty(st) == 1) return 0;
                stack_top(st, &c);
                if (c == '[') {
                    stack_pop(st);
                    break;
                }else {
                    return 0;
                    break;
                }
            default: stack_push(st, string[i]);
        }
    }
    int empty = (stack_empty(st));
    stack_free(st);
    return empty;
}
