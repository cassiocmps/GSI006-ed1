#ifndef _tseqlisth_
#define _tseqlisth_

#include "aluno.h"
#define MAX 3
#define SUCCESS 0
#define INVALID_NULL_POINTER -1
#define OUT_OF_MEMORY -2
#define OUT_OF_RANGE -3
#define ELEM_NOT_FOUND -4

typedef struct lista TSeqList;

TSeqList* cria_lista();
int libera_lista(TSeqList* li);

int consulta_lista_pos(TSeqList* li, int pos, struct aluno *al);
int consulta_lista_mat(TSeqList* li, int mat, struct aluno *al);
int insere_lista_final(TSeqList* li, struct aluno al);
int insere_lista_inicio(TSeqList* li, struct aluno al);
int insere_lista_pos(TSeqList* li, int pos, struct aluno al);
int remove_lista(TSeqList* li, int mat);
int remove_lista_inicio(TSeqList* li);
int remove_lista_final(TSeqList* li);
int tamanho_lista(TSeqList* li);
int lista_cheia(TSeqList* li);
int lista_vazia(TSeqList* li);
int imprime_lista(TSeqList* li);
int remove_lista_otimizado(TSeqList* li, int mat);
// funções da prova
int troca_pos_lista(TSeqList *li, int pos1, int pos2);
int remove_intervalo_lista(TSeqList *li, int posI, int posF);

#endif