#include <stdio.h>
#include <stdlib.h> // Necessário para malloc e free

// 1. Definimos a struct simples
typedef struct {
    int idade;
    float altura;
} Pessoa;

int main() {
    int n = 3; // Quantidade de pessoas no vetor
    Pessoa *lista; // Ponteiro que será o nosso vetor dinâmico

    // 2. Alocamos memória para um vetor de 'n' posições usando malloc
    // Multiplicamos o tamanho de uma struct pela quantidade desejada
    lista = (Pessoa *) malloc(n * sizeof(Pessoa));

    // Verificação de segurança (boa prática)
    if (lista == NULL) {
        printf("Erro: memoria insuficiente!\n");
        return 1;
    }

    // 3. Preenchendo o vetor usando um laço 'for'
    for (int i = 0; i < n; i++) {
        printf("\n--- Digitando dados para a pessoa %d ---\n", i + 1);
        
        printf("Digite a idade: ");
        scanf("%d", &lista[i].idade); // Usamos notação de vetor com o ponto (.)
        
        printf("Digite a altura: ");
        scanf("%f", &lista[i].altura);
    }

    // 4. Exibindo os valores armazenados usando outro 'for'
    printf("\n\n=== EXIBINDO OS DADOS CADASTRADOS ===\n");
    for (int i = 0; i < n; i++) {
        printf("Pessoa %d -> Idade: %d | Altura: %.2f\n", i + 1, lista[i].idade, lista[i].altura);
    }

    // 5. Liberamos a memória alocada para evitar vazamentos (memory leak)
    free(lista);

    // Boa prática: anular o ponteiro após liberar
    lista = NULL;

    return 0;
}
