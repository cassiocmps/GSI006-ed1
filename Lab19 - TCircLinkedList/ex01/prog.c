#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "TCircLinkedList.h"

int main(){
    struct aluno al[5], test;
    TCircLinkedList *list = circlist_create();

    al[3].matricula = 10;
    strcpy(al[3].nome, "cassio");
    al[3].n1 = 7;
    al[3].n2 = 7;
    al[3].n3 = 7;

    al[2].matricula = 20;
    strcpy(al[2].nome, "joao");
    al[2].n1 = 8;
    al[2].n2 = 8;
    al[2].n3 = 8;

    al[0].matricula = 30;
    strcpy(al[0].nome, "gustavo");
    al[0].n1 = 9;
    al[0].n2 = 9;
    al[0].n3 = 9;

    al[1].matricula = 40;
    strcpy(al[1].nome, "lucas");
    al[1].n1 = 6;
    al[1].n2 = 6;
    al[1].n3 = 6;

    al[4].matricula = 50;
    strcpy(al[4].nome, "bruno");
    al[4].n1 = 6.5;
    al[4].n2 = 6.5;
    al[4].n3 = 6.5;

    // circlist_free(list);

    circlist_print(list);
    printf("\nsize of list: %d", circlist_size(list));
    circlist_push_back(list, al[0]); // gustavo
    printf("\nsize of list: %d", circlist_size(list));
    circlist_push_front(list, al[1]); // lucas
    printf("\nsize of list: %d", circlist_size(list));
    circlist_push_back(list, al[2]); // joao
    printf("\nsize of list: %d", circlist_size(list));
    circlist_push_front(list, al[3]); // cassio
    printf("\nsize of list: %d", circlist_size(list));
    circlist_print(list);

    // circlist_front(list, &test);
    // printf("\n------------circlist_front()------------\n");
    // printf("Id: %d\n", test.matricula);
    // printf("Name: %s\n", test.nome);
    // printf("Grades: %.1f; %.1f; %.1f.\n", test.n1, test.n2, test.n3);

    // circlist_back(list, &test);
    // printf("\n------------circlist_back()------------\n");
    // printf("Id: %d\n", test.matricula);
    // printf("Name: %s\n", test.nome);
    // printf("Grades: %.1f; %.1f; %.1f.\n", test.n1, test.n2, test.n3);
    
    // for (int i=0; i<3; i++){
    //     printf("\npoping back...%d\n", i+1);
    //     circlist_pop_back(list);
    //     circlist_print(list);
    // }

    // // circlist_find_pos
    // for (int i=0; i<6; i++){
    //     printf("\n------------circlist_find_pos(%d)------------r:%d\n", i, circlist_find_pos(list, i, &test));
    //     printf("Id: %d\n", test.matricula);
    //     printf("Name: %s\n", test.nome);
    //     printf("Grades: %.1f; %.1f; %.1f.\n", test.n1, test.n2, test.n3);
    // }

    // // circlist_find_mat
    // for (int i=0; i<60; i+=10){
    //     printf("\n------------circlist_find_mat(%d)------------r:%d\n", i, circlist_find_mat(list, i, &test));
    //     printf("Id: %d\n", test.matricula);
    //     printf("Name: %s\n", test.nome);
    //     printf("Grades: %.1f; %.1f; %.1f.\n", test.n1, test.n2, test.n3);
    // }

    // circlist_find_mat
    // int pos;
    // for (int i=0; i<60; i+=10){
    //     printf("\n------------circlist_get_pos(mat %d)------------r:%d\n", i, circlist_get_pos(list, i, &pos));
    //     printf("position of %d: %d\n", i, pos);
    // }

    // // circlist_erase_pos
    // for (int i=4; i>0; i--){
    //     printf("\nerasing pos %d\n", i);
    //     circlist_erase_pos(list, i);
    //     circlist_print(list);
    // }

    // c_erase_data
    // circlist_erase_data(list, 40);
    // circlist_print(list);

    // c_insert()
    circlist_insert(list, 5, al[4]);
    circlist_print(list);

    circlist_free(list);
    return 0;
}
