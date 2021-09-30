#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "TDLinkedList.h"

int main(){
    TDLinkedList *lab_students;
    lab_students = list_create();

    // struct student stTest;
    
    // list_find_id(lab_students, 20, &stTest);
    // printf("\n----------list's #id 20--------------\n");
    // printf("Id: %d\n", stTest.id);
    // printf("Name: %s\n", stTest.name);
    // printf("Grades: %.1f; %.1f; %.1f.\n", stTest.g1, stTest.g2, stTest.g3);
        
    // list_find_pos(lab_students, 3, &stTest);
    // printf("\n----------list's #pos 3--------------\n");
    // printf("Id: %d\n", stTest.id);
    // printf("Name: %s\n", stTest.name);
    // printf("Grades: %.1f; %.1f; %.1f.\n", stTest.g1, stTest.g2, stTest.g3);

    // list_front(lab_students, &stTest);
    // printf("\n----------list's head--------------\n");
    // printf("Id: %d\n", stTest.id);
    // printf("Name: %s\n", stTest.name);
    // printf("Grades: %.1f; %.1f; %.1f.\n", stTest.g1, stTest.g2, stTest.g3);

    // list_back(lab_students, &stTest);
    // printf("\n----------list's back--------------\n");
    // printf("Id: %d\n", stTest.id);
    // printf("Name: %s\n", stTest.name);
    // printf("Grades: %.1f; %.1f; %.1f.\n", stTest.g1, stTest.g2, stTest.g3);

    // int posTest;
    // list_get_pos(lab_students, 10, &posTest);
    // printf("\npos %d\n", posTest);

    // printf("\n=== SIZE OF THE LIST: %d ===\n", list_size(lab_students));

    struct student st[5];
    st[3].id = 10;
    strcpy(st[3].name, "cassio");
    st[3].g1 = 7;
    st[3].g2 = 7;
    st[3].g3 = 7;

    st[2].id = 20;
    strcpy(st[2].name, "joao");
    st[2].g1 = 8;
    st[2].g2 = 8;
    st[2].g3 = 8;

    st[0].id = 30;
    strcpy(st[0].name, "gustavo");
    st[0].g1 = 9;
    st[0].g2 = 9;
    st[0].g3 = 9;

    st[1].id = 40;
    strcpy(st[1].name, "lucas");
    st[1].g1 = 6;
    st[1].g2 = 6;
    st[1].g3 = 6;

    st[4].id = 50;
    strcpy(st[4].name, "bruno");
    st[4].g1 = 6.5;
    st[4].g2 = 6.5;
    st[4].g3 = 6.5;

    for (int i=0; i<4; i++){
        // list_push_front(lab_students, st[i]);
        list_push_back(lab_students, st[i]);
        // list_insert(lab_students, i, st[i]);
    }
    // list_insert(lab_students, 5, st[4]);
    // list_push_back(lab_students, st[4]);

    list_print_forward(lab_students);
    printf("\n=== SIZE OF THE LIST: %d ===\n", list_size(lab_students));

    list_insert(lab_students, 1, st[4]);
    // list_erase(lab_students, 1);
    list_print_forward(lab_students);
    // for (int i=0; i<5; i++){
    // //     // list_pop_front(lab_students);
    // //     list_pop_back(lab_students);
    //     list_erase(lab_students, i);
    //     list_print_forward(lab_students);
    // }

    list_print_reverse(lab_students);

    // list_erase_data(lab_students, 30);
    // list_erase_pos(lab_students, 5);
    // list_insert(lab_students, 1, st[4]);
    // list_print(lab_students);
    // printf("\n=== SIZE OF THE LIST: %d ===\n", list_size(lab_students));
    
    // struct student stTest;
    
    // list_find_id(lab_students, 00, &stTest);
    // printf("\n----------list's #id 20--------------\n");
    // printf("Id: %d\n", stTest.id);
    // printf("Name: %s\n", stTest.name);
    // printf("Grades: %.1f; %.1f; %.1f.\n", stTest.g1, stTest.g2, stTest.g3);
    
    // for (int i=5; i>=0; i--){
    //     list_find_pos(lab_students, i, &stTest);
    //     printf("\n----------list's #pos %d--------------\n", i);
    //     printf("Id: %d\n", stTest.id);
    //     printf("Name: %s\n", stTest.name);
    //     printf("Grades: %.1f; %.1f; %.1f.\n", stTest.g1, stTest.g2, stTest.g3);
    // }

    // list_find_pos(lab_students, 3, &stTest);
    // printf("\n----------list's #pos 3--------------\n");
    // printf("Id: %d\n", stTest.id);
    // printf("Name: %s\n", stTest.name);
    // printf("Grades: %.1f; %.1f; %.1f.\n", stTest.g1, stTest.g2, stTest.g3);

    // list_front(lab_students, &stTest);
    // printf("\n----------list's head--------------\n");
    // printf("Id: %d\n", stTest.id);
    // printf("Name: %s\n", stTest.name);
    // printf("Grades: %.1f; %.1f; %.1f.\n", stTest.g1, stTest.g2, stTest.g3);

    // list_back(lab_students, &stTest);
    // printf("\n----------list's back--------------\n");
    // printf("Id: %d\n", stTest.id);
    // printf("Name: %s\n", stTest.name);
    // printf("Grades: %.1f; %.1f; %.1f.\n", stTest.g1, stTest.g2, stTest.g3);

    // int posTest;
    // list_get_pos(lab_students, 00, &posTest);
    // printf("\npos %d\n", posTest);

    // printf("\n=== SIZE OF THE LIST: %d ===\n", list_size(lab_students));
    
    // list_pop_front(lab_students);
    // list_pop_back(lab_students);

    list_free(lab_students);
    return 0;
}