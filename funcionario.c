#include <stdio.h> 
#include <stdlib.h>
#include "funcionario.h"

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
    system("clear||cls");
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("|                       >>  Cadastrar Funcionário  <<                       |\n");
    printf("|                                                                           |\n");
    printf("|-> Nome do funcionário:                                                    |\n");
    printf("|-> Cargo:                                                                  |\n");
    printf("|-> Endereço:                                                               |\n");
    printf("|-> Telefone:                                                               |\n");
    printf("|-> Email:                                                                  |\n");
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("\n");
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
