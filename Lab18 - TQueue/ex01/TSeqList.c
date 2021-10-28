#include <stdio.h>
#include <stdlib.h>
#include "TSeqList.h" //inclui os Protótipos

//Definição do tipo lista
struct lista
{
    int qtd;
    struct aluno dados[MAX];
};

TSeqList *cria_lista()
{
    TSeqList *li;
    li = (TSeqList *)malloc(sizeof(struct lista));
    if (li != NULL)
    {
        li->qtd = 0;
    }
    return li; 
}

int insere_lista_final(TSeqList *li, struct aluno al)
{
    if (li == NULL)
        return -1;
    if (li->qtd == MAX) //lista cheia
        return -1;
    li->dados[li->qtd] = al;
    li->qtd++;
    return 0;
}

int consulta_lista_pos(TSeqList *li, int pos, struct aluno *al)
{
    if (li == NULL)
        return -1;
    // if (pos <=0 || pos > li->qtd)
    //     return -1;
    *al = li->dados[pos];
    return 0;
}

int insere_lista_pos(TSeqList* li, int pos, struct aluno al){
    if (li == NULL)
        return -1;
    li->dados[pos] = al;
    return 0;
}

int insere_lista_inicio(TSeqList *li, struct aluno al)
{
    if (li == NULL)
        return -1;
    if (li->qtd == MAX) //lista cheia
        return -1;
    // deslocando os elementos
    for (int i = li->qtd - 1; i >= 0; i--)
    {
        li->dados[i + 1] = li->dados[i];
    }
    // primeira posição disponivel
    li->dados[0] = al;
    li->qtd++;
    return 0;
}

int remove_lista_final(TSeqList* li){
    if(li == NULL){
        return -1;
    }
    if(li->qtd == 0){
        return -1;
    }
    
    li->qtd--; 
    return 0;
}

int imprime_lista(TSeqList *li){
    if (li == NULL) // verifica se a lista existe
        return -1;

    for (int i = 0; i < li->qtd; i++) { // percorre o vetor baseado nos alunos inseridos, controlados pela variavel qtd
        printf("\nMatricula: %d", li->dados[i].matricula);
        printf("\nNome: %s", li->dados[i].nome);
        printf("\nNotas: %.1f;%.1f;%.1f\n", li->dados[i].n1, li->dados[i].n2, li->dados[i].n3);
    }
    return 0;
}

int troca_pos_lista(TSeqList *li, int pos1, int pos2){
    if (li == NULL)
        return -1;
    if (pos1 == pos2)
        return -1;
    if (pos1>li->qtd || pos2>li->qtd)
        return -1;
    if (pos1==0 || pos2==0)
        return -1;

    struct aluno temp;
    temp = li->dados[pos1-1];
    li->dados[pos1-1] = li->dados[pos2-1];
    li->dados[pos2-1] = temp;
    return 0;
}

int remove_intervalo_lista(TSeqList *li, int posI, int posF){
    if (li == NULL)
        return -1;
    if (posI >= posF)
        return -1;
    if (posI>li->qtd || posF>li->qtd)
        return -1;
    if (posI==0 || posF==0)
        return -1;

    for (int i=(posI-1), j=(posF); i < (posF); i++, j++){
        li->dados[i] = li->dados[j];
        li->qtd--;
    }
    
    return 0;
}

int tamanho_lista(TSeqList* li){
    if(li == NULL)
        return -1;
    else
        return li->qtd; // retorna o tamanho da lista
}

int lista_cheia(TSeqList* li){
    if(li == NULL)
        return -1;
    
    return (li->qtd == MAX);
}

int lista_vazia(TSeqList* li){
    if(li == NULL)
        return -1;
    
    return (li->qtd == 0);
}

int libera_lista(TSeqList *li)
{
    if (li == NULL)
        return INVALID_NULL_POINTER;
    
    free(li);
    return 0;
}
