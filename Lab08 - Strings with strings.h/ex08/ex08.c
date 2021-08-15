#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    printf("<< Vetor de Char >>\n");

    char nome[50], cpf[12], rg[9], endereco[100], cidade[50], estado[3], cep[9];
    
    printf("Digite seu nome: ");
    fgets(nome, 50, stdin);

    printf("Digite seu CPF(somente numeros): ");
    fgets(cpf, 12, stdin);

    printf("Digite seu RG(somente nummeros): ");
    fgets(rg, 9, stdin);

    printf("Digite seu endereco(rua, numero e complemento): ");
    fgets(endereco, 100, stdin);

    printf("Digite a cidade: ");
    fgets(cidade, 50, stdin);

    printf("Digite a estado(UF): ");
    fgets(estado, 3, stdin);

    printf("Digite o CEP(somente numeros): ");
    fgets(cep, 9, stdin);

    printf("\t\tD E C L A R A C A O \n");
    printf("Eu, %.*s, RG %.*s, CPF %.*s,\n", (int)strlen(nome)-1, nome, (int)strlen(rg)-1, rg, (int)strlen(nome)-1, cpf);
    printf("residente a %.*s, %.*s-%.*s,\n", (int)strlen(endereco)-1, endereco, (int)strlen(cidade)-1, cidade, (int)strlen(estado)-1, estado);
    printf("CEP %.*s, venho por meio deste declarar que vou estudar para a prova.\n", (int)strlen(cep)-1, cep);

    return 0;
}
