#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da pilha
typedef struct no {
    //valor armazenado no nó
    int dado;
    //ponteiro que aponta para o próximo nó
    struct no *proximo;
} tPilhaSimples;

// Verifica se a pilha está vazia
int pilhaVazia(tPilhaSimples *topo) {
    return (topo == NULL);
}

// Cria uma pilha unitária (se estiver vazia)
tPilhaSimples* criaPilha(int valor) {
    tPilhaSimples *novo = (tPilhaSimples*) malloc(sizeof(tPilhaSimples)); //aloca memória para o novo nó
    if (novo == NULL) {//verifica se a alocação falhou
        printf("Erro: não foi possível alocar memória.\n");
        return NULL;
    }
    novo->dado = valor;
    novo->proximo = NULL;
    return novo;
}

// Empilha (insere no topo)
tPilhaSimples* empilha(tPilhaSimples *topo, int valor) {
    tPilhaSimples *novo = (tPilhaSimples*) malloc(sizeof(tPilhaSimples));
    if (novo == NULL) {
        printf("Erro: não foi possível alocar memória.\n");
        return topo;
    }
    novo->dado = valor;
    novo->proximo = topo; // o antigo topo agora fica abaixo
    return novo; // novo passa a ser o topo
}

// Desempilha (remove do topo)
tPilhaSimples* desempilha(tPilhaSimples *topo) {
    if (pilhaVazia(topo)) {
        printf("A pilha está vazia, não é possível desempilhar.\n");
        return topo;
    }
    tPilhaSimples *novoTopo = topo->proximo;
    printf("Elemento removido: %d\n", topo->dado);
    free(topo); //libera o nó removido da memória
    return novoTopo; //retorna o novo topo
}

// Mostra os elementos da pilha (do topo até a base)
void mostraPilha(tPilhaSimples *topo) {
    if (pilhaVazia(topo)) {
        printf("A pilha está vazia.\n");
        return;
    }
    printf("Pilha (Topo -> Base): ");
    tPilhaSimples *temp = topo;
    while (temp != NULL) { //percorre ate o final da pilha
        printf("%d ", temp->dado);
        temp = temp->proximo;
    }
    printf("\n");
}

// Libera todos os nós da pilha e retorna quantos foram liberados
int liberaPilha(tPilhaSimples *topo) {
    int contador = 0;
    tPilhaSimples *temp;
    while (topo != NULL) {
        temp = topo;
        topo = topo->proximo; //avança para o proximo
        free(temp); //libera o no atual
        contador++; //conta quantos nós foram removidos
    }
    return contador;
}

int main() {
    //início da pilha (vazia)
    tPilhaSimples *topo = NULL;
    //variaveis para auxiliar no menu
    int opcao, valor, removidos;

    do {
        //menu com opções para realização do programa
        printf("\n=== MENU PILHA DINÂMICA ===\n");
        printf("1 - Testar se a pilha está vazia\n");
        printf("2 - Criar pilha unitária (se vazia)\n");
        printf("3 - Empilhar número\n");
        printf("4 - Desempilhar número\n");
        printf("5 - Mostrar pilha\n");
        printf("6 - Finalizar programa\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                //verifica se a pilha está vazia
                if (pilhaVazia(topo))
                    printf("A pilha está vazia.\n");
                else
                    printf("A pilha NÃO está vazia.\n");
                break;
            case 2:
                //Cria uma pilha unitaria se ainda nao existir
                if (pilhaVazia(topo)) {
                    printf("Digite um valor para criar a pilha: ");
                    scanf("%d", &valor);
                    topo = criaPilha(valor);
                    printf("Pilha criada com valor %d.\n", valor);
                } else {
                    printf("A pilha já existe. Use a opção de empilhar.\n");
                }
                break;
            case 3:
                //empilha um novo número
                printf("Digite um valor para empilhar: ");
                scanf("%d", &valor);
                topo = empilha(topo, valor);
                break;
            case 4:
                //desempilha o elemento do topo
                topo = desempilha(topo);
                break;
            case 5:
                //Mostra os elementos da pilha
                mostraPilha(topo);
                break;
            case 6:
                //Libera toda a memória utilizada e finaliza
                removidos = liberaPilha(topo);
                printf("Programa finalizado. Liberados: %d\n", removidos);
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 6); //repete o menu até o usuário querer sair

    return 0;
}
