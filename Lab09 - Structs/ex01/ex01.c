#include <stdio.h>

int main(){
    printf("<< Cadastrar telefones >>\n");

    struct numero {
        int ddd, telefone;
    };

    struct numero cliente[3];

    for (int i=0; i<3; i++){
        printf("digite o DDD: ");
        scanf("%d", &cliente[i].ddd);
        printf("digite o telefone: ");
        scanf("%d", &cliente[i].telefone);
    }

    printf("Telefones cadastrados: \n");
    
    for (int i=0; i<3; i++){
        printf("%d %d\n", cliente[i].ddd, cliente[i].telefone);
    }

    return 0;
}

/*
1) Crie uma estrutura chamada telefone, que armazena o DDD e o telefone (ilustração abaixo).  
Cadastre 3 telefones e mostre na tela os telefones cadastrados. 

Telefone**
+------------+------------+
| DDD        | Telefone   |  
+------------+------------+

-------------------------------------------------------------------------------
Exemplo de saída:
Digite o DDD: 34
Digite o telefone: 991501111
Digite o DDD: 31
Digite o telefone: 991502222
Digite o DDD: 64
Digite o telefone: 991503333

Telefones cadastrados: 
34 991501111
31 991502222
64 991503333
-------------------------------------------------------------------------------
*/