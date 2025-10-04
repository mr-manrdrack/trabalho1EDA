#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura do nó da lista duplamente encadeada
typedef struct no {
    int dado;
    struct no *anterior;
    struct no *proximo;
} tListaDupla;

// Função para verificar se a lista está vazia
int estaVazia(tListaDupla *inicio) {
    return inicio == NULL;
}

// Função para inserir um novo número na lista em ordem crescente
void inserirElemento(tListaDupla **inicio, int valor) {
    // Verifica se o valor já existe na lista
    tListaDupla *temp = *inicio;
    while (temp != NULL) {
        if (temp->dado == valor) {
            printf("Erro: O numero %d ja existe na lista.\n", valor);
            return;
        }
        temp = temp->proximo;
    }

    // Cria o novo nó
    tListaDupla *novoNo = (tListaDupla *)malloc(sizeof(tListaDupla));
    if (novoNo == NULL) {
        printf("Erro: Falha na alocacao de memoria.\n");
        return;
    }
    novoNo->dado = valor;
    novoNo->anterior = NULL;
    novoNo->proximo = NULL;

    // Caso 1: A lista está vazia ou o novo elemento é menor que o primeiro
    if (estaVazia(*inicio) || valor < (*inicio)->dado) {
        novoNo->proximo = *inicio;
        if (!estaVazia(*inicio)) {
            (*inicio)->anterior = novoNo;
        }
        *inicio = novoNo;
        printf("Numero %d inserido com sucesso.\n", valor);
        return;
    }

    // Caso 2: Encontrar a posição correta para inserir o novo nó
    tListaDupla *atual = *inicio;
    while (atual->proximo != NULL && atual->proximo->dado < valor) {
        atual = atual->proximo;
    }

    // Insere o novo nó após o nó 'atual'
    novoNo->proximo = atual->proximo;
    if (atual->proximo != NULL) {
        atual->proximo->anterior = novoNo;
    }
    atual->proximo = novoNo;
    novoNo->anterior = atual;
    printf("Numero %d inserido com sucesso.\n", valor);
}


// Função para criar uma lista unitária (apenas se estiver vazia)
void criarListaUnitaria(tListaDupla **inicio) {
    if (!estaVazia(*inicio)) {
        printf("Erro: A lista nao esta vazia. Nao e possivel criar uma lista unitaria.\n");
        return;
    }
    int valor;
    printf("Digite o valor para o primeiro no da lista: ");
    scanf("%d", &valor);
    inserirElemento(inicio, valor);
}

// Função para remover um elemento da lista
void removerElemento(tListaDupla **inicio, int valor) {
    if (estaVazia(*inicio)) {
        printf("Erro: A lista esta vazia.\n");
        return;
    }

    tListaDupla *atual = *inicio;

    // Procura o nó a ser removido
    while (atual != NULL && atual->dado != valor) {
        atual = atual->proximo;
    }

    // Se o elemento não foi encontrado
    if (atual == NULL) {
        printf("Numero %d nao encontrado na lista.\n", valor);
        return;
    }

    // Caso 1: O nó a ser removido é o primeiro da lista
    if (atual->anterior == NULL) {
        *inicio = atual->proximo;
        if (*inicio != NULL) {
            (*inicio)->anterior = NULL;
        }
    }
    // Caso 2: O nó a ser removido está no meio ou no fim
    else {
        atual->anterior->proximo = atual->proximo;
        if (atual->proximo != NULL) {
            atual->proximo->anterior = atual->anterior;
        }
    }

    free(atual);
    printf("Numero %d removido com sucesso.\n", valor);
}

// Função para pesquisar um elemento na lista
void pesquisarElemento(tListaDupla *inicio, int valor) {
    if (estaVazia(inicio)) {
        printf("A lista esta vazia.\n");
        return;
    }

    tListaDupla *atual = inicio;
    while (atual != NULL) {
        if (atual->dado == valor) {
            printf("Numero %d encontrado na lista.\n", valor);
            return;
        }
        atual = atual->proximo;
    }
    printf("Numero %d nao encontrado na lista.\n", valor);
}

// Exibir lista em ordem crescente
void exibirCrescente(tListaDupla *inicio) {
    if (estaVazia(inicio)) {
        printf("A lista esta vazia.\n");
        return;
    }

    printf("Lista em ordem crescente: ");
    tListaDupla *atual = inicio;
    while (atual != NULL) {
        printf("%d ", atual->dado);
        atual = atual->proximo;
    }
    printf("\n");
}

// Exibir lista em ordem decrescente
void exibirDecrescente(tListaDupla *inicio) {
    if (estaVazia(inicio)) {
        printf("A lista esta vazia.\n");
        return;
    }

    // Ir até o último nó
    tListaDupla *atual = inicio;
    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }

    printf("Lista em ordem decrescente: ");
    while (atual != NULL) {
        printf("%d ", atual->dado);
        atual = atual->anterior;
    }
    printf("\n");
}

// Função para destruir a lista e liberar memória
void destruirLista(tListaDupla **inicio) {
    int contador = 0;
    tListaDupla *atual = *inicio;
    while (atual != NULL) {
        tListaDupla *temp = atual;
        atual = atual->proximo;
        free(temp);
        contador++;
    }
    *inicio = NULL;
    printf("Lista destruida. %d nos foram liberados.\n", contador);
}

// Função para exibir o menu de opções
void exibirMenu() {
    printf("\n--- MENU ---\n");
    printf("1. Verificar se a lista esta vazia\n");
    printf("2. Criar lista unitaria (se vazia)\n");
    printf("3. Inserir numero (inedito e em ordem)\n");
    printf("4. Remover numero\n");
    printf("5. Pesquisar numero\n");
    printf("6. Exibir lista em ordem crescente\n");
    printf("7. Exibir lista em ordem decrescente\n");
    printf("8. Sair e destruir a lista\n");
    printf("Escolha uma opcao: ");
}

// Função principal
int main() {
    tListaDupla *lista = NULL; // Inicializa a lista como vazia
    int opcao, valor;

    do {
        exibirMenu();
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            if (estaVazia(lista)) {
                printf("A lista esta vazia.\n");
            } else {
                printf("A lista NAO esta vazia.\n");
            }
            break;
        case 2:
            criarListaUnitaria(&lista);
            break;
        case 3:
            printf("Digite o numero a ser inserido: ");
            scanf("%d", &valor);
            inserirElemento(&lista, valor);
            break;
        case 4:
            printf("Digite o numero a ser removido: ");
            scanf("%d", &valor);
            removerElemento(&lista, valor);
            break;
        case 5:
            printf("Digite o numero a ser pesquisado: ");
            scanf("%d", &valor);
            pesquisarElemento(lista, valor);
            break;
        case 6:
            exibirCrescente(lista);
            break;
        case 7:
            exibirDecrescente(lista);
            break;
        case 8:
            destruirLista(&lista);
            printf("Programa finalizado.\n");
            break;
        default:
            printf("Opcao invalida. Tente novamente.\n");
            break;
        }
    } while (opcao != 8);

    return 0;
}