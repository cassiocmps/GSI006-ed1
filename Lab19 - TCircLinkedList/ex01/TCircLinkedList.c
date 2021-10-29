#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include "TCircLinkedList.h"

typedef struct cl_node cl_node;

struct TCircLinkedList {
    cl_node *end;
};

struct cl_node {
    struct aluno data;
    cl_node *next;
};

TCircLinkedList *circlist_create(){
    TCircLinkedList *list;
    list = malloc(sizeof(TCircLinkedList));
    if (list != NULL){
        list->end = NULL;
    }
    return list;
}

int circlist_push_front(TCircLinkedList *list, struct aluno al){
    if (list == NULL){
        return INVALID_NULL_POINTER;
    }
    
    cl_node *new_node;
    new_node = malloc(sizeof(cl_node));
    if (new_node == NULL){
        return OUT_OF_MEMORY;
    }
    new_node->data = al;

    if (list->end == NULL) {
        list->end = new_node;
        list->end->next = list->end;
        return SUCCESS;
    } else {
        new_node->next = list->end->next;
        list->end->next = new_node;
        return SUCCESS;
    }
}

int circlist_push_back(TCircLinkedList *list, struct aluno al){
    if (list == NULL){
        return INVALID_NULL_POINTER;
    }
    
    cl_node *new_node;
    new_node = malloc(sizeof(cl_node));
    if (new_node == NULL){
        return OUT_OF_MEMORY;
    }
    new_node->data = al;

    if (list->end == NULL) {
        list->end = new_node;
        list->end->next = list->end;
        return SUCCESS;
    } else {
        new_node->next = list->end->next;
        list->end->next = new_node;
        list->end = new_node;
        return SUCCESS;
    }
}

int circlist_size(TCircLinkedList *list){
    if (list == NULL){
        return INVALID_NULL_POINTER;
    }
    int counter = 0;
    if (list->end == NULL){
        return counter;
    }
    cl_node *aux, *verification;
    aux = list->end->next;
    verification = list->end->next;
    
    do {
        counter++;
        aux = aux->next;
    } while (aux != verification);
    return counter;
}

int circlist_front(TCircLinkedList *list, struct aluno *al){
    if (list == NULL){
        return INVALID_NULL_POINTER;
    }
    if (list->end == NULL){
        return ELEM_NOT_FOUND;
    }
    *al = list->end->next->data;
    return SUCCESS;
}

int circlist_back(TCircLinkedList *list, struct aluno *al){
    if (list == NULL){
        return INVALID_NULL_POINTER;
    }
    if (list->end == NULL){
        return ELEM_NOT_FOUND;
    }
    *al = list->end->data;
    return SUCCESS;
}

int circlist_pop_front(TCircLinkedList *list){
    if (list == NULL){
        return INVALID_NULL_POINTER;
    }
    if (list->end == NULL){
        return ELEM_NOT_FOUND;
    }
    if (list->end == list->end->next){
        free(list->end);
        list->end = NULL;
        return SUCCESS;
    }
    cl_node *aux;
    aux = list->end->next;
    list->end->next = list->end->next->next;
    free(aux);
    return SUCCESS;
}

int circlist_pop_back(TCircLinkedList *list){
    if (list == NULL){
        return INVALID_NULL_POINTER;
    }
    if (list->end == NULL){
        return ELEM_NOT_FOUND;
    }
    if (list->end == list->end->next){
        free(list->end);
        list->end = NULL;
        return SUCCESS;
    }
    cl_node *aux;
    cl_node *previous = NULL;
    cl_node *current = list->end->next;
    
    while (current->next != list->end){
        previous = current;
        current = current->next;
    }
    aux = list->end;
    current->next = aux->next;
    list->end = current;
    free(aux);
    return SUCCESS;
}

int circlist_find_pos(TCircLinkedList *list, int pos, struct aluno *al){
    if (list == NULL){
        return INVALID_NULL_POINTER;
    }
    if (list->end == NULL){
        return ELEM_NOT_FOUND;
    }
    if (pos <=0 || pos > circlist_size(list)){
        return ELEM_NOT_FOUND;
    }
    
    cl_node *aux = list->end->next;
    for (int i=1; i<pos; i++){
        aux = aux->next;
    }
    *al = aux->data;
    return SUCCESS;
}

int circlist_find_mat(TCircLinkedList *list, int mat, struct aluno *al){
    if (list == NULL){
        return INVALID_NULL_POINTER;
    }
    if (list->end == NULL){
        return ELEM_NOT_FOUND;
    }

    cl_node *aux = list->end->next;
    while (aux->next != list->end->next && aux->data.matricula != mat){
        aux = aux->next;
    }

    if (aux == list->end){
        if (list->end->data.matricula == mat){
            *al = aux->data;
            return SUCCESS;
        } else {
            return ELEM_NOT_FOUND;
        }
    }else{
        *al = aux->data;
        return SUCCESS;
    }
}

int circlist_get_pos(TCircLinkedList *list, int mat, int *pos){
    if (list == NULL){
        return INVALID_NULL_POINTER;
    }
    if (list->end == NULL){
        return ELEM_NOT_FOUND;
    }

    cl_node *aux = list->end->next;
    int counter = 1;
    while (aux->next != list->end->next && aux->data.matricula != mat){
        aux = aux->next;
        counter++;
    }

    if (aux == list->end){
        if (list->end->data.matricula == mat){
            *pos = counter;
            return SUCCESS;
        } else {
            return ELEM_NOT_FOUND;
        }
    }else{
        *pos = counter;
        return SUCCESS;
    }
}

int circlist_erase_pos(TCircLinkedList *list, int pos){
    if (list == NULL){
        return INVALID_NULL_POINTER;
    }
    if (list->end == NULL){
        return ELEM_NOT_FOUND;
    }
    if (pos <=0 || pos > circlist_size(list)){
        return ELEM_NOT_FOUND;
    }
    
    cl_node *current, *previous;
    current = list->end->next;
    previous = NULL;

    if (pos == 1){
        circlist_pop_front(list);
    }
    else{
        for (int i=1; i<pos; i++){
            previous = current;
            current = current->next;
        }
        if (current == list->end){
            circlist_pop_back(list);
            return SUCCESS;
        }
        previous->next = current->next;
        free(current);
    }

    return SUCCESS;
}

int circlist_erase_data(TCircLinkedList *list, int mat){
    if (list == NULL){
        return INVALID_NULL_POINTER;
    }
    if (list->end == NULL){
        return ELEM_NOT_FOUND;
    }

    cl_node *aux;
    cl_node *previous = list->end;
    cl_node *current = list->end->next;
    
    while (current->next != list->end->next && current->data.matricula != mat){
        previous = current;
        current = current->next;
    }
    
    if (current == list->end){
        if (list->end->data.matricula == mat){
            circlist_pop_back(list);
            return SUCCESS;
        } else {
            return ELEM_NOT_FOUND;
        }
    }else{
        aux = current;
        previous->next = current->next;
        free(aux);
        return SUCCESS;
    }
}

int circlist_insert(TCircLinkedList *list, int pos, struct aluno al){
    if (list == NULL){
        return INVALID_NULL_POINTER;
    }
    int list_size = circlist_size(list);
    if (pos <= 0 || pos>list_size+1){
        return OUT_OF_RANGE;
    }

    if (pos == list_size+1){
        circlist_push_back(list, al);
        return SUCCESS;
    }
    cl_node *node;
    node = malloc(sizeof(cl_node));
    if (node == NULL){
        return OUT_OF_MEMORY;
    }    
    node->data = al;
    
    cl_node *current, *previous;
    current = list->end->next;
    previous = list->end;

    for (int i=1; i<pos; i++){
        previous = current;
        current = current->next;
    }

    if (previous == list->end){
        node->next = list->end->next;
        list->end->next = node;
    } else {
        previous->next = node;
        node->next = current;
    }

    return SUCCESS;
}

int circlist_print(TCircLinkedList *list){
    if (list == NULL){
        return INVALID_NULL_POINTER;
    }
    if (list->end == NULL){
        printf("\nEMPTY LIST.\n");
        return SUCCESS;
    }
    cl_node *aux, *verification;
    aux = list->end->next;
    verification = list->end->next;
    
    printf ("\n--- Printing list ---\n");
    do {
        printf("\n------------------------\n");
        printf("Id: %d\n", aux->data.matricula);
        printf("Name: %s\n", aux->data.nome);
        printf("Grades: %.1f; %.1f; %.1f.\n", aux->data.n1, aux->data.n2, aux->data.n3);
        aux = aux->next;
    } while (aux != verification);
    printf ("\n--- End of the list ---\n");
    return SUCCESS;
}

int circlist_free(TCircLinkedList *list){
    if (list == NULL){
        return INVALID_NULL_POINTER;
    }
    if (list->end == NULL){
        free(list->end);
        free(list);
        return SUCCESS;
    }
    
    cl_node *aux, *verification;
    verification = list->end;
    aux = list->end;

    int counter=0;
    do {
        list->end = aux->next;
        free(aux);
        aux = list->end;
        counter++;
    } while (aux != verification);
    free(list);
    return SUCCESS;
}
