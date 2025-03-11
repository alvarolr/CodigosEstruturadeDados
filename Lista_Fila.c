#include <stdio.h>
#include <stdlib.h>

// Estrutura para a Lista e a Fila
typedef struct No {
    int dado; // Armazena o valor do nó
    struct No* proximo; // Ponteiro para o próximo nó
} No;

// =================== FILA =================== //
typedef struct Fila { //Queue
    No* inicio; // Ponteiro para o primeiro elemento (primeiro a sair)
    No* fim;  // Ponteiro para o último elemento (último a entrar)
} Fila;

// Inicializa uma fila vazia
Fila* criarFila() {
    Fila* f = (Fila*)malloc(sizeof(Fila)); // Aloca memória para a estrutura da fila
    f->inicio = f->fim = NULL; // Define a fila como vazia (sem elementos)
    return f;
}

// Insere na fila (Enfileirar)
void enfileirar(Fila* f, int valor) { //enqueue
    // Cria um novo nó e aloca memória para ele
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->dado = valor; // Atribui o valor passado como parâmetro
    novoNo->proximo = NULL; // O próximo nó será NULL pois será o último da fila

    // Se a fila estiver vazia (não há elementos)
    if (f->fim == NULL) { 
        f->inicio = f->fim = novoNo; // O novo nó será o primeiro e o último elemento
        return; // Retorna pois já inserimos o elemento
    }

    // Se já há elementos na fila
    f->fim->proximo = novoNo; // O último elemento atual aponta para o novo nó
    f->fim = novoNo; // O novo nó se torna o último elemento da fila
}

// Remove da fila (Desenfileirar)
int desenfileirar(Fila* f) { //dequeue
    // Verifica se a fila está vazia
    if (f->inicio == NULL) {
        printf("Fila vazia!\n"); // Exibe mensagem de erro
        return -1; // Retorna um valor inválido indicando erro
    }

    // Cria um ponteiro temporário apontando para o primeiro elemento da fila
    No* temp = f->inicio; 
    int dado = temp->dado; // Armazena o valor do nó a ser removido

    // Atualiza o ponteiro de início para o próximo nó na fila
    f->inicio = f->inicio->proximo;

    // Se após a remoção o início da fila for NULL, significa que a fila ficou vazia
    if (f->inicio == NULL)
        f->fim = NULL; // Então também atualizamos o fim para NULL

    free(temp); // Libera a memória do nó removido
    return dado; // Retorna o valor removido
}

// Exibe a fila
void exibirFila(Fila* f) {
    No* temp = f->inicio; // Começa a partir do primeiro nó
    printf("Fila: ");
    while (temp) { // Enquanto houver elementos na fila
        printf("%d -> ", temp->dado); // Exibe o valor do nó
        temp = temp->proximo; // Move para o próximo nó
    }
    printf("NULL\n"); // Indica o final da fila
}

// =================== LISTA ENCADEADA =================== //
typedef struct ListaEncadeada {
    No* cabeca; // Ponteiro para o primeiro nó da lista
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
    Fila* f = criarFila(); // Cria uma fila vazia
    enfileirar(f, 10); // Adiciona 10 à fila
    enfileirar(f, 20); // Adiciona 20 à fila
    enfileirar(f, 30); // Adiciona 30 à fila
    exibirFila(f); // Exibe os elementos da fila
    printf("Removido da fila: %d\n", desenfileirar(f)); // Remove o primeiro elemento e exibe
    exibirFila(f); // Exibe novamente a fila após a remoção

    // Testando a Lista Encadeada
    ListaEncadeada* lista = criarLista(); // Cria uma lista vazia
    inserirNoInicio(lista, 5); // Insere 5 no início
    inserirNoInicio(lista, 3); // Insere 3 no início
    inserirNoFim(lista, 10); // Insere 10 no final
    inserirNoFim(lista, 20); // Insere 20 no final
    exibirLista(lista); // Exibe os elementos da lista
    printf("Removendo elemento 10\n");
    removerElemento(lista, 10); // Remove o elemento 10 da lista
    exibirLista(lista); // Exibe novamente após a remoção

    return 0;
}
