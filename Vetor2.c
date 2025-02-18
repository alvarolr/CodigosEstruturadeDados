#include <stdio.h>

#define TAMANHO 5 // Define o tamanho máximo do vetor

// Função para preencher o vetor com valores do usuário
void preencherVetor(int vetor[], int tamanho) {
    printf("Digite %d valores para o vetor:\n", tamanho);
    for (int i = 0; i < tamanho; i++) {
        printf("Elemento %d: ", i);
        scanf("%d", &vetor[i]); // Lê os valores e armazena no vetor
    }
}

// Função para exibir os elementos do vetor
void exibirVetor(int vetor[], int tamanho) {
    printf("Vetor: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]); // Mostra os valores armazenados
    }
    printf("\n");
}

// Função para encontrar um elemento no vetor
void buscarElemento(int vetor[], int tamanho, int valor) {
    int encontrado = 0;
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] == valor) {
            printf("Elemento %d encontrado na posição %d.\n", valor, i);
            encontrado = 1;
            break; // Sai do loop assim que encontrar o valor
        }
    }
    if (!encontrado) {
        printf("Elemento %d não encontrado no vetor.\n", valor);
    }
}

// Função principal
int main() {
    int vetor[TAMANHO]; // Declaração do vetor fixo
    int valorBusca;

    preencherVetor(vetor, TAMANHO); // Chama a função para preencher o vetor
    exibirVetor(vetor, TAMANHO); // Exibe o vetor preenchido

    // Busca um valor no vetor
    printf("Digite um número para buscar no vetor: ");
    scanf("%d", &valorBusca);
    buscarElemento(vetor, TAMANHO, valorBusca);

    return 0;
}
