#ifndef FUNCIONARIO_H  // Prevenção de múltiplas inclusões: garante que o arquivo só será incluído uma vez
#define FUNCIONARIO_H  // Marca FUNCIONARIO_H como definido

// Declaração das funções relacionadas ao funcionário
void menu_funcionario(void);
void cadastra_funcionario(void);
void pesquisa_funcionario(void);
void atualiza_funcionario(void);
void exclui_funcionario(void);

// Estrutura para armazenar os dados do funcionário
typedef struct {
    char *nome;       // Nome dinâmico
    char cpf[12];     // CPF com tamanho fixo
    char *email;      // E-mail dinâmico
    char *data;       // Data de nascimento ou cadastro dinâmico
    char *fone;       // Telefone dinâmico
} Funcionario;

#endif // Finaliza a proteção
