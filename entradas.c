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

void leNome(Cliente *cliente) {
  leEntradaMax(&cliente->nome);  // Passa o ponteiro para o nome
}

void leCpf(Cliente *cliente) {
    scanf("%11s", cliente->cpf);  // Acessa diretamente cliente->cpf
    getchar();
}

void leEmail(Cliente *cliente) {
    leEntradaMax(&cliente->email);  // Passa o ponteiro para o email
}

void leData(Cliente *cliente) {
    leEntradaMin(&cliente->data);  // Passa o ponteiro para a data
}

void leFone(Cliente *cliente) {
    leEntradaMin(&cliente->fone);  // Passa o ponteiro para o telefone
}

void leCodigo(char codigo[TAM_CODIGO]) {
    scanf("%6s", codigo);
    getchar();
}

void leComposicao(char **comp) {
    leEntradaMax(comp);
}

void leTipoLeite(char **tipo) {
    leEntradaMin(tipo);
}
