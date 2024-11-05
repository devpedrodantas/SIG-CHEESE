///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Seridó                     ///
///               Departamento de Computação e Tecnologia                   ///
///                  Disciplina DCT1106 -- Programação                      ///
///             Projeto Sistema de Gestão Para uma Fábrica de Queijo        ///
///                Developed by @devpedrodantas & @MizaelFGT                ///
///                              Versão: ???%                               ///
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

/////
// Assinatura das funções
int menu_principal(void);

void menu_cliente(void);
void cadastra_cliente(void);
void pesquisa_cliente(void);
void atualiza_cliente(void);
void exclui_cliente(void);

void menu_funcionario(void);
void cadastra_funcionario(void);
void pesquisa_funcionario(void);
void atualiza_funcionario(void);
void exclui_funcionario(void);

void menu_queijo(void);
void cadastra_queijo(void);
void pesquisa_queijo(void);
void atualiza_queijo(void);
void exclui_queijo(void);

void menu_sobre(void);
void menu_equipe(void);

/////
// Programa principal

int main(void) {
    int op;
    do {
        op = menu_principal();
        switch (op) {
            case 1: 
                menu_cliente();
                break;
            case 2:
                menu_funcionario();
                break;
            case 3:
                menu_queijo();
                break;
            case 4:
                menu_sobre();
                break;
            case 5:
                menu_equipe();
                break;
        	default:
                printf("Opção inválida, digite um número que esteja entre os dígitos válidos\n");
                printf("\n");
                printf("\t\t\t>>> Pressione ENTER para continuar...\n");
                getchar(); 
                break;
        }
    } while (op != 0);
    printf("The End\n");
    return 0;
}

///////////////
// Funções

int menu_principal(void) {
    int op;
    system("clear||cls");
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("|         * * * * * Sistema de Gestão Fábrica de Queijos * * * * *          |\n");
    printf("|                                                                           |\n");
    printf("| 1. Módulo Clientes                                                        |\n");
    printf("| 2. Módulo Funcionários                                                    |\n");
    printf("| 3. Módulo Queijos                                                         |\n");
    printf("| 4. Menu Sobre                                                             |\n");
    printf("| 5. Menu Equipe                                                            |\n");
    printf("| 0. Sair                                                                   |\n");
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("\n");
    printf("            Escolha a opção desejada: ");
    scanf("%d", &op);
    getchar();
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    return op;
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
                printf("Voltando para o menu principal\n");
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
    system("clear||cls");
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("|                         >>  Cadastrar Cliente  <<                         |\n");
    printf("|                                                                           |\n");
    printf("|-> Nome do cliente:                                                        |\n");
    printf("|-> Endereço:                                                               |\n");
    printf("|-> Telefone:                                                               |\n");
    printf("|-> Email:                                                                  |\n");
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("\n");
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
    printf("|-> Informe o nome ou ID do cliente:                                        |\n");
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

void menu_funcionario(void) {
    char op;
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
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    cadastra_funcionario();
    pesquisa_funcionario();
    atualiza_funcionario();
    exclui_funcionario();

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

void menu_queijo(void) {
    char op;
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
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    cadastra_queijo();
    pesquisa_queijo();
    atualiza_queijo();
    exclui_queijo();

}

void cadastra_queijo(void) {
    system("clear||cls");
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("|                         >>  Cadastrar Queijo  <<                          |\n");
    printf("|                                                                           |\n");
    printf("|-> Código do queijo:                                                       |\n");
    printf("|-> Nome do queijo:                                                         |\n");
    printf("|-> Ingredientes:                                                           |\n");
    printf("|-> Tipo do leite para o queijo:                                            |\n");
    printf("|-> Leite cru ou pasteurizado:                                              |\n");
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
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

void menu_sobre(void) {
    system("clear||cls");
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("|             Universidade Federal do Rio Grande do Norte                   |\n");
    printf("|                 Centro de Ensino Superior do Seridó                       |\n");
    printf("|               Departamento de Computação e Tecnologia                     |\n");
    printf("|                  Disciplina DCT1106 -- Programação                        |\n");
    printf("|                  Projeto Sistema de Gestão Fábrica de Queijo              |\n");
    printf("|                   Developed by @devpedrodantas & @MizaelFGT               |\n");
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("|            = = = = = Sistema de Gestão Fábrica de Queijo = = = = =        |\n");
    printf("|                                                                           |\n");
    printf("|  Programa exemplo utilizado na disciplina DCT1106 - Programação, para     |\n");
    printf("|  fins didáticos de ilustração. O programa contém os principais módulos    |\n");
    printf("|  e funcionalidades que serão exigidos na avaliação dos projetos a serem   |\n");
    printf("|  desenvolvidos pelos clientes ao longo da disciplina. Serve como um guia  |\n");
    printf("|  de consulta e referência para o desenvolvidos dos demais projetos.       |\n");
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void menu_equipe(void) {
    system("clear||cls");
    printf("\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("|                Universidade Federal do Rio Grande do Norte                |\n");
    printf("|                    Centro de Ensino Superior do Seridó                    |\n");
    printf("|                  Departamento de Computação e Tecnologia                  |\n");
    printf("|                    Disciplina DCT1106 -- Programação                      |\n");
    printf("|               Projeto Sistema de Gestão Fábrica de Queijos                |\n");
    printf("|                Developed by @devpedrodantas and @MizaelFGT                |\n");
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|            Este projeto exemplo foi desenvolvido por:                     |\n");
    printf("|                                                                           |\n");
    printf("|            Pedro Henrique de Souza Dantas                                 |\n");
    printf("|            E-mail: pedro.dantas.701@ufrn.edu.br                           |\n");
    printf("|            Redes sociais: @084_pedrin7                                    |\n");
    printf("|            Git: https://github.com/devpedrodantas/SIG-CHEESE.git          |\n");
    printf("|                                                                           |\n");
    printf("|                                                                           |\n");
    printf("|            Mizael Franklin Gomes da Trindade                              |\n");
    printf("|            E-mail: mizael.trindade.130@ufrn.edu.br                        |\n");
    printf("|            Redes sociais: @mizaelfgt                                      |\n");
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
} 
