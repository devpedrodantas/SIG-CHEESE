#include <stdio.h>
#include <stdlib.h>
#include "queijo.h"
#include "entradas.h"

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
// Chama funções responsáveis por ler entradas do usuário
    
    char codigo[TAM_CODIGO];    // Array de tamanho fixo para armazenar o código, alocação estática

    // Ponteiros para armazenar entradas alocadas dinamicamente
    char *nome;
    char *comp;
    char *data_validade;
    char *data_fabricacao;
    char *tipo;
    
    system("clear||cls");
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("|                         >>  Cadastrar Queijo  <<                          |\n");
    printf("|                                                                           |\n");
    printf("|-> Código do queijo(somente números): ");
    leCodigo(codigo);
    
    printf("|-> Nome do queijo: ");
    leNome(&nome);
    
    printf("|-> Ingredientes: ");
    leComposicao(&comp);
    
    printf("|-> Data de fabricação(DD/MM/AAAA): ");
    leData(&data_fabricacao);
    
    printf("|-> Data de validade(DD/MM/AAAA): ");
    leData(&data_validade);
    
    printf("|-> Tipo do leite para o queijo(cru ou pasteurizado): ");
    leTipoLeite(&tipo);
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

    // Liberação da memória alocada dinamicamente
    free(nome);
    free(comp);
    free(data_fabricacao);
    free(data_validade);
    free(tipo);
}

void pesquisa_queijo(void) {
    system("clear||cls");
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("|                          >> Pesquisar Queijo <<                           |\n");
    printf("|                                                                           |\n");
    printf("|-> Informe o código do queijo:                                             |\n");
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void atualiza_queijo(void) {
    system("clear||cls");
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("|                      >>  Alterar Dados do Queijo  <<                      |\n");
    printf("|                                                                           |\n");
    printf("|-> Informe o código do queijo:                                             |\n");
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void exclui_queijo(void) {
    system("clear||cls");
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("|                           >>  Excluir Queijo  <<                          |\n");
    printf("|                                                                           |\n");
    printf("|-> Informe o código do queijo:                                             |\n");
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}
