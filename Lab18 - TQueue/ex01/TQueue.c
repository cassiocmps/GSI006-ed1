#include <stdlib.h>
#include <stdio.h>
#include "TQueue.h"
#include "TSeqList.h"



// é possível criar a lista
struct TQueue{
    int front, rear, size;
    TSeqList *list;
};


TQueue *queue_create(){
    TQueue *queue;
    queue = malloc(sizeof(TQueue));
    if (queue != NULL){
        queue->list = cria_lista();
        if (queue->list == NULL){
            free(queue);
            return NULL;
        }
        queue->front = -1;
        queue->rear = 0;
        queue->size = 0; 
    }
    return queue;
}

int queue_free(TQueue *queue){
    if (queue == NULL){
        return INVALID_NULL_POINTER;
    }
    libera_lista(queue->list);
    free(queue);
    return 0;
}

int queue_push(TQueue *queue, struct aluno al){
    if (queue == NULL){
        return INVALID_NULL_POINTER;
    }
    if (queue->front == queue->rear){
        return OUT_OF_MEMORY;
    }
    
    if (queue->size == 0){
        // printf("%d",queue->size);
        // printf("%d", insere_lista_pos(queue->list, 0, al));
        if (insere_lista_pos(queue->list, 0, al) == 0){
            insere_lista_pos(queue->list, 0, al);
            queue->front = 0;
            queue->rear = 1;
            queue->size = 1;
            return 0;
        } else {
            return OUT_OF_RANGE;
        }
    } else {
        if (insere_lista_pos(queue->list, queue->rear, al) == 0){
            queue->rear = (queue->rear+1)%MAX;
            queue->size++;
            return 0;
        } else {
            return OUT_OF_RANGE;
        }
    }

}

int queue_pop(TQueue *queue){
    if (queue == NULL){
        return INVALID_NULL_POINTER;
    }
    if (queue->size == 0){
        return ELEM_NOT_FOUND;
    }
    
    queue->front = (queue->front+1)%MAX;
    queue->size--;
    return 0;
}

int queue_front(TQueue *queue, struct aluno *al){
    if (queue == NULL){
        return INVALID_NULL_POINTER;
    }
    if (queue->size == 0){
        return ELEM_NOT_FOUND;
    }
    return consulta_lista_pos(queue->list, queue->front, al);
}

int queue_rear(TQueue *queue, struct aluno *al){
    if (queue == NULL){
        return INVALID_NULL_POINTER;
    }
    if (queue->size == 0){
        return ELEM_NOT_FOUND;
    }
    if (queue->rear == 0){
        consulta_lista_pos(queue->list, MAX-1, al);
    } else {
        return consulta_lista_pos(queue->list, queue->rear-1, al);
    }
}

int queue_empty(TQueue *queue){
    if (queue == NULL){
        return INVALID_NULL_POINTER;
    }

    if (queue->size == 0){
        return 1;
    } else {
        return 0;
    }
}

int queue_full(TQueue *queue){
    if (queue == NULL){
        return INVALID_NULL_POINTER;
    }

    if (queue->size == 0){
        return 0;
    }
    if (queue->front == queue->rear){
        return 1;
    } else {
        return 0;
    }
}
