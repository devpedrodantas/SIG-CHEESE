#include <stdio.h>
#include <stdlib.h>  // Inclusão da biblioteca para manipulação de memória dinâmica.
#include <string.h>  // Inclusão da biblioteca para manipulação de strings.
#include "entradas.h"

// Função para ler entradas longas (ex.: nome, e-mail) e alocar memória dinamicamente
void leEntradaMax(char **entrada) {
    char buffer[256];
    int tam;

    // Lê a entrada do usuário
    scanf("%255[^\n]", buffer);
    getchar();

    // Aloca memória para a entrada com base no tamanho lido
    tam = strlen(buffer);
    *entrada = (char*) malloc(tam + 1);

    // Copia a string para a memória alocada
    strcpy(*entrada, buffer);
}

// Função para ler entradas curtas (ex.: data, telefone) e alocar memória dinamicamente
void leEntradaMin(char **entrada) {
    char buffer[16];
    int tam;

    scanf("%15[^\n]", buffer);
    getchar();

    tam = strlen(buffer);
    *entrada = (char*) malloc(tam + 1);
    strcpy(*entrada, buffer);
}

void leNome(char **nome) {
  leEntradaMax(nome);
}

void leCpf(char cpf[TAM_CPF]) {
    scanf("%11s", cpf);
    getchar();
}

void leEmail(char **email) {
    leEntradaMax(email);
}

void leData(char **data) {
    leEntradaMin(data);
}

void leFone(char **fone) {
    leEntradaMin(fone);
}
