#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "TQueue.h"

struct TQueue{
    int front, rear, current_size;
    int in_size, max_size;
    struct aluno *data;
};


TQueue *queue_create(int size){
    TQueue *queue;
    queue = malloc(sizeof(TQueue));
    if (queue != NULL){
        queue->data = malloc (sizeof(struct aluno)*size);
        if (queue->data == NULL){
            free(queue);
            return NULL;
        }
        queue->front = -1;
        queue->rear = 0;
        queue->current_size = 0;
        queue->in_size = size;
        queue->max_size = size;
    }
    return queue;
}

int queue_free(TQueue *queue){
    if (queue == NULL){
        return INVALID_NULL_POINTER;
    }
    free(queue->data);
    free(queue);
    return 0;
}

int queue_realloc(TQueue *queue){
    struct aluno *new, *old;
    int new_size = queue->max_size + queue->in_size;

    old = queue->data;
    new = malloc (sizeof(struct aluno)*new_size);
    if (new == NULL){
        free(new);
        return OUT_OF_MEMORY;
    }
    int i, j;
    for (i = queue->front, j=0; i < queue->current_size; i++, j++){
        if (i == queue->max_size){
            i=0;
        }
        new[j] = old[i];
    }
    queue->max_size = new_size;
    queue->front = 0;
    queue->rear = j;
    queue->data = new;
    free(old);
    return 0;
}

int queue_compact(TQueue *queue){
    struct aluno *new, *old;
    int new_size = ceil((queue->current_size/queue->in_size)*queue->in_size);

    old = queue->data;
    new = malloc (sizeof(struct aluno)*new_size);
    if (new == NULL){
        free(new);
        return OUT_OF_MEMORY;
    }
    int i, j;
    for (i = queue->front, j=0; i < queue->current_size; i++, j++){
        if (i == queue->max_size){
            i=0;
        }
        new[j] = old[i];
    }
    queue->max_size = new_size;
    queue->front = 0;
    queue->rear = j;
    queue->data = new;
    free(old);
    return 0;
}

int queue_push(TQueue *queue, struct aluno al){
    if (queue == NULL){
        return INVALID_NULL_POINTER;
    }
    
    if (queue->current_size == 0){
        queue->data[0] = al;
        queue->front = 0;
        queue->rear = 1;
        queue->current_size = 1;
        return 0;
    }
    
    if (queue_full(queue) == 1){
        queue_realloc(queue);
    }

    queue->data[queue->rear] = al;
    queue->rear = (queue->rear+1)%queue->max_size;
    queue->current_size++;
    return 0;
}

int queue_pop(TQueue *queue){
    if (queue == NULL){
        return INVALID_NULL_POINTER;
    }
    if (queue->current_size == 0){
        return ELEM_NOT_FOUND;
    }
    
    queue->front = (queue->front+1)%queue->max_size;
    queue->current_size--;
    return 0;
}

int queue_front(TQueue *queue, struct aluno *al){
    if (queue == NULL){
        return INVALID_NULL_POINTER;
    }
    if (queue->current_size == 0){
        return ELEM_NOT_FOUND;
    }
    *al = queue->data[queue->front];
    return 0;
}

int queue_rear(TQueue *queue, struct aluno *al){
    if (queue == NULL){
        return INVALID_NULL_POINTER;
    }
    if (queue->current_size == 0){
        return ELEM_NOT_FOUND;
    }
    if (queue->rear == 0){
        *al = queue->data[queue->max_size-1];
        return 0;
    } else {
        *al = queue->data[queue->rear-1];
        return 0;
    }
}

int queue_empty(TQueue *queue){
    if (queue == NULL){
        return INVALID_NULL_POINTER;
    }

    if (queue->current_size == 0){
        return 1;
    } else {
        return 0;
    }
}

int queue_full(TQueue *queue){
    if (queue == NULL){
        return INVALID_NULL_POINTER;
    }

    if (queue->current_size == 0){
        return 0;
    }
    if (queue->current_size == queue->max_size){
        return 1;
    } else {
        return 0;
    }
}
