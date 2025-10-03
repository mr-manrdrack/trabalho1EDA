# trabalho1EDA
1º Trabalho EDA UPE 2025
1° Trabalho de Implementação de EDA
 
1. Implemente em C ou C++ um programa para construir uma lista encadeada dupla cuja estrutura do nó é a seguinte:

typedef struct no{
   int dado;
   struct no *anterior,*proximo;
} tListaDupla;

Este programa deve ter as seguintes funcionalidades:

- Informar se essa lista está ou não vazia;
- Ter uma opção para criar uma lista unitária desse tipo apenas se a mesma estiver vazia;
- Permitir a inserção de números inteiros inéditos, de modo que essa lista fique em ordem crescente e seja mantida sua estrutura duplamente encadeada;
- Possibilitar a remoção de qualquer número dessa lista, sem desordená-la ou alterar sua estrutura duplamente encadeada;
- Possuir uma opção para pesquisar um número inteiro nessa lista e informar se o mesmo foi ou não encontrado;
- Ter uma opção para exibir uma listagem dos números dessa lista em ordem crescente e uma outra opção para listar esses mesmos números em ordem decrescente;
- Por fim, mostrar uma opção para finalizar o programa, de modo que antes dessa finalização a lista encadeada dupla seja destruída, mencionando inclusive a quantidade de nós liberados.

2. Elabore um outro programa também em C ou C++ usando uma lista simplesmente encadeada para criar e manipular uma pilha de números inteiros cuja estrutura do nó é mostrada abaixo:

typedef struct no{
   int dado;
   struct no *proximo;
} tPilhaSimples;

Este programa deve ter opções para testar se a pilha está vazia, criar uma pilha unitária apenas se a mesma estiver vazia, empilhar números, desempilhar números (desde que a pilha não esteja vazia), mostrar os elementos em forma de pilha e permitir finalizar o programa liberando antes as posições de memória alocadas dinamicamente mostrando a quantidade de nós excluídos.

3. Desenvolva mais um programa em C ou C++ usando uma lista simplesmente encadeada para criar e manipular uma fila de números inteiros cuja estrutura do nó é mostrada abaixo:

typedef struct no{
   int dado;
   struct no *proximo;
} tFilaSimples;

Este programa deve ter opções para testar se a fila está vazia, criar uma fila unitária apenas se a mesma estiver vazia, enfileirar números, desenfileirar números (desde que a fila não esteja vazia), mostrar os elementos conforme dispostos na fila e permitir finalizar o programa liberando antes as posições de memória alocadas dinamicamente mostrando a quantidade de nós excluídos.


ATENÇÃO:

- Utilizar alocação dinâmica de memória na resolução das questões deste trabalho.
- Fornecer o código fonte com comentários e o código executável, em conformidade com cada questão.
- Este trabalho deverá ser realizado em equipe, com no máximo cinco integrantes.

Data limite para entrega: 06/10/2025
