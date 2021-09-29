#define SUCCESS 0
#define INVALID_NULL_POINTER -1
#define OUT_OF_MEMORY -2
#define OUT_OF_RANGE -3
#define ELEM_NOT_FOUND -4

struct student{
    int id;
    char name[30];
    float g1,g2,g3;
};

typedef struct TLinkedList TLinkedList;

TLinkedList *list_create();
int list_push_front(TLinkedList *list, struct student st);
int list_push_back(TLinkedList *list, struct student st);
int list_insert_sorted(TLinkedList *list, struct student st);

// insere o student na posição ‘pos’ – essa posição inicia em 1
int list_insert(TLinkedList *list, int pos, struct student st);
// retorna o tamanho da lista (valores negativos em caso de erro)
int list_size(TLinkedList *li);
// retira da lista o primeiro student
int list_pop_front(TLinkedList *li);
// retira da lista o último student
int list_pop_back(TLinkedList *li);
// retira da lista o student de matricula ‘mat’
int list_erase_data(TLinkedList *list, int id);
// retira da lista o student da posição ‘pos’ (posição inicia em 1)
int list_erase_pos(TLinkedList *list, int pos);
// encontrar o student pela posição na lista (posição inicia em 1)
int list_find_pos(TLinkedList *list, int pos, struct student *st);
// encontrar o student pelo número de matrícula
int list_find_mat(TLinkedList *list, int id, struct student *st);
// retornar o student que está no início da lista
int list_front(TLinkedList *list, struct student *st);
// retornar o student que está no final da lista
int list_back(TLinkedList *list, struct student *st);
// dado um número de matrícula, retornar a posição a lista
int list_get_pos(TLinkedList *list, int id, int *pos);

int list_print(TLinkedList *list);
int list_free(TLinkedList *list);