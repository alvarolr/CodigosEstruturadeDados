#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Define o tamanho máximo da pilha

// Estrutura da pilha
typedef struct {
    int itens[MAX];
    int topo;
} Pilha;

// Função para inicializar a pilha
void inicializar(Pilha *p) {
    p->topo = -1;
}

// Função para verificar se a pilha está vazia
int estaVazia(Pilha *p) {
    return (p->topo == -1);
}

// Função para verificar se a pilha está cheia
int estaCheia(Pilha *p) {
    return (p->topo == MAX - 1);
}

// Função para inserir um elemento na pilha (PUSH)
void push(Pilha *p, int valor) {
    if (estaCheia(p)) {
        printf("Erro: Pilha cheia!\n");
        return;
    }
    p->topo++;
    p->itens[p->topo] = valor;
    printf("Inserido: %d\n", valor);
}

// Função para remover um elemento da pilha (POP)
int pop(Pilha *p) {
    if (estaVazia(p)) {
        printf("Erro: Pilha vazia!\n");
        return -1;
    }
    int valor = p->itens[p->topo];
    p->topo--;
    return valor;
}

// Função para exibir a pilha
void exibir(Pilha *p) {
    if (estaVazia(p)) {
        printf("Pilha vazia!\n");
        return;
    }
    printf("Pilha: ");
    for (int i = 0; i <= p->topo; i++) {
        printf("%d ", p->itens[i]);
    }
    printf("\n");
}

int main() {
    Pilha p;
    inicializar(&p);

    push(&p, 10);
    push(&p, 20);
    push(&p, 30);
    
    exibir(&p);

    printf("Removido: %d\n", pop(&p));

    exibir(&p);

    return 0;
}
