#include <stdlib.h>
#include <stdio.h>
#include "TStack.h"
#include "TSeqList.h"



// é possível criar a lista
struct TStack{
    TSeqList *list;
};


TStack *stack_create(){
    TStack *st;
    st = malloc(sizeof(TStack));
    if (st != NULL){
        st->list = cria_lista();
        if (st->list == NULL){
            free(st);
            return NULL;
        }
    }
    return st;
}

int stack_free(TStack *st)
{
    if (st == NULL){
        return INVALID_NULL_POINTER;
    }
    libera_lista(st->list);
    free(st);
    return 0;
}

int stack_push(TStack *st, struct aluno al)
{
    if (st == NULL){
        return INVALID_NULL_POINTER;
    }
    return insere_lista_final(st->list, al);

}

int stack_pop(TStack *st)
{
    if (st == NULL){
        return INVALID_NULL_POINTER;
    }
    return remove_lista_final(st->list);
}

int stack_top(TStack *st, struct aluno *al)
{
    if (st == NULL){
        return INVALID_NULL_POINTER;
    }
    int last_pos=(tamanho_lista(st->list)-1);
    return consulta_lista_pos(st->list, last_pos, al);
}

int stack_empty(TStack *st)
{
    if (st == NULL){
        return INVALID_NULL_POINTER;
    }
    return lista_vazia(st->list);
}

int stack_full(TStack *st)
{
    if (st == NULL){
        return INVALID_NULL_POINTER;
    }
    return lista_cheia(st->list);
}

int stack_print(TStack *st)
{
    if (st == NULL){
        return INVALID_NULL_POINTER;
    }

    printf("\nPRINTING STACK...\n");
    imprime_lista(st->list);
    printf("\nEND OF STACK.\n");
    return 0;
}

