#ifndef CLIENTE_H  // Prevenção de múltiplas inclusões: garante que o arquivo só será incluído uma vez
#define CLIENTE_H  // Marca CLIENTE_H como definido
#include "estruturas.h"  // Inclui a definição da estrutura Endereco

// Estrutura para armazenar os dados do cliente
typedef struct cliente {
    char status;
    char nome[52];
    char cpf[13];
    char email[258];
    char data[15];
    char fone[15];
    Endereco endereco;
    struct cliente* prox; // Ponteiro para o próximo cliente
} Cliente;



// Declaração das funções relacionadas ao cliente
void menu_cliente(void);
Cliente* cadastra_cliente(Cliente* lista);

void pesquisa_cliente(void);
void busca_cliente (const char *cpf_busca);

void atualiza_cliente(void);
void exclui_cliente(void);

void leCpfBusca (char *cpf_busca);
void exibe_cliente(const Cliente *cliente);
int verificaCpfCadastrado(const char *cpf);

#endif // Finaliza a proteção
