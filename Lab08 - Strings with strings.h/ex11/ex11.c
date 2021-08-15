#include <stdio.h>
#include <string.h>
int main(void){
    
    char buff[5];
    int pass = 0;
    
    printf("\n Entre com a senha : \n");
    fgets(buff, 5, stdin);
    if (strcmp(buff, "1234")) {
        printf ("\n Senha Errada \n");
    } 
    else {
        printf ("\n Senha Correta \n");
        pass = 1;
    }

    if (pass) {
        /* O usuário acertou a senha, poderá continuar*/
        printf ("\n Acesso liberado \n");
    } 
    else {
        printf ("\n Acesso negado \n");
    }
    return 0;
}

/*
11) Considere o seguinte programa

a) Qual é a função do programa?
    checar uma senha para a entrada num sistem,a comparando a string de entrada com a determinada no codigo.

b) Qual a saída quando a senha correta é digitada (senha correta: 1234)
    Senha Correta
    Acesso liberado

c) Qual a saída para as seguintes senhas
a. 123
    Senha Errada
    Acesso negado

b. 12345
    Senha Correta
    Acesso liberado

c. 123456
    Senha Correta
    Acesso liberado

d) Em quais casos o programa obteve um comportamento inválido. Explique o motivo.
    nos casos b e c. O motivo é que a função strcmp compara as strings até o ultimo caracter valido, no caso 4. Qualquer coisa depois desse quarto caracter não importa para a função.
*/