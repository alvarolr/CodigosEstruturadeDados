#include <stdio.h> 

// Função para realizar o Insertion Sort
void insertionSort(int arr[], int n) {
    int i, key, j; // Declaração das variáveis

    // Loop externo percorre o array do segundo elemento até o final
    for (i = 1; i < n; i++) {
        key = arr[i]; // Elemento atual a ser inserido no subarray ordenado
        j = i - 1;

        // Move os elementos do subarray ordenado que são maiores que 'key'
        // uma posição à frente para abrir espaço para 'key'
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j]; // Move o elemento maior para frente
            j = j - 1;           // Continua verificando elementos anteriores
        }

        // Insere 'key' na posição correta
        arr[j + 1] = key;
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
    int arr[] = {12, 11, 13, 5, 6};

    // Calcula o tamanho do array usando sizeof
    int n = sizeof(arr) / sizeof(arr[0]);

    // Exibe o array original
    printf("Array original: ");
    printArray(arr, n);

    // Chama a função Insertion Sort para ordenar o array
    insertionSort(arr, n);

    // Exibe o array ordenado
    printf("Array ordenado com Insertion Sort: ");
    printArray(arr, n);

    return 0; // Fim do programa
}
