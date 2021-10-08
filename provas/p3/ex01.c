/*
Considere o TAD TDLinkedList que serve para manipular uma lista duplamente 
encadeada de alunos (a lista usada na prática 16 – copiar o código 
da SUA PRÁTICA)

Implemente no TAD a função  int list_erase_max_nota_n1(TDLinkedList *li), que 
retira da  lista todos os alunos que possuem a maior nota na primeira prova
(elemento n1 da struct aluno; note que mais de um aluno pode possuir 
a nota máxima). Pode-se utilizar qualquer função já implementada na
lista (que estão no .h)


*/

int list_erase_max_nota_n1(TDLinkedList *list){
     if (list == NULL){
        return INVALID_NULL_POINTER;
    }
    if (list->begin == NULL){
        return ELEM_NOT_FOUND;
    }

    DLNode *aux;
    aux = list->begin;
    float best_grade = 0;

    while (aux != NULL){
        if (aux->data.n1 > best_grade){
            best_grade = aux->data.n1;
        }
        aux = aux->next;
    }

    aux = list->begin;
    while (aux != NULL){
        if (aux->data.n1 == best_grade){
            if  (aux->next == NULL && aux->prev == NULL){ // only one node
                list->begin = NULL;
                list->end = NULL;
            } else 
            if (aux->next == NULL){ // last node
                aux->prev->next = NULL;
                list->end = aux->prev;
            } else
            if (aux->prev == NULL){ // first node
                aux->next->prev = NULL;
                list->begin = aux->next;

            } else { // any other
                aux->prev->next = aux->next;
                aux->next->prev = aux->prev;
            }
            list->size--;
            free(aux);
        }
        aux = aux->next;
    }
    return SUCCESS;
}