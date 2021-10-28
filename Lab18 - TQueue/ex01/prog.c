#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "TQueue.h"

int main(){
    struct aluno al[5], test;
    TQueue *st = queue_create();

    al[3].matricula = 10;
    strcpy(al[3].nome, "cassio");
    al[3].n1 = 7;
    al[3].n2 = 7;
    al[3].n3 = 7;

    al[2].matricula = 20;
    strcpy(al[2].nome, "joao");
    al[2].n1 = 8;
    al[2].n2 = 8;
    al[2].n3 = 8;

    al[0].matricula = 30;
    strcpy(al[0].nome, "gustavo");
    al[0].n1 = 9;
    al[0].n2 = 9;
    al[0].n3 = 9;

    al[1].matricula = 40;
    strcpy(al[1].nome, "lucas");
    al[1].n1 = 6;
    al[1].n2 = 6;
    al[1].n3 = 6;

    al[4].matricula = 50;
    strcpy(al[4].nome, "bruno");
    al[4].n1 = 6.5;
    al[4].n2 = 6.5;
    al[4].n3 = 6.5;

    printf("\nFILA vazia: %d\n", queue_empty(st));

    for (int i=0; i<3; i++){
        printf("\n===PUSHING #%d===", i+1);
        queue_push(st, al[i]);
        // queue_push(st, al[1]);
        
        queue_front(st, &test);
        printf("\nMatricula FRONT: %d", test.matricula);
        printf("\nNome: %s", test.nome);
        printf("\nNotas: %.1f;%.1f;%.1f\n", test.n1, test.n2, test.n3);

        queue_rear(st, &test);
        printf("\nMatricula REAR: %d", test.matricula);
        printf("\nNome: %s", test.nome);
        printf("\nNotas: %.1f;%.1f;%.1f\n", test.n1, test.n2, test.n3);
        
        printf("\nFILA vazia: %d\n", queue_empty(st));
        printf("FILA cheia: %d\n\n", queue_full(st));
    }

    printf("\npoping first in queue...\n");
    queue_pop(st);
    
    queue_front(st, &test);
    printf("\nMatricula FRONT: %d", test.matricula);
    printf("\nNome: %s", test.nome);
    printf("\nNotas: %.1f;%.1f;%.1f\n", test.n1, test.n2, test.n3);
    printf("FILA vazia: %d\n", queue_empty(st));
    printf("FILA cheia: %d\n\n", queue_full(st));

    queue_rear(st, &test);
    printf("\nMatricula REAR: %d", test.matricula);
    printf("\nNome: %s", test.nome);
    printf("\nNotas: %.1f;%.1f;%.1f\n", test.n1, test.n2, test.n3);
    printf("FILA vazia: %d\n", queue_empty(st));
    printf("FILA cheia: %d\n\n", queue_full(st));

    
    printf("\npushing new in queue...\n");
    queue_push(st, al[3]);

    queue_front(st, &test);
    printf("\nMatricula FRONT: %d", test.matricula);
    printf("\nNome: %s", test.nome);
    printf("\nNotas: %.1f;%.1f;%.1f\n", test.n1, test.n2, test.n3);
    printf("FILA vazia: %d\n", queue_empty(st));
    printf("FILA cheia: %d\n\n", queue_full(st));

    queue_rear(st, &test);
    printf("\nMatricula REAR: %d", test.matricula);
    printf("\nNome: %s", test.nome);
    printf("\nNotas: %.1f;%.1f;%.1f\n", test.n1, test.n2, test.n3);
    printf("FILA vazia: %d\n", queue_empty(st));
    printf("FILA cheia: %d\n\n", queue_full(st));

    printf("\ntrying to push with full queue: %d\n", queue_full(st));
    queue_push(st, al[5]);

    queue_front(st, &test);
    printf("\nMatricula FRONT: %d", test.matricula);
    printf("\nNome: %s", test.nome);
    printf("\nNotas: %.1f;%.1f;%.1f\n", test.n1, test.n2, test.n3);
    printf("FILA vazia: %d\n", queue_empty(st));
    printf("FILA cheia: %d\n\n", queue_full(st));

    queue_rear(st, &test);
    printf("\nMatricula REAR: %d", test.matricula);
    printf("\nNome: %s", test.nome);
    printf("\nNotas: %.1f;%.1f;%.1f\n", test.n1, test.n2, test.n3);
    printf("FILA vazia: %d\n", queue_empty(st));
    printf("FILA cheia: %d\n\n", queue_full(st));


    printf("\nloop for emptying queue...\n");
    for (int i=0; i<5; i++){
        queue_pop(st);
    }
    printf("FILA vazia: %d\n", queue_empty(st));
    printf("FILA cheia: %d\n\n", queue_full(st));

    queue_free(st);
    return 0;
}
