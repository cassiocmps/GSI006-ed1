#include <stdlib.h>
#include <stdio.h>
#include "TDLinkedList.h"

typedef struct DLNode DLNode;

struct TDLinkedList {
    DLNode *begin;
    DLNode *end;
    int size;
};

struct DLNode {
    struct student data;
    DLNode *next;
    DLNode *prev;
};

TDLinkedList *list_create(){
    TDLinkedList *list;
    list = malloc(sizeof(TDLinkedList));
    if (list != NULL){
        list->begin = NULL;
        list->end = NULL;
        list->size = 0;
    }
    return list;
}

int list_free(TDLinkedList *list){
    if (list == NULL){
        return INVALID_NULL_POINTER;
    }
    DLNode *aux;
    aux = list->begin;

    while (aux != NULL){
        list->begin = aux->next;
        free(aux);
        aux = list->begin;
    }
    free(list);
    return SUCCESS;
}

int list_push_front(TDLinkedList *list, struct student st){
    if (list == NULL){
        return INVALID_NULL_POINTER;
    }
    DLNode *node;
    node = malloc(sizeof(DLNode));
    if (node == NULL){
        return OUT_OF_MEMORY;
    }
    
    node->data = st;
    node->prev = NULL;
    if (list->begin == NULL){
        node->next = NULL;
        list->begin = node;
        list->end = node;
    } else {
        node->next = list->begin;
        list->begin->prev = node;
        list->begin = node;
    }
    list->size = list->size + 1;
    return SUCCESS;
}

int list_push_back(TDLinkedList *list, struct student st){
    if (list == NULL){
        return INVALID_NULL_POINTER;
    }
    DLNode *node;
    node = malloc(sizeof(DLNode));
    if (node == NULL){
        return OUT_OF_MEMORY;
    }
    
    node->data = st;
    node->next = NULL;
    if (list->begin == NULL){
        node->next = NULL;
        list->begin = node;
        list->end = node;
    } else {
        node->prev = list->end;
        list->end->next = node;
        list->end = node;
    }
    list->size = list->size + 1;
    return SUCCESS;
}

int list_insert(TDLinkedList *list, int pos, struct student st){
    if (list == NULL){
        return INVALID_NULL_POINTER;
    }
    // if (list->begin == NULL){
    //     return ELEM_NOT_FOUND;
    // }
    if (pos <=0 || pos > (list->size+1)){
        return ELEM_NOT_FOUND;
    }
    DLNode *node;
    node = malloc(sizeof(DLNode));
    if (node == NULL){
        return OUT_OF_MEMORY;
    }
    node->data = st;

    if (pos == 1){ // insert at the begining
        if (list->begin == NULL){ // empty list
            node->prev = NULL;
            node->next = NULL;
            list->begin = node;
            list->end = node;
            list->size++;
            return SUCCESS; 
        }else { // non-empty list
        node->prev = NULL;
        node->next = list->begin;
        list->begin->prev = node;
        list->begin = node;
        list->size++;
        return SUCCESS;
        }
    }

    if (pos == (list->size+1)){ // insert at the end
        node->next = NULL;
        node->prev = list->end;
        list->end->next = node;
        list->end = node;
        list->size++;
        return SUCCESS;
    }

    DLNode *aux;
    if (pos < (list->size/2)){
        aux = list->begin;
        for (int i=1; i<pos; i++){
            aux = aux->next;
        }
    } else {
        aux = list->end;
        for (int i=list->size; i>pos; i--){
            aux = aux->prev;
        }
    }
    
    node->next = aux;
    node->prev = aux->prev;
    aux->prev->next = node;
    aux->prev = node;

    list->size++;
    return SUCCESS;
}

int list_size(TDLinkedList *list){
    if (list == NULL){
        return INVALID_NULL_POINTER;
    }
    return list->size;
}

int list_pop_front(TDLinkedList *list){
    if (list == NULL){
        return INVALID_NULL_POINTER;
    }
    if (list->begin == NULL){
        return ELEM_NOT_FOUND;
    }
    
    DLNode *aux = list->begin;
    if (list->size == 1){
        list->begin = NULL;
        list->end = NULL;
    }else{
        list->begin = list->begin->next;
        list->begin->prev = NULL;
    }
    list->size--;
    free(aux);
    return SUCCESS;
}

int list_pop_back(TDLinkedList *list){
    if (list == NULL){
        return INVALID_NULL_POINTER;
    }
    if (list->begin == NULL){
        return ELEM_NOT_FOUND;
    }
    
    DLNode *aux = list->end;
    if (list->size == 1){
        list->begin = NULL;
        list->end = NULL;
    }else{
        list->end = list->end->prev;
        list->end->next = NULL;
    }
    list->size--;
    free(aux);
    return SUCCESS;
}

int list_erase(TDLinkedList *list, int pos){
    if (list == NULL){
        return INVALID_NULL_POINTER;
    }
    if (list->begin == NULL){
        return ELEM_NOT_FOUND;
    }
    if (pos <=0 || pos > list->size){
        return ELEM_NOT_FOUND;
    }
    DLNode *aux;
    
    if (pos < (list->size/2)){
        aux = list->begin;
        for (int i=1; i<pos; i++){
            aux = aux->next;
        }
    } else {
        aux = list->end;
        for (int i=list->size; i>pos; i--){
            aux = aux->prev;
        }
    }
    
    if  (aux->next == NULL && aux->prev == NULL){ // only one node
        list->begin = NULL;
        list->end = NULL;
    } else 
    if (aux->next == NULL){ // last node
        aux->prev->next = NULL;
        list->end = aux->prev;
    } else
    if (aux->prev == NULL){ // first node
        aux->next->prev = NULL;
        list->begin = aux->next;

    } else { // any other
        aux->prev->next = aux->next;
        aux->next->prev = aux->prev;
    }
    list->size--;
    free(aux);
    return SUCCESS;
}

int list_find_pos(TDLinkedList *list, int pos, struct student *st){
    if (list == NULL){
        return INVALID_NULL_POINTER;
    }
    if (list->begin == NULL){
        return ELEM_NOT_FOUND;
    }
    if (pos <=0 || pos > list->size){
        return ELEM_NOT_FOUND;
    }
    DLNode *aux;
    
    if (pos < (list->size/2)){
        aux = list->begin;
        for (int i=1; i<pos; i++){
            aux = aux->next;
        }
    } else {
        aux = list->end;
        for (int i=list->size; i>pos; i--){
            aux = aux->prev;
        }
    }

    *st = aux->data;
    return SUCCESS;
}

int list_find_id(TDLinkedList *list, int id, struct student *st){
    if (list == NULL){
        return INVALID_NULL_POINTER;
    }
    if (list->begin == NULL){
        return ELEM_NOT_FOUND;
    }

    DLNode *aux;
    aux = list->begin;

    while (aux != NULL && aux->data.id != id){
        aux = aux->next;
    }
    if (aux == NULL){
        return ELEM_NOT_FOUND;
    }else{
        *st = aux->data;
        return SUCCESS;
    }
}

int list_front(TDLinkedList *list, struct student *st){
    if (list == NULL){
        return INVALID_NULL_POINTER;
    }
    if (list->begin == NULL){
        return ELEM_NOT_FOUND;
    }
    *st = list->begin->data;
    return SUCCESS;
}

int list_back(TDLinkedList *list, struct student *st){
    if (list == NULL){
        return INVALID_NULL_POINTER;
    }
    if (list->end == NULL){
        return ELEM_NOT_FOUND;
    }
    *st = list->end->data;
    return SUCCESS;
}

int list_get_pos(TDLinkedList *list, int id, int *pos){
    if (list == NULL){
        return INVALID_NULL_POINTER;
    }
    if (list->begin == NULL){
        return ELEM_NOT_FOUND;
    }

    DLNode *aux;
    aux = list->begin;
    int count=1;

    while (aux != NULL && aux->data.id != id){
        aux = aux->next;
        count++;
    }
    if (aux == NULL){
        return ELEM_NOT_FOUND;
    }else{
        *pos = count;
        return SUCCESS;
    }
}

int list_print_forward(TDLinkedList *list){
    if (list == NULL){
        return INVALID_NULL_POINTER;
    }
    DLNode *aux;
    aux = list->begin;
    
    printf ("\n--- Printing list forward---\n");
    while (aux != NULL){
        printf("\n------------------------\n");
        printf("Id: %d\n", aux->data.id);
        printf("Name: %s\n", aux->data.name);
        printf("Grades: %.1f; %.1f; %.1f.\n", aux->data.g1, aux->data.g2, aux->data.g3);

        aux = aux->next;
    }
    printf ("\n--- End of the list ---\n");
    return SUCCESS;
}

int list_print_reverse(TDLinkedList *list){
    if (list == NULL){
        return INVALID_NULL_POINTER;
    }
    DLNode *aux;
    aux = list->end;
    
    printf ("\n--- Printing list reverse---\n");
    while (aux != NULL){
        printf("\n------------------------\n");
        printf("Id: %d\n", aux->data.id);
        printf("Name: %s\n", aux->data.name);
        printf("Grades: %.1f; %.1f; %.1f.\n", aux->data.g1, aux->data.g2, aux->data.g3);

        aux = aux->prev;
    }
    printf ("\n--- End of the list ---\n");
    return SUCCESS;
}
