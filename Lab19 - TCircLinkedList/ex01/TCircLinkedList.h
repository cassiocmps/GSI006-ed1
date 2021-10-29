#define SUCCESS 0
#define INVALID_NULL_POINTER -1
#define OUT_OF_MEMORY -2
#define OUT_OF_RANGE -3
#define ELEM_NOT_FOUND -4

struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};

typedef struct TCircLinkedList TCircLinkedList;

TCircLinkedList *circlist_create();
int circlist_push_front(TCircLinkedList *list, struct aluno al);
int circlist_push_back(TCircLinkedList *list, struct aluno al);
int circlist_size(TCircLinkedList *list);
int circlist_front(TCircLinkedList *list, struct aluno *al);
int circlist_back(TCircLinkedList *list, struct aluno *al);
int circlist_pop_front(TCircLinkedList *list);
int circlist_pop_back(TCircLinkedList *list);
int circlist_find_pos(TCircLinkedList *list, int pos, struct aluno *al);
int circlist_find_mat(TCircLinkedList *list, int mat, struct aluno *al);
int circlist_get_pos(TCircLinkedList *list, int mat, int *pos);
int circlist_erase_pos(TCircLinkedList *list, int pos);
int circlist_erase_data(TCircLinkedList *list, int mat);
int circlist_insert(TCircLinkedList *list, int pos, struct aluno al);
int circlist_print(TCircLinkedList *list);
int circlist_free(TCircLinkedList *list);