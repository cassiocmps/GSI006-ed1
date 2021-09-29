#include "TLinkedList.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct list_node list_node;

struct TLinkedList {
    list_node *head;
};

struct list_node {
    struct student data;
    list_node *next;
};

// struct student{
//     int matricula;
//     char nome[30];
//     float n1,n2,n3;
// };

TLinkedList *list_create(){
    TLinkedList *list;
    list = malloc(sizeof(TLinkedList));
    if (list != NULL)
    {
        list->head = NULL;
    }
    return list;
}

int list_push_front(TLinkedList *list, struct student st){
    if (list == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    else
    {
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

int list_push_back(TLinkedList *list, struct student st){
    if (list == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    else
    {
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

int list_insert(TLinkedList *list, int pos, struct student st){
    if (list == NULL){
        return INVALID_NULL_POINTER;
    }

    if (pos <= 0){
        return OUT_OF_RANGE;
    }
    
    list_node *node;
    node = malloc(sizeof(node));
    if (node == NULL){
        return OUT_OF_MEMORY;
    }
    
    node->data = st;

    list_node *current, *previous;
    previous = NULL;
    current = list->head;
    int i=1;

    while (i <= pos){
        previous = current;
        current = current->next;
        i++;
    }
    if (previous == NULL){ // insert in head
        node->next = list->head;
        list->head = node;
    } else { // insert in any other position
        previous->next = node;
        node->next = current;
    }
    return SUCCESS;
}

int list_insert_sorted(TLinkedList *list, struct student st){
    if (list == NULL){
        return INVALID_NULL_POINTER;
    }
    
    list_node *node;
    node = malloc(sizeof(node));
    if (node == NULL){
        return OUT_OF_MEMORY;
    }
    
    node->data = st;

    list_node *current, *previous;
    previous = NULL;
    current = list->head;

    while (current!=NULL && current->data.id < st.id){
        previous = current;
        current = current->next;
    }
    if (previous == NULL){ // insert in head
        node->next = list->head;
        list->head = node;
    } else { // insert in any other position
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
    
    printf ("\n--- Printing list ---\n");
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
