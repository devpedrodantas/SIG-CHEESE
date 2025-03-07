#ifndef FUNCIONARIO_H  // Prevenção de múltiplas inclusões: garante que o arquivo só será incluído uma vez
#define FUNCIONARIO_H  // Marca FUNCIONARIO_H como definido

// Estrutura para armazenar os dados do funcionário
typedef struct {
    char status;              // Status do funcionário (ativo, inativo, etc)
    char nome[52];            // Nome como array estático
    char cpf[13];             // CPF com tamanho como array estático
    char email[258];          // E-mail como array estático
    char data[15];            // Data de nascimento como array estático
    char fone[15];            // Telefone como array estático
} Funcionario;

// Declaração das funções relacionadas ao funcionário
void menu_funcionario(void);
void cadastra_funcionario(void);

void pesquisa_funcionario(void);
void busca_funcionario (const char *cpf_busca);

void atualiza_funcionario(void);
void exclui_funcionario(void);

void leCpfBuscaF (char *cpf_busca);
int verificaCpfCadastradoF(const char *cpf); 
void exibe_funcionario(const Funcionario *funcionario);


#endif // Finaliza a proteção
