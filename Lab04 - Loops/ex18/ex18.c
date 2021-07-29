#include <stdio.h>

int main(){

    char opcao;
    float velocidade;
    
    while(1){
        printf("<< Conversor >>\n");
        printf("Digite uma opcao\n");
        printf("1 - para converter de km/h para m/s\n");
        printf("2 - para converter de m/s para hm/h\n");
        printf("q - para sair\n");

        scanf(" %c", &opcao);

        if (opcao=='1'){
            printf("Digite a velocidade (km/h): ");
            scanf("%f", &velocidade);
            printf("A velocidade em m/s eh %.2f\n\n", velocidade/3.6);
        }

        else if (opcao=='2'){
            printf("Digite a velocidade (m/s):");
            scanf("%f", &velocidade);
            printf("A velocidade em km/h eh %.2f\n\n", velocidade*3.6);
        }

        else if (opcao=='q') break;

        else printf("Opcao invalida! Retornando...\n\n");
    }

    return 0;
}
