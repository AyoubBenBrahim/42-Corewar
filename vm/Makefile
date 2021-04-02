NAME = ../corewar

SRC_DIR = ./src
INC_DIR = ./inc/
LIBFT_INC = $(LIBFT_DIR)/
OBJ_DIR = ./obj

LIBFT = ./libft/libft.a
LIBPRINTF = ./ft_printf/libftprintf.a
LIBFT_DIR = ./libft
LIBPRINTF_DIR = ./ft_printf

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
			parsing_related_3.o\
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
CFLAGS = -Wall -Werror -Wextra
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

$(NAME): $(LIBFT) $(LIBPRINTF) $(OBJ_SRC) $(OBJ_OP)
	@$(CC) $(OBJ_SRC) $(OBJ_OP) $(LIBFT) $(LIBPRINTF) -o $(NAME)
	@printf "Corewar  %-25s$(C_GREEN)[done]$(C_NONE)\n" $@

lib:
	@make -C $(LIBFT_DIR)
	@make -C $(LIBPRINTF_DIR)

cleanlib:
	@make -C $(LIBFT_DIR) clean
	@make -C $(LIBPRINTF_DIR) clean

fcleanlib:
	@make -C $(LIBFT_DIR) fclean
	@make -C $(LIBPRINTF_DIR) fclean

clean: cleanlib
	@rm -rf $(OBJ_DIR)
	@printf "Corewar  %-25s$(C_RED)[done]$(C_NONE)\n" $@

fclean: clean fcleanlib
	@rm -rf $(NAME)
	@printf "Corewar  %-25s$(C_RED)[done]$(C_NONE)\n" $@

re: fclean all
