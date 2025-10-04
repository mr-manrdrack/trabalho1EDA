#include <stdio.h>
#include <stdlib.h>

// Estrutura do n� da fila
typedef struct no {
    int dado; //valor armazenado no n�
    struct no *proximo; //ponteiro para o proximo n�
} tFilaSimples;

// Fun��o para verificar se a fila est� vazia
int filaVazia(tFilaSimples *inicio) {
    return (inicio == NULL);
}

// Fun��o para criar uma fila unit�ria (apenas se vazia)
tFilaSimples* criaFila(int valor) {
    //aloca memoria para um novo n�
    tFilaSimples *novo = (tFilaSimples*) malloc(sizeof(tFilaSimples));
    if (novo == NULL) { //verifica se houve falha
        printf("Erro: n�o foi poss�vel alocar mem�ria.\n");
        return NULL;
    }
    //preenche os dados do novo n�
    novo->dado = valor;
    novo->proximo = NULL;
    return novo;
}

// Fun��o para enfileirar (inserir no fim)
tFilaSimples* enfileira(tFilaSimples *inicio, int valor) {
    //Cria um novo no para armazenar o valor
    tFilaSimples *novo = (tFilaSimples*) malloc(sizeof(tFilaSimples));
    if (novo == NULL) {
        printf("Erro: n�o foi poss�vel alocar mem�ria.\n");
        return inicio; //retorna fila sem altera��es
    }
    novo->dado = valor;
    novo->proximo = NULL;
    //se est� vazia, o novo n� ser� o primeiro
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

// Fun��o para desenfileirar (remover do in�cio)
tFilaSimples* desenfileira(tFilaSimples *inicio) {
    if (filaVazia(inicio)) { //verifica se h� elementos
        printf("A fila est� vazia, n�o � poss�vel desenfileirar.\n");
        return inicio;
    }
    //guarda o novo inicio
    tFilaSimples *novoInicio = inicio->proximo;
    printf("Elemento removido: %d\n", inicio->dado);
    free(inicio); //libera a mem�ria do n� removido
    return novoInicio;
}

// Fun��o para mostrar os elementos da fila
void mostraFila(tFilaSimples *inicio) {
    if (filaVazia(inicio)) {
        printf("A fila est� vazia.\n");
        return;
    }
    printf("Fila: ");
    tFilaSimples *temp = inicio;
    while (temp != NULL) { //percorre a fila at� o final
        printf("%d ", temp->dado);
        temp = temp->proximo;
    }
    printf("\n");
}

// Fun��o para liberar toda a fila
int liberaFila(tFilaSimples *inicio) {
    int contador = 0;
    tFilaSimples *temp;
    while (inicio != NULL) {
        temp = inicio; //guarda o n� atual
        inicio = inicio->proximo; //avan�a o proximo
        free(temp); //libera o no atual
        contador++; //conta quantos foram removidos
    }
    return contador;
}

int main() {
    //ponteiro para o in�cio da fila
    tFilaSimples *inicio = NULL;
    //variaveis para auxiliar o menu
    int opcao, valor, removidos;

    do {
        printf("\n=== MENU FILA DIN�MICA ===\n");
        printf("1 - Testar se a fila est� vazia\n");
        printf("2 - Criar fila unit�ria (se vazia)\n");
        printf("3 - Enfileirar n�mero\n");
        printf("4 - Desenfileirar n�mero\n");
        printf("5 - Mostrar fila\n");
        printf("6 - Finalizar programa\n");
        printf("Escolha uma op��o: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                //verifica se a fila esta vazia
                if (filaVazia(inicio))
                    printf("A fila est� vazia.\n");
                else
                    printf("A fila N�O est� vazia.\n");
                break;
            case 2:
                //cria uma nova fila unitaria, se ainda nao existir
                if (filaVazia(inicio)) {
                    printf("Digite um valor para criar a fila: ");
                    scanf("%d", &valor);
                    inicio = criaFila(valor);
                    printf("Fila criada com valor %d.\n", valor);
                } else {
                    printf("A fila j� existe. Use a op��o de enfileirar.\n");
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
                printf("Op��o inv�lida!\n");
        }
    } while (opcao != 6); //repete ate o usuario escolher sair

    return 0;
}
