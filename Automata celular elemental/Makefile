# Directorios de origen y destino
SRC_DIR := src
BIN_DIR := bin

# Compilador y opciones
CXX := g++
CXXFLAGS := -std=c++11 -w

# Archivos fuente y ejecutables
SRCS := $(wildcard $(SRC_DIR)/*.cc)
OBJS := $(SRCS:$(SRC_DIR)/%.cc=$(BIN_DIR)/%.o)
EXE := $(BIN_DIR)/mi_programa

# Regla principal
all: $(EXE)

# Regla para compilar los objetos
$(BIN_DIR)/%.o: $(SRC_DIR)/%.cc | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla para compilar el ejecutable
$(EXE): $(OBJS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(EXE)

# Regla para crear el directorio bin si no existe
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Regla para limpiar archivos generados
clean:
	rm -rf $(BIN_DIR)/*.o $(EXE)

.PHONY: all clean
