#include <stdio.h> 

// Função para realizar o Bubble Sort
void bubbleSort(int arr[], int n) {
    int i, j, temp; // Declaração das variáveis auxiliares

    // Loop externo para percorrer todos os elementos do array
    for (i = 0; i < n - 1; i++) {
        // Loop interno para comparar elementos adjacentes
        for (j = 0; j < n - i - 1; j++) {
            // Se o elemento atual for maior que o próximo, troque-os
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];            // Armazena o valor atual em uma variável temporária
                arr[j] = arr[j + 1];      // Move o próximo elemento para a posição atual
                arr[j + 1] = temp;        // Coloca o valor armazenado na próxima posição
            }
        }
        // Após cada iteração do loop externo, o maior elemento vai para o final
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
    int arr[] = {64, 34, 25, 12, 22, 11, 90};

    // Calcula o tamanho do array usando sizeof
    int n = sizeof(arr) / sizeof(arr[0]);

    // Exibe o array original
    printf("Array original: ");
    printArray(arr, n);

    // Chama a função Bubble Sort para ordenar o array
    bubbleSort(arr, n);

    // Exibe o array ordenado
    printf("Array ordenado com Bubble Sort: ");
    printArray(arr, n);

    return 0; // Fim do programa
}
