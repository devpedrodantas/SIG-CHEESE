#ifndef ENTRADAS_H  // Proteção contra múltiplas inclusões
#define ENTRADAS_H

#include "cliente.h"          // Inclui a definição do tipo Cliente
#include "funcionario.h"      // Inclui a definição do tipo Funcionário
#include "queijo.h"           // Inclui a definição do tipo Queijo
#include "estruturas.h"         

#define TAM_CODIGO 7

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
void lePreco(Queijo *queijo);
void leEstoque(Queijo *queijo);

// Funções que recebem um ponteiro para a struct Endereco
void leBairro(Endereco *endereco);
void leCidade(Endereco *endereco);
void leEstado(Endereco *endereco);



//////////////////////////////////////////////////////////////////////////////////////////
// Funções que fazem apenas a captura das entradas
// void leApenasNome(Cliente *cliente);
// void leApenasCpf(Cliente *cliente);
// void leApenasEmail(Cliente *cliente);
// void leApenaData(Cliente *cliente);
// void leApenasFone(Cliente *cliente);

// void leApenasNomeF(Funcionario *funcionario);
// void leApenasCpfF(Funcionario *funcionario);
// void leApenasEmailF(Funcionario *funcionario);
// void leApenaDataF(Funcionario *funcionario);
// void leApenasFoneF(Funcionario *funcionario);

// void leApenasNomeQ(Queijo *queijo);
// void leApenasDataFab(Queijo *queijo);
// void leApenasDataVal(Queijo *queijo);
// void leApenasCodigo(Queijo *queijo);
// void leApenasComposicao(Queijo *queijo);
// void leApenasTipo(Queijo *queijo);

#endif // ENTRADAS_H
