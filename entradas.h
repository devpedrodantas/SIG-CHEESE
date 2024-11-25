#ifndef ENTRADAS_H  // Proteção contra múltiplas inclusões
#define ENTRADAS_H

#define TAM_CPF 12
#define TAM_CODIGO 7

#include "cliente.h"      // Inclui a definição do tipo Cliente
#include "funcionario.h"  // Inclui a definição do tipo Funcionario

// Funções que recebem um ponteiro para a struct Cliente
void leNomeCliente(Cliente *cliente);
void leCpfCliente(Cliente *cliente);
void leEmailCliente(Cliente *cliente);
void leDataCliente(Cliente *cliente);
void leFoneCliente(Cliente *cliente);

// Funções que recebem um ponteiro para a struct Funcionario
void leNomeFuncionario(Funcionario *funcionario);
void leCpfFuncionario(Funcionario *funcionario);
void leEmailFuncionario(Funcionario *funcionario);
void leDataFuncionario(Funcionario *funcionario);
void leFoneFuncionario(Funcionario *funcionario);

// Funções auxiliares
void leCodigo(char codigo[TAM_CODIGO]);
void leComposicao(char **comp);
void leTipoLeite(char **tipo);

#endif // ENTRADAS_H
