#ifndef ALGORITMOS_H
#define ALGORITMOS_H

#include <stdio.h>

// Função para carregar o array do arquivo de entrada
int* carregarArrayDoArquivo(const char *nomeArquivo, int *tamanho);

// Funções de ordenação para cada algoritmo
int* insertionSort(const char *arquivo, const char *nomePasta, const char *tipo);
int* bubbleSort(const char *arquivo, const char *nomePasta, const char *tipo);
int* shellSort(const char *arquivo, const char *nomePasta, const char *tipo);
int* selectionSort(const char *arquivo, const char *nomePasta, const char *tipo);

// Função para escolher o algoritmo de ordenação
int* ordenar(const char *algoritmo, const char *arquivo, const char *nomePasta, const char *tipo);

#endif // ALGORITMOS_H
