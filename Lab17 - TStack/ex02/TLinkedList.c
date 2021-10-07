#include <stdio.h>
#include "TLinkedList.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct list_node list_node;

struct TLinkedList {
    list_node *head;
};

struct list_node {
    struct aluno data;
    list_node *next;
};

TLinkedList *list_create(){
    // if (sorted!=0 && sorted!=1){
    //     return NULL;
    // }
    TLinkedList *list;
    list = malloc(sizeof(TLinkedList));
    if (list != NULL){
        list->head = NULL;
    }
    return list;
}

int list_push_front(TLinkedList *list, struct aluno st){
    if (list == NULL){
        return INVALID_NULL_POINTER;
    }
    else{
        list_node *node;
        node = malloc(sizeof(list_node));
        if (node == NULL)
        {
            return OUT_OF_MEMORY;
        }
        node->data = st;
        node->next = list->head;

        list->head = node;
        return SUCCESS;
    }
}

int list_push_back(TLinkedList *list, struct aluno st){
    if (list == NULL){
        return INVALID_NULL_POINTER;
    }else{
        list_node *node;
        node = malloc(sizeof(list_node));
        if (node == NULL){
            return OUT_OF_MEMORY;
        }
        
        node->data = st;
        node->next = NULL;

        if (list->head == NULL){
            list->head = node;
        }
        else {
            list_node *aux;
            aux = list->head;
            while (aux->next != NULL){
                aux = aux->next;
            }
            aux->next = node;
        }
        return SUCCESS;
    }
}

int list_size(TLinkedList *list){
    if (list == NULL){
        return INVALID_NULL_POINTER;
    }
    int counter=0;
    list_node *aux;
    aux = list->head;

    while (aux != NULL){
        counter++;
        aux = aux->next;
    }
    return counter;
}

int list_front(TLinkedList *list, struct aluno *st){
    if (list == NULL){
        return INVALID_NULL_POINTER;
    }
    if (list->head == NULL){
        return ELEM_NOT_FOUND;
    }
    *st = list->head->data;
    return SUCCESS;
}

int list_back(TLinkedList *list, struct aluno *st){
    if (list == NULL){
        return INVALID_NULL_POINTER;
    }
    if (list->head == NULL){
        return ELEM_NOT_FOUND;
    }
    list_node *aux;
    aux = list->head;

    while (aux->next != NULL){
        aux = aux->next;
    }
    *st = aux->data;
    return SUCCESS;
}

int list_pop_front(TLinkedList *list){
    if (list == NULL){
        return INVALID_NULL_POINTER;
    }
    if (list->head == NULL){
        return ELEM_NOT_FOUND;
    }
    list_node *aux = NULL;
    aux = list->head;
    list->head = list->head->next;
    free(aux);
    return SUCCESS;
}

int list_pop_back(TLinkedList *list){
    if (list == NULL){
        return INVALID_NULL_POINTER;
    }
    if (list->head == NULL){
        return ELEM_NOT_FOUND;
    }

    list_node *previous = NULL;
    list_node *current = list->head;
    
    while (current->next != NULL){
            previous = current;
            current = current->next;
        }
    previous->next = NULL;
    free(current);
    return SUCCESS;
}

int list_find_pos(TLinkedList *list, int pos, struct aluno *st){
    if (list == NULL){
        return INVALID_NULL_POINTER;
    }
    if (list->head == NULL){
        return ELEM_NOT_FOUND;
    }
    if (pos <=0 || pos > list_size(list)){
        return ELEM_NOT_FOUND;
    }
    list_node *aux;
    aux = list->head;

    for (int i=1; i<pos; i++){
        aux = aux->next;
    }

    *st = aux->data;
    return SUCCESS;
}

int list_find_id(TLinkedList *list, int id, struct aluno *st){
    if (list == NULL){
        return INVALID_NULL_POINTER;
    }
    if (list->head == NULL){
        return ELEM_NOT_FOUND;
    }

    list_node *aux;
    aux = list->head;

    while (aux != NULL && aux->data.matricula != id){
        aux = aux->next;
    }

    if (aux == NULL){
        return ELEM_NOT_FOUND;
    }else{
        *st = aux->data;
        return SUCCESS;
    }
}

int list_get_pos(TLinkedList *list, int id, int *pos){
    if (list == NULL){
        return INVALID_NULL_POINTER;
    }
    if (list->head == NULL){
        return ELEM_NOT_FOUND;
    }

    list_node *aux;
    aux = list->head;
    int count=1;

    while (aux != NULL && aux->data.matricula != id){
        count++;
        aux = aux->next;
    }

    if (count > list_size(list)){
        return ELEM_NOT_FOUND;
    } else {
        *pos = count;
        return SUCCESS;
    }
}

int list_erase_pos(TLinkedList *list, int pos){
    if (list == NULL){
        return INVALID_NULL_POINTER;
    }
    if (list->head == NULL){
        return ELEM_NOT_FOUND;
    }
    if (pos <=0 || pos > list_size(list)){
        return ELEM_NOT_FOUND;
    }
    
    list_node *current, *previous;
    current = list->head;
    previous = NULL;

    if (pos == 1){
        list->head = list->head->next;
        free(current);
    }
    else{
        for (int i=1; i<pos; i++){
            previous = current;
            current = current->next;
        }
        previous->next = current->next;
        free(current);
    }

    return SUCCESS;
}

int list_erase_data(TLinkedList *list, int id){
    if (list == NULL){
        return INVALID_NULL_POINTER;
    }
    if (list->head == NULL){
        return ELEM_NOT_FOUND;
    }

    list_node *current, *previous;
    current = list->head;
    previous = NULL;

    while (current != NULL && current->data.matricula != id){
        previous = current;
        current = current->next;
    }
    if (previous == NULL){
        list->head = list->head->next;
        free(current);
    }else{
        previous->next = current->next;
        free(current);
    }
    return SUCCESS;
}

int list_insert(TLinkedList *list, int pos, struct aluno st){
    if (list == NULL){
        return INVALID_NULL_POINTER;
    }
    if (pos <= 0 || pos>(list_size(list)+1)){
        return OUT_OF_RANGE;
    }
    
    list_node *node;
    node = malloc(sizeof(list_node));
    if (node == NULL){
        return OUT_OF_MEMORY;
    }    
    node->data = st;
    
    list_node *current, *previous;
    current = list->head;
    previous = NULL;

    for (int i=1; i<pos; i++){
        previous = current;
        current = current->next;
    }

    if (previous == NULL){
        node->next = list->head;
        list->head = node;
        
    } else {
        previous->next = node;
        node->next = current;
    }

    return SUCCESS;
}

int list_insert_sorted(TLinkedList *list, struct aluno st){
    if (list == NULL){
        return INVALID_NULL_POINTER;
    }
    
    list_node *node;
    node = malloc(sizeof(list_node));
    if (node == NULL){
        return OUT_OF_MEMORY;
    }
    node->data = st;

    list_node *current, *previous;
    previous = NULL;
    current = list->head;
    
    while (current != NULL && current->data.matricula < st.matricula){
        previous = current;
        current = current->next;
    }
    if (previous == NULL){
        node->next = list->head;
        list->head = node;
    } else {
        previous->next = node;
        node->next = current;
    }
    return SUCCESS;
    
}

int list_print(TLinkedList *list){
    if (list == NULL){
        return INVALID_NULL_POINTER;
    }
    list_node *aux;
    aux = list->head;
    
    // printf ("\n--- Printing list ---\n");
    while (aux != NULL){
        printf("\n------------------------\n");
        printf("Id: %d\n", aux->data.matricula);
        printf("Name: %s\n", aux->data.nome);
        printf("Grades: %.1f; %.1f; %.1f.\n", aux->data.n1, aux->data.n2, aux->data.n3);

        aux = aux->next;
    }
    // printf ("\n--- End of the list ---\n");
    return SUCCESS;
}

int list_free(TLinkedList *list){
    if (list == NULL){
        return INVALID_NULL_POINTER;
    }
    list_node *aux;
    aux = list->head;

    while (aux != NULL){
        list->head = aux->next;
        free(aux);
        aux = list->head;
    }
    free(list);
    return SUCCESS;
}
