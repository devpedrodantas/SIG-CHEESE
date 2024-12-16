#include <stdio.h>
#include <stdlib.h>
#include <string.h>           // Para usar o strcpy
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
    char situacao[20];   // Declaração de variável para armazenar a situação 
    
    Funcionario *funcionario = (Funcionario*) malloc(sizeof(Funcionario));      // Aloca dinamicamente memória para a estrutura
    if (funcionario == NULL) {
        perror("Erro ao alocar memória em funcionario");
        exit(1);
    }

    FILE* fp;  // Ponteiro para o arquivo
    system("clear||cls");
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("|                       >>  Cadastrar Funcionário  <<                       |\n");
    printf("|                                                                           |\n");

    leNomeFuncionario(funcionario);   // Chama a função que lê e valida o nome

    // Lê o CPF e verifica se já está cadastrado
    do {
        leCpfFuncionario(funcionario); // Lê e valida o CPF do cliente
        if (verificaCpfCadastradoF(funcionario->cpf)) {
            printf("\nErro: CPF %s já cadastrado!\n", funcionario->cpf);
            printf("Tente novamente.\n");
        } else {
            break; // CPF não está duplicado, sai do loop
        }
    } while (1); // Continua até o CPF ser válido e único

    leEmailFuncionario(funcionario);     // Chama a função que lê e valida o Email
    leDataFuncionario(funcionario);      // Chama a função que lê e valida a data
    leFoneFuncionario(funcionario);      // Chama a função que lê e valida o telefone

    // Serão adicionados
    ///printf("|-> Cargo: |\n");
    ///printf("|-> Endereço:  |\n");
    
    funcionario->status = 'a';                  // Coloca o status do funcionário como 'ativo'
    strcpy(situacao, "Ativo");

    // Exibe as informações para o usuário
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("| Funcionário cadastrado com sucesso\n");
    printf("|\n");
    printf("| Nome: %s\n", funcionario->nome);                     // Acessa o campo 'nome' da estrutura 'funcionario'
    printf("| CPF: %s\n", funcionario->cpf);                       // Acessa o campo 'cpf' da estrutura 'funcionario'
    printf("| Email: %s\n", funcionario->email);                   // Acessa o campo 'email' da estrutura 'funcionario'
    printf("| Data de nascimento: %s\n", funcionario->data);       // Acessa o campo 'data' da estrutura 'funcionario'
    printf("| Número de telefone: %s\n", funcionario->fone);       // Acessa o campo 'fone' da estrutura 'funcionario'
    printf("| Situação do funcionário: %s\n", situacao);
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

    fp = fopen ("funcionarios.dat", "ab");
    if(fp == NULL) {
        perror("Erro ao abrir o arquivo funcionarios.dat");
        exit(1);  // Mantém a saída do programa caso haja um erro ao abrir o arquivo
    }
    fwrite(funcionario, sizeof(Funcionario), 1, fp);

    fclose (fp);  //Fecha o arquivo
    free (funcionario);                        // libera memória da estrutura funcionario
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

            
int verificaCpfCadastradoF(const char *cpf) {
    FILE *fp;
    Funcionario funcionario;
    
    // Abre o arquivo de funcionários para leitura
    fp = fopen("funcionarios.dat", "rb");
    if (fp == NULL) {
        perror("Erro ao abrir o arquivo de funcionários");
        return 0;  // Retorna 0 para indicar erro na abertura do arquivo
    }

    // Lê os funcionários do arquivo
    while (fread(&funcionario, sizeof(Funcionario), 1, fp)) {
        if (strcmp(funcionario.cpf, cpf) == 0) {
            fclose(fp);
            return 1;  // Retorna 1 se o CPF já estiver cadastrado
        }
    }

    fclose(fp);
    return 0;  // Retorna 0 se o CPF não estiver cadastrado
}

