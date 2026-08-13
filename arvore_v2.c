#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da árvore
typedef struct No {
    int valor;
    struct No* esquerda;
    struct No* direita;
} No;

// Função para criar um novo nó
No* criarNo(int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

// Função para inserir um valor na árvore binária de busca
No* inserir(No* raiz, int valor) {
    // Se a árvore estiver vazia, retorna um novo nó
    if (raiz == NULL) {
        return criarNo(valor);
    }

    // Caso contrário, percorre a árvore para encontrar a posição correta
    if (valor < raiz->valor) {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = inserir(raiz->direita, valor);
    }

    return raiz;
}

// Função para exibir a árvore em ordem (Esquerda, Raiz, Direita)
void emOrdem(No* raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esquerda);
        printf("%d ", raiz->valor);
        emOrdem(raiz->direita);
    }
}

int main() {
    No* raiz = NULL;

    // Inserindo elementos na árvore
    raiz = inserir(raiz, 50);
    inserir(raiz, 30);
    inserir(raiz, 20);
    inserir(raiz, 40);
    inserir(raiz, 70);
    inserir(raiz, 60);
    inserir(raiz, 80);

    printf("Percurso em ordem (C):\n");
    emOrdem(raiz);
    printf("\n");

    return 0;
}
