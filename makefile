# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -g

# Directories
SRC_DIR = src
OBJ_DIR = bin/obj
BIN_DIR = bin

# Source files
SRCS = $(wildcard $(SRC_DIR)/*.c)

# Object files
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

# Output binary
OUTPUT = $(BIN_DIR)/mygit

# Default target
all: directories $(OUTPUT)

# Create necessary directories
directories:
	@mkdir -p $(OBJ_DIR) $(BIN_DIR)

# Rule to compile object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to link object files and create the binary
$(OUTPUT): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Run program
run:
	./bin/mygit $(ARGS)

# Clean target
clean:
	rm -rf $(OBJ_DIR)/*.o $(OUTPUT)
	rm -rf .mygit

test:
	make clean
	make
	./tests/test_repo_one/test_script.sh 2

# Phony targets
.PHONY: all clean directories