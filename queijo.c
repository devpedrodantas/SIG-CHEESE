#include <stdio.h>
#include <stdlib.h>
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
    Queijo queijo;
    system("clear||cls");
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("|                         >>  Cadastrar Queijo  <<                          |\n");
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
            
    
    printf("|-> Nome do queijo: ");
    do {
        leNomeQueijo(&queijo);
        if (validaNome(queijo.nome)) {
            printf("Nome válido\n");
            break;
        } else {
            printf("Nome inválido, tente novamente");
            getchar();
            printf("|-> Nome do queijo: ");
        }
    } while (!validaNome(queijo.nome));
            
    
    printf("|-> Ingredientes: ");
    do {
        leComposicao(&queijo);
        if (validaComposicao(queijo.comp)) {
            printf("Ingrediente/composição válido\n");
            break;
        } else {
            printf("Ingrediente/composição inválido, tente novamente");
            getchar();
            printf("|-> Ingredientes: ");
        }
    } while (!validaComposicao(queijo.comp));

    
    printf("|-> Data de fabricação(DD/MM/AAAA): ");
    do {
        leDataFabricacao(&queijo);
        if (validaData(queijo.data_fabricacao)) {
            printf("Data válido\n");
            break;
        } else {
            printf("Data inválido, tente novamente");
            getchar();
            printf("|-> Data de fabricação(DD/MM/AAAA): ");
        }
    } while (!validaData(queijo.data_fabricacao));

    
    printf("|-> Data de validade(DD/MM/AAAA): ");
    do {
        leDataValidade(&queijo);
        if (validaData(queijo.data_validade)) {
            printf("Data válido\n");
            break;
        } else {
            printf("Data inválido, tente novamente");
            getchar();
            printf("|-> Data de fabricação(DD/MM/AAAA): ");
        }
    } while (!validaData(queijo.data_validade));

    
    printf("|-> Tipo do leite para o queijo(cru ou pasteurizado): ");
    do {
        leTipoLeite(&queijo);
        if (validaTipoLeite(queijo.tipo)) {
            printf("Tipo de leite válido\n");
            break;
        } else {
            printf("Tipo de leite inválido, tente novamente");
            getchar();
            printf("|-> Tipo do leite para o queijo(cru ou pasteurizado): ");
        }
    } while (!validaTipoLeite(queijo.tipo));
    
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");

    //implementar uma interface 
    printf("Queijo foi cadastrado com sucesso\n");
    printf("\n");
    printf("Nome do queijo: %s\n", queijo.nome);
    printf("Código do queijo: %s\n", queijo.codigo);
    printf("Ingredientes/composição: %s\n", queijo.comp);
    printf("Data de fabricação: %s\n", queijo.data_fabricacao);
    printf("Data de validade: %s\n", queijo.data_validade);
    printf("Tipo do queijo: %s\n", queijo.tipo);
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

    // Liberação da memória alocada dinamicamente
    free(queijo.nome);
    free(queijo.comp);
    free(queijo.data_fabricacao);
    free(queijo.data_validade);
    free(queijo.tipo);
}

void pesquisa_queijo(void) {
    Queijo queijo;
    system("clear||cls");
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("|                          >> Pesquisar Queijo <<                           |\n");
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
