// Assinaturas das funções de entradas

#define TAM_CPF 12
#define TAM_CODIGO 7

void leNome(char **nome);   // Tipo do parâmetro 'nome' alterado para ponteiro
void leCpf(char cpf[TAM_CPF]);
void leEmail(char **email); // Tipo do parâmetro 'email' alterado para ponteiro
void leData(char **data);   // Tipo do parâmetro 'data' alterado para ponteiro
void leFone(char **fone);   // Tipo do parâmetro 'fone' alterado para ponteiro

void leCodigo(char codigo[TAM_CODIGO]);
void leComposicao(char **comp);
void leTipoLeite(char **tipo);
