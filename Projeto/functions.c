#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <time.h>
#include "functions.h"
#include "algoritmos.h"

void executarMenu(const char *algoritmo) {
    while (1) {
        printf("\nEscolha uma opcao:\n");
        printf("1. Gerar instancias crescentes\n");
        printf("2. Gerar instancias decrescentes\n");
        printf("3. Gerar instancias aleatorias\n");
        printf("4. Sair\n");
        printf("Digite sua escolha: ");
        
        int escolha;
        scanf("%d", &escolha);
        
        if (escolha == 4) break;
        
        int tamanho = selecionarTamanho();
        if (tamanho == -1) {
            printf("Escolha de tamanho inválida.\n");
            continue;
        }

        const char *tipo;
        const char *nomePasta;

        switch (escolha) {
            case 1: tipo = "crescente"; nomePasta = "Crescente"; break;
            case 2: tipo = "decrescente"; nomePasta = "Decrescente"; break;
            case 3: tipo = "random"; nomePasta = "Random"; break;
            default: printf("Opção inválida.\n"); continue;
        }

        gerarInstancias(algoritmo, nomePasta, tipo, tamanho);
        
        char arquivo[200];
        sprintf(arquivo, "%s/Arquivos de Entrada/%s/entrada%s%d.txt", algoritmo, nomePasta, tipo, tamanho);
        
        
        ///ARRUUMNARARARADASDSADKAFLHJDLGÇHJDFSAGAHGJKGLASFHGJLAKFHJKDFLBHJKLSFHBADSJKLFHSJKDLFHASJKLFDSHAFGHJBAJKL
        int *arrayOrdenado = ordenar(algoritmo, arquivo, nomePasta, tipo);
        if (arrayOrdenado) {
            gerarInstanciasDeSaida(algoritmo, arrayOrdenado, nomePasta, tipo, tamanho);
            free(arrayOrdenado);  // Libera memória após uso
        }
    }

    printf("Programa encerrado.\n");
}

int* carregarArrayDoArquivo(const char *nomeArquivo, int *tamanho) {
    FILE *file = fopen(nomeArquivo, "r");
    if (!file) {
        printf("Erro ao abrir o arquivo %s!\n", nomeArquivo);
        return NULL;
    }

    fscanf(file, "%d", tamanho);
    int *array = malloc(*tamanho * sizeof(int));
    if (!array) {
        printf("Erro de alocação de memória!\n");
        fclose(file);
        return NULL;
    }

    for (int i = 0; i < *tamanho; i++) {
        fscanf(file, "%d", &array[i]);
    }

    fclose(file);
    return array;
}

void gerarInstancias(const char *algoritmo, const char *nomePasta, const char *tipo, int tamanho) {
    char nomeArquivo[200];
    sprintf(nomeArquivo, "%s/Arquivos de Entrada/%s/entrada%s%d.txt", algoritmo, nomePasta, tipo, tamanho);

    FILE *file = fopen(nomeArquivo, "w");
    if (!file) {
        printf("Erro ao criar o arquivo %s!\n", nomeArquivo);
        return;
    }

    fprintf(file, "%d\n", tamanho);
    srand(time(NULL));
    for (int i = 0; i < tamanho; i++) {
        int numero = (strcmp(tipo, "crescente") == 0) ? i + 1 :
                     (strcmp(tipo, "decrescente") == 0) ? tamanho - i :
                     rand() % 1000000;
        fprintf(file, "%d\n", numero);
    }
    fclose(file);
    //printf("Arquivo %s criado com sucesso!\n", nomeArquivo);
}

void gerarInstanciasDeSaida(const char *algoritmo, const int *array, const char *nomePasta, const char *tipo, int tamanho) {
    char nomeArquivo[200];
    sprintf(nomeArquivo, "%s/Arquivos de Saida/%s/saida%s%d.txt", algoritmo, nomePasta, tipo, tamanho);

    FILE *file = fopen(nomeArquivo, "w");
    if (!file) {
        printf("Erro ao criar o arquivo %s!\n", nomeArquivo);
        return;
    }

    fprintf(file, "%d\n", tamanho);
    for (int i = 0; i < tamanho; i++) {
        fprintf(file, "%d\n", array[i]);
    }
    fclose(file);
    //printf("Arquivo %s criado com sucesso!\n", nomeArquivo);
}

int selecionarTamanho() {
    int tamanhos[] = {10, 100, 1000, 10000, 100000, 1000000};
    int quantidade = sizeof(tamanhos) / sizeof(tamanhos[0]);

    printf("\nEscolha o tamanho das instancias:\n");
    for (int i = 0; i < quantidade; i++) {
        printf("%d. %d\n", i + 1, tamanhos[i]);
    }
    printf("Digite sua escolha: ");
    
    int escolha;
    scanf("%d", &escolha);
    return (escolha >= 1 && escolha <= quantidade) ? tamanhos[escolha - 1] : -1;
}

