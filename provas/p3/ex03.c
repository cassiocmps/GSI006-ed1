/*
Utilizando uma ED de Pilha (STACK) que armazena caracteres, 
faça um programa que lê uma string do teclado e, 
**utilizando a pilha**, mostre a string na ordem reversa. 
Entregar somente o código do programa principal. 
Não há necessidade de mostrar o código da pilha

Se a pessoa digitar abcd, o programa vai devolver: dcba

*/

int main(){
    TStack *st;
    char s[100], print;
    printf("\nINSIRA A STRING A SER INVERTIDA: ");
    fgets(s, 100, stdin);
    st = stack_create((strlen(s)-1));

    for (int i=0; i<(strlen(s)-1); i++){
        stack_push(st, s[i]);
    }

    for (int i=0; i<(strlen(s)-1); i++){
        stack_top(st, &print);
        printf("%c", print);
        stack_pop(st);
    }
    printf("\n");

    stack_free(st);
    return 0;
}