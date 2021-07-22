#include <stdio.h>

int main() {
    float temp;
    printf("<< Conversor Temperatura >>\n");
    printf("Digite a temperatura (em Celsius): ");
    scanf("%f", &temp);
    printf("%.1f graus Celsius correspondem a %.1f Fahrenheit\n", temp, temp*1.8+32);
    return 0;
}