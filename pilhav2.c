#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
    int itens[MAX];
    int topo;
} Pilha;

void inicializar(Pilha *p) {
    p->topo = -1;
}

int estaVazia(Pilha *p) {
    return (p->topo == -1);
}

int estaCheia(Pilha *p) {
    return (p->topo == MAX - 1);
}

void push(Pilha *p, int valor) {
    if (estaCheia(p)) {
        printf("Erro: Pilha cheia!\n");
        return;
    }
    p->topo++;
    p->itens[p->topo] = valor;
}

int pop(Pilha *p) {
    if (estaVazia(p)) {
        return -1;
    }
    int valor = p->itens[p->topo];
    p->topo--;
    return valor;
}

void exibir(Pilha *p, const char *nome) {
    if (estaVazia(p)) {
        printf("%s: [ Vazia ]\n", nome);
        return;
    }
    printf("%s (base -> topo): ", nome);
    for (int i = 0; i <= p->topo; i++) {
        printf("%d ", p->itens[i]);
    }
    printf("\n");
}

// Função para remover um valor específico do meio da pilha
int removerEspecifico(Pilha *principal, int valorAlvo) {
    Pilha auxiliar;
    inicializar(&auxiliar);
    
    int encontrado = 0;

    // 1. Desempilha da principal para a auxiliar até achar o valor ou esvaziar
    while (!estaVazia(principal)) {
        int atual = pop(principal);
        
        if (atual == valorAlvo) {
            encontrado = 1;
            break; // Encontrou o valor, para o loop (ele não vai para a auxiliar)
        }
        
        push(&auxiliar, atual);
    }

    // 2. Devolve os elementos da auxiliar de volta para a principal
    while (!estaVazia(&auxiliar)) {
        push(principal, pop(&auxiliar));
    }

    return encontrado;
}

int main() {
    Pilha p;
    inicializar(&p);

    // Inserindo elementos (10 fica na base, 50 no topo)
    push(&p, 10);
    push(&p, 20);
    push(&p, 30);
    push(&p, 40);
    push(&p, 50);

    exibir(&p, "Pilha Original");

    int alvo = 30;
    printf("\nRemovendo o valor %d do meio...\n", alvo);
    
    if (removerEspecifico(&p, alvo)) {
        printf("Valor %d removido com sucesso!\n", alvo);
    } else {
        printf("Valor %d nao encontrado na pilha.\n", alvo);
    }

    exibir(&p, "Pilha Apos a Remocao");

    return 0;
}
