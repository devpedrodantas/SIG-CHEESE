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
    printf("| Situação do funcionário: Ativo\n");
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
    char cpf_busca[13];
    system("clear||cls");
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("|                       >>  Pesquisar Funcionário  <<                       |\n");
    printf("|                                                                           |\n");
    
    leCpfBuscaF(cpf_busca);
    busca_funcionario(cpf_busca);
}

void busca_funcionario (const char *cpf_busca) {
    
    FILE *fp;
    Funcionario funcionario;

    fp = fopen("funcionarios.dat", "rb");
    if (fp == NULL) {
        perror("Erro ao abrir o arquivo!\n");
        exit(1);
    }

    int encontrado = 0;
        // Ler os dados do arquivo cliente por cliente
    while (fread(&funcionario, sizeof(Funcionario), 1, fp)) {
  
              // Verifica se o CPF corresponde ao que foi procurado
       if (strcmp(funcionario.cpf, cpf_busca) == 0) {
            exibe_funcionario(&funcionario);
            printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
            getchar();  // Espera o usuário pressionar ENTER para continuar
            encontrado = 1;
            break; // Encerra o loop quando encontrar o cliente
        }
    }
    if (!encontrado) {
        printf("funcionário não encontrado\n");
    }
    fclose(fp);  // Fecha o arquivo após o uso
}


void atualiza_funcionario(void) {
    char opcao[3];
    char cpf_busca[13];
    int encontrado = 0;

    FILE *fp;
    Funcionario *funcionario;
    funcionario = (Funcionario*) malloc(sizeof(Funcionario));
    if (funcionario == NULL) {
        perror("Erro ao alocar memória em cliente");
        exit(1);
    }
    
    system("clear||cls");
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("|                       >> Atualizar Funcionário  <<                        |\n");
    printf("|                                                                           |\n");
    
    leCpfBuscaF(cpf_busca);

    fp = fopen("funcionarios.dat", "r+b");
    if (fp == NULL) {
        perror("Erro ao abrir o arquivo!\n");
        exit(1);
    }
        // Ler os dados do arquivo funcionario por funcionario
    while (fread(funcionario, sizeof(Funcionario), 1, fp)) {
  

        // Verifica se o CPF corresponde ao que foi procurado
       if (strcmp(funcionario->cpf, cpf_busca) == 0 && funcionario->status == 'a') {
           encontrado = 1;
           
            // Adicionar uma interface e limpar a tela após cada mudança
            do {
                printf("\n Funcionário encontrado:\n");
                printf("1. Nome: %s\n", funcionario->nome);
                printf("2. CPF: %s\n", funcionario->cpf);
                printf("3. Email: %s\n", funcionario->email);
                printf("4. Data: %s\n", funcionario->data);
                printf("5. Telefone: %s\n", funcionario->fone);
                printf("0. Sair da atualização\n");
                printf("\n");
                printf("Escolha o campo que deseja atualizar: ");
                
                // Lê a opção utilizando fgets
                fgets(opcao, sizeof(opcao), stdin); // Lê a opção como string
                opcao[strcspn(opcao, "\n")] = '\0'; // Remove o '\n' do final

                switch (opcao[0]) {  // Usa a primeira letra da opção
                    case '1':
                        leNomeFuncionario(funcionario);
                        break;
                    case '2':
                        leCpfFuncionario(funcionario);
                        break;
                    case '3':
                        leEmailFuncionario(funcionario);
                        break;
                    case '4':
                        leDataFuncionario(funcionario);
                        break;
                    case '5':
                        leFoneFuncionario(funcionario);
                        break;
                    case '0':
                        printf("Finalizando a atualização...\n");
                        break;
                    default:
                        printf("Opção inválida.\n");
                }

                // Atualiza o cliente no arquivo após cada alteração
                if (opcao[0] >= '1' && opcao[0] <= '5') {
                    fseek(fp, -sizeof(Funcionario), SEEK_CUR);     // Volta para o início do registro
                    fwrite(funcionario, sizeof(Funcionario), 1, fp);
                    printf("Dados atualizados com sucesso!\n");
                }
            } while (opcao[0] != '0');

            break; // Sai do loop após encontrar e atualizar o cliente
        }
    }

    if (!encontrado) {
        printf("Funcionario com CPF %s não encontrado ou inativo.\n", cpf_busca);
    }

    fclose(fp);
    free (funcionario);                        // libera memória da estrutura funcionario
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
}

void exclui_funcionario(void) {
    char cpf_busca[13];
    int encontrado = 0;

    FILE *fp;
    Funcionario *funcionario;
    funcionario = (Funcionario*) malloc(sizeof(Funcionario));
    if (funcionario == NULL) {
        perror("Erro ao alocar memória em cliente");
        exit(1);
    }
    
    system("clear||cls");
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("|                        >>  Excluir Funcionário  <<                        |\n");
    printf("|                                                                           |\n");
    
    leCpfBuscaF(cpf_busca);

    fp = fopen("funcionarios.dat", "r+b");
    if (fp == NULL) {
        perror("Erro ao abrir o arquivo!\n");
        exit(1);
    }

  // Lê os registros do arquivo original e encontra o funcionario
    while (fread(funcionario, sizeof(Funcionario), 1, fp)) {
        // Se o CPF corresponder, exibe os dados do funcionario
        if (strcmp(funcionario->cpf, cpf_busca) == 0 && funcionario->status == 'a') {
            exibe_funcionario(funcionario);
            printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
            getchar();  // Espera o usuário pressionar ENTER para continuar
            encontrado = 1;
            
            // Pergunta para o usuário se deseja excluir
            char confirmacao[3];  // Usar um array de 2 caracteres
            printf("Tem certeza que deseja excluir este Funcionário? (S/N): ");
            fgets(confirmacao, sizeof(confirmacao), stdin);
            // Remove o '\n' que pode ser deixado no buffer por causa do fgets
            confirmacao[strcspn(confirmacao, "\n")] = 0;

            // Trata a confirmação (sem considerar maiúsculas/minúsculas)
            if (confirmacao[0] == 'S' || confirmacao[0] == 's' || confirmacao[0] == 'Y' || confirmacao[0] == 'y') {
                
                // Marca o funcionario como inativo
                funcionario->status = 'i';
                fseek(fp, -sizeof(Funcionario), SEEK_CUR); // Volta ao início do registro atual
                fwrite(funcionario, sizeof(Funcionario), 1, fp); // Atualiza o registro no arquivo

                printf("\nFuncionário com CPF %s foi marcado como inativo.\n", cpf_busca);
                printf("Pressione Enter para continuar...\n");
                getchar(); // Aguarda o usuário pressionar Enter antes de continuar
            } else {
                printf("\nExclusão cancelada.\n");
                printf("Pressione Enter para voltar ao menu...\n");
                getchar(); // Aguarda o usuário pressionar Enter antes de voltar
            }
            encontrado = 1;
            break; // Sai do loop após encontrar o cliente
        }
    }

    // Se o cliente não for encontrado
    if (!encontrado) {
        printf("Funcionário com CPF %s não encontrado ou já está inativo.\n", cpf_busca);
        printf("Pressione Enter para continuar...\n");
        getchar(); // Aguarda o usuário pressionar Enter antes de continuar
    }

    fclose(fp); // Fecha o arquivo após o uso
    free(funcionario); // Libera a memória alocada
}

void leCpfBuscaF (char *cpf_busca) {
    printf("|-> CPF (somente números): ");     // Criar uma nova função parecida com o leCpfCliente mas para cpf_busca
    do {
        fgets(cpf_busca, 13, stdin);
        cpf_busca[strcspn(cpf_busca, "\n")] = '\0';  // Remove o '\n' do final

        if (validaCPF(cpf_busca)) {
            printf("CPF válido\n");
            break;
        } else {
            printf("CPF inválido, tente novamente apertando a tecla ENTER\n");
            getchar();  // Aguarda a tecla ENTER para evitar erro de input
        }
    } while (!validaCPF(cpf_busca));  // Continua até o CPF ser válido
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

void exibe_funcionario(const Funcionario *funcionario){
    printf("+---------------------------------------------------------------------------+\n");
    printf("| Nome: %s\n", funcionario->nome);
    printf("| CPF: %s\n", funcionario->cpf);
    printf("| Email: %s\n", funcionario->email);
    printf("| Data de nascimento: %s\n", funcionario->data);
    printf("| Telefone: %s\n", funcionario->fone);
    printf("| Situação do funcionário: %s\n", funcionario->status == 'a' ? "Ativo" : "Inativo");
    printf("+---------------------------------------------------------------------------+\n");
}
