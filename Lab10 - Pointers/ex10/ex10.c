#include <stdio.h>

int main(){
    printf("<< Pointers >>\n");

    int vetor[10]={0,1,2,3,4,5,6,7,8,9};
    
    for (int i=9; i>=0; i--){
        printf("%d\n", *(vetor+i));
    }

    return 0;
}