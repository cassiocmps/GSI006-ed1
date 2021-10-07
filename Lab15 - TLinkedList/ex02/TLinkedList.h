#define SUCCESS 0
#define INVALID_NULL_POINTER -1
#define OUT_OF_MEMORY -2
#define OUT_OF_RANGE -3
#define ELEM_NOT_FOUND -4
#define WRONG_LIST_TYPE -5

struct student{
    int id;
    char name[30];
    float g1,g2,g3;
};

typedef struct TLinkedList TLinkedList;

TLinkedList *list_create(int sorted);
int list_push_front(TLinkedList *list, struct student st);
int list_push_back(TLinkedList *list, struct student st);
int list_size(TLinkedList *list);
int list_front(TLinkedList *list, struct student *st);
int list_back(TLinkedList *list, struct student *st);
int list_pop_front(TLinkedList *list);
int list_pop_back(TLinkedList *list);
int list_find_pos(TLinkedList *list, int pos, struct student *st);
int list_find_id(TLinkedList *list, int id, struct student *st);
int list_get_pos(TLinkedList *list, int id, int *pos);
int list_erase_pos(TLinkedList *list, int pos);
int list_erase_data(TLinkedList *list, int id);
int list_insert_sorted(TLinkedList *list, struct student st);
int list_insert(TLinkedList *list, int pos, struct student st);
int list_print(TLinkedList *list);
int list_free(TLinkedList *list);