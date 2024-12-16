#include <stdio.h> 
#include <stdlib.h>
#include <string.h>           // Para usar o strcpy
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
    char situacao[20];
    
    Cliente *cliente = (Cliente*) malloc(sizeof(Cliente));      // Aloca dinamicamente memória para a estrutura Cliente
    if (cliente == NULL) {
        perror("Erro ao alocar memória em cliente");
        exit(1);
    }

    FILE* fp;  // Ponteiro para o arquivo
    system("clear||cls");
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("|                         >>  Cadastrar Cliente  <<                         |\n");
    printf("|                                                                           |\n");
    /// Ainda será implementado >>> printf("|-> Endereço: ");;
    /// + opções de entradas de dados

    leNomeCliente(cliente);                 // Chama a função que agora lê e valida o nome do cliente
    
    // Necessário verificar se o CPF inserido já não está cadastrado
    leCpfCliente(cliente);                  // Chama a função que agora lê e valida o CPF do cliente
    leEmailCliente(cliente);                // Chama a função que agora lê e valida o Email do cliente
    leDataCliente(cliente);                 // Chama a função que agora lê e valida a data do cliente
    leFoneCliente(cliente);                 // Chama a função que agora lê e valida o telefone do cliente
    
    cliente->status = 'a';                  // Atualiza o status do cliente para 'ativo'
    strcpy(situacao, "Ativo");
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("\n");

    // Exibe as informações para o usuário
    if (cliente->status == 'x') {
        printf("Cliente Inexistente");
    } else {
        printf("+---------------------------------------------------------------------------+\n");
        printf("|                                                                           |\n");
        printf("| Cliente cadastrado com sucesso\n");
        printf("|\n");
        printf("| Nome: %s\n", cliente->nome);
        printf("| CPF: %s\n", cliente->cpf);
        printf("| Email: %s\n", cliente->email);
        printf("| Data de nascimento: %s\n", cliente->data);
        printf("| Número de telefone: %s\n", cliente->fone);
        printf("| Situação do cliente: %s\n", situacao);
        printf("|                                                                           |\n");
        printf("+---------------------------------------------------------------------------+\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();
    }

    fp = fopen ("clientes.dat", "ab");
    if(fp == NULL) {
        perror("Erro ao abrir o arquivo clientes.dat");
        exit(1);  // Mantém a saída do programa caso haja um erro ao abrir o arquivo
    }
    fwrite(cliente, sizeof(Cliente), 1, fp);

    fclose (fp);  //Fecha o arquivo
    free (cliente);                        //libera memória da estrutura Cliente

    
    // A pedido de Flavius (Informações em arquivo texto chamada a partir de clientes.txt) 
    //fprintf(fp, "+---------------------------------------------------------------------------+\n");
    //fprintf(fp, "| Nome: %s\n", cliente->nome);
    //fprintf(fp, "| CPF: %s\n", cliente->cpf);
    //fprintf(fp, "| Email: %s\n", cliente->email);
    //fprintf(fp, "| Data de nascimento: %s\n", cliente->data);
    //fprintf(fp, "| Número de telefone: %s\n", cliente->fone);                                                              
    //fprintf(fp, "+---------------------------------------------------------------------------+\n");
}

// Função para validar o CPF informado pelo usuário e acionar a busca do cliente
void pesquisa_cliente(void) {
    char cpf_busca[13];
    system("clear||cls");
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("|                         >>  Pesquisar Cliente  <<                         |\n");
    printf("|                                                                           |\n");
    
    // Lê o CPF
    leCpfBusca(cpf_busca);     // nova função parecida com o leCpfCliente mas para cpf_busca
    
    busca_cliente(cpf_busca);     // Busca o cliente pelo CPF informado e exibe-o 
}

// Função responsável por buscar e exibir os dados de um cliente com base no CPF informado
void busca_cliente (const char *cpf_busca) {
    FILE *fp;
    Cliente *cliente;
    cliente = (Cliente*) malloc(sizeof(Cliente));
  
    fp = fopen("clientes.dat", "rb");
    if (fp == NULL) {
        perror("Erro ao abrir o arquivo!\n");
        exit(1);
    }

    int encontrado = 0;
        // Ler os dados do arquivo cliente por cliente
    while (fread(cliente, sizeof(Cliente), 1, fp)) {
  

        // Verifica se o CPF corresponde ao que foi procurado
        if (strcmp(cliente->cpf, cpf_busca) == 0) {
            printf("+---------------------------------------------------------------------------+\n");
            printf("| Cliente encontrado\n");
            printf("| Nome: %s\n", cliente->nome);
            printf("| CPF: %s\n", cliente->cpf);
            printf("| Email: %s\n", cliente->email);
            printf("| Data de nascimento: %s\n", cliente->data);
            printf("| Telefone: %s\n", cliente->fone);
            printf("+---------------------------------------------------------------------------+\n");
            encontrado = 1;
            break; // Encerra o loop quando encontrar o cliente
        }
    }
    if (!encontrado) {
        printf("Cliente não encontrado\n");
    }
    fclose(fp);  // Fecha o arquivo após o uso
}

void atualiza_cliente(void) {
    char opcao[3];
    char cpf_busca[13];
    int encontrado = 0;

    FILE *fp;
    Cliente *cliente;
    cliente = (Cliente*) malloc(sizeof(Cliente));
    if (cliente == NULL) {
        perror("Erro ao alocar memória em cliente");
        exit(1);
    }
    
    system("clear||cls");
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("|                         >>  Atualizar Cliente  <<                         |\n");
    printf("|                                                                           |\n");
    
    // Lê o CPF
    leCpfBusca(cpf_busca);     // nova função parecida com o leCpfCliente mas para cpf_busca
    
    // Abre o arquivo de clientes
    fp = fopen("clientes.dat", "r+b");  // Abre o arquivo para leitura e escrita
    if (fp == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(1);
    }
    while (fread(cliente, sizeof(Cliente), 1, fp)) {
        if (strcmp(cliente->cpf, cpf_busca) == 0 && cliente->status == 'a') {
            encontrado = 1;

            // Adicionar uma interface e limpar a tela após cada mudança
            do {
                printf("\nCliente encontrado:\n");
                printf("1. Nome: %s\n", cliente->nome);
                printf("2. CPF: %s\n", cliente->cpf);
                printf("3. Email: %s\n", cliente->email);
                printf("4. Data: %s\n", cliente->data);
                printf("5. Telefone: %s\n", cliente->fone);
                printf("0. Sair da atualização\n");
                printf("\n");
                printf("Escolha o campo que deseja atualizar: ");
                
                // Lê a opção utilizando fgets
                fgets(opcao, sizeof(opcao), stdin); // Lê a opção como string
                opcao[strcspn(opcao, "\n")] = '\0'; // Remove o '\n' do final

                switch (opcao[0]) {  // Usa a primeira letra da opção
                    case '1':
                        leNomeCliente(cliente);
                        break;
                    case '2':
                        leCpfCliente(cliente);
                        break;
                    case '3':
                        leEmailCliente(cliente);
                        break;
                    case '4':
                        leDataCliente(cliente);
                        break;
                    case '5':
                        leFoneCliente(cliente);
                        break;
                    case '0':
                        printf("Finalizando a atualização...\n");
                        break;
                    default:
                        printf("Opção inválida.\n");
                }

                // Atualiza o cliente no arquivo após cada alteração
                if (opcao[0] >= '1' && opcao[0] <= '5') {
                    fseek(fp, -sizeof(Cliente), SEEK_CUR);     // Volta para o início do registro
                    fwrite(cliente, sizeof(Cliente), 1, fp);
                    printf("Dados atualizados com sucesso!\n");
                }
            } while (opcao[0] != '0');

            break; // Sai do loop após encontrar e atualizar o cliente
        }
    }

    if (!encontrado) {
        printf("Cliente com CPF %s não encontrado ou inativo.\n", cpf_busca);
    }

    fclose(fp);
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
}

void exclui_cliente(void) {
    char cpf_busca[13];
    FILE *fp, *fp_temp;
    int encontrado = 0;
    
    Cliente *cliente;
    cliente = (Cliente*) malloc(sizeof(Cliente));
    if (cliente == NULL) {
        perror("Erro ao alocar memória em cliente");
        exit(1);
    }
    system("clear||cls");
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("|                          >>  Excluir Cliente  <<                          |\n");
    printf("|                                                                           |\n");
    
    // Lê o CPF
    leCpfBusca(cpf_busca);

    // Abre o arquivo original para leitura
    fp = fopen("clientes.dat", "rb");
    if (fp == NULL) {
        perror("Erro ao abrir o arquivo original!\n");
        exit(1);
    }

    // Lê os registros do arquivo original e encontra o cliente
    while (fread(cliente, sizeof(Cliente), 1, fp)) {
        // Se o CPF corresponder, exibe os dados do cliente
        if (strcmp(cliente->cpf, cpf_busca) == 0) {
            printf("+---------------------------------------------------------------------------+\n");
            printf("| Cliente encontrado\n");
            printf("| Nome: %s\n", cliente->nome);
            printf("| CPF: %s\n", cliente->cpf);
            printf("| Email: %s\n", cliente->email);
            printf("| Data de nascimento: %s\n", cliente->data);
            printf("| Telefone: %s\n", cliente->fone);
            printf("+---------------------------------------------------------------------------+\n");

            // Pergunta para o usuário se deseja excluir
            char confirmacao[3];  // Usar um array de 2 caracteres
            printf("Tem certeza que deseja excluir este cliente? (S/N): ");
            fgets(&confirmacao, sizeof(confirmacao), stdin);
            // Remove o '\n' que pode ser deixado no buffer por causa do fgets
            confirmacao[strcspn(confirmacao, "\n")] = 0;

            // Trata a confirmação (sem considerar maiúsculas/minúsculas)
            if (confirmacao[0] == 'S' || confirmacao[0] == 's' || confirmacao[0] == 'Y' || confirmacao[0] == 'y') {
                // Abre o arquivo temporário para gravação
                fp_temp = fopen("clientes_temp.dat", "wb");
                if (fp_temp == NULL) {
                    perror("Erro ao criar o arquivo temporário!\n");
                    fclose(fp);
                    exit(1);
                }

                // Lê os dados novamente e grava no arquivo temporário
                fseek(fp, 0, SEEK_SET);  // Volta para o início do arquivo
                while (fread(cliente, sizeof(Cliente), 1, fp)) {
                    // Só escreve no arquivo temporário os clientes que não foram excluídos
                    if (strcmp(cliente->cpf, cpf_busca) != 0) {
                        fwrite(cliente, sizeof(Cliente), 1, fp_temp);
                    }
                }

                fclose(fp);
                fclose(fp_temp);

                // Remove o arquivo original e substitui pelo temporário
                if (remove("clientes.dat") != 0) {
                    perror("Erro ao remover o arquivo original\n");
                    return;
                }

                if (rename("clientes_temp.dat", "clientes.dat") != 0) {
                    perror("Erro ao renomear o arquivo temporário\n");
                    return;
                }

                 // Exibe a mensagem de sucesso após a exclusão ser realizada
                printf("\nCliente com CPF %s foi excluído com sucesso.\n", cpf_busca);
                printf("Pressione Enter para continuar...\n");
                getchar();  // Aguarda o usuário pressionar Enter antes de continuar
            } else {
                printf("\nExclusão cancelada.\n");
                printf("Pressione Enter para voltar ao menu...\n");
                getchar();  // Aguarda o usuário pressionar Enter antes de voltar
            }
            encontrado = 1;
            break;  // Sai do loop após encontrar o cliente
        }
    }

    // Se o cliente não for encontrado
    if (!encontrado) {
        printf("Cliente com CPF %s não encontrado\n", cpf_busca);
        printf("Pressione Enter para continuar...\n");
        getchar();  // Aguarda o usuário pressionar Enter antes de continuar
        fclose(fp);  // Fecha o arquivo caso o cliente não seja encontrado
    }
}

void leCpfBusca (char *cpf_busca) {
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

int verificaCpfCadastrado(const char *cpf) {
    FILE *fp;
    Cliente cliente;

    // Abre o arquivo de clientes para leitura
    fp = fopen("clientes.dat", "rb");
    if (fp == NULL) {
        perror("Erro ao abrir o arquivo de clientes");
        return 0;  // Retorna 0 para indicar erro na abertura do arquivo
    }

    // Lê os clientes do arquivo
    while (fread(&cliente, sizeof(Cliente), 1, fp)) {
        if (strcmp(cliente.cpf, cpf) == 0) {
            fclose(fp);
            return 1;  // Retorna 1 se o CPF já estiver cadastrado
        }
    }

    fclose(fp);
    return 0;  // Retorna 0 se o CPF não estiver cadastrado
}
