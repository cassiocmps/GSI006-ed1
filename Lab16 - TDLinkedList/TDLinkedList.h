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

typedef struct TDLinkedList TDLinkedList;

TDLinkedList *list_create();
int list_free(TDLinkedList *list);

int list_push_front(TDLinkedList *list, struct student st);
int list_push_back(TDLinkedList *list, struct student st);
int list_insert(TDLinkedList *list, int pos, struct student st);
int list_size(TDLinkedList *list);
int list_pop_front(TDLinkedList *list);
int list_pop_back(TDLinkedList *list);
int list_erase(TDLinkedList *list, int pos);
int list_find_pos(TDLinkedList *list, int pos, struct student *st);
int list_find_id(TDLinkedList *list, int id, struct student *st);
int list_front(TDLinkedList *list, struct student *st);
int list_back(TDLinkedList *list, struct student *st);
int list_get_pos(TDLinkedList *list, int id, int *pos);
int list_print_forward(TDLinkedList *list);
int list_print_reverse(TDLinkedList *list);