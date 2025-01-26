#include <stdbool.h>  // Inclua esta linha para habilitar o uso de bool

// Assinaturas das funções de validação

int validaNome(const char* nome);
int validaCPF(const char* cpf);
int validaFone(const char* fone);
int validaEmail(const char* email);
int validaLetra(char c);
int validaDigito(char c);
int validaData(const char* data);

int validaCodigo(const char* codigo);
int validaComposicao(const char* comp);
int validaTipoLeite(const char* tipo);
int validaCodigoQueijo(int codigoQueijo, int codigoEsperado);
bool validaEstoque(int estoque);
bool validaPreco(float preco);

int validaId(const char *id_venda);
