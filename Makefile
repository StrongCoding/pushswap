NAME = push_swap

SRC := main.c \
		operation_utils.c \
		others.c \
		ft_atoi_special.c

OBJ := $(SRC:.c=.o)

CFIL := $(SRC:.c=)
CCFLAGS := -Wall -Wextra -Werror

.PHONY: all bonus clean fclean re

all:$(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./ft_printf
	 cc $(CCFLAGS) $(OBJ) ./ft_printf/libftprintf.a -o $(NAME)
$(OBJ):
	cc -c $(SRC) $(CCFLAGS)
clean:
	$(MAKE) clean -C ./ft_printf
	rm -f $(OBJ) $(BNS_OBJ)
fclean: clean
	$(MAKE) fclean -C ./ft_printf
	rm -f $(NAME) 
re: fclean all