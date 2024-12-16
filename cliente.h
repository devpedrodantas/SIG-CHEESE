#ifndef CLIENTE_H  // Prevenção de múltiplas inclusões: garante que o arquivo só será incluído uma vez
#define CLIENTE_H  // Marca CLIENTE_H como definido

// Estrutura para armazenar os dados do cliente
typedef struct {
    char status;      // Status do cliente (ativo, inativo, etc.)
    char nome[52];       // Nome dinâmico
    char cpf[13];     // CPF com tamanho fixo
    char email[258];      // E-mail dinâmico
    char data[15];       // Data de nascimento ou cadastro dinâmico
    char fone[15];       // Telefone dinâmico
} Cliente;


// Declaração das funções relacionadas ao cliente
void menu_cliente(void);
void cadastra_cliente(void);

void pesquisa_cliente(void);
void busca_cliente (const char *cpf_busca);

void atualiza_cliente(void);
void exclui_cliente(void);

void leCpfBusca (char *cpf_busca);

#endif // Finaliza a proteção
