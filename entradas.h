#ifndef ENTRADAS_H  // Proteção contra múltiplas inclusões
#define ENTRADAS_H
#include "cliente.h"          // Inclui a definição do tipo Cliente
#include "funcionario.h"      // Inclui a definição do tipo Funcionário
#include "queijo.h"           // Inclui a definição do tipo Queijo

#define TAM_CODIGO 7

// Funções genéricas TEMPORÁRIAS para leitura das entradas 
void leEntrada(char **entrada, size_t tamanho);
void leEntradaMax(char **entrada);
void leEntradaMin(char **entrada);

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

// Funções que recebem um ponteiro para a struct Queijo
void leNomeQueijo(Queijo *queijo);
void leDataFabricacao(Queijo *queijo);
void leDataValidade(Queijo *queijo);
void leCodigo(Queijo *queijo);
void leComposicao(Queijo *queijo);
void leTipoLeite(Queijo *queijo);

#endif // ENTRADAS_H
