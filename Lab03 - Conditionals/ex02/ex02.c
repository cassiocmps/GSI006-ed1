#include <stdio.h>

int main(){
    int temp, newTemp=0;
    char unidade;

    printf("<< Conversor de Temperatura >>\n");
    printf("Digite a temperatura: ");
    scanf("%d", &temp);

    printf("Digite a unidade: ");
    scanf(" %c", &unidade);

    if (unidade=='c'){
        newTemp = temp*1.8+32;
        printf("%d graus Celsius equivale a %d graus Fahrenheit\n", temp, newTemp);
    }
    
    if (unidade=='f'){
        newTemp = (temp-32)*5/9;
        printf("%d graus Fahrenheit equivale a %d graus Celsius\n", temp, newTemp);
    }

    return 0;
}
/*
Faça um algoritmo que calcule a média ponderada das notas de 3 provas. A primeira e
a segunda prova têm peso 1 e a terceira tem peso 2. Antes de o usuário entrar com as
notas do aluno ele entre com a inicial do nome do aluno (mais adiante aprenderemos
como entrar com o nome completo do aluno – por enquanto nesta lista vamos
identificar o aluno somente com uma letra). Ao final, mostrar o nome do aluno
juntamente com a sua média e indicar se o aluno foi aprovado ou reprovado.
Exemplo de saída:
<< Cálculo da Média >>
Digite a inicial do nome do aluno: T
Digite a nota da prova 1: 40
Digite a nota da prova 2: 40
Digite a nota da prova 3: 80
A nota média do aluno T. é 60 => APROVADO!
*/