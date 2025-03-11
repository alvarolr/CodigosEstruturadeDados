#include <stdio.h>
#include <stdlib.h>

// Estrutura para a Lista e a Fila
typedef struct No {
    int dado;
    struct No* proximo;
} No;

// =================== FILA =================== //
typedef struct Fila {
    No* inicio; // Ponteiro para o primeiro elemento
    No* fim;  // Ponteiro para o último elemento
} Fila;

// Inicializa uma fila vazia
Fila* criarFila() {
    Fila* f = (Fila*)malloc(sizeof(Fila));
    f->inicio = f->fim = NULL;
    return f;
}

// Insere na fila (Enfileirar)
void enfileirar(Fila* f, int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->dado = valor;
    novoNo->proximo = NULL;
    if (f->fim == NULL) {
        f->inicio = f->fim = novoNo;
        return;
    }
    f->fim->proximo = novoNo;
    f->fim = novoNo;
}

// Remove da fila (Desenfileirar)
int desenfileirar(Fila* f) {
    if (f->inicio == NULL) {
        printf("Fila vazia!\n");
        return -1;
    }
    No* temp = f->inicio;
    int dado = temp->dado;
    f->inicio = f->inicio->proximo;
    if (f->inicio == NULL)
        f->fim = NULL;
    free(temp);
    return dado;
}

// Exibe a fila
void exibirFila(Fila* f) {
    No* temp = f->inicio;
    printf("Fila: ");
    while (temp) {
        printf("%d -> ", temp->dado);
        temp = temp->proximo;
    }
    printf("NULL\n");
}

// =================== LISTA ENCADEADA =================== //
typedef struct ListaEncadeada {
    No* cabeca;
} ListaEncadeada;

// Inicializa uma lista vazia
ListaEncadeada* criarLista() {
    ListaEncadeada* lista = (ListaEncadeada*)malloc(sizeof(ListaEncadeada));
    lista->cabeca = NULL;
    return lista;
}

// Insere no início da lista
void inserirNoInicio(ListaEncadeada* lista, int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->dado = valor;
    novoNo->proximo = lista->cabeca;
    lista->cabeca = novoNo;
}

// Insere no final da lista
void inserirNoFim(ListaEncadeada* lista, int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->dado = valor;
    novoNo->proximo = NULL;

    if (lista->cabeca == NULL) {
        lista->cabeca = novoNo;
        return;
    }

    No* temp = lista->cabeca;
    while (temp->proximo) {
        temp = temp->proximo;
    }
    temp->proximo = novoNo;
}

// Remove um elemento da lista
void removerElemento(ListaEncadeada* lista, int valor) {
    No* temp = lista->cabeca, *anterior = NULL;

    if (temp != NULL && temp->dado == valor) {
        lista->cabeca = temp->proximo;
        free(temp);
        return;
    }

    while (temp != NULL && temp->dado != valor) {
        anterior = temp;
        temp = temp->proximo;
    }

    if (temp == NULL) return;

    anterior->proximo = temp->proximo;
    free(temp);
}

// Exibe a lista encadeada
void exibirLista(ListaEncadeada* lista) {
    No* temp = lista->cabeca;
    printf("Lista: ");
    while (temp) {
        printf("%d -> ", temp->dado);
        temp = temp->proximo;
    }
    printf("NULL\n");
}

// =================== PROGRAMA PRINCIPAL =================== //
int main() {
    // Testando a Fila
    Fila* f = criarFila();
    enfileirar(f, 10);
    enfileirar(f, 20);
    enfileirar(f, 30);
    exibirFila(f);
    printf("Removido da fila: %d\n", desenfileirar(f));
    exibirFila(f);

    // Testando a Lista Encadeada
    ListaEncadeada* lista = criarLista();
    inserirNoInicio(lista, 5);
    inserirNoInicio(lista, 3);
    inserirNoFim(lista, 10);
    inserirNoFim(lista, 20);
    exibirLista(lista);
    printf("Removendo elemento 10\n");
    removerElemento(lista, 10);
    exibirLista(lista);

    return 0;
}
