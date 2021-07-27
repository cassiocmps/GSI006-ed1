#include <stdio.h>
#include <math.h>

int main() {
    int num, raizRedonda;
    float raiz;
    
    printf("<< Quadrado perfeito >>\n");
    
    printf("Digite o numero: ");
    scanf("%d",&num);
    
    raiz=sqrt((double)num);
    raizRedonda=raiz;
    // caso a o valor de raiz caiba em um integer, quer dizer q é um numero exato.
    
    if(raizRedonda==raiz) printf("A raiz quadrada de %d é %.0f.\n", num, raiz); 
    else printf("%d não é um quadrado perfeito.\n",num);
    
    return 0;
}