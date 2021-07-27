#include <stdio.h>

int main(){

    float altura, peso, imc;

    printf("<< Calculo de IMC >>\n");

    printf("Altura (em cm): ");
    scanf("%f", &altura);
    altura=altura/100;

    printf("Peso (em kg): ");
    scanf("%f", &peso);

    imc = peso / (altura*altura);

    if (imc<18.5)            printf("IMC: %.1f (magreza)\n", imc);
    if (imc>=18.5 && imc<25) printf("IMC: %.1f (saudavel)\n", imc);
    if (imc>=25 && imc<30)   printf("IMC: %.1f (sobrepeso)\n", imc);
    if (imc>=30 && imc<35)   printf("IMC: %.1f (obesidade 1)\n", imc);
    if (imc>=35 && imc<40)   printf("IMC: %.1f (obesidade 2)\n", imc);
    if (imc>=40)             printf("IMC: %.1f (obesidade 3)\n", imc);

    return 0;
}