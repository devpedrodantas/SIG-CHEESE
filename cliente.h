#ifndef CLIENTE_H  // Prevenção de múltiplas inclusões: garante que o arquivo só será incluído uma vez
#define CLIENTE_H  // Marca CLIENTE_H como definido
#include "estruturas.h"  // Inclui a definição da estrutura Endereco

// Estrutura para armazenar os dados do cliente
typedef struct {
    char status;          // Status do cliente (ativo, inativo, etc)
    char nome[52];        // Nome como array estático
    char cpf[13];         // CPF com tamanho fixo
    char email[258];      // E-mail como array estático
    char data[15];        // Data de nascimento como array estático
    char fone[15];        // Telefone como array estático
    Endereco endereco;    // Endereço associado ao cliente (definido em estruturas.h)
} Cliente;


// Declaração das funções relacionadas ao cliente
void menu_cliente(void);
void cadastra_cliente(void);

void pesquisa_cliente(void);
void busca_cliente (const char *cpf_busca);

void atualiza_cliente(void);
void exclui_cliente(void);

void leCpfBusca (char *cpf_busca);
void exibe_cliente(const Cliente *cliente);
int verificaCpfCadastrado(const char *cpf);

#endif // Finaliza a proteção
