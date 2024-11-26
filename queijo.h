#ifndef QUEIJO_H  // Prevenção de múltiplas inclusões: garante que o arquivo só será incluído uma vez
#define QUEIJO_H  // Marca QUEIJO_H como definido

// Declaração das funções relacionadas ao queijo
void menu_queijo(void);
void cadastra_queijo(void);
void pesquisa_queijo(void);
void atualiza_queijo(void);
void exclui_queijo(void);

// Estrutura para armazenar os dados do queijo
typedef struct {
    char codigo[6];     // Codigo com tamanho fixo
    char *nome;         // Nome dinâmico
    char *data_fabricacao;   // Data de fabricação dinâmico
    char *data_validade;     // Data de validade dinâmico
    char *comp;         // Composição/ingredientes dinâmico
    char *tipo;         // Tipo dinâmico
} Queijo;

#endif // Finaliza a proteção
