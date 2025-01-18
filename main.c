///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Seridó                     ///
///               Departamento de Computação e Tecnologia                   ///
///                  Disciplina DCT1106 -- Programação                      ///
///             Projeto Sistema de Gestão Para uma Fábrica de Queijo        ///
///           Developed by @devpedrodantas & @MizaelFGT &IvysonWNM          ///
///                              Versão: 0.10                               ///
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "funcionario.h"
#include "queijo.h"
#include "relatorio.h"

///// + 1 CRUD
//// Atualizar o menu sobre e equipe
//// Melhorar as validações 

/////
// Assinatura das funções
int menu_principal(void);
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
                menu_relatorio();
                break;
            case 5:
                menu_sobre();
                break;
            case 6:
                menu_equipe();
                break;
        }
    } while (op !=0 );
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
    printf("| 1. Módulo Cliente                                                         |\n");
    printf("| 2. Módulo Funcionário                                                     |\n");
    printf("| 3. Módulo Queijo                                                          |\n");
    printf("| 4. Módulo Relatório                                                       |\n");
    printf("| 5. Menu Sobre                                                             |\n");
    printf("| 6. Menu Equipe                                                            |\n");
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
    printf("|            Mizael Franklin Gomes da Trindade                              |\n");
    printf("|            E-mail: mizael.trindade.130@ufrn.edu.br                        |\n");
    printf("|            Redes sociais: @mizaelfgt                                      |\n");
    printf("|                                                                           |\n");
    printf("|            Ivyson Wanderson Nunes Martins                                 |\n");
    printf("|            E-mail: ivyson.nunes.707@ufrn.edu.br                           |\n");
    printf("|                                                                           |\n");
    printf("+---------------------------------------------------------------------------+\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
} 
