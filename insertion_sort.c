#include<stdio.h>

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; ++i) {
        int chave = arr[i];
        int j = i - 1;

        // Move os elementos do array[0..i-1], que são amaiores que a chave, para a posição da frente da sua posicao atual
        while (j >= 0 && arr[j] > chave) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = chave;
    }
}

// Uma função para printar um array de tamanho n
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

// Função Principal
int main()
{
    int arr[] = { 25, 12, 87, 3, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);
    printArray(arr, n);

    return 0;
}
