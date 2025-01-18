# Nome do executável
TARGET = projeto

# Arquivos fonte
SRCS = main.c cliente.c funcionario.c queijo.c entradas.c validacao.c relatorio.c util.c

# Arquivos de cabeçalho
HDRS = validacao.h cliente.h funcionario.h queijo.h entradas.h relatorio.h estruturas.h util.h

# Diretório de objetos
OBJ_DIR = obj

# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -pedantic -g

# Arquivos objetos
OBJS = $(SRCS:.c=.o)

# Regra padrão
all: $(TARGET)

# Criação do diretório de objetos, se não existir
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Compilação dos arquivos .c em objetos .o
$(OBJ_DIR)/%.o: %.c $(HDRS) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Regra para criar o executável
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Regra para executar o programa
run: $(TARGET)
	./$(TARGET)

# Limpar arquivos gerados
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

# Gerar as dependências automaticamente
depend: $(SRCS)
	$(CC) -MM $^ > .depend

# Incluir as dependências geradas
-include .depend

# Créditos ao chatGPT
