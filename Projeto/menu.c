#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#ifdef _WIN32
    #include <direct.h>
    #define MKDIR(DIR) _mkdir(DIR)
#endif
#include "insertionsort.h"


void criarDiretorioSort() {
    struct stat st = {0};

    // Criar o diretório principal para o projeto se ele não existir
    if (stat("InsertionSort", &st) == -1) {
        MKDIR("InsertionSort");
    }

    // Definindo as categorias de entrada
    char categorias[][50] = {"Arquivos de Entrada", "Arquivos de Saida", "Arquivos de Tempo"};
    
    // Criar subdiretórios dentro do diretório principal
    for (int i = 0; i < 3; i++) {
        char dirName[50];
        snprintf(dirName, sizeof(dirName), "InsertionSort/%s", categorias[i]);
        
        // Verificar se o diretório existe, caso contrário, criá-lo
        if (stat(dirName, &st) == -1) {
            MKDIR(dirName);
            printf("Diretório %s criado com sucesso.\n", dirName);
        }

        char subcategorias[][20] = {"Crescente", "Decrescente", "Random"};
        for(int j = 0; j < 3; j++){
            snprintf(dirName, sizeof(dirName), "InsertionSort/%s/%s",  categorias[i], subcategorias[j]);
            if(stat(dirName, &st) == -1){
                MKDIR(dirName);
                printf("Diretório %s criado com sucesso.\n", dirName);
            }
        }
    }
}

void mostrarMenuPrincipal() {
    printf("\nEscolha o algoritmo a ser executado:\n");
    printf("1. Insertion Sort\n");
    printf("2. Outro Algoritmo (Exemplo)\n");
    printf("3. Sair\n");
    printf("Digite sua escolha: ");
}

int main()
{
    criarDiretorioSort();

    int escolha = 0;
    
    while (1) {
        mostrarMenuPrincipal();
        scanf("%d", &escolha);
        
        switch (escolha) {
            case 1:
                printf("Executando Insertion Sort...\n");
                executarInsertionSortMenu();
                break;

            case 2:
                printf("Executando Outro Algoritmo...\n");
                break;

            case 3:
                printf("Saindo do programa...\n");
                return 0;

            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    }

    return 0; 
}