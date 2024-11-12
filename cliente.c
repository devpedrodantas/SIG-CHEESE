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
/// Melhorar as duplicações
    
    char nome[TAM_NOME];     /// Torná-la dinâmica
    char cpf[TAM_CPF];
    char email[TAM_EMAIL];   /// Torná-la dinâmica
    char data[TAM_DATA];
    char fone[TAM_FONE];
    
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
        leNome(nome);
        if (validaNome(nome)) {
            printf("Nome válido\n");
            break;
        } else {
            printf("Nome inválido, tente novamente apertando a tecla ENTER");
            getchar();
            printf("|-> Nome do cliente: ");
        }
    } while (!validaNome(nome));

    printf("|-> CPF (somente números): ");
    do {
        leCpf(cpf);
        if (validaCPF(cpf)) {
            printf("CPF válido\n");
            break;
        } else {
            printf("CPF inválido, tente novamente apertando a tecla ENTER");
            getchar();
            printf("|-> CPF (somente números): ");
        }
    } while (!validaCPF(cpf));

    printf("|-> Email: ");
    do {
        leEmail(email);
        if (validaEmail(email)) {
            printf("Email válido\n");
            break;
        } else {
            printf("Email inválido, tente novamente apertando a tecla ENTER");
            getchar();
            printf("|-> Email: ");
        }
    } while(!validaEmail(email));
    
    
    printf("|-> Data de nascimento (DD/MM/AAAA): ");
        do {
        leData(data);
        if (validaData(data)) {
            printf("Data válido\n");
            break;
        } else {
            printf("Data inválida, tente novamente apertando a tecla ENTER");
            getchar();
            printf("|-> Data de nascimento (DD/MM/AAAA): ");
        }
    } while(!validaData(data));
    
    printf("|-> Telefone (somente números): ");
     do {
        leFone(fone);
        if (validaFone(fone)) {
            printf("Número de telefone válido\n");
            break;
        } else {
            printf("Número de telefone inválido, tente novamente apertando a tecla ENTER");
            getchar();
            printf("|-> Telefone (somente números): ");
        }
    } while(!validaFone(fone));    
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("\n");

///implementar uma interface
    printf("Cliente cadastrado com sucesso\n");
    printf("\n");
    printf("Nome: %s\n", nome);
    printf("CPF: %s\n", cpf);
    printf("Email: %s\n", email);
    printf("Data de nascimento: %s\n", data);
    printf("Número de telefone: %s\n", fone);  
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void pesquisa_cliente(void) {
    char cpf[TAM_CPF];
    system("clear||cls");
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("|                         >>  Pesquisar Cliente  <<                         |\n");
    printf("|                                                                           |\n");
    printf("|-> Informe seu CPF: ");
    do {
        leCpf(cpf);
        if (validaCPF(cpf)) {
            break;
        } else {
            printf("CPF inválido, tente novamente apertando a tecla ENTER");
            getchar();
            printf("|-> Informe seu CPF: ");
        }
    } while(!validaCPF(cpf));
    
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("\n");
    printf("CPF inserido: %s\n", cpf);
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void atualiza_cliente(void) {
    char cpf[TAM_CPF];
    system("clear||cls");
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("|                         >>  Atualizar Cliente  <<                         |\n");
    printf("|                                                                           |\n");
    printf("|-> Informe seu CPF: ");
    do {
        leCpf(cpf);
        if (validaCPF(cpf)) {
            break;
        } else {
            printf("CPF inválido, tente novamente apertando a tecla ENTER");
            getchar();
            printf("|-> Informe seu CPF: ");
        }
    } while(!validaCPF(cpf));
    
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("\n");
    printf("CPF inserido: %s\n", cpf);
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void exclui_cliente(void) {
    char cpf[TAM_CPF];
    system("clear||cls");
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("|                          >>  Excluir Cliente  <<                          |\n");
    printf("|                                                                           |\n");
    printf("|-> Informe seu CPF: ");
    do {
        leCpf(cpf);
        if (validaCPF(cpf)) {
            break;
        } else {
            printf("CPF inválido, tente novamente apertando a tecla ENTER");
            getchar();
            printf("|-> Informe seu CPF: ");
        }
    } while(!validaCPF(cpf));
    
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("\n");
    printf("CPF inserido: %s\n", cpf);
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}
