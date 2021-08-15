#include <stdio.h>

int main(){
    printf("<< Pointers >>\n");
    int  v1 = 1;
    double v2 = 2;
    char c = 'a';

    int *p_v1;
    double *p_v2;
    char *p_c;

    p_v1 = &v1;
    p_v2 = &v2;
    p_c = &c;


    printf("\nEndereço de v1 %u", p_v1);
    printf("\nEndereço de v2 %u", p_v2);
    printf("\nEndereço de c %u", p_c);

    printf("\nEndereço+1 de v1 %u", p_v1+1);
    printf("\nEndereço+1 de v2 %u", p_v2+1);
    printf("\nEndereço+1 de c %u", p_c+1);

    printf("\nEndereço-1 de v1 %u", p_v1-1);
    printf("\nEndereço-1 de v2 %u", p_v2-1);
    printf("\nEndereço-1 de c %u", p_c-1);

    printf("\nEndereço+2 de v1 %u", p_v1+2);
    printf("\nEndereço+2 de v2 %u", p_v2+2);
    printf("\nEndereço+2 de c %u", p_c+2);

    printf("\nEndereço-2 de v1 %u", p_v1-2);
    printf("\nEndereço-2 de v2 %u", p_v2-2);
    printf("\nEndereço-2 de c %u", p_c-2);

    return 0;
}

/* 5)	Os operadores + e – funcionam com ponteiros. Chamamos de aritmética de ponteiros. 
Considere o código abaixo. Complete o código e preencha a tabela abaixo com os endereços de cada printf.

*** modificar o especificador de formato no printf caso seja necessário

+-----------------------------+-------------------+-------------------+-----------------+-------------------+-------------------+
| Nome variável               |                   |                   |                 |                   |                   |
| / Endereços                 | Endereço var-2    | Endereço var-1    | Endereço var    | Endereço var+1    | Endereço var+2    |
+-----------------------------+-------------------+-------------------+-----------------+-------------------+-------------------+
|                             | 1965491292        | 1965491296        |1965491300       |1965491304         | 1965491308        |
| p_v1                        |                   |                   |                 |                   |                   |
+-----------------------------+-------------------+-------------------+-----------------+-------------------+-------------------+
|                             | 1965491288        | 1965491296        |1965491304       |1965491312         | 1965491320        |
| p_v2                        |                   |                   |                 |                   |                   |
+-----------------------------+-------------------+-------------------+-----------------+-------------------+-------------------+
|                             |  1965491297       | 1965491298        |                 | 1965491300        | 1965491301        |
| p_c                         |                   |                   |1965491299       |                   |                   |
+-----------------------------+-------------------+-------------------+-----------------+-------------------+-------------------+


*/