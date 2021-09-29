#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "TLinkedList.h"

int main(){
    TLinkedList *lab_students;
    lab_students = list_create();
    
    struct student st[4];
    st[0].id = 10;
    strcpy(st[0].name, "cassio");
    st[0].g1 = 7;
    st[0].g2 = 7;
    st[0].g3 = 7;

    st[1].id = 20;
    strcpy(st[1].name, "joao");
    st[1].g1 = 8;
    st[1].g2 = 8;
    st[1].g3 = 8;

    st[2].id = 30;
    strcpy(st[2].name, "gustavo");
    st[2].g1 = 9;
    st[2].g2 = 9;
    st[2].g3 = 9;

    st[3].id = 40;
    strcpy(st[3].name, "lucas");
    st[3].g1 = 6;
    st[3].g2 = 6;
    st[3].g3 = 6;

    for (int i=0; i<4; i++){
        // list_push_front(lab_students, st[i]);
        // list_push_back(lab_students, st[i]);
        list_insert_sorted(lab_students, st[i]);
    }

    list_print(lab_students);
    list_free(lab_students);
    return 0;
}