#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

// Prototipo da função para o menu do Insertion Sort
void executarInsertionSortMenu();
int selecionarTamanho();
void gerarInstancias(const char *nomePasta, const char *tipo, int tamanho);
int* insertionSort(const char *arquivo, const char *nomePasta, const char *tipo);
void gerarInstanciasDeSaida(const int *array, const char *nomePasta, const char *tipo, int tamanho);

#endif