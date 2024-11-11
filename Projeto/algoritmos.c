#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <time.h>
#include "algoritmos.h"
#include "functions.h"


int* insertionSort(const char *arquivo, const char *nomePasta, const char *tipo) {
    int tamanho;
    int *array = carregarArrayDoArquivo(arquivo, &tamanho);
    if (!array) return NULL;

    // Inicia o temporizador
    clock_t startC = clock();

    // Ordenação
    for (int i = 1; i < tamanho; i++) {
        int chave = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > chave) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = chave;
    }

    // Finaliza o temporizador e calcula o tempo
    clock_t endC = clock();
    double tempo = (double)(endC - startC) / CLOCKS_PER_SEC;
    printf("Tempo de execucao: %f segundos\n", tempo);

    // Registra o tempo em um arquivo específico
    char nomeArquivoTempo[200];
    sprintf(nomeArquivoTempo, "InsertionSort/Arquivos de Tempo/%s/tempo%s%d.txt", nomePasta, tipo, tamanho);
    FILE *fileTempo = fopen(nomeArquivoTempo, "w");
    if (fileTempo) {
        fprintf(fileTempo, "Tempo de execução: %f segundos\n", tempo);
        fclose(fileTempo);
        //printf("Arquivo de tempo %s criado com sucesso!\n", nomeArquivoTempo);
    } else {
        printf("Erro ao criar o arquivo de tempo %s!\n", nomeArquivoTempo);
    }

    return array;
}

int* bubbleSort(const char *arquivo, const char *nomePasta, const char *tipo) {
    int tamanho;
    int *array = carregarArrayDoArquivo(arquivo, &tamanho);
    if (!array) return NULL;

    // Inicia o temporizador
    clock_t startC = clock();

    // Algoritmo de Bubble Sort
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    // Finaliza o temporizador e calcula o tempo
    clock_t endC = clock();
    double tempo = (double)(endC - startC) / CLOCKS_PER_SEC;
    printf("Tempo de execucao: %f segundos\n", tempo);

    // Registra o tempo em um arquivo específico
    char nomeArquivoTempo[200];
    sprintf(nomeArquivoTempo, "%s/Arquivos de Tempo/%s/tempo%s%d.txt", nomePasta, tipo, tamanho);
    FILE *fileTempo = fopen(nomeArquivoTempo, "w");
    if (fileTempo) {
        fprintf(fileTempo, "Tempo de execução: %f segundos\n", tempo);
        fclose(fileTempo);
    } else {
        printf("Erro ao criar o arquivo de tempo %s!\n", nomeArquivoTempo);
    }

    return array;
}

int* shellSort(const char *arquivo, const char *nomePasta, const char *tipo) {
    int tamanho;
    int *array = carregarArrayDoArquivo(arquivo, &tamanho);
    if (!array) return NULL;

    // Inicia o temporizador
    clock_t startC = clock();

    // Algoritmo de Shell Sort
    for (int gap = tamanho / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < tamanho; i++) {
            int temp = array[i];
            int j;
            for (j = i; j >= gap && array[j - gap] > temp; j -= gap) {
                array[j] = array[j - gap];
            }
            array[j] = temp;
        }
    }

    // Finaliza o temporizador e calcula o tempo
    clock_t endC = clock();
    double tempo = (double)(endC - startC) / CLOCKS_PER_SEC;
    printf("Tempo de execucao: %f segundos\n", tempo);

    // Registra o tempo em um arquivo específico
    char nomeArquivoTempo[200];
    sprintf(nomeArquivoTempo, "%s/Arquivos de Tempo/%s/tempo%s%d.txt", nomePasta, tipo, tamanho);
    FILE *fileTempo = fopen(nomeArquivoTempo, "w");
    if (fileTempo) {
        fprintf(fileTempo, "Tempo de execução: %f segundos\n", tempo);
        fclose(fileTempo);
    } else {
        printf("Erro ao criar o arquivo de tempo %s!\n", nomeArquivoTempo);
    }

    return array;
}

int* selectionSort(const char *arquivo, const char *nomePasta, const char *tipo) {
    int tamanho;
    int *array = carregarArrayDoArquivo(arquivo, &tamanho);
    if (!array) return NULL;

    // Inicia o temporizador
    clock_t startC = clock();

    // Algoritmo de Selection Sort
    for (int i = 0; i < tamanho - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < tamanho; j++) {
            if (array[j] < array[min_idx]) {
                min_idx = j;
            }
        }
        int temp = array[min_idx];
        array[min_idx] = array[i];
        array[i] = temp;
    }

    // Finaliza o temporizador e calcula o tempo
    clock_t endC = clock();
    double tempo = (double)(endC - startC) / CLOCKS_PER_SEC;
    printf("Tempo de execucao: %f segundos\n", tempo);

    // Registra o tempo em um arquivo específico
    char nomeArquivoTempo[200];
    sprintf(nomeArquivoTempo, "%s/Arquivos de Tempo/%s/tempo%s%d.txt", nomePasta, tipo, tamanho);
    FILE *fileTempo = fopen(nomeArquivoTempo, "w");
    if (fileTempo) {
        fprintf(fileTempo, "Tempo de execução: %f segundos\n", tempo);
        fclose(fileTempo);
    } else {
        printf("Erro ao criar o arquivo de tempo %s!\n", nomeArquivoTempo);
    }

    return array;
}


int* ordenar(const char *algoritmo, const char *arquivo, const char *nomePasta, const char *tipo) {
    if (strcmp(algoritmo, "InsertionSort") == 0) {
        return insertionSort(arquivo, nomePasta, tipo);
    } else if (strcmp(algoritmo, "BubbleSort") == 0) {
        return bubbleSort(arquivo, nomePasta, tipo);
    } else if (strcmp(algoritmo, "ShellSort") == 0) {
        return shellSort(arquivo, nomePasta, tipo);
    } else if (strcmp(algoritmo, "SelectionSort") == 0) {
        return selectionSort(arquivo, nomePasta, tipo);
    }
    return NULL;
}


