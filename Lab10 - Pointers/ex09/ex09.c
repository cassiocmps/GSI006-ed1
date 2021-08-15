#include <stdio.h>

int main(){
    printf("<< Pointers >>\n");

    double vetor[10]={0,1,2,3,4,5,6,7,8,9};
    
    for (int i=0; i<10; i++){
        printf("%lf\n", *(vetor+i));
    }

    return 0;
}