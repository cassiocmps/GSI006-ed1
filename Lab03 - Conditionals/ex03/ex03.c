#include <stdio.h>

int main(){
    float valor;
    char federacao;

    printf("<< Valor do Produto com imposto >>\n");
    printf("Digite o valor do produto R$: ");
    scanf("%f", &valor);

    printf("Digite a unidade da federação: ");
    scanf(" %c", &federacao);

    if (federacao=='1'){
        valor += valor*0.07;
        printf("Valor final com impostos R$: %.2f\n", valor);
    }
    
    else if (federacao=='2'){
        valor += valor*0.12;
        printf("Valor final com impostos R$: %.2f\n", valor);
    }

    else if (federacao=='3'){
        valor += valor*0.15;
        printf("Valor final com impostos R$: %.2f\n", valor);
    }

    else if (federacao=='4'){
        valor += valor*0.08;
        printf("Valor final com impostos R$: %.2f\n", valor);
    }

    else printf("Federação não cadastrada\n");

    return 0;
}