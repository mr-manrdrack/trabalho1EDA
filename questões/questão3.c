#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da fila
typedef struct no {
    int dado; //valor armazenado no nó
    struct no *proximo; //ponteiro para o proximo nó
} tFilaSimples;

// Função para verificar se a fila está vazia
int filaVazia(tFilaSimples *inicio) {
    return (inicio == NULL);
}

// Função para criar uma fila unitária (apenas se vazia)
tFilaSimples* criaFila(int valor) {
    //aloca memoria para um novo nó
    tFilaSimples *novo = (tFilaSimples*) malloc(sizeof(tFilaSimples));
    if (novo == NULL) { //verifica se houve falha
        printf("Erro: não foi possível alocar memória.\n");
        return NULL;
    }
    //preenche os dados do novo nó
    novo->dado = valor;
    novo->proximo = NULL;
    return novo;
}

// Função para enfileirar (inserir no fim)
tFilaSimples* enfileira(tFilaSimples *inicio, int valor) {
    //Cria um novo no para armazenar o valor
    tFilaSimples *novo = (tFilaSimples*) malloc(sizeof(tFilaSimples));
    if (novo == NULL) {
        printf("Erro: não foi possível alocar memória.\n");
        return inicio; //retorna fila sem alterações
    }
    novo->dado = valor;
    novo->proximo = NULL;
    //se está vazia, o novo nó será o primeiro
    if (inicio == NULL) {
        return novo; // se a fila estava vazia
    } else {
        //caso contrario percorre ate o fim da fila
        tFilaSimples *temp = inicio;
        while (temp->proximo != NULL) {
            temp = temp->proximo;
        }
        temp->proximo = novo;
        return inicio;
    }
}

// Função para desenfileirar (remover do início)
tFilaSimples* desenfileira(tFilaSimples *inicio) {
    if (filaVazia(inicio)) { //verifica se há elementos
        printf("A fila está vazia, não é possível desenfileirar.\n");
        return inicio;
    }
    //guarda o novo inicio
    tFilaSimples *novoInicio = inicio->proximo;
    printf("Elemento removido: %d\n", inicio->dado);
    free(inicio); //libera a memória do nó removido
    return novoInicio;
}

// Função para mostrar os elementos da fila
void mostraFila(tFilaSimples *inicio) {
    if (filaVazia(inicio)) {
        printf("A fila está vazia.\n");
        return;
    }
    printf("Fila: ");
    tFilaSimples *temp = inicio;
    while (temp != NULL) { //percorre a fila até o final
        printf("%d ", temp->dado);
        temp = temp->proximo;
    }
    printf("\n");
}

// Função para liberar toda a fila
int liberaFila(tFilaSimples *inicio) {
    int contador = 0;
    tFilaSimples *temp;
    while (inicio != NULL) {
        temp = inicio; //guarda o nó atual
        inicio = inicio->proximo; //avança o proximo
        free(temp); //libera o no atual
        contador++; //conta quantos foram removidos
    }
    return contador;
}

int main() {
    //ponteiro para o início da fila
    tFilaSimples *inicio = NULL;
    //variaveis para auxiliar o menu
    int opcao, valor, removidos;

    do {
        printf("\n=== MENU FILA DINÂMICA ===\n");
        printf("1 - Testar se a fila está vazia\n");
        printf("2 - Criar fila unitária (se vazia)\n");
        printf("3 - Enfileirar número\n");
        printf("4 - Desenfileirar número\n");
        printf("5 - Mostrar fila\n");
        printf("6 - Finalizar programa\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                //verifica se a fila esta vazia
                if (filaVazia(inicio))
                    printf("A fila está vazia.\n");
                else
                    printf("A fila NÃO está vazia.\n");
                break;
            case 2:
                //cria uma nova fila unitaria, se ainda nao existir
                if (filaVazia(inicio)) {
                    printf("Digite um valor para criar a fila: ");
                    scanf("%d", &valor);
                    inicio = criaFila(valor);
                    printf("Fila criada com valor %d.\n", valor);
                } else {
                    printf("A fila já existe. Use a opção de enfileirar.\n");
                }
                break;
            case 3:
                //adiciona novo elemento ao final da fila
                printf("Digite um valor para enfileirar: ");
                scanf("%d", &valor);
                inicio = enfileira(inicio, valor);
                break;
            case 4:
                //remove o primeiro elemento da fila
                inicio = desenfileira(inicio);
                break;
            case 5:
                //exibe todos os elementos da fila
                mostraFila(inicio);
                break;
            case 6:
                //libera memoria da fila
                removidos = liberaFila(inicio);
                printf("Programa finalizado. Liberados: %d\n", removidos);
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 6); //repete ate o usuario escolher sair

    return 0;
}
