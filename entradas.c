#include <stdio.h>

void leNome(char nome [TAM_NOME]) {
    scanf("%49[^\n]", nome);
    getchar();
}

void leCpf(char cpf[TAM_CPF]) {
    scanf("%11s", cpf);
    getchar();
}

void leEmail(char email[TAM_EMAIL]) {
    scanf("%49[^\n]", email);
    getchar();
}

void leData(char data[TAM_DATA]) {
    scanf("%10s", data);
    getchar();
}

void leFone(char fone[TAM_FONE]) {
    scanf("%11s", fone);
    getchar();
}
