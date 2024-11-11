#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>

// Declaração das funções do programa

// Função para executar o menu e gerar e ordenar as instâncias
void executarMenu(const char *algoritmo);

// Função para carregar o array do arquivo de entrada
int* carregarArrayDoArquivo(const char *nomeArquivo, int *tamanho);

// Função para gerar instâncias de entrada
void gerarInstancias(const char *algoritmo, const char *nomePasta, const char *tipo, int tamanho);

// Função para gerar instâncias de saída com o array ordenado
void gerarInstanciasDeSaida(const char *algoritmo, const int *array, const char *nomePasta, const char *tipo, int tamanho);

// Função para selecionar o tamanho da instância
int selecionarTamanho();

#endif // FUNCTIONS_H
