# Nome do diretório de build e executável
BUILD_DIR = build
# No Windows, executáveis precisam da extensão .exe
EXE_NAME = sortbenchmark
TEST_NAME = testalg

# Detecção de Sistema Operacional
ifeq ($(OS),Windows_NT)
    # Comandos Windows (CMD)
    RM = rmdir /s /q
    RUN_COMMAND = $(BUILD_DIR)\bin\$(EXE_NAME).exe
	TEST_COMMAND = $(BUILD_DIR)\bin\$(EXE_NAME).exe
else
    # Comandos Linux/macOS
    RM = rm -rf
    RUN_COMMAND = ./$(BUILD_DIR)/bin/$(EXE_NAME)
	TEST_COMMAND = ./$(BUILD_DIR)/bin/$(TEST_NAME)
endif

# Comando padrão: configura e compila
all:
	@cmake -S . -B $(BUILD_DIR) -DCMAKE_BUILD_TYPE=Release
	@cmake --build $(BUILD_DIR) --config Release

# Atalho para rodar o benchmark após compilar
run: all
	@echo "Executando benchmark..."
	@$(RUN_COMMAND)

test: all
	@echo "Executando testes..."
	@$(TEST_COMMAND)

# Limpeza total
clean:
	@$(RM) $(BUILD_DIR)
	@echo "Pasta $(BUILD_DIR) removida."