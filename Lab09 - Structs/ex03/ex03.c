#include <stdio.h>
#include <string.h>

int main(){
    printf("<< Endereços >>\n");

    struct endereco {
        char rua[100], numero[10], complemento[100], cidade[50], estado[5], cep[10];
    };

    struct endereco cadastro[3];

    for (int i=0; i<3; i++){
        printf("Rua: ");
        fgets(cadastro[i].rua, 100, stdin);

        printf("Numero: ");
        fgets(cadastro[i].numero, 10, stdin);

        printf("Complemento: ");
        fgets(cadastro[i].complemento, 100, stdin);

        printf("Cidade: ");
        fgets(cadastro[i].cidade, 50, stdin);

        printf("Estado: ");
        fgets(cadastro[i].estado, 5, stdin);

        printf("CEP: ");
        fgets(cadastro[i].cep, 10, stdin);

    }

    printf("Enderecos cadastrados que sao de \"MG\":\n");

    for (int i=0; i<3; i++){
        if (strcasecmp("MG\n", cadastro[i].estado)==0){
            printf("%.*s, %.*s. %.*s. %.*s-%.*s, %.*s.\n", (int)strlen(cadastro[i].rua)-1, cadastro[i].rua,
                                                         (int)strlen(cadastro[i].numero)-1, cadastro[i].numero, 
                                                         (int)strlen(cadastro[i].complemento)-1, cadastro[i].complemento, 
                                                         (int)strlen(cadastro[i].cidade)-1, cadastro[i].cidade,
                                                         (int)strlen(cadastro[i].estado)-1, cadastro[i].estado,
                                                         (int)strlen(cadastro[i].cep)-1, cadastro[i].cep);

        }
    }

    return 0;
}


/*
1) Crie uma estrutura chamada endereco, que armazena Rua, Número, Complemento,
Cidade, Estado e CEP (ilustração abaixo).  
Cadastre 3 endereços. Mostre ao final, todos os dados dos endereços cadastrados que são do estado “MG”

Endereco*
+------------+------------+---------------+
| Rua        | Número     |  Complemento  |    
+------------+------------+---------------+
| Cidade     | Estado     |     CEP       | 
+------------+------------+---------------+


-------------------------------------------------------------------------------
Exemplo de saída:
Rua: Joao
Numero: 32
Complemento: casa A
Cidade: Uberlandia
Estado: MG
CEP: 38400034


Rua: Almeida
Numero: 43
Complemento: Sem
Cidade: Araguari
Estado: MG
CEP: 38400045


Rua: Coronel Pedro
Numero: 25
Complemento: apto 40
Cidade: Caldas Novas
Estado: GO
CEP: 75780023


Enderecos cadastrados que sao de "MG":
Joao, 32. casa A. Uberlandia-MG, 38400034.
Almeida, 43. Sem. Araguari-MG, 38400045.
-------------------------------------------------------------------------------
*/