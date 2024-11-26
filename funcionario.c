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
    Funcionario funcionario;  // Declara um struct do tipo Funcionário 
    system("clear||cls");
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("|                       >>  Cadastrar Funcionário  <<                       |\n");
    printf("|                                                                           |\n");
    printf("|-> Nome do funcionário: ");
    do {
        leNomeFuncionario(&funcionario);  // Atualizado para usar o campo da estrutura
        if (validaNome(funcionario.nome)) {
            printf("Nome válido\n");
            break;
        } else {
            printf("Nome inválido, tente novamente apertando a tecla ENTER");
            getchar();
            printf("|-> Nome do funcionário: ");
        }
    } while (!validaNome(funcionario.nome));

    printf("|-> CPF (somente números): ");
    do {
        leCpfFuncionario(&funcionario);
        if (validaCPF(funcionario.cpf)) {
            printf("CPF válido\n");
            break;
        } else {
            printf("CPF inválido, tente novamente apertando a tecla ENTER");
            getchar();
            printf("|-> CPF (somente números): ");
        }
    } while (!validaCPF(funcionario.cpf));

    printf("|-> Email: ");
    do {
        leEmailFuncionario(&funcionario);    // Lê o email dinamicamente através do ponteiro
        if (validaEmail(funcionario.email)) {
            printf("Email válido\n");
            break;
        } else {
            printf("Email inválido, tente novamente apertando a tecla ENTER");
            getchar();
            printf("|-> Email: ");
        }
    } while (!validaEmail(funcionario.email));

    printf("|-> Telefone (somente números): ");
    do {
        leFoneFuncionario(&funcionario);    // Lê o número de telefone dinamicamente através do ponteiro
        if (validaFone(funcionario.fone)) {
            printf("Número de telefone válido\n");
            break;
        } else {
            printf("Número de telefone inválido, tente novamente apertando a tecla ENTER");
            getchar();
            printf("|-> Telefone (somente números): ");
        }
    } while (!validaFone(funcionario.fone));

    printf("|-> Data de nascimento  (DD/MM/AAAA): ");
    do {
        leDataFuncionario(&funcionario);    // Lê a data dinamicamente através do ponteiro
        if (validaData(funcionario.data)) {
            printf("Data válida\n");
            break;
        } else {
            printf("Data inválida, tente novamente apertando a tecla ENTER");
            getchar();
            printf("|-> Data de nascimento  (DD/MM/AAAA): ");
        }
    } while (!validaData(funcionario.data));

    ///printf("|-> Cargo: |\n");
    ///printf("|-> Endereço:  |\n");
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("\n");
///implementar uma interface
    
    printf("Nome: %s\n", funcionario.nome);                     // Acessa o campo 'nome' da estrutura 'funcionario'
    printf("CPF: %s\n", funcionario.cpf);                       // Acessa o campo 'cpf' da estrutura 'funcionario'
    printf("Email: %s\n", funcionario.email);                   // Acessa o campo 'email' da estrutura 'funcionario'
    printf("Data de nascimento: %s\n", funcionario.data);       // Acessa o campo 'data' da estrutura 'funcionario'
    printf("Número de telefone: %s\n", funcionario.fone);       // Acessa o campo 'fone' da estrutura 'funcionario'
    
   // Liberação da memória alocada dinamicamente
    free (funcionario.nome);
    free (funcionario.email);
    free (funcionario.data);
    free (funcionario.fone);
}

void pesquisa_funcionario(void) {
    Funcionario funcionario;  // Declara um struct do tipo Funcionário 
    system("clear||cls");
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("|                       >>  Pesquisar Funcionário  <<                       |\n");
    printf("|                                                                           |\n");
    printf("|-> Informe o seu CPF: ");
    do {
        leCpfFuncionario(&funcionario);
        if (validaCPF(funcionario.cpf)) {
            break;
        } else {
            printf("CPF inválido, tente novamente apertando a tecla ENTER");
            getchar();
            printf("|-> CPF (somente números): ");
        }
    } while (!validaCPF(funcionario.cpf));

    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("\n");
    printf("CPF inserido: %s\n", funcionario.cpf);

    //    printf("Nome: %s\n", nome);
    //    printf("CPF: %s\n", cpf);
    //    printf("Email: %s\n", email);
    //    printf("Data de nascimento: %s\n", data);
    //    printf("Número de telefone: %s\n", fone);

    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void atualiza_funcionario(void) {
    Funcionario funcionario;  // Declara um struct do tipo Funcionário 
    system("clear||cls");
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("|                       >> Atualizar Funcionário  <<                        |\n");
    printf("|                                                                           |\n");
    printf("|-> Informe seu CPF: ");
    do {
        leCpfFuncionario(&funcionario);
        if (validaCPF(funcionario.cpf)) {
            break;
        } else {
            printf("CPF inválido, tente novamente apertando a tecla ENTER");
            getchar();
            printf("|-> Informe seu CPF: ");
        }
    } while(!validaCPF(funcionario.cpf));

    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("\n");
    printf("CPF inserido: %s\n", funcionario.cpf);

    //    Dados do funcionário atualizados:
    //    printf("Nome: %s\n", nome);
    //    printf("CPF: %s\n", cpf);
    //    printf("Email: %s\n", email);
    //    printf("Data de nascimento: %s\n", data);
    //    printf("Número de telefone: %s\n", fone);

    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void exclui_funcionario(void) {
    Funcionario funcionario;  // Declara um struct do tipo Funcionário 
    system("clear||cls");
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("|                        >>  Excluir Funcionário  <<                        |\n");
    printf("|                                                                           |\n");
    printf("|-> Informe seu CPF: ");
    do {
        leCpfFuncionario(&funcionario);
        if (validaCPF(funcionario.cpf)) {
            break;
        } else {
            printf("CPF inválido, tente novamente apertando a tecla ENTER");
            getchar();
            printf("|-> Informe seu CPF: ");
        }
    } while(!validaCPF(funcionario.cpf));

    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("\n");
    printf("CPF inserido: %s\n", funcionario.cpf);

    //    Funcionário excluído:
    //    printf("Nome: %s\n", nome);
    //    printf("CPF: %s\n", cpf);
    //    printf("Email: %s\n", email);
    //    printf("Data de nascimento: %s\n", data);
    //    printf("Número de telefone: %s\n", fone);

    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}
