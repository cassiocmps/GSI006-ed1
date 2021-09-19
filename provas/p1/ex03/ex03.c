#include <stdio.h>
#include <stdlib.h>

// Função: Cálculo do lucro
// Crie um função que calcula qual foi o lucro (ou prejuízo) de uma venda
// A função recebe como entrada o preço de compra e o preço de venda
// Ela calcula e retorna o porcentual de lucro ou prejuízo obtido
//
// A função deve retornar um valor inteiro de acordo com a classificação listada na tabela abaixo.
// Valores inválidos correspondem a números negativos e zeros
// Todos os comandos de entrada e saída devem estar no programa principal
// Todos os cálculos devem ser feitos na função.

/*
+-------------------+-----------------------------------------------+----------------+
| Retorno da Função | Porcentual de lucro                           | Classificação  |
+-------------------+-----------------------------------------------+----------------+
| -1                | -                                             | Valor invalido |
+-------------------+-----------------------------------------------+----------------+
| 1                 | abaixo ou igual 0%                            | Prejuízo       |
+-------------------+-----------------------------------------------+----------------+
| 2                 | acima de 0% e menor ou igual a 20%            | Lucro pequeno  |
+-------------------+-----------------------------------------------+----------------+
| 3                 | acima de 20% e menor ou igual a 40%           | Lucro bom      |
+-------------------+-----------------------------------------------+----------------+
| 4                 | acima de 40%                                  | Lucro alto     |
+-------------------+-----------------------------------------------+----------------+

*/
int calculo_lucro (double compra, double venda, double *porcentagem){
    
    double lucroBruto, margemLucro;

    lucroBruto = venda - compra;
// check:<<<erro: e3.3: Cálculo com erros (não corresponde a porcentagem pedida OU erro na fórmula OU porcentagem baseada na venda e não na compra OU divisão inteira )>>>>
    margemLucro = (lucroBruto / venda) * 100.0;
    *porcentagem = margemLucro;

    if (margemLucro <= 0) return 1;
    else if (margemLucro > 0 && margemLucro <= 20) return 2;
    else if (margemLucro > 20 && margemLucro <= 30) return 3;
    else if (margemLucro > 40) return 4;
    else return -1;// check:<<<erro: e3.2: Faltou testar os valores inválidos dentro da função / teste errado / faltou alguns testes>>>>
    // check:<<<comentário: e3.4: o último teste é desnecessário E/OU alguns testes no IF são desnecessários>>>>
}

int main(){
    double compra, venda;
    int calculo;
    double porcentagem;
   // Ex03: utilizando a função de cálculo de lucro, leia o preço de compra e venda
   // e mostre o percentual de lucro ou prejuízo e a classificação de acordo com
   // a tabela acima. 
   printf("Digite o preco de compra: ");
   scanf("%lf", &compra);
   printf("Digite o preco de venda: ");
   scanf("%lf", &venda);

   calculo = calculo_lucro(compra, venda, &porcentagem);

   printf("Preço de compra: %.0lf; Preco de venda: %.0lf; ", compra, venda);
   if (calculo == 1) printf("Prejuizo de %.0lf%%\n", porcentagem);
   else if (calculo == 2) printf("Lucro pequeno de %.0lf%%\n", porcentagem);
   else if (calculo == 3) printf("Lucro bom de %.0lf%%\n", porcentagem);
   else if (calculo == 4) printf("Lucro alto de %.0lf%%\n", porcentagem);
   else printf("Margem: erro no calculo\n");
   
   // exemplo de saída:
   // Preço de compra: 10; Preco de venda:11; Lucro Pequeno de 10%
   // Preço de compra: 10; Preco de venda: 9; Prejuízo de 10%
  
    return 0;
}