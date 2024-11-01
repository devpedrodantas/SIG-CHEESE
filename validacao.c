#include <ctype.h>  // Para a função isalpha

int validaLetra(char c) {
    return isalpha(c);
}

int validarNome(char* nome) {
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
