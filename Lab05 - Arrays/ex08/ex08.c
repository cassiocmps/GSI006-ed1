#include <stdio.h>
#include <math.h>

int main(){
    printf("<< Media e desvio-padrao >>\n");

    int num[5], maior, menor;
    double media, total=0, somatorio=0, dp;

    for (int i=0; i<5; i++){
        
        printf("Digite o valor %d: ", i+1);
        scanf("%d", &num[i]);

        total+=num[i];

    }

    media=total/5;

    for (int i=0; i<5; i++) {
        somatorio+=(num[i]-media)*(num[i]-media);
    }

    dp=sqrt(somatorio/(5-1));

    printf("A media eh %.2lf e o desvio-padrao eh %.2lf\n", media, dp);

    return 0;
}

/*
Calcular a média e o desvio padrão amostral de 5 números informados pelo usuário.
obs: desvio-padrão (amostral, normalizado por N-1)

Exemplo de saída:
<< Media e desvio-padrao >>
Digite o valor 1: 50
Digite o valor 2: 60
Digite o valor 3: 70
Digite o valor 4: 80
Digite o valor 5: 60
A media eh 64 e o desvio-padrao eh 11.40
*/
