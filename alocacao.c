#include <stdio.h>
#include <stdlib.h> // Necessário para malloc e free

// 1. Definimos uma struct simples
typedef struct {
    int idade;
    float altura;
} Pessoa;

int main() {
    // 2. Declaramos um ponteiro para a struct.
    // Ele vai guardar o endereço da memória que vamos alocar no heap.
    Pessoa *p;

    // 3. Alocamos memória dinamicamente usando malloc.
    // sizeof(Pessoa) calcula exatamente quantos bytes a struct precisa.
    p = (Pessoa *) malloc(sizeof(Pessoa));

    // Verificação de segurança (boa prática obrigatória)
    if (p == NULL) {
        printf("Erro: memoria insuficiente!\n");
        return 1;
    }

    // 4. Atribuímos valores aos campos usando a seta (->) 
    // porque 'p' é um ponteiro para struct.
    p->idade = 25;
    p->altura = 1.75;

    // 5. Exibimos os valores armazenados
    printf("Idade: %d\n", p->idade);
    printf("Altura: %.2f\n", p->altura);

    // 6. Liberamos a memória alocada para evitar vazamentos (memory leak)
    free(p);

    // Boa prática: anular o ponteiro após liberar
    p = NULL;

    return 0;
}
