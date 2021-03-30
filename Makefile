NAME = corewar
LIBFT_FILE = libft.a

LIBFT_DIR = ./libft
SRC_DIR = ./src
INC_DIR = ./inc/
LIBFT_INC = $(LIBFT_DIR)/
OBJ_DIR = ./obj

LFLAG =

LIBFT = $(LIBFT_DIR)/$(LIBFT_FILE)

HEADERS = $(INC_DIR)cor.h $(INC_DIR)op.h

SRC_FILES = cursor_related.o\
			free_nd_exit.o\
			let_the_game_begin.o\
			little_to_big_endian.o\
			main.o\
			memory.o\
			op.o\
			operations.o\
			parse_operation.o\
			parsing_related.o\
			parsing_related_2.o\
			player_related.o\
			tools_related.o\
			vm_related.o\

OP_FILES = 	operations/add.o\
			operations/aff.o\
			operations/and.o\
			operations/fork.o\
			operations/ld.o\
			operations/ldi.o\
			operations/live.o\
			operations/lld.o\
			operations/lldi.o\
			operations/or.o\
			operations/st.o\
			operations/sti.o\
			operations/sub.o\
			operations/xor.o\
			operations/zjmp.o\
			verbosity/print_operation.o\
			verbosity/verbosity_levels.o

OBJ_SRC = $(addprefix $(OBJ_DIR)/, $(SRC_FILES))
OBJ_OP = $(addprefix $(OBJ_DIR)/, $(OP_FILES))

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
INC = -I $(INC_DIR) -I $(LIBFT_INC)

C_RED = \033[31m
C_GREEN = \033[32m
C_CYAN = \033[36m
C_NONE = \033[0m

all: lib $(NAME)


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $(INC) $< -o $@
	@printf "Corewar  %-25s$(C_GREEN)[done]$(C_NONE)\n" $@

$(NAME): $(LIBFT) $(OBJ_SRC) $(OBJ_OP)
	@$(CC) $(OBJ_SRC) $(OBJ_OP) $(LIBFT) -o $(NAME)
	@printf "Corewar  %-25s$(C_GREEN)[done]$(C_NONE)\n" $@

lib:
	@make -C $(LIBFT_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean
	@printf "Corewar  %-25s$(C_RED)[done]$(C_NONE)\n" $@

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@printf "Corewar  %-25s$(C_RED)[done]$(C_NONE)\n" $@

re: fclean all
