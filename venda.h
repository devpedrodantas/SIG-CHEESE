#ifndef VENDA_H  
#define VENDA_H  

#include "cliente.h" 
#include "queijo.h" 

typedef struct {
    char cpf_cliente[13];     // CPF do cliente que realizou a compra
    char codigo_produto[10];  // Código do produto comprado
    float quantidade_comprada; // Quantidade do produto comprado
    float preco_total;         // Preço total da compra
    char data[11];             // Data da compra (Exemplo: "18/01/2025")
} Venda;

void menu_venda(void);
void cadastra_venda(void);
void registra_venda(const char *cpf_cliente, Queijo *queijo, float quantidade);
void realiza_compra();
void pesquisa_venda(void);
void atualiza_venda(void);
void exclui_venda(void);
void atualiza_estoque(void);

#endif // Finaliza a proteção
