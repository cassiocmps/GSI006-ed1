#include <stdio.h>
#include <math.h>
// Determinar as raízes, reais ou complexas, de uma equação de segundo grau.
int main() {
    
    double a, b, c, discriminante, raiz1, raiz2, real, imagem;
    
    printf("<< Determinando raizes de equação de segundo grau >>\n");

    printf("Digite o termo a: ");
    scanf("%lf", &a);
    printf("Digite o termo b: ");
    scanf("%lf", &b);
    printf("Digite o termo c: ");
    scanf("%lf", &c);

    discriminante = b*b - 4*a*c;

    if (discriminante == 0) { //raizes iguais
        raiz1 = -b / (2*a);
        printf("As raizes são iguais, de valor %.2lf\n", raiz1);
    }

    else if (discriminante > 0) { //duas raizes reais
        raiz1 = (-b + sqrt(discriminante)) / (2*a);
        raiz2 = (-b - sqrt(discriminante)) / (2*a);
        printf("As raizes sao reais: %.2lf e %.2lf\n", raiz1, raiz2);
    }

    else { //raizes complexas
        real = -b / (2*a);
        imagem = sqrt(-discriminante) / (2*a);
        printf("As raizes sao complexas: %.2lf+%.2lfi e %.2f-%.2fi", real, imagem, real, imagem);
    }

    return 0;
} 