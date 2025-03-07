#include <stdio.h>
#include <stdlib.h>           // Inclusão da biblioteca para manipulação de memória dinâmica.
#include <string.h>           // Inclusão da biblioteca para manipulação de strings.

#include "cliente.h"          // Inclui a definição do tipo Cliente
#include "funcionario.h"      // Inclui a definição do tipo Funcionário
#include "queijo.h"           // Inclui a definição do tipo Queijo
#include "venda.h"        
#include "validacao.h"        // Contém funções para validações gerais.
#include "estruturas.h"       // Contém estruturas genéricas (Endereço).
#include "util.h"


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
///                    CÓDIGO do Queijo                    ///
//---------------------------------------------------------///
// Função para capturar apenas o código do queijo

void leApenasCodigoQueijo(Queijo *queijo) {
    fgets(queijo->codigo, sizeof(queijo->codigo), stdin);              
    queijo->codigo[strcspn(queijo->codigo, "\n")] = '\0';
}

// Função para ler e validar o código do queijo
void leCodigoQueijo(Queijo *queijo) {
    printf("|-> Código do queijo(6 dígitos): ");
    do {
       leApenasCodigoQueijo(queijo);
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

///--------------------------------------------------------///
///                         Estoque                        ///
///--------------------------------------------------------///
// Função para ler e validar o estoque

void leEstoque(Queijo *queijo) {
    do {
        printf("|-> Estoque (ex: 1000): ");
        if (scanf("%d", &queijo->estoque) != 1) {
            printf("Entrada inválida. Digite um número inteiro.\n");
            limparBuffer(); // Garante que o buffer será limpo
            continue;
        }
        if (queijo->estoque >= 0) {
            printf("Estoque válido\n");
            break;
        } else {
            printf("Estoque inválido, tente novamente apertando a tecla ENTER\n");
            limparBuffer();
        }
    } while (1);
}

///--------------------------------------------------------///
///                     Preço do Queijo                    ///
///--------------------------------------------------------///
// Função para ler e validar preço

void lePrecoQueijo(Queijo *queijo) {
    do {
        printf("|-> Preço (30): ");
        scanf("%f", &queijo->preco);  
        if (validaPreco(queijo->preco)) {
            printf("Preço válido\n");
            break;
        } else {
            printf("Preço inválido, tente novamente apertando a tecla ENTER");
            getchar();
            printf("|-> Preço (30): ");
        }
    } while (!validaPreco(queijo->preco));
}

///--------------------------------------------------------///
///                         Quantidade                     ///
///--------------------------------------------------------///

void leApenasQuantidade(char *entrada) {
    fgets(entrada, 20, stdin);
    entrada[strcspn(entrada, "\n")] = '\0'; // Remove o '\n'
}

void leQuantidade(Venda *venda) {
    char entrada[10];  // Para armazenar a entrada do usuário (tamanho reduzido)

    printf("|-> Informe a quantidade: ");
    leApenasQuantidade(entrada);  // Lê a entrada com a função modificada

    // Verifica se a quantidade é válida
    if (validaQuantidade(entrada)) {
        // Converte a entrada para inteiro e atribui a quantidade
        venda->quantidade_comprada = atoi(entrada);
        printf("Quantidade válida: %.2f\n", venda->quantidade_comprada);
    } else {
        printf("Quantidade inválida, tente novamente.\n");
        leQuantidade(venda);  // Chama novamente caso a entrada seja inválida
    }
}

///--------------------------------------------------------///
///                     Preço da venda                     ///
///--------------------------------------------------------///

void lePrecoVenda(Venda *venda) {
    do {
        printf("|-> Preço (30): ");
        scanf("%f", &venda->preco_total);  
        if (validaPreco(venda->preco_total)) {
            printf("Preço válido\n");
            break;
        } else {
            printf("Preço inválido, tente novamente apertando a tecla ENTER");
            getchar();
            printf("|-> Preço (30): ");
        }
    } while (!validaPreco(venda->preco_total));
}

///--------------------------------------------------------///
///                 CÓDIGO do Queijo Vendido               ///
//---------------------------------------------------------///
// Função para ler o código do produto (venda)
void leApenasCodigoVenda(Venda *venda) {
    fgets(venda->codigo_produto, sizeof(venda->codigo_produto), stdin);              
    venda->codigo_produto[strcspn(venda->codigo_produto, "\n")] = '\0';  // Remove o '\n'
}

// Função para ler e validar o código do produto (venda)
void leCodigoVenda(Venda *venda) {
    printf("|-> Código do produto (6 dígitos): ");
    do {
        leApenasCodigoVenda(venda);  // Lê o código do produto
        if (validaCodigo(venda->codigo_produto)) {  // Valida o código do produto
            printf("Código válido\n");
            break;  // Código válido, sai do loop
        } else {
            printf("Código inválido, tente novamente apertando a tecla ENTER\n");
            printf("|-> Código do produto (6 dígitos): ");
        }
    } while (!validaCodigo(venda->codigo_produto));  // Repete até o código ser válido
}

/////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////// ---- Endereço ---- /////////////////////////////////////

///--------------------------------------------------------///
///                        Bairro                          ///
//---------------------------------------------------------///
// Função para capturar apenas o bairro

void leApenasBairro(Endereco *endereco) {
    fgets(endereco->bairro, sizeof(endereco->bairro), stdin);
    endereco->bairro[strcspn(endereco->bairro, "\n")] = '\0';
}

// Função para ler e validar o bairro
void leBairro(Endereco *endereco) {
    printf("|-> Bairro: ");
    do {
       leApenasBairro(endereco);
        if (validaNome(endereco->bairro)) {
            break;
        } else {
            printf("Bairro inválido, tente novamente apertando a tecla ENTER");
            getchar();
            printf("|-> Bairro: ");
        }
    } while (!validaNome(endereco->bairro));
}

///--------------------------------------------------------///
///                         Cidade                         ///
///--------------------------------------------------------///
/// Função para capturar apenas a cidade

void leApenasCidade(Endereco *endereco) {
    fgets(endereco->cidade, sizeof(endereco->cidade), stdin);
    endereco->cidade[strcspn(endereco->cidade, "\n")] = '\0';
}

// Função para ler e validar a cidade
void leCidade(Endereco *endereco) {
    printf("|-> Cidade: ");
    do {
       leApenasCidade(endereco);
        if (validaNome(endereco->cidade)) {
            break;
        } else {
            printf("Cidade inválida, tente novamente apertando a tecla ENTER");
            getchar();
            printf("|-> Cidade: ");
        }
    } while (!validaNome(endereco->cidade));
}

///--------------------------------------------------------///
///                         Estado                         ///
///--------------------------------------------------------///
/// Função para capturar apenas o estado

void leApenasEstado(Endereco *endereco) {
    fgets(endereco->estado, sizeof(endereco->estado), stdin);
    endereco->estado[strcspn(endereco->estado, "\n")] = '\0';
}

// Função para ler e validar o estado
void leEstado(Endereco *endereco) {
    printf("|-> Estado: ");
    do {
       leApenasEstado(endereco);
        if (validaNome(endereco->estado)) {
            break;
        } else {
            printf("Estado inválido, tente novamente apertando a tecla ENTER");
            getchar();
            printf("|-> Estado: ");
        }
    } while (!validaNome(endereco->estado));
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
