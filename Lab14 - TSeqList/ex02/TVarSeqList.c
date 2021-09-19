#include <stdio.h>
#include <stdlib.h>
#include "TVarSeqList.h" //inclui os Protótipos
#include <math.h>

//Definição do tipo lista
struct lista {
    int qtd, tam_i, tam_max;
    struct aluno *dados;
};

Lista* cria_lista(int tamanho){ 
    Lista *li;
    li = (Lista *)malloc(sizeof(struct lista)); //a alocação com malloc é importante pois não desaparecem ao final da função
    
    if (li != NULL) // verifica se foi realmente alocado. pode acontecer erro quando não há memoria disponivel
    {
        li->qtd = 0; // importante iniciar com zero, indicando que a lista está vazia. caso contrario as funções de incremento/decremento de qtd vão operar sobre lixo de memoria
        li->tam_i = tamanho;
        li->tam_max = tamanho;
        li->dados = (Aluno *)malloc (sizeof(struct aluno)*tamanho);
    }

    return li;
}

int consulta_lista_pos(Lista *li, int pos, struct aluno *al){
    if (li == NULL)
        return -1;
    if (pos <=0 || pos > li->qtd) //verifica se a posição passada eh valida;
        return -1;
    *al = li->dados[pos-1]; // a variavel temporaria receberá os dados da lista na posicao indicada, uma vez q o main não tem acesso a lista
    return 0;
}

int consulta_lista_mat(Lista* li, int mat, struct aluno *al){
    if(li == NULL)
        return -1;
    
    int i = 0;
    while(i < li->qtd && li->dados[i].matricula != mat){ // percorre o vetor enquanto a matricula for diferente
        i++;
    }
    // ao encontrar uma matricula correspondente, sai do loop e o valor do i representa a posição da matricula buscada
    
    if(i == li->qtd) // se i chegar ao valor de qtd, indica q o ve tor todo foi percorrido e não foi encontrado a matricula
        return -1;
    
    *al = li->dados[i]; // agora o aluno temporario vai receber os dados encontrados
    
    return 0;
}

int insere_lista_inicio(Lista *li, struct aluno al){
    if (li == NULL) //verifica se a lista existe
        return -1;
    if (li->qtd == li->tam_max)
        // printf("passei aqui\n");
        realoca_lista(li);
    
    for (int i=li->qtd-1; i>=0; i--) { // percorre o vetor de traz pra frente
        li->dados[i+1] = li->dados[i]; // e passando os componentes para a posição da frente
    }
    li->dados[0] = al; // e a primeira posição recebe o termo inserido na chamada da função
    li->qtd++; // +1 no tamanho da lista
    return 0;
}

int insere_lista_final(Lista *li, struct aluno al){
    if (li == NULL) // verifica se a lista já foi alocada
        return -1;
    
    if (li->qtd == li->tam_max)
        realoca_lista(li);
    
    li->dados[li->qtd] = al; // o aluno recebido é inserido no vetor dados na posição qtd
    li->qtd++; // registra o aumento da lista
    
    return 0;
}

int insere_lista_ordenada(Lista* li, struct aluno al){
    if(li == NULL)
        return -1;
    
    if (li->qtd == li->tam_max)
        realoca_lista(li);
    
    int k,i = 0;
    while(i<li->qtd && li->dados[i].matricula < al.matricula){
    // o loop para quando ele encontra uma matricula da lista maior que a matricula que se quer inserir
        i++;   // assim, o loop fecha e o valor de i é a posição que deve ser inserido o novo aluno
    }
    
    for(k=li->qtd-1; k >= i; k--){ // percorre o vetor de traz pra frente, até a posição encontrada no laço anterior
        li->dados[k+1] = li->dados[k]; // repassando os alunos para a posição da frente
    }
    
    // assim, a posição i estará liberada para receber os dados do novo aluno
    li->dados[i] = al;
    li->qtd++;
    
    return 0;
}

int remove_lista(Lista* li, int mat){
    if(li == NULL)
        return -1;
    if(li->qtd == 0)
        return -1;

    int k,i = 0;
    while(i<li->qtd && li->dados[i].matricula != mat) // percorre até encontrar a matricula correspondente
        i++; // salva qual a posição de tal matricula

    if(i == li->qtd) // elemento nao encontrado
        return -1;
    
    for(k=i; k< li->qtd-1; k++) // mesma ideia de remover_lista_inicio(), mas a partir da posição encontrada pelo while anterior
        li->dados[k] = li->dados[k+1];
    
    li->qtd--; // mesma obs de remover_lista_inicio() sobre a copia do ultimo elemento
    
    return 0;
}

int remove_lista_otimizado(Lista* li, int mat){
    if(li == NULL)
        return -1;
    if(li->qtd == 0)
        return -1;
    
    int i = 0;
    while(i<li->qtd && li->dados[i].matricula != mat) // percorre o vetor até encontrar a matricula
        i++; // salva a posição
    
    if(i == li->qtd)
        return -1;

    li->qtd--;
    li->dados[i] = li->dados[li->qtd]; // a posição encontrada vai receber o ultimo item da lista
    // otimiza o tempo de processamento, descartando o loop q iria reposicionar todos os itens da posicao encontrada em diante

    return 0;
}

int remove_lista_inicio(Lista* li){
    if(li == NULL)
        return -1;
    if(li->qtd == 0)
        return -1;
    
    for(int i=0; i < li->qtd-1; i++) // percorre o vetor puxando o aluno da frente para a posição anterior
        li->dados[i] = li->dados[i+1];
    
    li->qtd--; // e ao final diminui o tamanho da lista
    // obs: o ultimo aluno vai ter seus dados dupĺicados na proxima posição do vetor, mas não importa pq não vai ser acessado, uma vez q diminuimos o tamanho do vetor
    
    return 0;
}

int remove_lista_final(Lista* li){
    if(li == NULL)
        return -1;
    if(li->qtd == 0)
        return -1;
    
    li->qtd--; // apenas diminui o tamanho da lista
    // o elemento continuara na memoria, mas com o qtd menor não é possivel acessa-lo
    
    return 0;
}

int tamanho_lista(Lista* li){
    if(li == NULL)
        return -1;
    else
        return li->qtd; // retorna o tamanho da lista
}

int lista_cheia(Lista* li){
    if(li == NULL)
        return -1;
    
    return (li->qtd == MAX); // retorna um bool, comparando a qtd com o maximo de elementos q o vetor suporta
}

int lista_vazia(Lista* li){
    if(li == NULL)
        return -1;
    
    return (li->qtd == 0); // retorna um bool, comparando a qtd com 0
}

int imprime_lista(Lista *li){
    if (li == NULL) // verifica se a lista existe
        return -1;

    for (int i = 0; i < li->qtd; i++) { // percorre o vetor baseado nos alunos inseridos, controlados pela variavel qtd
        printf("\nMatricula: %d", li->dados[i].matricula);
        printf("\nNome: %s\n", li->dados[i].nome);
        printf("Notas: %.1f;%.1f;%.1f\n", li->dados[i].n1, li->dados[i].n2, li->dados[i].n3);
    }
    return 0;
}

void libera_lista(Lista *li){
    // free(li->dados);
    free(li);
}

int realoca_lista(Lista* li){
    
    li->tam_max = li->tam_max + li->tam_i;
    Aluno* ponteiro = realloc(li->dados, sizeof(struct aluno)*li->tam_max);
    // realloc (li->dados, sizeof(struct aluno)*li->tam_max);
    
    if (ponteiro == NULL) 
        return -1;

    return 0;
}

int tamanho_max_lista(Lista* li){
    if(li == NULL)
        return -1;
    else
        return li->tam_max;
}

int compacta_lista(Lista* li){
    if(li == NULL)
        return -1;
    
    int tamanho_novo = ceil(li->qtd/li->tam_i)*li->tam_i;
    
    void* ponteiro = realloc (li->dados, sizeof(struct aluno)*tamanho_novo);
    if (ponteiro == NULL) 
        return -1;
    
    li->tam_max = tamanho_novo;

    return 0;
}
