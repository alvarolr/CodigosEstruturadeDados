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

// Função para remover um item específico da pilha preservando a ordem dos demais
void removerEspecifico(Pilha *p, int valorAlvo) {
    Pilha temp;
    inicializar(&temp);
    int encontrado = 0;

    // Esvazia a pilha original para a temporária, procurando o valor alvo
    while (!estaVazia(p)) {
        int v = pop(p);
        if (v == valorAlvo && !encontrado) {
            encontrado = 1; // Descarta a primeira ocorrência do valor encontrado
        } else {
            push(&temp, v);
        }
    }

    // Devolve os elementos da pilha temporária de volta para a original
    while (!estaVazia(&temp)) {
        push(p, pop(&temp));
    }

    if (encontrado) {
        printf("Elemento %d removido com sucesso da pilha!\n", valorAlvo);
    } else {
        printf("Elemento %d nao foi encontrado na pilha!\n", valorAlvo);
    }
}

int main() {
    Pilha p;
    inicializar(&p);

    push(&p, 10);
    push(&p, 20);
    push(&p, 30);
    
    exibir(&p);

    // Testando a remoção de um item específico (ex: 20, que está no meio)
    removerEspecifico(&p, 20);

    exibir(&p);

    return 0;
}
