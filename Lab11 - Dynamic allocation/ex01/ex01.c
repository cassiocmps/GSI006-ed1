#include <stdio.h>
//lembre-se de incluir as bibliotecas adequadas
#include <stdlib.h>


int main(void){
 double *produtos;
 int n,i;

 printf("Informe o número de produtos: ");
  scanf("%d",&n);
  // é necessário usar o comando malloc para alocar a memória
  produtos = (double *)malloc(n*sizeof(double));

  for   (i = 0; i < n; i++){
    printf("Informe o valor do produto %d R$: ",i+1);
    scanf("%lf", &produtos[i]);
  } 

  printf("\nProdutos cadastrados\n" );
  for   (i = 0; i < n; i++){
    printf("Produto %d  - R$: %.2f\n" ,i+1, produtos[i]);
  }
  
  // ao terminar de usar o vetor, devemos liberar a memória
  free(produtos);

  return 0;
}

/*
1) Alocação dinâmica: outra utilidade dos ponteiros é que eles permitem 
fazermos o que é chamado de alocação dinâmica. Isso significa que podemos 
reservar espaços de memória enquanto estamos executando o programa. Seria
como criar variáveis com o programa executando. Por exemplo, considere um
vetor que armazenará o preço de produtos. Não sabemos quantos produtos serão
cadastradas enquanto estamos programando. Podemos fazer alocação dinâmica 
para resolver este problema. 

Implemente o programa abaixo, teste para diferentes
valores de n e discuta o que significa o valor de n e de sizeof(double) no 
commando malloc(n*sizeof(double)).


---------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>


int main(void){
 double *produtos;
 int n,i;

 printf("Informe o número de produtos: ");
  scanf("%d",&n);
  // é necessário usar o comando malloc para alocar a memória
  produtos = (double *)malloc(n*sizeof(double));

  for   (i = 0; i < n; i++){
    printf("Informe o valor do produto %d R$: ",i+1);
    scanf("%lf", &produtos[i]);
  } 

  printf("\nProdutos cadastrados\n" );
  for   (i = 0; i < n; i++){
    printf("Produto %d  - R$: %.2f\n" ,i+1, produtos[i]);
  }
  
  // ao terminar de usar o vetor, devemos liberar a memória
  free(produtos);

  return 0;
}
---------------------------------------------------------------

Suas considerações:

Quais foram os valores de n testados?
  2, 5 e 10
O que significa o valor de n?
  A função malloc recebe como parametro a quantidade de endereços de memoria que devem ser reservados.
  Dentro ddos parametros para essa função, n é a quantidade de variaveis que iram ocupar espaço no programa,
  que multiplicado pelo tipo de dado (integer=4, double=8, char=1, etc) dá à função a quantidade de endereços necessára. 
O que significa o valor de de sizeof(double) no commando malloc(n*sizeof(double)).
  Respondida junto com a questão anterior.

*/