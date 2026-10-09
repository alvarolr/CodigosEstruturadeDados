#include <stdio.h>
#include <stdlib.h>

#define TAM 5 // Define o tamanho máximo fixo que a fila pode ter

// Definição da estrutura da Fila Circular
typedef struct {
    int vetor[TAM]; // O vetor estático que armazena os elementos
    int inicio;     // Índice que aponta para o primeiro elemento da fila (quem sai primeiro)
    int fim;        // Índice que aponta para a próxima posição livre onde um novo elemento será inserido
    int qtd;        // Contador para saber quantos elementos estão armazenados na fila no momento
} FilaCircular;

// Função para inicializar a fila
void inicializar(FilaCircular *f) {
    f->inicio = 0; // O início começa na posição 0
    f->fim = 0;    // O fim começa na posição 0
    f->qtd = 0;    // A quantidade de elementos começa zerada (fila vazia)
}

// Função para verificar se a fila está vazia
int estaVazia(FilaCircular *f) {
    return f->qtd == 0; // Retorna verdadeiro (1) se a quantidade for 0, senão falso (0)
}

// Função para verificar se a fila está cheia
int estaCheia(FilaCircular *f) {
    return f->qtd == TAM; // Retorna verdadeiro (1) se a quantidade atingir o tamanho máximo (5)
}

// Função para inserir um elemento no final da fila (Enqueue)
void enfileirar(FilaCircular *f, int valor) {
    // Primeiro, verifica se a fila está cheia antes de tentar inserir
    if (estaCheia(f)) {
        printf("Erro: Fila cheia!\n");
        return;
    }
    
    // Insere o valor na posição atual apontada por 'fim'
    f->vetor[f->fim] = valor;
    
    // Avança o índice 'fim' de forma circular. 
    // O operador '%' faz com que, ao chegar em 5 (tamanho máximo), ele volte para 0.
    f->fim = (f->fim + 1) % TAM; 
    
    f->qtd++; // Incrementa a quantidade de elementos na fila
    printf("Elemento %d inserido com sucesso.\n", valor);
}

// Função para remover um elemento do início da fila (Dequeue)
int desenfileirar(FilaCircular *f) {
    // Verifica se a fila está vazia antes de tentar remover
    if (estaVazia(f)) {
        printf("Erro: Fila vazia!\n");
        return -1; // Retorna -1 indicando erro
    }
    
    // Guarda o valor que está no início da fila para retorná-lo depois
    int removido = f->vetor[f->inicio];
    
    // Avança o índice 'inicio' de forma circular também usando '%'
    f->inicio = (f->inicio + 1) % TAM; 
    
    f->qtd--; // Decrementa a quantidade de elementos na fila
    return removido; // Retorna o elemento que foi retirado
}

// Função para exibir todos os elementos atuais da fila
void exibir(FilaCircular *f) {
    // Se a fila estiver vazia, avisa e encerra a função
    if (estaVazia(f)) {
        printf("Fila vazia!\n");
        return;
    }
    
    printf("Fila: ");
    int i = f->inicio; // Começa a leitura a partir do início da fila
    
    // Percorre a quantidade exata de elementos presentes na fila
    for (int cont = 0; cont < f->qtd; cont++) {
        printf("%d ", f->vetor[i]);
        
        // Usa o '%' para garantir que, se 'i' chegar ao final do vetor, 
        // ele dê a volta para a posição 0 ao continuar imprimindo
        i = (i + 1) % TAM;
    }
    printf("\n");
}

// Função principal (onde o programa começa a rodar e testa a fila)
int main() {
    FilaCircular f;      // Declara a variável da fila na memória stack
    inicializar(&f);     // Inicializa os ponteiros e o contador

    // Preenche a fila até atingir o limite máximo (5 elementos)
    enfileirar(&f, 10);
    enfileirar(&f, 20);
    enfileirar(&f, 30);
    enfileirar(&f, 40);
    enfileirar(&f, 50);

    exibir(&f); // Mostra: 10 20 30 40 50

    // Remove dois elementos do início (o 10 e o 20 saem)
    printf("Removido: %d\n", desenfileirar(&f)); // Remove 10
    printf("Removido: %d\n", desenfileirar(&f)); // Remove 20

    // Insere novos elementos (aqui entra a mágica da fila circular: 
    // como duas posições no começo foram desocupadas, o 'fim' dá a volta e ocupa essas posições)
    enfileirar(&f, 60);
    enfileirar(&f, 70);

    exibir(&f); // Mostra a fila atualizada com os novos valores na frente/volta

    return 0;
}
