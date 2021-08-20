#include <stdio.h>
#include <stdlib.h>

// Fazer um programa para cadastro de livros. As informações para cadastro são: 
// - o nome do livro
// - O preço
// - Indicação se o livro é novo ou usado
// - ano de compra


// Definir as estruturas necessárias aqui:

typedef struct {
    char nome[50];
    double preco;
    int novo;
    int anoCompra;
} livro;


int main(){

    livro *vetor;
    int n;
    // Ex 01: permitir que o usuário cadastre quantos livros quiser
    //  - ler do teclado a quantidade de livros que o usuário escolheu
    //  - ler do teclado as informações dos livros
    printf("Informe quantos livros deseja cadastrar: ");
    scanf("%d", &n);

    vetor = (livro *) malloc(n*sizeof(livro));

    for (int i=0; i<n; i++){
        printf("\nInformações do livro %d:\n", i+1);
        printf("Nome: ");
        getchar();
        fgets(vetor[i].nome, 50, stdin);
        printf("Preco: ");
        scanf("%lf", &vetor[i].preco);
        printf("Novo? (1 para sim e 0 para não) ");
        scanf("%d", &vetor[i].novo);
        printf("Ano da compra: ");
        scanf("%d", &vetor[i].anoCompra);
    }

    // for (int i=0; i<n; i++){
    //     printf("\nInformações do cadastradas do livro %d:\n", i+1);
    //     printf("Nome: %s", vetor[i].nome);
    //     printf("Preco: %.2lf\n", vetor[i].preco);
    //     if (vetor[i].novo==1) printf("Livro novo\n");
    //         else printf("Livro usado\n");
    //     printf("Ano da compra: %d\n", vetor[i].anoCompra);
    // }

    free(vetor);
  
    return 0;
}