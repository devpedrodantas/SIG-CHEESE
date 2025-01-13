#ifndef RELATORIO_H
#define RELATORIO_H 

// Declaração das funções relacionadas aos relatórios
void menu_relatorio(void);         // Exibe o menu principal de relatórios
void relatorio_cliente(void);      // Exibe o relatório de clientes
void relatorio_funcionario(void);  // Exibe o relatório de funcionários
void relatorio_queijo(void);       // Exibe o relatório de queijos

void lista_clientes_por_bairro(void);
void leBairroRelatorio(char* bairro_lido);
void buscaBairroRelatorio(char* bairro_lido);

#endif 
