#include <stdio.h>  // Importa a biblioteca padrão de entrada e saída (para usar o printf)
#include <stdlib.h> // Importa a biblioteca padrão para alocação de memória (malloc e free)

// Definição do nó que armazena o dado e o ponteiro para o próximo elemento
typedef struct No {
    int dado;             // Armazena o valor inteiro guardado no nó
    struct No* proximo;   // Ponteiro que aponta para o próximo nó da fila
} No;

// Definição da estrutura da Fila contendo ponteiros para o início e o fim
typedef struct {
    No* inicio;           // Ponteiro que aponta para o primeiro elemento da fila (quem sai primeiro)
    No* fim;              // Ponteiro que aponta para o último elemento da fila (quem entrou por último)
} Fila;

// Função para criar e inicializar uma nova fila vazia
Fila* criarFila() {
    Fila* f = (Fila*) malloc(sizeof(Fila)); // Aloca memória dinamicamente para a estrutura da fila
    if (f != NULL) {                        // Verifica se a alocação deu certo
        f->inicio = NULL;                   // Inicializa o início como vazio (NULL)
        f->fim = NULL;                      // Inicializa o fim como vazio (NULL)
    }
    return f;                               // Retorna o ponteiro para a nova fila criada
}

// Função para verificar se a fila está vazia
int estaVazia(Fila* f) {
    return (f->inicio == NULL);             // Retorna verdadeiro (1) se o início for NULL, ou falso (0) caso contrário
}

// Função para inserir um elemento no final da fila (Enqueue)
void enfileirar(Fila* f, int valor) {
    No* novoNo = (No*) malloc(sizeof(No));  // Aloca memória para um novo nó
    if (novoNo == NULL) {                   // Verifica se houve falha na alocação de memória
        printf("Erro de alocacao de memoria!\n");
        return;
    }
    novoNo->dado = valor;                   // Atribui o valor recebido ao campo 'dado' do novo nó
    novoNo->proximo = NULL;                 // Como será o último, seu ponteiro 'proximo' aponta para NULL

    // Se a fila estiver vazia, o novo nó é tanto o início quanto o fim
    if (estaVazia(f)) {
        f->inicio = novoNo;
    } else {
        // Caso contrário, o 'proximo' do antigo último nó passa a apontar para o novo nó
        f->fim->proximo = novoNo;
    }
    f->fim = novoNo;                        // Atualiza o ponteiro 'fim' da fila para o novo nó criado
    printf("Elemento %d enfileirado com sucesso.\n", valor);
}

// Função para remover um elemento do início da fila (Dequeue)
int desenfileirar(Fila* f) {
    if (estaVazia(f)) {                     // Verifica se a fila está vazia antes de tentar remover
        printf("Aviso: A fila esta vazia!\n");
        return -1;                          // Retorna -1 indicando erro de fila vazia
    }

    No* temp = f->inicio;                   // Guarda temporariamente o nó do início que será removido
    int valorRetornado = temp->dado;        // Salva o valor armazenado nesse nó

    // Move o início da fila para o próximo elemento
    f->inicio = temp->proximo;

    // Se o início virar NULL, significa que a fila esvaziou completamente, logo o fim também deve ser NULL
    if (f->inicio == NULL) {
        f->fim = NULL;
    }

    free(temp);                             // Libera a memória alocada do nó que foi removido
    return valorRetornado;                  // Retorna o valor do elemento que estava na frente
}

// Função para exibir todos os elementos da fila
void imprimirFila(Fila* f) {
    if (estaVazia(f)) {                     // Verifica se a fila está vazia
        printf("Fila atual: [ Vazia ]\n");
        return;
    }

    No* atual = f->inicio;                  // Cria um ponteiro auxiliar para percorrer a fila a partir do início
    printf("Fila (Inicio -> Fim): ");
    while (atual != NULL) {                 // Percorre a fila até o final
        printf("[%d] ", atual->dado);       // Imprime o dado do nó atual
        atual = atual->proximo;             // Avança para o próximo nó
    }
    printf("\n");
}

// Função principal para testar as operações da fila
int main() {
    Fila* minhaFila = criarFila();          // Cria e inicializa a fila

    // Inserindo elementos na fila
    enfileirar(minhaFila, 10);
    enfileirar(minhaFila, 20);
    enfileirar(minhaFila, 30);

    // Mostrando o estado atual da fila
    imprimirFila(minhaFila);

    // Removendo um elemento (o primeiro a entrar foi o 10)
    int removido = desenfileirar(minhaFila);
    printf("Elemento removido: %d\n", removido);

    // Mostrando a fila após a remoção
    imprimirFila(minhaFila);

    // Inserindo novo elemento no final
    enfileirar(minhaFila, 40);
    imprimirFila(minhaFila);

    // Liberando toda a memória restante da fila ao final do programa (boa prática)
    while (!estaVazia(minhaFila)) {
        desenfileirar(minhaFila);
    }
    free(minhaFila);                        // Libera a estrutura principal da fila

    return 0;                               // Encerra o programa com sucesso
}
