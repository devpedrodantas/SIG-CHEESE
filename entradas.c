#include <stdio.h>
#include <stdlib.h>           // Inclusão da biblioteca para manipulação de memória dinâmica.
#include <string.h>           // Inclusão da biblioteca para manipulação de strings.
#include "cliente.h"          // Inclui a definição do tipo Cliente
#include "funcionario.h"      // Inclui a definição do tipo Funcionário
#include "queijo.h"           // Inclui a definição do tipo Queijo


// Função geral para leitura de entradas
void leEntrada(char **entrada, size_t tamanho) {
    char buffer[tamanho];
    fgets(buffer, tamanho, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';  // Remove o \n no final da string

    if (*entrada != NULL) {
        free(*entrada);  // Libera memória previamente alocada
    }

    *entrada = (char*) malloc(strlen(buffer) + 1);
    if (*entrada == NULL) {
        perror("Erro ao alocar memória");
        exit(1);  // Sai caso a alocação falhe
    }

    strcpy(*entrada, buffer);  // Copia o buffer para o ponteiro
}


// Funções temporárias para ler entradas curtase longas (serão REMOVIDAS depois)
void leEntradaMax(char **entrada) {
    leEntrada(entrada, 256);
}

void leEntradaMin(char **entrada) {
    leEntrada(entrada, 16);
}


// Funções para Cliente                                              (Ainda é necessário evitar esta redundância com cliente, funcionario e queijo)
void leNomeCliente(Cliente *cliente) {
  leEntradaMax(&cliente->nome);  // Passa o ponteiro para o nome
}

void leCpfCliente(Cliente *cliente) {
    scanf("%11s", cliente->cpf);  // Acessa diretamente cliente->cpf
    getchar();
}

void leEmailCliente(Cliente *cliente) {
    leEntradaMax(&cliente->email);  // Passa o ponteiro para o email
}

void leDataCliente(Cliente *cliente) {
    leEntradaMin(&cliente->data);  // Passa o ponteiro para a data
}


void leFoneCliente(Cliente *cliente) {
    leEntradaMin(&cliente->fone);  // Passa o ponteiro para o telefone
}

// Funções para Funcionario
void leNomeFuncionario(Funcionario *funcionario) {
  leEntradaMax(&funcionario->nome);  // Passa o ponteiro para o nome
}

void leCpfFuncionario(Funcionario *funcionario) {
    scanf("%11s", funcionario->cpf);  // Acessa diretamente funcionario->cpf
    getchar();
}

void leEmailFuncionario(Funcionario *funcionario) {
    leEntradaMax(&funcionario->email);  // Passa o ponteiro para o email
}

void leDataFuncionario(Funcionario *funcionario) {
    leEntradaMin(&funcionario->data);  // Passa o ponteiro para a data
}

void leFoneFuncionario(Funcionario *funcionario) {
    leEntradaMin(&funcionario->fone);  // Passa o ponteiro para o telefone
}

// Funções para Queijo
void leNomeQueijo(Queijo *queijo) {
  leEntradaMax(&queijo->nome);  // Passa o ponteiro para o nome
}

void leDataFabricacao(Queijo *queijo) {
    leEntradaMin(&queijo->data_fabricacao);  // Passa o ponteiro para a data
}

void leDataValidade(Queijo *queijo) {
    leEntradaMin(&queijo->data_validade);  // Passa o ponteiro para a data
}


void leCodigo(Queijo *queijo) {
    scanf("%6s", queijo->codigo); //Acessa diretamente queijo->codigo
    getchar();
}

void leComposicao(Queijo *queijo) {
    leEntradaMax(&queijo->comp); // Passa o ponteiro para a composição/ingrediente
}

void leTipoLeite(Queijo *queijo) {
    leEntradaMin(&queijo->tipo); // Passa o ponteiro para a tipo
}
