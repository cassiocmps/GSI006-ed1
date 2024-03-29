#include <stdio.h>
#include <string.h>

int main(){
    printf("<< Consumo de energia >>\n");

    struct eletro {
      char nome[15];
      float potencia, tempo;
    };

    struct eletro eletrodomestico[5];
    float dias, total;

    for (int i=0; i<5; i++){
      printf("\nInforme os dados do %do eletrodomestico:\n", i+1);
      
      printf("Nome: ");
      fgets(eletrodomestico[i].nome, 15, stdin);

      printf("Potencia: ");
      scanf("%f", &eletrodomestico[i].potencia);
      getchar();

      printf("Tempo ativo por dia: ");
      scanf("%f", &eletrodomestico[i].tempo);
      getchar();

    }

    printf("\nInforme um valor de tempo (em dias): ");
    scanf("%f", &dias);

    for (int i=0; i<5; i++){
      total+=eletrodomestico[i].potencia*eletrodomestico[i].tempo;
    }
    printf("Consumo total: %.0f KW\n", total);

    printf("Consumo relativo: \n");
    for (int i=0; i<5; i++){
      printf("%.*s: %.1f%%\n", (int)strlen(eletrodomestico[i].nome)-1, eletrodomestico[i].nome, ((eletrodomestico[i].potencia*eletrodomestico[i].tempo)/total)*100);
    }   

    return 0;
}

/*
6.Faça um programa que controla o consumo de energia dos eletrodomésticos de uma casa.

    • Crie e leia as informações de 5 eletrodomésticos: o nome (máximo 15 letras), 
      potencia (real,  em kW) e tempo ativo por dia (real, em horas).

    • Leia um valor de tempo t (em dias), calcule e mostre o consumo total na casa e
      o consumo relativo de cada eletrodoméstico  (consumo/consumo total) nesse período
      de tempo. Apresente este ultimo dado em porcentagem.

-------------------------------------------------------------------------------
Exemplo de saída:
Informe os dados do 1º eletrodomestico: 
Nome: Geladeira
Potencia: 800
Tempo ativo por dia: 24

Informe os dados do 2º eletrodomestico: 
Nome: Ar Condicionado
Potencia: 1500
Tempo ativo por dia: 8

Informe os dados do 3º eletrodomestico: 
Nome: Chuveiro
Potencia: 4500
Tempo ativo por dia: 1

Informe os dados do 4º eletrodomestico: 
Nome: Radio
Potencia: 100
Tempo ativo por dia: 6

Informe os dados do 5º eletrodomestico: 
Nome: Computador
Potencia: 750
Tempo ativo por dia: 18

Informe um valor de tempo (em dia): 30
Consumo total: 1494000 KW
Consumo relativo: 
Geladeira 38.6%
Ar Condicionado 24.1%
Chuveiro 9.0%
Radio 1.2%
Computador 27.1%
-------------------------------------------------------------------------------
*/