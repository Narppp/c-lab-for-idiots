CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude -O2
SRC_DIR = src
OBJ_DIR = obj
BUILD_DIR = normal_build
DEBUG_DIR = debug_build
DEBUG_FLAGS = -fsanitize=address -g3

SRCS = $(wildcard src/*.c)

NORM_OBJ_DIR = obj/norm_obj
DEBUG_OBJ_DIR = obj/debug_obj

NORM_OBJS = $(SRCS:$(SRC_DIR)/%.c=$(NORM_OBJ_DIR)/%.o)
DEBUG_OBJS = $(SRCS:$(SRC_DIR)/%.c=$(DEBUG_OBJ_DIR)/%.o)

NORM_PROJ_NAME = $(BUILD_DIR)/norm_vec
DEBUG_PROJ_NAME = $(DEBUG_DIR)/debug_vec

all: $(NORM_PROJ_NAME)

run: $(NORM_PROJ_NAME)
	@clear
	@./$(NORM_PROJ_NAME)

debug: $(DEBUG_PROJ_NAME)
	@gdb ./$(DEBUG_PROJ_NAME)

sanitize: $(DEBUG_PROJ_NAME)
	@./$(DEBUG_PROJ)

valgrind: $(NORM_PROJ_NAME)
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NORM_PROJ_NAME)

$(DEBUG_PROJ_NAME): $(DEBUG_OBJS) | $(DEBUG_DIR)
	@$(CC) $(CFLAGS) $(DEBUG_OBJS) $(DEBUG_FLAGS) -o $(DEBUG_PROJ_NAME)

$(NORM_PROJ_NAME): $(NORM_OBJS) | $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(NORM_OBJS) -o $(NORM_PROJ_NAME)

$(NORM_OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(NORM_OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(DEBUG_OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(DEBUG_OBJ_DIR)
	@$(CC) $(CFLAGS) $(DEBUG_FLAGS) -c $< -o $@

$(OBJ_DIR) $(BUILD_DIR) $(DEBUG_DIR) $(NORM_OBJ_DIR) $(DEBUG_OBJ_DIR):
	@mkdir -p $@

clean:
	@rm -rf $(OBJ_DIR) $(BUILD_DIR) $(DEBUG_DIR)

help:
	@echo "Available commands:"
	@echo "make - Build the shell"
	@echo "make run - Build AND Run the shell"
	@echo "make clean - Deletes all files for proper restart"
	@echo "make sanitize - Checks ASan for mem leak"
	@echo "make debug - Runs gdb for debugging"
	@echo "make valgrind - Runs valgrind for easier bug traces"

.PHONY: all clean run help sanitize debug valgrind
