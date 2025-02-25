#include <stdio.h> 

// Função para realizar o Selection Sort
void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp; // Declaração das variáveis

    // Loop externo percorre o array até o penúltimo elemento
    for (i = 0; i < n - 1; i++) {
        min_idx = i; // Assume que o menor elemento está na posição atual

        // Loop interno para encontrar o menor elemento no subarray restante
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j; // Atualiza o índice do menor elemento
            }
        }

        // Após encontrar o menor elemento, troca com o elemento atual
        temp = arr[min_idx];    // Armazena o menor elemento encontrado
        arr[min_idx] = arr[i];  // Move o elemento atual para a posição do menor
        arr[i] = temp;          // Coloca o menor elemento na posição correta
    }
}

// Função para imprimir o array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]); // Imprime cada elemento seguido de um espaço
    }
    printf("\n"); // Quebra de linha após imprimir todos os elementos
}

int main() {
    // Declaração e inicialização do array
    int arr[] = {64, 25, 12, 22, 11};

    // Calcula o tamanho do array usando sizeof
    int n = sizeof(arr) / sizeof(arr[0]);

    // Exibe o array original
    printf("Array original: ");
    printArray(arr, n);

    // Chama a função Selection Sort para ordenar o array
    selectionSort(arr, n);

    // Exibe o array ordenado
    printf("Array ordenado com Selection Sort: ");
    printArray(arr, n);

    return 0; // Fim do programa
}
