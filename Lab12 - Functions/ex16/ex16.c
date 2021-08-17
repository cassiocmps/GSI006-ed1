#include <stdio.h>
#include <string.h>

typedef struct {
    double x, y;
} ponto;

void inc_dir(ponto *p, char c);
void inc_diag(ponto *p, char c[]);

int main(){

    ponto p;
    ponto *ponteiro;
    char direcao[10]; //dir;

    printf("Digite o ponto (x,y): ");
    scanf("%lf,%lf", &p.x, &p.y);
    getchar(); // necessario antes de um fgets precedido por um scanf para "absorver" o \n
    
    printf("Digite a direcao: ");
    fgets(direcao, 10, stdin);
    direcao[strcspn(direcao,"\n")] = '\0'; // fgets adiciona um \n entre o ultimo caracter da string e o seu \0.  esse comando substitui o \n por um \0 para facilitar a comparação

    // if (strcasecmp(direcao, "norte")==0) dir = 'n';
    // if (strcasecmp(direcao, "sul")==0) dir = 's';
    // if (strcasecmp(direcao, "leste")==0) dir = 'l';
    // if (strcasecmp(direcao, "oeste")==0) dir = 'n';

    ponteiro = &p;

    printf("Resultado: (%.0lf,%.0lf) %s  => ", p.x, p.y, direcao);
    inc_diag(ponteiro, direcao);
    printf("(%.0lf,%.0lf)\n", p.x, p.y);

    return 0;
}

void inc_dir(ponto *p ,char c){
    if (c=='n') p->y+=1;
    if (c=='s') p->y-=1;
    if (c=='l') p->x+=1;
    if (c=='o') p->x-=1;
}

void inc_diag(ponto *p, char c[]){
    if (strcasecmp(c,"sudeste")==0){
        inc_dir(p, 's');
        inc_dir(p, 'l');
    }
    if (strcasecmp(c,"sudoeste")==0){
        inc_dir(p, 's');
        inc_dir(p, 'o');
    }
    if (strcasecmp(c,"nordeste")==0){
        inc_dir(p, 'n');
        inc_dir(p, 'l');
    }
    if (strcasecmp(c,"noroeste")==0){
        inc_dir(p, 'n');
        inc_dir(p, 'o');
    }
}


/*
=> Crie um procedimento para andar na diagonal (sudeste, 
sudoeste, nordeste, noroeste). Use obrigatoriamente as funções do 
exercício anterior.

Exemplo de chamada:
ind_diag(p,"sudeste"); 
ind_diag(p,"sudoeste");

-------------------------------------------------------------------------------
Exemplo de Saída:

(1,3) sudeste => (2,2)
(2,4) sudoeste => (1,3)
-------------------------------------------------------------------------------
*/