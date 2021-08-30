#include <stdio.h>
#include <stdlib.h>
#include "cad.h"

int main () {
    
    char n[50], m[20];
    char main_n[50], main_m[20];
    double cra, main_cra;
    aluno *ponteiroA;

    printf("=== Cadastro de aluno ===\n");
    printf("Nome: ");
    scanf("%s", n);
    printf("Matricula: ");
    scanf("%s", m);
    printf("CRA: ");
    scanf("%lf", &cra);

    ponteiroA = cadastra_aluno(n, m, cra);

    imprime_aluno(ponteiroA);

    printf("\n=== Atualizando CRA ===\n");
    printf("Entre com o novo valor do CRA: ");
    scanf("%lf", &cra);
    atualizar_cra(ponteiroA, cra);

    imprime_aluno(ponteiroA);

    printf("\n=== Copiando dados do aluno para variaveis no MAIN ===\n");
    copia_dados(ponteiroA, main_n, main_m, &main_cra);
    printf("Variaveis no main:\n");
    printf("%s %s %.2lf\n", main_n, main_m, main_cra);

    destroi_aluno(ponteiroA);
    return 0;
    
}
