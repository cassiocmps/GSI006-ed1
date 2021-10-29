/*
ex03) Mostre como uma pilha pode ser usada para resolver a expressão 
matemática abaixo. Não confundir números negativos com subtrações.

Cada número e operador é lido em um passo. 
Para cada passo, mostre o estado da pilha 

Exemplo de como mostrar a pilha
2 2 <topo  // o número 2 está no topo
2 3 4 <topo // o número 4 está no topo

Expressão: 

1 -7 3 + * 4 -

--------------------------------------------------------------------------
1 <topo
1 -7 <topo
1 -7 3 <topo
1 -4 <topo (3 e -7 desempilhados, somando, e resultado é empilhado)
-4 <topo (-4 e 1 desempilhados, multiplicando, e resultado é empilhado)
-4 4 <topo
-8 <topo (4 e -4 desempilhados, subtraindo, e resultado é empilhado)

-8 é o unico elemento empilhado e portanto é o resutlado final


*/