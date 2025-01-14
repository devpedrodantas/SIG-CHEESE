#ifndef QUEIJO_H  // Prevenção de múltiplas inclusões: garante que o arquivo só será incluído uma vez
#define QUEIJO_H  // Marca QUEIJO_H como definido

// Estrutura para armazenar os dados do queijo
typedef struct {
    char status;                        // Status do queijo (ativo, inativo, etc)
    char nome[52];                       // Nome como array estático
    char codigo[10];                      // Codigo com tamanho fixo
    char data_fabricacao[15];            // Data de fabricação como array estático
    char data_validade[15];              // Data de validade como array estático
    char comp[200];                      // Composição/ingredientes como array estático
    char tipo[20];                       // Tipo como array estático
} Queijo;

// Declaração das funções relacionadas ao queijo
void menu_queijo(void);
void cadastra_queijo(void);

void pesquisa_queijo(void);
void busca_queijo (const char *codigo_busca);

void atualiza_queijo(void);
void exclui_queijo(void);

void leCodigoBusca (char *codigo_busca);
int verificaCodigoCadastrado(const char *codigo); 

void exibe_queijo(const Queijo *queijo);


#endif // Finaliza a proteção
