#include <stdio.h>
#include <string.h>

int main(){
    printf("<< Alunos da graduação >>\n");

    struct graduando{
        char matricula[10], nome[30];
        double nota[3], media;
        int faltas;
    };

    struct graduando aluno[3];
    double maiorNota1=0, melhorMedia=0, piorMedia=100;
    char nomeProva1[30], nomeMelhorMedia[30], nomePiorMedia[30];

    for (int i=0; i<3; i++){
        printf("Entre com os dados do %do graduando:\n", i+1);
        printf("Matricula: ");
        fgets(aluno[i].matricula, 30, stdin);
        
        printf("Nome: ");
        fgets(aluno[i].nome, 30, stdin);

        for (int j=0; j<3; j++){
            printf("Nota da prova %d: ", j+1);
            scanf("%lf", &aluno[i].nota[j]);
            getchar();
            aluno[i].media+=aluno[i].nota[j];
        }

        aluno[i].media=aluno[i].media/3.0;        

        printf("NUmero de faltas: ");
        scanf("%d", &aluno[i].faltas);
        getchar();
        printf("\n");

        if (aluno[i].nota[0]>maiorNota1){
            maiorNota1=aluno[i].nota[0];
            strcpy(nomeProva1, aluno[i].nome);
        }

        if (aluno[i].media>melhorMedia){
            melhorMedia=aluno[i].media;
            strcpy(nomeMelhorMedia, aluno[i].nome);
        }

        if (aluno[i].media<piorMedia){
            piorMedia=aluno[i].media;
            strcpy(nomePiorMedia, aluno[i].nome);
        }        
    }

    printf("\nAluno com maior nota na prova 1 foi %.*s com %.1lf pontos.\n", (int)strlen(nomeProva1)-1, nomeProva1, maiorNota1);
    printf("Aluno com maior media geral foi %.*s com %.1lf pontos.\n", (int)strlen(nomeMelhorMedia)-1, nomeMelhorMedia, melhorMedia);
    printf("Aluno com menor media geral foi %.*s com %.1lf pontos.\n", (int)strlen(nomePiorMedia)-1, nomePiorMedia, piorMedia);

    printf("\nSituação dos alunos:\n");
    for (int i=0; i<3; i++){
        
        printf("%d- %.*s. ", i+1, (int)strlen(aluno[i].nome)-1, aluno[i].nome);
        
        if (aluno[i].faltas>18){ // 18 é o maximo de faltas permitidas para 75% de presença em 72 aulas
            printf("Reprovado por falta.\n");
        }
        else if (aluno[i].media<60){
            printf("Reprovado por nota.\n");
        }
        else printf("Aprovado.\n");
    }

    return 0;
}

/*
5.Crie uma estrutura representando os alunos de um curso de graduação. 
A estrutura deve conter a matrícula do graduando, nome, nota da primeira prova, 
nota da segunda prova, nota da terceira prova, média e número de faltas.

    (a) Permita ao usuário entrar com os dados de 3 alunos. 
    (b) Encontre o graduando com maior nota da primeira prova.
    (c) Encontre o graduando com maior média geral.
    (d) Encontre o graduando com menor média geral.
    (e) Mostre a situação final do graduando. Para ser aprovado o graduando precisa ter nota média final 
        maior ou igual a 60 e ter presença maior ou igual a 75% (considere um total de 72 aulas). 
        No caso de reprovação, mostrar o motivo da mesma, isto é, caso o graduando foi reprovado por 
        falta, mostrar “Reprovado por falta”. Caso tenha sido reprovado por nota, mostrar “Reprovado por nota”. 
        Se um graduando foi reprovado por falta e por nota, prevalece, como motivo para reprovação, as faltas. Assim,
        mostrar a mensagem “Reprovado por falta”. 


-------------------------------------------------------------------------------
Exemplo de saída:
Entre com os dados do 1º aluno: 
Matricula: 1
Nome: Paulo
Nota da prova 1: 50
Nota da prova 2: 70
Nota da prova 3: 60
Numero de faltas: 12

Entre com os dados do 2º aluno: 
Matricula: 2
Nome: Gustavo
Nota da prova 1: 95
Nota da prova 2: 90
Nota da prova 3: 100
Numero de faltas: 19

Entre com os dados do 3º aluno: 
Matricula: 3
Nome: Luis
Nota da prova 1: 50
Nota da prova 2: 60
Nota da prova 3: 58
Numero de faltas: 2

Aluno com maior nota na prova 1 foi Gustavo com 95,0 pontos.
Aluno com maior media geral foi Gustavo com 95,0 pontos.
Aluno com menor media geral foi Luis com 56,0 pontos.

Situacao dos Alunos: 
1- Paulo. Aprovado.
2- Gustavo. Reprovado por falta.
3- Luis. Reprovado por nota.
-------------------------------------------------------------------------------
*/