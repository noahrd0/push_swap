#	COLORS
NOC         = \033[0m
GREEN       = \033[1;32m
RED         = \033[1;31m
BLUE        = \033[1;34m

#	NAME
NAME=push_swap

#	PATH
SRC_PATH = ./srcs/
OBJ_PATH = ./objs/
INC_DIR = includes

#	SRC
SRC_NAME =	push_swap.c \
			array_management.c \
			parser.c \
			solver_small.c \
			solver.c

OBJ_NAME = $(SRC_NAME:.c=.o)

#	FILES
SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

#	LIBFT
FT = ./libft/
FT_LIB = $(addprefix $(FT),libft.a)
FT_INC	= -I ./libft
FT_LNK	= -L ./libft -l ft

#	FLAGS
CC = gcc $(CFLAGS)
CFLAGS = -Wall -Wextra -Werror

all: $(FT_LIB) $(NAME)

$(FT_LIB):
	@echo "$(BLUE)[>]		creating $@ ...$(NOC)"
	@make --no-print-directory -C $(FT)
	@echo "$(BLUE)[>]		$@ created.$(NOC)"

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) -c $< -o $@
	@echo "$(GREEN)[>]		$@ created.$(NOC)"

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(FT_LIB) -o $@
	@echo "$(GREEN)[>]		$@ created.$(NOC)"

clean:
	@rm -rf $(OBJ_PATH)
	@echo "$(GREEN)[>]		.o files deleted.$(NOC)"
	@make --no-print-directory -C $(FT) clean

fclean: clean
	@rm $(NAME)
	@echo "$(GREEN)[>]		$(NAME) deleted.$(NOC)"
	@make --no-print-directory -C $(FT) ffclean

re: fclean all