#include <stdio.h>
#include <stdlib.h>  // Inclusão da biblioteca para manipulação de memória dinâmica.
#include <string.h>  // Inclusão da biblioteca para manipulação de strings.
#include "entradas.h"

void leNome(char **nome) {
    char entrada[101];  // Buffer temporário para entrada inicial
    int tam;

    scanf("%100[^\n]", entrada);
    getchar();

    tam = strlen(entrada);  // Calcula o tamanho real do texto
    *nome = (char*) malloc (tam+1);   // Aloca memória dinâmica com base no tamanho
    strcpy(*nome, entrada);  // Copia o texto do buffer para a memória alocada
}

void leCpf(char cpf[TAM_CPF]) {
    scanf("%11s", cpf);
    getchar();
}

void leEmail(char email[TAM_EMAIL]) {
    scanf("%49[^\n]", email);
    getchar();
}

void leData(char data[TAM_DATA]) {
    scanf("%10s", data);
    getchar();
}

void leFone(char fone[TAM_FONE]) {
    scanf("%11s", fone);
    getchar();
}
