#include <stdio.h>
#include <stdlib.h>           // Inclusão da biblioteca para manipulação de memória dinâmica.
#include <string.h>           // Inclusão da biblioteca para manipulação de strings.
#include "cliente.h"          // Define a estrutura e funções do Cliente.
#include "funcionario.h"      // Define a estrutura e funções do Funcionário.
#include "queijo.h"           // Define a estrutura e funções do Queijo.
#include "validacao.h"        // Contém funções para validações gerais.


// Funções específicas para Cliente               (Ainda é necessário evitar esta redundância com cliente, funcionário e queijo)

///--------------------------------------------------------///
///                        NOME                            ///
//---------------------------------------------------------///
// Função para capturar apenas o nome do cliente
void leApenasNome(Cliente *cliente) {
    fgets(cliente->nome, sizeof(cliente->nome), stdin);              
    cliente->nome[strcspn(cliente->nome, "\n")] = '\0';
}

// Função para ler e validar o nome do cliente
void leNomeCliente(Cliente *cliente) {
    printf("|-> Nome do cliente: ");
    do {
       leApenasNome(cliente);
        if (validaNome(cliente->nome)) {
            printf("Nome válido\n");
            break;
        } else {
            printf("Nome inválido, tente novamente apertando a tecla ENTER");
            getchar();
            printf("|-> Nome do cliente: ");
        }
    } while (!validaNome(cliente->nome));
}


///--------------------------------------------------------///
///                         CPF                            ///
//---------------------------------------------------------///
// Função para capturar apenas o CPF do cliente
void leApenasCpf(Cliente *cliente) {
    fgets(cliente->cpf, sizeof(cliente->cpf), stdin);
    cliente->cpf[strcspn(cliente->cpf, "\n")] = '\0';
}

// Função para ler e validar o CPF do cliente
void leCpfCliente(Cliente *cliente) {
    printf("|-> CPF (somente números): ");
    do {
        leApenasCpf(cliente);
        if (validaCPF(cliente->cpf)) {
            printf("CPF válido\n");
            getchar();
            break;
        } else {
            printf("CPF inválido, tente novamente apertando a tecla ENTER");
            getchar();
            printf("|-> CPF (somente números): ");
        }
    } while (!validaCPF(cliente->cpf)); // Continua até o CPF ser válido
}


///--------------------------------------------------------///
///                        EMAIL                           ///
//---------------------------------------------------------///
// Função para capturar apenas o email do cliente
void leApenasEmail(Cliente *cliente) {
    fgets(cliente->email, sizeof(cliente->email), stdin);
    cliente->email[strcspn(cliente->email, "\n")] = '\0';
}

// Função para ler e validar o Email do cliente
void leEmailCliente(Cliente *cliente) {
    printf("|-> Email: ");
    do {
        leApenasEmail(cliente);    // Lê o email dinamicamente através do ponteiro
        if (validaEmail(cliente->email)) {
            printf("Email válido\n");
            break;
        } else {
            printf("Email inválido, tente novamente apertando a tecla ENTER");
            getchar();
            printf("|-> Email: ");
        }
    } while(!validaEmail(cliente->email));
}


///--------------------------------------------------------///
///                        DATA                            ///
//---------------------------------------------------------///
// Função para capturar apenas a data do cliente
void leApenaData(Cliente *cliente) {
    fgets(cliente->data, sizeof(cliente->data), stdin);
    cliente->data[strcspn(cliente->data, "\n")] = '\0';
}

// Função para ler e validar a data do cliente
void leDataCliente(Cliente *cliente) {
    printf("|-> Data de nascimento (DD/MM/AAAA): ");
        do {
        leApenaData(cliente);   // Lê a data dinamicamente através do ponteiro
        if (validaData(cliente->data)) {
            printf("Data válida\n");
            break;
        } else {
            printf("Data inválida, tente novamente apertando a tecla ENTER");
            getchar();
            printf("|-> Data de nascimento (DD/MM/AAAA): ");
        }
    } while(!validaData(cliente->data));
}


///--------------------------------------------------------///
///                        FONE                            ///
//---------------------------------------------------------///
// Função para capturar apenas o número de telefone do cliente
void leApenasFone(Cliente *cliente) {
    fgets(cliente->fone, sizeof(cliente->fone), stdin);
    cliente->fone[strcspn(cliente->fone, "\n")] = '\0';
}

// Função para ler e validar o  número de telefone do cliente
void leFoneCliente(Cliente *cliente) {
  printf("|-> Telefone (somente números): ");
     do {
        leApenasFone(cliente);    // Lê o número de telefone dinamicamente através do ponteiro
        if (validaFone(cliente->fone)) {
            printf("Número de telefone válido\n");
            break;
        } else {
            printf("Número de telefone inválido, tente novamente apertando a tecla ENTER");
            getchar();
            printf("|-> Telefone (somente números): ");
        }
    } while(!validaFone(cliente->fone));
}
// Função geral para leitura de entradas
void leEntrada(char **entrada, size_t tamanho) {
    char buffer[tamanho];
    fgets(buffer, tamanho, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';  // Remove o \n no final da string

    if (*entrada != NULL) {
        free(*entrada);  // Libera memória previamente alocada
    }

    *entrada = (char*) malloc(strlen(buffer) + 1);
    if (*entrada == NULL) {
        perror("Erro ao alocar memória");
        exit(1);  // Sai caso a alocação falhe
    }

    strcpy(*entrada, buffer);  // Copia o buffer para o ponteiro
}


// Funções temporárias para ler entradas curtase longas (serão REMOVIDAS depois)
void leEntradaMax(char **entrada) {
    leEntrada(entrada, 256);
}

void leEntradaMin(char **entrada) {
    leEntrada(entrada, 16);
}


// Funções para Funcionario
void leNomeFuncionario(Funcionario *funcionario) {
  leEntradaMax(&funcionario->nome);  // Passa o ponteiro para o nome
}

void leCpfFuncionario(Funcionario *funcionario) {
    scanf("%11s", funcionario->cpf);  // Acessa diretamente funcionario->cpf
    getchar();
}

void leEmailFuncionario(Funcionario *funcionario) {
    leEntradaMax(&funcionario->email);  // Passa o ponteiro para o email
}

void leDataFuncionario(Funcionario *funcionario) {
    leEntradaMin(&funcionario->data);  // Passa o ponteiro para a data
}

void leFoneFuncionario(Funcionario *funcionario) {
    leEntradaMin(&funcionario->fone);  // Passa o ponteiro para o telefone
}

// Funções para Queijo
void leNomeQueijo(Queijo *queijo) {
  leEntradaMax(&queijo->nome);  // Passa o ponteiro para o nome
}

void leDataFabricacao(Queijo *queijo) {
    leEntradaMin(&queijo->data_fabricacao);  // Passa o ponteiro para a data
}

void leDataValidade(Queijo *queijo) {
    leEntradaMin(&queijo->data_validade);  // Passa o ponteiro para a data
}


void leCodigo(Queijo *queijo) {
    scanf("%6s", queijo->codigo); //Acessa diretamente queijo->codigo
    getchar();
}

void leComposicao(Queijo *queijo) {
    leEntradaMax(&queijo->comp); // Passa o ponteiro para a composição/ingrediente
}

void leTipoLeite(Queijo *queijo) {
    leEntradaMin(&queijo->tipo); // Passa o ponteiro para a tipo
}
