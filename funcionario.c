#include <stdio.h> 
#include <stdlib.h>
#include "funcionario.h"
#include "entradas.h"
#include "validacao.h"

void menu_funcionario(void) {
    char op;
    do {
        system("clear||cls");
        printf("\n");
        printf("+---------------------------------------------------------------------------+\n");
        printf("|                                                                           |\n");
        printf("|                      * * * Módulo Funcionário * * *                       |\n");
        printf("|                                                                           |\n");
        printf("|-> 1. Cadastrar um novo funcionário                                        |\n");
        printf("|-> 2. Pesquisar os dados de um funcionário                                 |\n");
        printf("|-> 3. Atualizar os dados de um funcionário                                 |\n");
        printf("|-> 4. Excluir um funcionário do sistema                                    |\n");
        printf("|-> 0. Voltar ao menu anterior                                              |\n");
        printf("|                                                                           |\n");
        printf("+---------------------------------------------------------------------------+\n");
        printf("\n");  
        printf("               Escolha a opção desejada: ");
        scanf("%c", &op);
        getchar();
        printf("\n");                                                                      
        printf("+---------------------------------------------------------------------------+\n");
        switch(op) {
            case '1':
                cadastra_funcionario();
                break;
            case '2':
                pesquisa_funcionario();
                break;
            case '3':
                atualiza_funcionario();
                break;
            case '4':
                exclui_funcionario();
                break;
            case '0':
                printf("Voltando ao Menu Principal\n");
                printf("\n");
                printf("\t\t\t>>> Tecle ENTER para continuar...\n");
                getchar();
                break;
            default:
                printf("Número inválido, digite um dígito entre os disponíveis\n");
                printf("\n");
                printf("\t\t\t>>> Tecle ENTER para continuar...\n");
                getchar(); 
                break;
        }
    } while(op != '0');
}

void cadastra_funcionario(void) {
    char nome [TAM_NOME];
    char cpf [TAM_CPF];
    char email [TAM_EMAIL];
    char fone [TAM_FONE];
    char data [TAM_DATA];
    
    system("clear||cls");
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("|                       >>  Cadastrar Funcionário  <<                       |\n");
    printf("|                                                                           |\n");
    printf("|-> Nome do funcionário: ");
    do {
        leNome(nome);
        if (validaNome(nome)) {
            printf("Nome válido\n");
            break;
        } else {
            printf("Nome inválido, tente novamente apertando a tecla ENTER");
            getchar();
            printf("|-> Nome do funcionário: ");
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
    } while (!validaEmail(email));
    
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
    } while (!validaFone(fone));
    
    printf("|-> Data de nascimento  (DD/MM/AAAA): ");
    do {
        leData(data);
        if (validaData(data)) {
            printf("Data válida\n");
            break;
        } else {
            printf("Data inválida, tente novamente apertando a tecla ENTER");
            getchar();
            printf("|-> Data de nascimento  (DD/MM/AAAA): ");
        }
    } while (!validaData(data));
    
    ///printf("|-> Cargo: |\n");
    ///printf("|-> Endereço:  |\n");
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("\n");
///implementar uma interface
    printf("Funcionário cadastrado com sucesso\n");
    printf("\n");
    printf("Nome: %s\n", nome);
    printf("CPF: %s\n", cpf);
    printf("Email: %s\n", email);
    printf("Data de nascimento: %s\n", data);
    printf("Número de telefone: %s\n", fone);  
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void pesquisa_funcionario(void) {
    system("clear||cls");
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("|                       >>  Pesquisar Funcionário  <<                       |\n");
    printf("|                                                                           |\n");
    printf("|-> Informe o nome ou ID do funcionário:                                    |\n");
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void atualiza_funcionario(void) {
    system("clear||cls");
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("|                       >> Atualizar Funcionário  <<                        |\n");
    printf("|                                                                           |\n");
    printf("|-> Informe o ID do funcionário a ser atualizado:                           |\n");
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void exclui_funcionario(void) {
    system("clear||cls");
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("|                        >>  Excluir Funcionário  <<                        |\n");
    printf("|                                                                           |\n");
    printf("|-> Informe o ID do funcionário a ser excluído:                             |\n");
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}
