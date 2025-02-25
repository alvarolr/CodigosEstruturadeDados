#include <stdio.h> 

// Função para trocar dois elementos de lugar
void swap(int *a, int *b) {
    int temp = *a;   // Armazena o valor de 'a' temporariamente
    *a = *b;         // Atribui o valor de 'b' em 'a'
    *b = temp;       // Atribui o valor armazenado em 'temp' para 'b'
}

// Função de partição (pivô é colocado em sua posição correta)
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Escolhe o último elemento como pivô
    int i = (low - 1);      // Índice do menor elemento

    // Percorre o array do índice 'low' até 'high - 1'
    for (int j = low; j <= high - 1; j++) {
        // Se o elemento atual for menor ou igual ao pivô
        if (arr[j] <= pivot) {
            i++;                // Incrementa o índice do menor elemento
            swap(&arr[i], &arr[j]);  // Traz o elemento menor para a esquerda do pivô
        }
    }

    // Coloca o pivô em sua posição correta no array
    swap(&arr[i + 1], &arr[high]);
    return (i + 1); // Retorna o índice do pivô
}

// Função principal do Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // 'pi' é o índice do pivô após a partição
        int pi = partition(arr, low, high);

        // Recursivamente ordena os elementos antes e depois do pivô
        quickSort(arr, low, pi - 1);  // Subarray à esquerda do pivô
        quickSort(arr, pi + 1, high); // Subarray à direita do pivô
    }
}

// Função para imprimir o array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]); // Imprime cada elemento seguido de um espaço
    }
    printf("\n"); // Quebra de linha após imprimir todos os elementos
}

// Função principal
int main() {
    int arr[] = {10, 7, 8, 9, 1, 5}; // Array de exemplo
    int n = sizeof(arr) / sizeof(arr[0]); // Calcula o tamanho do array

    printf("Array original: ");
    printArray(arr, n);

    quickSort(arr, 0, n - 1); // Chama a função Quick Sort

    printf("Array ordenado com Quick Sort: ");
    printArray(arr, n);

    return 0; // Fim do programa
}
