#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <time.h>

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

void gerarInstancias(const char *nomePasta, const char *tipo, int tamanho) {
    char nomeArquivo[200];
    sprintf(nomeArquivo, "InsertionSort/Arquivos de Entrada/%s/entrada%s%d.txt", nomePasta, tipo, tamanho);

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
    printf("Arquivo %s criado com sucesso!\n", nomeArquivo);
}

void gerarInstanciasDeSaida(const int *array, const char *nomePasta, const char *tipo, int tamanho) {
    char nomeArquivo[200];
    sprintf(nomeArquivo, "InsertionSort/Arquivos de Saida/%s/saida%s%d.txt", nomePasta, tipo, tamanho);

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
    printf("Arquivo %s criado com sucesso!\n", nomeArquivo);
}

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
    printf("Tempo de execução: %f segundos\n", tempo);

    // Registra o tempo em um arquivo específico
    char nomeArquivoTempo[200];
    sprintf(nomeArquivoTempo, "InsertionSort/Arquivos de Tempo/tempo_%s%d.txt", tipo, tamanho);
    FILE *fileTempo = fopen(nomeArquivoTempo, "w");
    if (fileTempo) {
        fprintf(fileTempo, "Tempo de execução: %f segundos\n", tempo);
        fclose(fileTempo);
        printf("Arquivo de tempo %s criado com sucesso!\n", nomeArquivoTempo);
    } else {
        printf("Erro ao criar o arquivo de tempo %s!\n", nomeArquivoTempo);
    }

    return array;
}

int selecionarTamanho() {
    int tamanhos[] = {10, 100, 1000, 10000, 100000, 1000000};
    int quantidade = sizeof(tamanhos) / sizeof(tamanhos[0]);

    printf("\nEscolha o tamanho das instâncias:\n");
    for (int i = 0; i < quantidade; i++) {
        printf("%d. %d\n", i + 1, tamanhos[i]);
    }
    printf("Digite sua escolha: ");
    
    int escolha;
    scanf("%d", &escolha);
    return (escolha >= 1 && escolha <= quantidade) ? tamanhos[escolha - 1] : -1;
}

int main() {
    while (1) {
        printf("\nEscolha uma opção:\n");
        printf("1. Gerar instâncias crescentes\n");
        printf("2. Gerar instâncias decrescentes\n");
        printf("3. Gerar instâncias aleatórias\n");
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

        gerarInstancias(nomePasta, tipo, tamanho);
        
        char arquivo[200];
        sprintf(arquivo, "InsertionSort/Arquivos de Entrada/%s/entrada%s%d.txt", nomePasta, tipo, tamanho);
        
        int *arrayOrdenado = insertionSort(arquivo, nomePasta, tipo);
        if (arrayOrdenado) {
            gerarInstanciasDeSaida(arrayOrdenado, nomePasta, tipo, tamanho);
            free(arrayOrdenado);  // Libera memória após uso
        }
    }

    printf("Programa encerrado.\n");
    return 0;
}
