#include <stdio.h>
#include <string.h>
int main(void){
    
    char buff[6];
    int pass = 0;
    
    printf("\n Entre com a senha : \n");
    fgets(buff, 6, stdin);
    buff[strcspn(buff,"\n")] = '\0';

    if(strcmp(buff, "1234")) {
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
12) A função fgets() também permite a leitura de strings do teclado. A diferença para a
função gets() é que é possível limitar o número de caracteres que serão lidos do
teclado (no caso representado por stdin – standard input).
Exemplo:
char nome[100];
fgets(nome,100,stdin);
Com esse comando é possível ler um nome com até 99 caracteres (o centésimo
caractere é ‘\0’, colocado automaticamente pelo fgets()).
Uma observação importante é que o fgets armazena o caractere `\n` (newline). Assim,
no exemplo acima, se o nome digitado for Maria, a string nome fica assim:
‘M’
‘a’
‘r’
‘i’
‘a’
‘\n’
‘\0’
lixo
lixo
O seguinte comando pode ser usado para substituir o `\n` por `\0`
nome[strcspn(nome, "\n")] = '\0';
a) Pense em uma solução para o problema do exercício 11 que utiliza fgets.
Considere que o tamanho máximo de uma senha são 4 dígitos.
b) Teste com os seguintes valores
a. 123
b. 12345
c. 123456
*/