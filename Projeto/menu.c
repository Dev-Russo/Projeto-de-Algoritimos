#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#ifdef _WIN32
    #include <direct.h>
    #define MKDIR(DIR) _mkdir(DIR)
#endif
#include "algoritmos.h"
#include "functions.h"


void criarDiretorioSort(const char *algoritmos) {
    struct stat st = {0};

    // Criar o diretório principal para o projeto se ele não existir
    if (stat(algoritmos, &st) == -1) {
        MKDIR(algoritmos);
    }

    // Definindo as categorias de entrada
    const char *categorias[] = {"Arquivos de Entrada", "Arquivos de Saida", "Arquivos de Tempo"};
    
    // Criar subdiretórios dentro do diretório principal
    for (int i = 0; i < 3; i++) {
        char dirName[100];
        snprintf(dirName, sizeof(dirName), "%s/%s", algoritmos ,categorias[i]);
        
        // Verificar se o diretório existe, caso contrário, criá-lo
        if (stat(dirName, &st) == -1) {
            MKDIR(dirName);
            printf("Diretório %s criado com sucesso.\n", dirName);
        }

        const char *subcategorias[] = {"Crescente", "Decrescente", "Random"};
        for(int j = 0; j < 3; j++){
            snprintf(dirName, sizeof(dirName), "%s/%s/%s",  algoritmos, categorias[i], subcategorias[j]);
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
    printf("2. Bubble Sort\n");
    printf("3. Shell Sort\n");
    printf("4. Selection Sort\n");
    printf("5. Sair\n");
    printf("Digite sua escolha: ");
}

int main()
{
    char algoritmos[][50] = {"InsertionSort, BubbleSort, ShellSort, SelectSort"};
    int escolha = 0;
    
    while (1) {
        mostrarMenuPrincipal();
        scanf("%d", &escolha);
        
        switch (escolha) {
            case 1:
                printf("Executando Insertion Sort...\n");
                criarDiretorioSort("InsertionSort");
                executarMenu("InsertionSort");
                break;
            case 2:
                printf("Executando Bubble Sort...\n");
                criarDiretorioSort("BubbleSort");
                executarMenu("BubbleSort");
                break;
            case 3:
                printf("Executando Shell Sort...\n");
                criarDiretorioSort("ShellSort");
                executarMenu("ShellSort");
                break;
            case 4:
                printf("Executando Selection Sort...\n");
                criarDiretorioSort("SelectionSort");
                executarMenu("SelectionSort");
                break;
            case 5:
                printf("Saindo do programa...\n");
                return 0;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    }

    return 0; 
}