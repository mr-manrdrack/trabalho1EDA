#include <stdio.h>
#include <stdlib.h>

// Estrutura do n� da pilha
typedef struct no {
    //valor armazenado no n�
    int dado;
    //ponteiro que aponta para o pr�ximo n�
    struct no *proximo;
} tPilhaSimples;

// Verifica se a pilha est� vazia
int pilhaVazia(tPilhaSimples *topo) {
    return (topo == NULL);
}

// Cria uma pilha unit�ria (se estiver vazia)
tPilhaSimples* criaPilha(int valor) {
    tPilhaSimples *novo = (tPilhaSimples*) malloc(sizeof(tPilhaSimples)); //aloca mem�ria para o novo n�
    if (novo == NULL) {//verifica se a aloca��o falhou
        printf("Erro: n�o foi poss�vel alocar mem�ria.\n");
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
        printf("Erro: n�o foi poss�vel alocar mem�ria.\n");
        return topo;
    }
    novo->dado = valor;
    novo->proximo = topo; // o antigo topo agora fica abaixo
    return novo; // novo passa a ser o topo
}

// Desempilha (remove do topo)
tPilhaSimples* desempilha(tPilhaSimples *topo) {
    if (pilhaVazia(topo)) {
        printf("A pilha est� vazia, n�o � poss�vel desempilhar.\n");
        return topo;
    }
    tPilhaSimples *novoTopo = topo->proximo;
    printf("Elemento removido: %d\n", topo->dado);
    free(topo); //libera o n� removido da mem�ria
    return novoTopo; //retorna o novo topo
}

// Mostra os elementos da pilha (do topo at� a base)
void mostraPilha(tPilhaSimples *topo) {
    if (pilhaVazia(topo)) {
        printf("A pilha est� vazia.\n");
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

// Libera todos os n�s da pilha e retorna quantos foram liberados
int liberaPilha(tPilhaSimples *topo) {
    int contador = 0;
    tPilhaSimples *temp;
    while (topo != NULL) {
        temp = topo;
        topo = topo->proximo; //avan�a para o proximo
        free(temp); //libera o no atual
        contador++; //conta quantos n�s foram removidos
    }
    return contador;
}

int main() {
    //in�cio da pilha (vazia)
    tPilhaSimples *topo = NULL;
    //variaveis para auxiliar no menu
    int opcao, valor, removidos;

    do {
        //menu com op��es para realiza��o do programa
        printf("\n=== MENU PILHA DIN�MICA ===\n");
        printf("1 - Testar se a pilha est� vazia\n");
        printf("2 - Criar pilha unit�ria (se vazia)\n");
        printf("3 - Empilhar n�mero\n");
        printf("4 - Desempilhar n�mero\n");
        printf("5 - Mostrar pilha\n");
        printf("6 - Finalizar programa\n");
        printf("Escolha uma op��o: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                //verifica se a pilha est� vazia
                if (pilhaVazia(topo))
                    printf("A pilha est� vazia.\n");
                else
                    printf("A pilha N�O est� vazia.\n");
                break;
            case 2:
                //Cria uma pilha unitaria se ainda nao existir
                if (pilhaVazia(topo)) {
                    printf("Digite um valor para criar a pilha: ");
                    scanf("%d", &valor);
                    topo = criaPilha(valor);
                    printf("Pilha criada com valor %d.\n", valor);
                } else {
                    printf("A pilha j� existe. Use a op��o de empilhar.\n");
                }
                break;
            case 3:
                //empilha um novo n�mero
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
                //Libera toda a mem�ria utilizada e finaliza
                removidos = liberaPilha(topo);
                printf("Programa finalizado. Liberados: %d\n", removidos);
                break;
            default:
                printf("Op��o inv�lida!\n");
        }
    } while (opcao != 6); //repete o menu at� o usu�rio querer sair

    return 0;
}
