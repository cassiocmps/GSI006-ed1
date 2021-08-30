#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cad.h"

struct aluno {
    char nome[50];
    char matricula[20];
    double cra;
};

aluno* cadastra_aluno(char nome[], char matricula[], double cra){

    aluno* ponteiro;
    ponteiro = (aluno*) malloc(1*sizeof(aluno));

    strcpy(ponteiro->nome,nome);
    strcpy(ponteiro->matricula,matricula);
    ponteiro->cra = cra;

    return ponteiro;
    
}

void imprime_aluno(aluno* p){
    printf("\n--- Aluno cadastrado ---\n");
    printf("Nome: %s\n", p->nome);
    printf("Matricula: %s\n", p->matricula);
    printf("CRA: %.2lf\n", p->cra);
}

int destroi_aluno (aluno* p){
    if (p==NULL) return -1;
    else {
        free(p);
        return 0;
    }
}

int atualizar_cra(aluno* p, double novo_cra){
    p->cra = novo_cra;
    return 0;    
}

int copia_dados(aluno* p, char *nome, char *matricula, double *cra){
    strcpy(nome, p->nome);
    strcpy(matricula, p->matricula);
    *cra = p->cra;
    return 0;
}