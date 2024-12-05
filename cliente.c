#include <stdio.h> 
#include <stdlib.h>
#include "cliente.h"
#include "entradas.h"
#include "validacao.h"

void menu_cliente(void) {
    char op;
    do {
        system("clear||cls");
        printf("\n");
        printf("+---------------------------------------------------------------------------+\n");
        printf("|                                                                           |\n");
        printf("|                        * * * Módulo Cliente * * *                         |\n");
        printf("|                                                                           |\n");
        printf("|-> 1. Cadastrar um novo cliente                                            |\n");
        printf("|-> 2. Pesquisar os dados de um cliente                                     |\n");
        printf("|-> 3. Atualizar os dados de um cliente                                     |\n");
        printf("|-> 4. Excluir um cliente do sistema                                        |\n");
        printf("|-> 0. Voltar ao menu anterior                                              |\n");
        printf("|                                                                           |\n");
        printf("+---------------------------------------------------------------------------+\n");
        printf("\n");
        printf("               Escolha a opção desejada: ");
        scanf("%c", &op);
        getchar();
        printf("\n");                                                                        
        printf("+---------------------------------------------------------------------------+\n");
        switch (op) {
            case '1':
                cadastra_cliente();
                break;
            case '2':
                pesquisa_cliente();
                break;
            case '3':
                atualiza_cliente();
                break;
            case '4':
                exclui_cliente();
                break;
            case '0':
                printf("Voltando ao menu principal\n");
                printf("\n");
                printf("\t\t\t>>> Tecle ENTER para continuar...\n");
                getchar();
                break;
            default:
                printf("Opção inválida, digite um dígito entre os disponíveis\n");
                printf("\n");
                printf("\t\t\t>>> Tecle ENTER para continuar...\n");
                getchar(); 
                break;	
        }
    } while (op != '0');
}

void cadastra_cliente(void) {
    Cliente *cliente = (Cliente*) malloc(sizeof(Cliente)); // Declara um struct do tipo Cliente   
    if (cliente == NULL) {
        perror("Erro ao alocar memória em cliente");
        exit(1);
    }
    
    system("clear||cls");
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("|                         >>  Cadastrar Cliente  <<                         |\n");
    printf("|                                                                           |\n");
    /// Ainda será implementado >>> printf("|-> Endereço: ");
    /// + opções de entradas de dados
    printf("|-> Nome do cliente: ");
    do {
        leNomeCliente(&cliente); // Atualizado para usar o campo da estrutura
        if (validaNome(cliente.nome)) {
            printf("Nome válido\n");
            break;
        } else {
            printf("Nome inválido, tente novamente apertando a tecla ENTER");
            getchar();
            printf("|-> Nome do cliente: ");
        }
    } while (!validaNome(cliente.nome));

    printf("|-> CPF (somente números): ");
    do {
        leCpfCliente(&cliente);
        if (validaCPF(cliente.cpf)) {
            printf("CPF válido\n");
            break;
        } else {
            printf("CPF inválido, tente novamente apertando a tecla ENTER");
            getchar();
            printf("|-> CPF (somente números): ");
        }
    } while (!validaCPF(cliente.cpf));

    printf("|-> Email: ");
    do {
        leEmailCliente(&cliente);    // Lê o email dinamicamente através do ponteiro
        if (validaEmail(cliente.email)) {
            printf("Email válido\n");
            break;
        } else {
            printf("Email inválido, tente novamente apertando a tecla ENTER");
            getchar();
            printf("|-> Email: ");
        }
    } while(!validaEmail(cliente.email));
    
    
    printf("|-> Data de nascimento (DD/MM/AAAA): ");
        do {
        leDataCliente(&cliente);   // Lê a data dinamicamente através do ponteiro
        if (validaData(cliente.data)) {
            printf("Data válida\n");
            break;
        } else {
            printf("Data inválida, tente novamente apertando a tecla ENTER");
            getchar();
            printf("|-> Data de nascimento (DD/MM/AAAA): ");
        }
    } while(!validaData(cliente.data));
    
    printf("|-> Telefone (somente números): ");
     do {
        leFoneCliente(&cliente);    // Lê o número de telefone dinamicamente através do ponteiro
        if (validaFone(cliente.fone)) {
            printf("Número de telefone válido\n");
            break;
        } else {
            printf("Número de telefone inválido, tente novamente apertando a tecla ENTER");
            getchar();
            printf("|-> Telefone (somente números): ");
        }
    } while(!validaFone(cliente.fone));    
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("\n");

///implementar uma interface
    printf("Cliente cadastrado com sucesso\n");
    printf("\n");
    printf("Nome: %s\n", cliente.nome);                     // Acessa o campo 'nome' da estrutura 'cliente'
    printf("CPF: %s\n", cliente.cpf);                       // Acessa o campo 'cpf' da estrutura 'cliente'
    printf("Email: %s\n", cliente.email);                   // Acessa o campo 'email' da estrutura 'cliente'
    printf("Data de nascimento: %s\n", cliente.data);       // Acessa o campo 'data' da estrutura 'cliente'
    printf("Número de telefone: %s\n", cliente.fone);       // Acessa o campo 'fone' da estrutura 'cliente'
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    
    // Liberação da memória alocada dinamicamente
    free (cliente.nome);
    free (cliente.email);
    free (cliente.data);
    free (cliente.fone);
}

void pesquisa_cliente(void) {
    Cliente cliente; // Declara uma variável do tipo Cliente
    system("clear||cls");
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("|                         >>  Pesquisar Cliente  <<                         |\n");
    printf("|                                                                           |\n");
    printf("|-> Informe seu CPF: ");
    do {
        leCpfCliente(&cliente); // Atualizado para armazenar diretamente no campo da struct
        if (validaCPF(cliente.cpf)) {
            break;
        } else {
            printf("CPF inválido, tente novamente apertando a tecla ENTER");
            getchar();
            printf("|-> Informe seu CPF: ");
        }
    } while(!validaCPF(cliente.cpf));
    
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("\n");
    printf("CPF inserido: %s\n", cliente.cpf); // Acessa o campo cpf do struct

    //    printf("Nome: %s\n", nome);
    //    printf("CPF: %s\n", cpf);
    //    printf("Email: %s\n", email);
    //    printf("Data de nascimento: %s\n", data);
    //    printf("Número de telefone: %s\n", fone); 

    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void atualiza_cliente(void) {
    Cliente cliente; // Declara uma variável do tipo Cliente
    system("clear||cls");
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("|                         >>  Atualizar Cliente  <<                         |\n");
    printf("|                                                                           |\n");
    printf("|-> Informe seu CPF: ");
    do {
        leCpfCliente(&cliente);
        if (validaCPF(cliente.cpf)) {
            break;
        } else {
            printf("CPF inválido, tente novamente apertando a tecla ENTER");
            getchar();
            printf("|-> Informe seu CPF: ");
        }
    } while(!validaCPF(cliente.cpf));
    
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("\n");
    printf("CPF inserido: %s\n", cliente.cpf);  // Acessa o campo cpf do struct

    //    Dados do cliente atualizados:
    //    printf("Nome: %s\n", nome);
    //    printf("CPF: %s\n", cpf);
    //    printf("Email: %s\n", email);
    //    printf("Data de nascimento: %s\n", data);
    //    printf("Número de telefone: %s\n", fone); 

    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void exclui_cliente(void) {
    Cliente cliente; // Declara uma variável do tipo Cliente
    system("clear||cls");
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("|                          >>  Excluir Cliente  <<                          |\n");
    printf("|                                                                           |\n");
    printf("|-> Informe seu CPF: ");
    do {
        leCpfCliente(&cliente);
        if (validaCPF(cliente.cpf)) {
            break;
        } else {
            printf("CPF inválido, tente novamente apertando a tecla ENTER");
            getchar();
            printf("|-> Informe seu CPF: ");
        }
    } while(!validaCPF(cliente.cpf));
    
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("\n");
    printf("CPF inserido: %s\n", cliente.cpf);  // Acessa o campo cpf do struct

    //    Cliente excluído:
    //    printf("Nome: %s\n", nome);
    //    printf("CPF: %s\n", cpf);
    //    printf("Email: %s\n", email);
    //    printf("Data de nascimento: %s\n", data);
    //    printf("Número de telefone: %s\n", fone); 

    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}
