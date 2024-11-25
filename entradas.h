// Assinaturas das funções de entradas

#define TAM_CPF 12
#define TAM_CODIGO 7

#include "cliente.h"  // Inclui a definição do tipo Cliente

// Funções que agora recebem um ponteiro para a struct Cliente
void leNome(Cliente *cliente); 
void leCpf(Cliente *cliente);
void leEmail(Cliente *cliente); 
void leData(Cliente *cliente);  
void leFone(Cliente *cliente); 

void leCodigo(char codigo[TAM_CODIGO]);
void leComposicao(char **comp);
void leTipoLeite(char **tipo);

