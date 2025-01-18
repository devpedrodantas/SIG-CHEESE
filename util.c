#include <stdio.h>
#include "util.h"

void limparBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}  // Limpa caracteres até encontrar \n ou EOF
}
