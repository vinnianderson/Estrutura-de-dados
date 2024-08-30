Lista de Exercícios de Estruturas de Dados Lineares


Implementação do TAD – Stack
Em sala de aula, implementamos o TAD Stack (pilha) de inteiros. A pilha foi 
implementada utilizando um vetor para guardar os dados empilhados (ver código 
disponibilizado no Teams da disciplina). 

1ªQuestão: Implemente um programa para inverter um dado número inteiro. O 
número a ser invertido deverá ser fornecido pelo usuário. O programa somente 
deverá aceitar números inteiros maiores que zero.

Exemplo de entrada
Informe um inteiro maior que zero: 12345
Exemplo de saída
Número invertido: 54321

2ªQuestão: Implemente um programa para converter um número inteiro, 
fornecido pelo usuário na notação decimal (base 10), para um número expresso 
no sistema de numeração binário (base 2).
 A conversão é realizada pela divisão repetida, pela base, à qual o número está sendo convertido, e então se tomando os restos da divisão na ordem inversa. Por exemplo, a conversão para binário 
do número 6 exige três de tais divisões: 6/2 = 3 com resto 0, 3/2 = 1, com resto 
1 e, finalmente, 1/2 = 0 com resto 1. Os restos 0, 1 e 1 são colocados na ordem 
inversa, de modo que o binário equivalente a 6 é igual a 110. 

OBS.: A solução dos problemas propostos é bem simples se utilizarmos, em 
nossa lógica, o TAD Stack (pilha). Implemente soluções para os problemas
propostos utilizando o TAD Stack implementado em sala.

3ª Questão: Implemente um programa para determinar se uma palavra é ou não 
um palíndromo, ou seja, se a palavra é soletrada identicamente do início para o 
fim e do fim para o início. A palavra (String) a ser analisada deve ser fornecida 
pelo usuário. Exemplos de palíndromos: “asa”, “ovo”, “radar”, “reviver”. 

OBS.: Utilizando, como exemplo, a pilha de inteiros que implementamos em sala,
implemente uma pilha de caracteres e a utilize na solução do problema proposto 
na 3ª questão.