#include <stdio.h>
#include <string.h>

int main(){
    printf("<< Data >>\n");

    struct data {
        char mes[15];
        int dia, ano;
    };

    struct data cadastro[3];
    int maiorAno=0;

    for (int i=0; i<3; i++){
        
        printf("Digite o dia: ");
        scanf("%d", &cadastro[i].dia);
        getchar(); //getchar() captura o enter da entrada e impede que atrapalhe o fgets

        printf("Digite o mes: ");
        fgets(cadastro[i].mes, 15, stdin);

        printf("Digite o ano: ");
        scanf("%d", &cadastro[i].ano);
        getchar();

        printf("\n");
    }

    printf("Datas cadastradas: \n");
    
    for (int i=0; i<3; i++){
        printf("Dia %d de %.*s de %d\n", cadastro[i].dia, (int)strlen(cadastro[i].mes)-1, cadastro[i].mes, cadastro[i].ano);
        if (cadastro[i].ano>maiorAno){
            maiorAno=cadastro[i].ano;
        }
    }

    printf("\n%d foi o maior ano cadastrado.\n", maiorAno);

    

    return 0;
}

/*
1) Crie uma estrutura chamada data, que armazena o dia, mês e o ano (ilustração abaixo).  
Cadastre 3 datas, mostre as datas e o maior ano cadastrado. 

Data***
+------------+------------+---------------+
| Dia        | Mês        |   Ano         |    
+------------+------------+---------------+

-------------------------------------------------------------------------------
Exemplo de saída:
Digite o dia: 2
Digite o mes: Janeiro
Digite o ano: 2015

Digite o dia: 15
Digite o mes: Maio
Digite o ano: 2018

Digite o dia: 21
Digite o mes: Dezembro
Digite o ano: 2020


Datas cadastradas: 
Dia 2 de Janeiro de 2015
Dia 15 de Maio de 2018
Dia 21 de Dezembro de 2020

2020 foi o maior ano cadastrado.
-------------------------------------------------------------------------------
*/