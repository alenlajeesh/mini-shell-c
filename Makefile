# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror -Iinclude

# Target name
NAME = minishell

# Source files
SRC = \
	src/main.c \
	src/input.c \
	src/parser.c \
	src/execute.c \
	src/builtins.c

# Object files
OBJ = $(SRC:.c=.o)

# Default rule
all: $(NAME)

# Build executable
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

# Compile .c to .o
src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJ)

# Clean everything
fclean: clean
	rm -f $(NAME)

# Rebuild
re: fclean all

.PHONY: all clean fclean re

