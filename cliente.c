#include <stdio.h> 
#include <stdlib.h>
#include "cliente.h"

void leNome(char nome []) {
    scanf("%49[^\n]", nome);
    getchar();
}

void leCpf(char cpf[]) {
    scanf("%11s", cpf);
    getchar();
}

void leEmail(char email[]) {
    scanf("%49[^\n]", email);
    getchar();
}

void leData(char data[]) {
    scanf("%10s", data);
    getchar();
}

void leFone(char fone[]) {
    scanf("%11s", fone);
    getchar();
}

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
    char nome[50];
    char cpf[12];
    char email[50];
    char data[11];
    char fone[12];
    
    system("clear||cls");
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("|                         >>  Cadastrar Cliente  <<                         |\n");
    printf("|                                                                           |\n");
    
    printf("|-> Nome do cliente: ");
    leNome(nome);
    
/// Ainda será implementado >>> printf("|-> Endereço: ");
    printf("|-> CPF (somente números): ");
    leCpf(cpf);

    printf("|-> Email: ");
    leEmail(email);
    
    printf("|-> Data de nascimento (DD/MM/AAAA): ");
    leData(data);
    
    printf("|-> Telefone (somente números): ");
    leFone(fone);
    
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("\n");

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
    system("clear||cls");
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("|                         >>  Pesquisar Cliente  <<                         |\n");
    printf("|                                                                           |\n");
    printf("|-> Informe seu CPF:                                                        |\n");
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void atualiza_cliente(void) {
    system("clear||cls");
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("|                         >>  Atualizar Cliente  <<                         |\n");
    printf("|                                                                           |\n");
    printf("|-> Informe o ID do cliente a ser atualizado:                               |\n");
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void exclui_cliente(void) {
    system("clear||cls");
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("|                          >>  Excluir Cliente  <<                          |\n");
    printf("|                                                                           |\n");
    printf("|-> Informe o ID do cliente a ser excluído:                                 |\n");
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}