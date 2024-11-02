#include <stdio.h>
#include <string.h>
#include <ctype.h>  // Para a função isalpha

//---------------------------------------------------------
//                   Validação para Letra
//---------------------------------------------------------

int validaLetra(char c) {
    return isalpha(c);
}

//---------------------------------------------------------
//                  Validação para Nome
//---------------------------------------------------------

int validaNome(char* nome) {
    int temLetra = 0; 

    if (nome[0] == '\0') {
        return 0; // Nome inválido: campo vazio
    }

    for (int i = 0; nome[i] != '\0'; i++) {
        if (!validaLetra(nome[i]) && nome[i] != ' ') {
            return 0; // Nome inválido: caracteres não permitidos
        }
        if (validaLetra(nome[i])) {
            temLetra = 1; // Letra encontrada
        }
    }

    if (!temLetra) {
        return 0; // Nome inválido: apenas espaços
    }
    return 1; // Nome válido: contém pelo menos uma letra
}

//---------------------------------------------------------
//                    Validação para CPF                   
//---------------------------------------------------------
// Créditos ao ChatGPT

/// Retorna 1 se a string recebida corresponde a um número de CPF válido 
/// (apenas dígitos) ou retorna 0 caso contrário


int validaCPF(char* cpf) {
    int tam = strlen(cpf);
    
    // Verifica se o CPF tem 11 dígitos
    if (tam != 11) {
        return 0;
    }

    // Verifica se todos os caracteres são dígitos
    for (int i = 0; i < tam; i++) {
        if (!isdigit(cpf[i])) {
            return 0; // Retorna 0 se não for dígito
        }
    }

    // Cálculo dos dígitos verificadores
    int soma1 = 0, soma2 = 0, d1, d2;

    // Calcula o primeiro dígito verificador
    for (int i = 0; i < 9; i++) {
        soma1 += (cpf[i] - '0') * (10 - i);
    }
    d1 = (soma1 * 10) % 11;
    if (d1 == 10) d1 = 0;

    // Calcula o segundo dígito verificador
    for (int i = 0; i < 9; i++) {
        soma2 += (cpf[i] - '0') * (11 - i);
    }
    soma2 += d1 * 2; // Inclui o primeiro dígito verificador
    d2 = (soma2 * 10) % 11;
    if (d2 == 10) d2 = 0;
    
    // Verifica se os dígitos verificadores estão corretos
    if (cpf[9] - '0' != d1 || cpf[10] - '0' != d2) {
        return 0; // Retorna 0 se os dígitos não são válidos
    }
    return 1; // Retorna 1 se o CPF é válido
}


