#include <stdio.h>
#include <stdlib.h>

// Definir as estruturas necessárias aqui (copiar do exercício anterior):
typedef struct {
    char nome[50];
    double preco;
    int novo;
    int anoCompra;
} livro;

// Função:
// Essa função retorna o livro usado mais antigo
// - Entrada: todos os livros cadastrados 
// - Saída: índice do vetor indicando o livro usado mais antigo
// (se houver empate pode ser retornado qualquer um dos livros)

int buscar_mais_antigo (livro vetor[], int tamanho){
    
    int antigo = vetor[0].anoCompra;
    int indice = 0;

    for (int i=0; i<tamanho; i++){
        if (vetor[i].novo!=1){
            if (vetor[i].anoCompra < antigo) {
                antigo = vetor[i].anoCompra;
                indice = i;
            }
        }
    }

    return indice;
}


int main(){

   // Ex02: utilizando a função de buscar, mostre
   // todas as informações do livro *usado* mais antigo

   // Todas as funções de entrada e saída devem estar no programa
   // principal

   // Dica: para testar, crie um vetor estático preenchido com alguns valores (opcional)
   

    livro *vetor;
    int n, indiceAntigo;

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

    printf("Livro usado mais antigo: \n");

    indiceAntigo = buscar_mais_antigo(vetor, n);

    printf("\nInformações do livro mais antigo:\n");
    printf("Nome: %s", vetor[indiceAntigo].nome);
    printf("Preco: %.2lf\n", vetor[indiceAntigo].preco);
    printf("Livro usado\n");
    printf("Ano da compra: %d\n", vetor[indiceAntigo].anoCompra);

    free(vetor);
  
    return 0;

  
    return 0;
}