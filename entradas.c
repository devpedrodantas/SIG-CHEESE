#include <stdio.h>
#include <stdlib.h>           // Inclusão da biblioteca para manipulação de memória dinâmica.
#include <string.h>           // Inclusão da biblioteca para manipulação de strings.
#include "cliente.h"          // Define a estrutura e funções do Cliente.
#include "funcionario.h"      // Define a estrutura e funções do Funcionário.
#include "queijo.h"           // Define a estrutura e funções do Queijo.
#include "validacao.h"        // Contém funções para validações gerais.


// Funções específicas para Cliente (Ainda é necessário evitar esta redundância com cliente, funcionário e queijo)

///--------------------------------------------------------///
///                        NOME C                          ///
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
///                         CPF C                          ///
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
            break;
        } else {
            printf("CPF inválido, tente novamente apertando a tecla ENTER");
            getchar();
            printf("|-> CPF (somente números): ");
        }
    } while (!validaCPF(cliente->cpf)); // Continua até o CPF ser válido
}


///--------------------------------------------------------///
///                        EMAIL C                         ///
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
///                        DATA C                          ///
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
///                        FONE C                          ///
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

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////// ---- Funcionário ---- ///////////////////////////////////

///--------------------------------------------------------///
///                        NOME F                          ///
//---------------------------------------------------------///
// Função para capturar apenas o nome do funcionário

void leApenasNomeF(Funcionario *funcionario) {
    fgets(funcionario->nome, sizeof(funcionario->nome), stdin);              
    funcionario->nome[strcspn(funcionario->nome, "\n")] = '\0';
}

// Função para ler e validar o nome do funcionário
void leNomeFuncionario(Funcionario *funcionario) {
    printf("|-> Nome do funcionário: ");
    do {
        leApenasNomeF(funcionario);
        if (validaNome(funcionario->nome)) {
            printf("Nome válido\n");
            break;
        } else {
            printf("Nome inválido, tente novamente apertando a tecla ENTER");
            getchar();
            printf("|-> Nome do funcionário: ");
        }
    } while (!validaNome(funcionario->nome));
}

///--------------------------------------------------------///
///                         CPF F                          ///
//---------------------------------------------------------///
// Função para capturar apenas o CPF do funcionário
void leApenasCpfF(Funcionario *funcionario) {
    fgets(funcionario->cpf, sizeof(funcionario->cpf), stdin);
    funcionario->cpf[strcspn(funcionario->cpf, "\n")] = '\0';
}

// Função para ler e validar o CPF do funcionário
void leCpfFuncionario(Funcionario *funcionario) {
    printf("|-> CPF (somente números): ");
    do {
        leApenasCpfF(funcionario);
        if (validaCPF(funcionario->cpf)) {
            printf("CPF válido\n");
            break;
        } else {
            printf("CPF inválido, tente novamente apertando a tecla ENTER");
            getchar();
            printf("|-> CPF (somente números): ");
        }
    } while (!validaCPF(funcionario->cpf)); // Continua até o CPF ser válido
}


///--------------------------------------------------------///
///                        EMAIL F                         ///
//---------------------------------------------------------///
// Função para capturar apenas o email do funcionário
void leApenasEmailF(Funcionario *funcionario) {
    fgets(funcionario->email, sizeof(funcionario->email), stdin);
    funcionario->email[strcspn(funcionario->email, "\n")] = '\0';
}

// Função para ler e validar o Email do funcionário
void leEmailFuncionario(Funcionario *funcionario) {
    printf("|-> Email: ");
    do {
        leApenasEmailF(funcionario);    // Lê o email dinamicamente através do ponteiro
        if (validaEmail(funcionario->email)) {
            printf("Email válido\n");
            break;
        } else {
            printf("Email inválido, tente novamente apertando a tecla ENTER");
            getchar();
            printf("|-> Email: ");
        }
    } while(!validaEmail(funcionario->email));
}


///--------------------------------------------------------///
///                        DATA F                          ///
//---------------------------------------------------------///
// Função para capturar apenas a data do funcionário
void leApenaDataF(Funcionario *funcionario) {
    fgets(funcionario->data, sizeof(funcionario->data), stdin);
    funcionario->data[strcspn(funcionario->data, "\n")] = '\0';
}

// Função para ler e validar a data do funcionário
void leDataFuncionario(Funcionario *funcionario) {
    printf("|-> Data de nascimento (DD/MM/AAAA): ");
        do {
        leApenaDataF(funcionario);   // Lê a data dinamicamente através do ponteiro
        if (validaData(funcionario->data)) {
            printf("Data válida\n");
            break;
        } else {
            printf("Data inválida, tente novamente apertando a tecla ENTER");
            getchar();
            printf("|-> Data de nascimento (DD/MM/AAAA): ");
        }
    } while(!validaData(funcionario->data));
}


///--------------------------------------------------------///
///                        FONE F                          ///
//---------------------------------------------------------///
// Função para capturar apenas o número de telefone do funcionário
void leApenasFoneF(Funcionario *funcionario) {
    fgets(funcionario->fone, sizeof(funcionario->fone), stdin);
    funcionario->fone[strcspn(funcionario->fone, "\n")] = '\0';
}

// Função para ler e validar o  número de telefone do funcionário
void leFoneFuncionario(Funcionario *funcionario) {
  printf("|-> Telefone (somente números): ");
     do {
        leApenasFoneF(funcionario);    // Lê o número de telefone dinamicamente através do ponteiro
        if (validaFone(funcionario->fone)) {
            printf("Número de telefone válido\n");
            break;
        } else {
            printf("Número de telefone inválido, tente novamente apertando a tecla ENTER");
            getchar();
            printf("|-> Telefone (somente números): ");
        }
    } while(!validaFone(funcionario->fone));
}


/////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////// ---- Queijo ---- //////////////////////////////////////

///--------------------------------------------------------///
///                        NOME Q                          ///
//---------------------------------------------------------///
// Função para capturar apenas o nome do queijo

void leApenasNomeQ(Queijo *queijo) {
    fgets(queijo->nome, sizeof(queijo->nome), stdin);              
    queijo->nome[strcspn(queijo->nome, "\n")] = '\0';
}

// Função para ler e validar o nome do queijo
void leNomeQueijo(Queijo *queijo) {
    printf("|-> Nome do queijo: ");
    do {
       leApenasNomeQ(queijo);
        if (validaNome(queijo->nome)) {
            printf("Nome válido\n");
            break;
        } else {
            printf("Nome inválido, tente novamente apertando a tecla ENTER");
            getchar();
            printf("|-> Nome do queijo: ");
        }
    } while (!validaNome(queijo->nome));
}

///--------------------------------------------------------///
///                       FABRICAÇÃO                       ///
//---------------------------------------------------------///
// Função para capturar apenas a data de fabricação do queijo

void leApenasDataFab(Queijo *queijo) {
    fgets(queijo->data_fabricacao, sizeof(queijo->data_fabricacao), stdin);              
    queijo->data_fabricacao[strcspn(queijo->data_fabricacao, "\n")] = '\0';
}

// Função para ler e validar a data de fabricação do queijo
void leDataFabricacao(Queijo *queijo) {
    printf("|-> Data de fabricação(DD/MM/AAAA): ");
    do {
       leApenasDataFab(queijo);
        if (validaData(queijo->data_fabricacao)) {
            printf("Data de fabricação válida\n");
            break;
        } else {
            printf("Data de fabricação inválida, tente novamente apertando a tecla ENTER");
            getchar();
            printf("|-> Data de fabricação(DD/MM/AAAA): ");
        }
    } while (!validaData(queijo->data_fabricacao));
}

///--------------------------------------------------------///
///                        VALIDADE                        ///
//---------------------------------------------------------///
// Função para capturar apenas a data de validade do queijo

void leApenasDataVal(Queijo *queijo) {
    fgets(queijo->data_validade, sizeof(queijo->data_validade), stdin);              
    queijo->data_validade[strcspn(queijo->data_validade, "\n")] = '\0';
}

// Função para ler e validar a data de validade do queijo
void leDataValidade(Queijo *queijo) {
    printf("|-> Data de validade(DD/MM/AAAA): ");
    do {
       leApenasDataVal(queijo);
        if (validaData(queijo->data_validade)) {
            printf("Data de validade válida\n");
            break;
        } else {
            printf("Data de validade inválida, tente novamente apertando a tecla ENTER");
            getchar();
            printf("|-> Data de validade(DD/MM/AAAA): ");
        }
    } while (!validaData(queijo->data_validade));
}

///--------------------------------------------------------///
///                        CÓDIGO                          ///
//---------------------------------------------------------///
// Função para capturar apenas o código do queijo

void leApenasCodigo(Queijo *queijo) {
    fgets(queijo->codigo, sizeof(queijo->codigo), stdin);              
    queijo->codigo[strcspn(queijo->codigo, "\n")] = '\0';
}

// Função para ler e validar o código do queijo
void leCodigo(Queijo *queijo) {
    printf("|-> Código do queijo(6 dígitos): ");
    do {
       leApenasCodigo(queijo);
        if (validaCodigo(queijo->codigo)) {
            printf("Código válido\n");
            break;
        } else {
            printf("Código inválido, tente novamente apertando a tecla ENTER\n");
            printf("|-> Código do queijo(6 dígitos): ");
        }
    } while (!validaCodigo(queijo->codigo));
}

///--------------------------------------------------------///
///                        COMPOSIÇÃO                      ///
//---------------------------------------------------------///
// Função para capturar apenas a composição/ingrediente do queijo

void leApenasComposicao(Queijo *queijo) {
    fgets(queijo->comp, sizeof(queijo->comp), stdin);              
    queijo->comp[strcspn(queijo->comp, "\n")] = '\0';
}

// Função para ler e validar a composição/ingrediente do queijo
void leComposicao(Queijo *queijo) {
    printf("|-> Composição/ingrediente do queijo: ");
    do {
       leApenasComposicao(queijo);
        if (validaComposicao(queijo->comp)) {
            printf("Composição/ingrediente válido\n");
            break;
        } else {
            printf("Composição/ingrediente inválido, tente novamente apertando a tecla ENTER");
            getchar();
            printf("|-> Composição/ingrediente do queijo: ");
        }
    } while (!validaComposicao(queijo->comp));
}

///--------------------------------------------------------///
///                         TIPO                           ///
//---------------------------------------------------------///
// Função para capturar apenas o tipo do queijo

void leApenasTipo(Queijo *queijo) {
    fgets(queijo->tipo, sizeof(queijo->tipo), stdin);              
    queijo->tipo[strcspn(queijo->tipo, "\n")] = '\0';
}

// Função para ler e validar o tipo do queijo
void leTipoLeite(Queijo *queijo) {
    printf("|-> Tipo do queijo(cru ou pasteurizado): ");
    do {
       leApenasTipo(queijo);
        if (validaTipoLeite(queijo->tipo)) {
            printf("Tipo válido\n");
            break;
        } else {
            printf("Tipo inválido, tente novamente apertando a tecla ENTER");
            getchar();
            printf("|-> Tipo do queijo(cru ou pasteurizado): ");
        }
    } while (!validaTipoLeite(queijo->tipo));
}



///////////////////////////////////////////////////
//            Funções não mais usadas            
//
// // Função geral para leitura de entradas
// void leEntrada(char **entrada, size_t tamanho) {
//     char buffer[tamanho];
//     fgets(buffer, tamanho, stdin);
//     buffer[strcspn(buffer, "\n")] = '\0';  // Remove o \n no final da string

//     if (*entrada != NULL) {
//         free(*entrada);  // Libera memória previamente alocada
//     }

//     *entrada = (char*) malloc(strlen(buffer) + 1);
//     if (*entrada == NULL) {
//         perror("Erro ao alocar memória");
//         exit(1);  // Sai caso a alocação falhe
//     }

//     strcpy(*entrada, buffer);  // Copia o buffer para o ponteiro
// }


// // Funções temporárias para ler entradas curtase longas (serão REMOVIDAS depois)
// void leEntradaMax(char **entrada) {
//     leEntrada(entrada, 256);
// }

// void leEntradaMin(char **entrada) {
//     leEntrada(entrada, 16);
// }


// // Funções para Funcionario
// void leNomeFuncionario(Funcionario *funcionario) {
//   leEntradaMax(&funcionario->nome);  // Passa o ponteiro para o nome
// }

// void leCpfFuncionario(Funcionario *funcionario) {
//     scanf("%11s", funcionario->cpf);  // Acessa diretamente funcionario->cpf
//     getchar();
// }

// void leEmailFuncionario(Funcionario *funcionario) {
//     leEntradaMax(&funcionario->email);  // Passa o ponteiro para o email
// }

// void leDataFuncionario(Funcionario *funcionario) {
//     leEntradaMin(&funcionario->data);  // Passa o ponteiro para a data
// }

// void leFoneFuncionario(Funcionario *funcionario) {
//     leEntradaMin(&funcionario->fone);  // Passa o ponteiro para o telefone
// }

// // Funções para Queijo
// void leNomeQueijo(Queijo *queijo) {
//   leEntradaMax(&queijo->nome);  // Passa o ponteiro para o nome
// }

// void leDataFabricacao(Queijo *queijo) {
//     leEntradaMin(&queijo->data_fabricacao);  // Passa o ponteiro para a data
// }

// void leDataValidade(Queijo *queijo) {
//     leEntradaMin(&queijo->data_validade);  // Passa o ponteiro para a data
// }


// void leCodigo(Queijo *queijo) {
//     scanf("%6s", queijo->codigo); //Acessa diretamente queijo->codigo
//     getchar();
// }

// void leComposicao(Queijo *queijo) {
//     leEntradaMax(&queijo->comp); // Passa o ponteiro para a composição/ingrediente
// }

// void leTipoLeite(Queijo *queijo) {
//     leEntradaMin(&queijo->tipo); // Passa o ponteiro para a tipo
// }
