CC = cc

CFLAGS = -Wall -Wextra -Werror

FT_PRINTF_DIR = ft_printf

SRC = ./assign_all.c ./calc2.c ./calc_atob.c ./calc_btoa.c ./calc.c ./clear.c ./ft_split.c ./linked_lists.c ./operations2.c ./operations_b.c ./operations.c ./parsing2.c ./parsing.c ./push_swap.c ./sorting.c

OBJ = $(SRC:.c=.o)

FT_PRINTF_OBJ = $(FT_PRINTF_DIR)/libftprintf.a

NAME = push_swap

$(NAME): $(OBJ) $(FT_PRINTF_OBJ)
	${CC} ${CFLAGS} $(OBJ) $(FT_PRINTF_OBJ) -o $(NAME)

ft_printf/libftprintf.a:
	$(MAKE) -C $(FT_PRINTF_DIR)

all: $(NAME)

.c.o:
	${CC} ${CFLAGS} -c  $< -o ${<:.c=.o}

clean: 
	rm -rf $(OBJ) 
	$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all