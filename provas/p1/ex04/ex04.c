#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double x, y;
} ponto;

typedef struct {
    ponto centro;
    double raio;
} circulo;


int main(){

   circulo c1;

   double area, distancia;

   c1.centro.x = 3;
   c1.centro.y = 5;
   c1.raio = 2;

   area = 3.14*c1.raio*c1.raio;
   distancia = sqrt(c1.centro.x*c1.centro.x + c1.centro.y*c1.centro.y);

   printf("Circulo: Centro(%.0lf,%.0lf); Raio %.0lf; Area: %.2lf; Distancia: %.1lf\n", c1.centro.x, c1.centro.y, c1.raio, area, distancia);

   return 0;
   
   // Ex04: Um círculo pode ser definido com duas informações
   // - um ponto central; que é sua coordenada x,y no espaço cartesiano
   // - um raio; que é a distância da borda ao centro

   // Crie uma estrura Circulo. Para isso, crie uma estrutura chamada Ponto, que armazenará as
   // coordenadas reais (x,y) de um ponto. Em seguida, crie uma estrutura chamada Circulo,
   // que define o círculo, isto é, armazena um ponto e um raio.
   
   // No programa principal crie uma variável para definir um círculo e a partir dessa variável
   // e mostre a área e a distância do centro do círculo até a origem. 
   // fórmulas:
   // area = 3,14*r*r
   // distancia d = sqtr(x*x + y*y)
   
   // Exemplo de saída: Circulo: Centro (3,5); Raio 2; Área: 12.56; Distancia: 5.0

}