/* ex02
Uma das utilidades das listas circulares dinâmicas é a possibilidade de percorrer
todos os elementos por diversas vezes em um loop. Modifique o TAD para incluir uma
função que retornará sempre o próximo elemento. Por exemplo, se a lista não foi
percorrida ainda, o próximo elemento é a cabeça. Depois, ao chamar a função
novamente, será devolvido o segundo elemento, e assim sucessivamente.

(a) mostrar como fica a estrutura do TAD

typedef struct cl_node cl_node;

struct TCircLinkedList {
    cl_node *end;
};

struct cl_node {
    struct aluno data;
    cl_node *next;
    int current;
};

(b) mostrar a função que retorna o próximo elemento
*Não é necessário mostrar as outras funções afetadas pela modificação proposta

int circlist_current(TCircLinkedList *list, struct aluno *al){
    if (list == NULL){
        return INVALID_NULL_POINTER;
    }
    if (list->end == NULL){
        return ELEM_NOT_FOUND;
    }

    cl_node *aux = list->end->next;
    while (aux->next != list->end->next && aux->current != 1){
        aux = aux->next;
    }

    if (aux == list->end){
        if (list->end->current == 1){
            *al = aux->data;
            aux->current = 0;
            aux->next->current = 1;
            return SUCCESS;
        } else {
            *al = list->end->next->data;
            list->end->next->current = 0;
            list->end->next->next->current = 1;
            return SUCCESS;
        }
    }else{
        *al = aux->data;
        aux->current = 0;
        aux->next->current = 1;
        return SUCCESS;
    }
}


(c) Qual a diferença entre o vetor de acesso circular usado na 
implementação de uma fila estática de uma lista circular?
// responder aqui:
o vetor de acesso circular é usado para reaproveitar espaços desalocados durante o processamento da fila.
a lista circular é uma estrutura de dados q pode ser usada para percorrer infinitamente uma lista, onde o ultimo elemento aponta para o primeiro como se fosse seu proximo. 

*/