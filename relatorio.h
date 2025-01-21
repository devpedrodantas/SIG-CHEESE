#ifndef RELATORIO_H
#define RELATORIO_H 

// ========================= RELATÓRIOS GERAIS =========================
void menu_relatorio(void);         // Exibe o menu principal de relatórios
void relatorio_cliente(void);      // Exibe o relatório de clientes
void relatorio_funcionario(void);  // Exibe o relatório de funcionários
void relatorio_queijo(void);       // Exibe o relatório de queijos


// ================= RELATÓRIOS DE CLIENTES POR BAIRRO =================
void lista_clientes_por_bairro(void);
void leBairroRelatorio(char* bairro_lido);
void buscaBairroRelatorio(char* bairro_lido); 


// ==================== RELATÓRIOS QUEIJOS POR TIPO ====================
void busca_tipo_queijo_Relatorio(char* tipo_lido); 
void leTipoRelatorio(char* tipo_lido); 
void lista_queijo_tipo(void);


// ================= RELATÓRIOS DE CLIENTES POR VENDAS =================
void busca_cliente_por_compras(void);
void buscaVendas(const char *cpf_relatorio);
void leCpfRelatorio(char *cpf);

#endif 
