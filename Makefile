# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g $(INCLUDES)
INCLUDES = -Iinclude/ -Ifront/include/

# Directories
SRC_DIR = src
FRONT_DIR = front/src
OBJ_DIR = obj
BIN_DIR = bin

# Source and object files
SRC = $(wildcard $(SRC_DIR)/*.c $(FRONT_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Executable name
EXEC = $(BIN_DIR)/neural_network.exe

# Windows-specific libraries for WinAPI
LIBS = -lgdi32 -luser32 -lkernel32

# Default target
all: $(EXEC)

# Link the executable
$(EXEC): $(OBJ)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

# Compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

# Clean build artifacts
clean:
	rm -rf $(OBJ_DIR)/*.o $(BIN_DIR)/*.exe

# Run the executable
run: $(EXEC)
	$(EXEC)

.PHONY: all clean run
