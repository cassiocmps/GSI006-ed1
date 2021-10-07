#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "TStack.h"

int main(){
    char test1[30], test2[30];
    strcpy(test1, "(()[()])");
    strcpy(test2, "(([()])");
    printf("\n%s\n", test1);
    printf("\n WELL FORMED STRING: %d\n", well_formed(test1));
    printf("\n%s\n", test2);
    printf("\n WELL FORMED STRING: %d\n", well_formed(test2));
    
    return 0;
}
