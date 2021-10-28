#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include "TQueue.h"

typedef struct qnode qnode;

struct TQueue {
    qnode *front;
};

struct qnode {
    struct aluno data;
    qnode *next;
};

TQueue *queue_create(){
    TQueue *queue;
    queue = malloc(sizeof(TQueue));
    if (queue != NULL){
        queue->front = NULL;
    }
    return queue;
}

int queue_push(TQueue *queue, struct aluno al){ // pushing at the head/front
    if (queue == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    else
    {
        qnode *node;
        node = malloc(sizeof(qnode));
        if (node == NULL)
        {
            return OUT_OF_MEMORY;
        }
        node->data = al;
        node->next = queue->front;

        queue->front = node;
        return SUCCESS;
    }
}

int queue_pop(TQueue *queue){ // popping at the end/rear
    if (queue == NULL){
        return INVALID_NULL_POINTER;
    }
    if (queue->front == NULL){
        return ELEM_NOT_FOUND;
    }

    qnode *previous = NULL;
    qnode *current = queue->front;
    
    while (current->next != NULL){
            previous = current;
            current = current->next;
        }
    if (previous == NULL){
        free(current);
        queue->front = NULL;
        return SUCCESS;
    }
    previous->next = NULL;
    free(current);
    return SUCCESS;
}

int queue_rear(TQueue *queue, struct aluno *al){
    if (queue == NULL){
        return INVALID_NULL_POINTER;
    }
    if (queue->front == NULL){
        return ELEM_NOT_FOUND;
    }
    *al = queue->front->data;
    return SUCCESS;
}

int queue_front(TQueue *queue, struct aluno *al){
    if (queue == NULL){
        return INVALID_NULL_POINTER;
    }
    if (queue->front == NULL){
        return ELEM_NOT_FOUND;
    }
    qnode *aux;
    aux = queue->front;

    while (aux->next != NULL){
        aux = aux->next;
    }
    *al = aux->data;
    return SUCCESS;
}

int queue_size(TQueue *queue){
    if (queue == NULL){
        return INVALID_NULL_POINTER;
    }
    int counter=0;
    qnode *aux;
    aux = queue->front;

    while (aux != NULL){
        counter++;
        aux = aux->next;
    }
    return counter;
}

int queue_print(TQueue *queue){
    if (queue == NULL){
        return INVALID_NULL_POINTER;
    }
    qnode *aux;
    aux = queue->front;
    
    printf ("\n--- Printing queue ---\n");
    while (aux != NULL){
        printf("\n------------------------\n");
        printf("Id: %d\n", aux->data.matricula);
        printf("Name: %s\n", aux->data.nome);
        printf("Grades: %.1f; %.1f; %.1f.\n", aux->data.n1, aux->data.n2, aux->data.n3);

        aux = aux->next;
    }
    printf ("\n--- End of the queue ---\n");
    return SUCCESS;
}

int queue_free(TQueue *queue){
    if (queue == NULL){
        return INVALID_NULL_POINTER;
    }
    qnode *aux;
    aux = queue->front;

    while (aux != NULL){
        queue->front = aux->next;
        free(aux);
        aux = queue->front;
    }
    free(queue);
    return SUCCESS;
}
