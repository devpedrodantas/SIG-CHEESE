#include <stdio.h>
#include <stdlib.h>
#include <string.h>           // Para usar o strcpy
#include "queijo.h"
#include "entradas.h"
#include "validacao.h"

void menu_queijo(void) {
    char op;
    do {
        system("clear||cls");
        printf("\n");
        printf("+---------------------------------------------------------------------------+\n");
        printf("|                                                                           |\n");
        printf("|                         * * * Menu Queijos * * *                          |\n");
        printf("|                                                                           |\n");
        printf("|-> 1. Cadastrar um novo queijo no sistema                                  |\n");
        printf("|-> 2. Pesquisar os dados de um queijo                                      |\n");
        printf("|-> 3. Atualizar os dados de um queijo                                      |\n");
        printf("|-> 4. Excluir um queijo do sistema                                         |\n");
        printf("|-> 0. Voltar ao menu anterior                                              |\n");
        printf("|                                                                           |\n");
        printf("+---------------------------------------------------------------------------+\n");
        printf("\n");
        printf("            Escolha a opção desejada: ");
        scanf("%c", &op);
        getchar();
        printf("\n");
        printf("+---------------------------------------------------------------------------+\n");
        switch(op) {
            case '1':
                cadastra_queijo();
                break;
            case'2':
                pesquisa_queijo();
                break;
            case '3':
                atualiza_queijo();  
                break;
            case '4':
                exclui_queijo();
                break;
            case '0':
                printf("Voltando ao Menu Principal\n");
                printf("\n");
                printf("\t\t\t>>> Tecle ENTER para continuar...\n");
                getchar();
                break;
            default:
                printf("Opção inválida, pressione um dígito entre os disponíveis\n");
                printf("\n");
                printf("\t\t\t>>> Tecle ENTER para continuar...\n");
                getchar();
                break;
        }
    } while(op != '0');
}

void cadastra_queijo(void) {
    char situacao[20];   // Declaração de variável para armazenar a situação 
    
    Queijo *queijo = (Queijo*) malloc(sizeof(Queijo));      // Aloca dinamicamente memória para a estrutura
    if (queijo == NULL) {
        perror("Erro ao alocar memória em queijo");
        exit(1);
    }

    FILE* fp;  // Ponteiro para o arquivo
    system("clear||cls");
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("|                         >>  Cadastrar Queijo  <<                          |\n");
    printf("|                                                                           |\n");

    leNomeQueijo(queijo);    // Chama a função que lê e valida o nome

    // Lê o código e verifica se já está cadastrado
    do {
        leCodigo(queijo); // Lê e valida o código do queijo
        if (verificaCodigoCadastrado(queijo->codigo)) {
            printf("\nErro: código %s já cadastrado!\n", queijo->codigo);
            printf("Tente novamente.\n");
        } else {
            break; // código não está duplicado, sai do loop
        }
    } while (1); // Continua até o código ser válido e único

    leDataFabricacao(queijo);    // Chama a função que lê e valida a data de fabricação
    leDataValidade(queijo);      // Chama a função que lê e valida a data de validade
    leComposicao(queijo);        // Chama a função que lê e valida a composição/ingrediente
    leTipoLeite(queijo);         // Chama a função que lê e valida o tipo do queijo
    
    queijo->status = 'a';                  // Coloca o status do queijo como 'ativo'
    strcpy(situacao, "Ativo");

    // Exibe as informações para o usuário
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("| Queijo cadastrado com sucesso\n");
    printf("|\n");
    printf("| Nome do queijo: %s\n", queijo->nome);
    printf("| Código do queijo: %s\n", queijo->codigo);
    printf("| Ingredientes/composição: %s\n", queijo->comp);
    printf("| Data de fabricação: %s\n", queijo->data_fabricacao);
    printf("| Data de validade: %s\n", queijo->data_validade);
    printf("| Tipo do queijo: %s\n", queijo->tipo);
    printf("| Situação do queijo: %s\n", situacao);
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

    fp = fopen ("queijos.dat", "ab");
    if(fp == NULL) {
        perror("Erro ao abrir o arquivo queijos.dat");
        exit(1);  // Mantém a saída do programa caso haja um erro ao abrir o arquivo
    }
    fwrite(queijo, sizeof(Queijo), 1, fp);

    fclose (fp);  //Fecha o arquivo
    free (queijo);                        // libera memória da estrutura queijo
}

void pesquisa_queijo(void) {
    char codigo_busca[10];
    system("clear||cls");
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("|                          >> Pesquisar Queijo <<                           |\n");
    printf("|                                                                           |\n");
    leCodigoBusca(codigo_busca);
    busca_queijo(codigo_busca);
}

void busca_queijo (const char *codigo_busca) {
    char situacao[20];    // Declaração de variável para armazenar a situação do cliente
    
    FILE *fp;
    Queijo *queijo;
    queijo = (Queijo*) malloc(sizeof(Queijo));
    if (queijo == NULL) {
        perror("Erro ao alocar memória em queijo");
        exit(1);
    }

  
    fp = fopen("queijos.dat", "rb");
    if (fp == NULL) {
        perror("Erro ao abrir o arquivo!\n");
        exit(1);
    }

    int encontrado = 0;
        // Ler os dados do arquivo queijo por queijo
    while (fread(queijo, sizeof(Queijo), 1, fp)) {
  

        // Verifica se o código corresponde ao que foi procurado
       if (strcmp(queijo->codigo, codigo_busca) == 0) {
            printf("+---------------------------------------------------------------------------+\n");
            printf("| Queijo encontrado\n");
            printf("| Nome: %s\n", queijo->nome);
            printf("| Código: %s\n", queijo->codigo);
            printf("| Data de fabricação: %s\n", queijo->data_fabricacao);
            printf("| Data de validade: %s\n", queijo->data_validade);
            printf("| Composição: %s\n", queijo->comp);
            printf("| Tipo: %s\n", queijo->tipo);
            
            // Verifica o status do queijo (ativo ou inativo)
            if (queijo->status == 'a') {
                strcpy(situacao, "Ativo");
            } else if (queijo->status == 'i') {
                strcpy(situacao, "Inativo");
            } else {
                strcpy(situacao, "Não informado");
            }
        
            printf("| Situação do queijo: %s\n", situacao);
            printf("+---------------------------------------------------------------------------+\n");
            printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
            getchar();
            encontrado = 1;
            break; // Encerra o loop quando encontrar o queijo
        }
    }
    if (!encontrado) {
        printf("Queijo não encontrado\n");
        getchar();
    }
    fclose(fp);  // Fecha o arquivo após o uso
    free (queijo);                        // libera memória da estrutura queijo
}


void atualiza_queijo(void) {
    char opcao[3];
    char codigo_busca[10];
    int encontrado = 0;

    FILE *fp;
    Queijo *queijo;
    queijo = (Queijo*) malloc(sizeof(Queijo));
    if (queijo == NULL) {
        perror("Erro ao alocar memória em queijo");
        exit(1);
    }

    system("clear||cls");
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("|                      >>  Alterar Dados do Queijo  <<                      |\n");
    printf("|                                                                           |\n");
    leCodigoBusca(codigo_busca);

    fp = fopen("queijos.dat", "r+b");
    if (fp == NULL) {
        perror("Erro ao abrir o arquivo!\n");
        exit(1);
    }
    while (fread(queijo, sizeof(Queijo), 1, fp)) {
        if (strcmp(queijo->codigo, codigo_busca) == 0 && queijo->status == 'a') {
            encontrado = 1;

            // Adicionar uma interface e limpar a tela após cada mudança
            do {
                printf("\nCliente encontrado:\n");
                printf("1. Nome: %s\n", queijo->nome);
                printf("2. Código: %s\n", queijo->codigo);
                printf("3. Data de fabricação: %s\n", queijo->data_fabricacao);
                printf("4. Data de validade: %s\n", queijo->data_validade);
                printf("5. Composição: %s\n", queijo->comp);
                printf("6. Tipo: %s\n", queijo->tipo);
                printf("0. Sair da atualização\n");
                printf("\n");
                printf("Escolha o campo que deseja atualizar: ");
                
                // Lê a opção utilizando fgets
                fgets(opcao, sizeof(opcao), stdin); // Lê a opção como string
                opcao[strcspn(opcao, "\n")] = '\0'; // Remove o '\n' do final

                switch (opcao[0]) {  // Usa a primeira letra da opção
                    case '1':
                        leNomeQueijo(queijo);
                        break;
                    case '2':
                        leCodigo(queijo);
                        break;
                    case '3':
                        leDataFabricacao(queijo);
                        break;
                    case '4':
                        leDataValidade(queijo);
                        break;
                    case '5':
                        leComposicao(queijo);
                        break;
                    case '6':
                        leTipoLeite(queijo);;
                        break;
                    case '0':
                        printf("Finalizando a atualização...\n");
                        break;
                    default:
                        printf("Opção inválida.\n");
                }

                // Atualiza o cliente no arquivo após cada alteração
                if (opcao[0] >= '1' && opcao[0] <= '6') {
                    fseek(fp, -sizeof(Queijo), SEEK_CUR);     // Volta para o início do registro
                    fwrite(queijo, sizeof(Queijo), 1, fp);
                    printf("Dados atualizados com sucesso!\n");
                }
            } while (opcao[0] != '0');

            break; // Sai do loop após encontrar e atualizar o queijo
        }
    }

    if (!encontrado) {
        printf("Queijo com CPF %s não encontrado ou inativo.\n", codigo_busca);
    }

    fclose(fp);
    free (queijo);                        // libera memória da estrutura queijo
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
}

void exclui_queijo(void) {
    char situacao[20];   // Declaração de variável para armazenar a situação do cliente
    char codigo_busca[13];
    FILE *fp;
    int encontrado = 0;
    
    Queijo *queijo;
    queijo = (Queijo*) malloc(sizeof(Queijo));
    if (queijo == NULL) {
        perror("Erro ao alocar memória em queijo");
        exit(1);
    }
    
    system("clear||cls");
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("|                           >>  Excluir Queijo  <<                          |\n");
    printf("|                                                                           |\n");
    leCodigoBusca(codigo_busca);

    fp = fopen("queijos.dat", "r+b");
    if (fp == NULL) {
        perror("Erro ao abrir o arquivo!\n");
        exit(1);
    }
    while (fread(queijo, sizeof(Queijo), 1, fp)) {
        if (strcmp(queijo->codigo, codigo_busca) == 0 && queijo->status == 'a') {
            encontrado = 1;
            
            // Exibe a situação do cliente
            if (queijo->status == 'a') {
                strcpy(situacao, "Ativo");
            } else if (queijo->status == 'i') {
                strcpy(situacao, "Inativo");
            } else {
                strcpy(situacao, "Não informado");
            }
            
            printf("+---------------------------------------------------------------------------+\n");
            printf("| Queijo encontrado\n");
            printf("| Nome: %s\n", queijo->nome);
            printf("| Código: %s\n", queijo->codigo);
            printf("| Data de fabricação: %s\n", queijo->data_fabricacao);
            printf("| Data de validade: %s\n", queijo->data_validade);
            printf("| Composição: %s\n", queijo->comp);
            printf("| Tipo: %s\n", queijo->tipo);
            printf("| Situação do cliente: %s\n", situacao);  // Exibe a situação do cliente
            printf("+---------------------------------------------------------------------------+\n");

            // Pergunta para o usuário se deseja excluir
            char confirmacao[3];  // Usar um array de 2 caracteres
            printf("Tem certeza que deseja excluir este cliente? (S/N): ");
            fgets(&confirmacao, sizeof(confirmacao), stdin);
            // Remove o '\n' que pode ser deixado no buffer por causa do fgets
            confirmacao[strcspn(confirmacao, "\n")] = 0;

            // Trata a confirmação (sem considerar maiúsculas/minúsculas)
            if (confirmacao[0] == 'S' || confirmacao[0] == 's' || confirmacao[0] == 'Y' || confirmacao[0] == 'y') {
                
                // Marca o queijo como inativo
                queijo->status = 'i';
                fseek(fp, -sizeof(Queijo), SEEK_CUR); // Volta ao início do registro atual
                fwrite(queijo, sizeof(Queijo), 1, fp); // Atualiza o registro no arquivo

                printf("\nQueijo com CPF %s foi marcado como inativo.\n", codigo_busca);
                printf("Pressione Enter para continuar...\n");
                getchar(); // Aguarda o usuário pressionar Enter antes de continuar
            } else {
                printf("\nExclusão cancelada.\n");
                printf("Pressione Enter para voltar ao menu...\n");
                getchar(); // Aguarda o usuário pressionar Enter antes de voltar
            }
            encontrado = 1;
            break; // Sai do loop após encontrar o Queijo
        }
    }

    // Se o cliente não for encontrado
    if (!encontrado) {
        printf("Queijo com CPF %s não encontrado ou já está inativo.\n", codigo_busca);
        printf("Pressione Enter para continuar...\n");
        getchar(); // Aguarda o usuário pressionar Enter antes de continuar
    }

    fclose(fp); // Fecha o arquivo após o uso
    free(queijo); // Libera a memória alocada
}

void leCodigoBusca (char *codigo_busca) {
    printf("|-> Código (6 Dígitos): ");     // Criar uma nova função parecida com o leCpfCliente mas para cpf_busca
    do {
        fgets(codigo_busca, 10, stdin);
        codigo_busca[strcspn(codigo_busca, "\n")] = '\0';  // Remove o '\n' do final

        if (validaCodigo(codigo_busca)) {
            printf("Código válido\n");
            break;
        } else {
            printf("Código inválido, tente novamente apertando a tecla ENTER\n");
        }
    } while (!validaCodigo(codigo_busca));  // Continua até o CPF ser válido
}

int verificaCodigoCadastrado(const char *codigo) {
    FILE *fp;
    Queijo queijo;

    // Abre o arquivo de queijos para leitura
    fp = fopen("queijos.dat", "rb");
    if (fp == NULL) {
        perror("Erro ao abrir o arquivo de queijos");
        return 0;  // Retorna 0 para indicar erro na abertura do arquivo
    }

    // Lê os queijos do arquivo
    while (fread(&queijo, sizeof(Queijo), 1, fp)) {
        if (strcmp(queijo.codigo, codigo) == 0) {
            fclose(fp);
            return 1;  // Retorna 1 se o CPF já estiver cadastrado
        }
    }

    fclose(fp);
    return 0;  // Retorna 0 se o CPF não estiver cadastrado
}
