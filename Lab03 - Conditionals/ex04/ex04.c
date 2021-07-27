#include <stdio.h>

int main(){
    float nota[3], maior=0, menor=10;
    char nome[3], melhor, pior;

    printf("<< Notas da Turma >>\n");
    
    for (int i=0; i<3; i++) {
        printf("Entre com o nome do aluno #%d: ", i+1);
        scanf(" %c", &nome[i]);
        
        printf("Entre com a nota do aluno #%d: ", i+1);
        scanf(" %f", &nota[i]);

        if (nota[i]>maior) {
            maior = nota[i];
            melhor = nome[i];
            }
        
        if (nota[i]<menor) {
            menor = nota[i];
            pior = nome[i];
            } 
    }

    printf(" %c. tem a maior nota (%.1f) e %c. a menor (%.1f)\n", melhor, maior, pior, menor);

    return 0;
}