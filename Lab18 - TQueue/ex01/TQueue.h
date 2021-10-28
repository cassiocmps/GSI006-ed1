#ifndef _tqueueh_
#define _tqueueh_

#define SUCCESS 0
#define INVALID_NULL_POINTER -1
#define OUT_OF_MEMORY -2
#define OUT_OF_RANGE -3
#define ELEM_NOT_FOUND -4

#include "aluno.h"

typedef struct TQueue TQueue;

TQueue *queue_create();
int queue_free(TQueue *queue);

int queue_push(TQueue *queue, struct aluno al);
int queue_pop(TQueue *queue);
int queue_front(TQueue *queue, struct aluno *al);
int queue_rear(TQueue *queue, struct aluno *al);

int queue_empty(TQueue *queue);
int queue_full(TQueue *queue);

#endif