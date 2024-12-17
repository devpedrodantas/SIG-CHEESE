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
        // Ler os dados do arquivo cliente por cliente
    while (fread(queijo, sizeof(Queijo), 1, fp)) {
  

        // Verifica se o CPF corresponde ao que foi procurado
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
    Queijo queijo;
    system("clear||cls");
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("|                      >>  Alterar Dados do Queijo  <<                      |\n");
    printf("|                                                                           |\n");
    printf("|-> Código do queijo(somente números): ");
    do {
        leCodigo(&queijo);
        if (validaCodigo(queijo.codigo)) {
            printf("Código válido\n");
            break;
        } else {
            printf("Código inválido, tente novamente");
            getchar();
            printf("|-> Código do queijo(somente números): ");
        }
    } while (!validaCodigo(queijo.codigo));
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("\n");
    printf("Código do produto inserido: %s\n", queijo.codigo);
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void exclui_queijo(void) {
    Queijo queijo;
    system("clear||cls");
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("|                           >>  Excluir Queijo  <<                          |\n");
    printf("|                                                                           |\n");
    printf("|-> Código do queijo(somente números): ");
    do {
        leCodigo(&queijo);
        if (validaCodigo(queijo.codigo)) {
            printf("Código válido\n");
            break;
        } else {
            printf("Código inválido, tente novamente");
            getchar();
            printf("|-> Código do queijo(somente números): ");
        }
    } while (!validaCodigo(queijo.codigo));
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("\n");
    printf("Código do produto inserido: %s\n", queijo.codigo);
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
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
