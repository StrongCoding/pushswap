NAME = push_swap
NAME_BNS = checker

SRC := main.c \
		operation_utils.c \
		sort_less.c \
		ft_sort_a_lot.c \
		operations_rotate.c \
		operations_rr.c \
		operations_ps.c \
		ft_sort_two.c \
		ft_sort_five_hundred.c \
		sort_a_lot_utils.c

OBJ := $(SRC:.c=.o)

BOTH_SRC := errors.c \
		others.c \
		ft_atoi_special.c

BOTH_OBJ := $(BOTH_SRC:.c=.o)

BNS_SRC := checker_bonus.c \
		execute_commands.c
OBJ := $(SRC:.c=.o)

BNS_OBJ := $(BNS_SRC:.c=.o)

CFIL := $(SRC:.c=)
CCFLAGS := -Wall -Wextra -Werror

.PHONY: all bonus clean fclean re

all:$(NAME)

$(NAME): $(OBJ) $(BOTH_OBJ)
	$(MAKE) -C ./ft_printf
	 cc $(CCFLAGS) $(OBJ) $(BOTH_OBJ) ./ft_printf/libftprintf.a -o $(NAME)
$(OBJ):
	cc -c $(SRC) $(CCFLAGS)

bonus:$(BNS_OBJ) $(BOTH_OBJ)
	$(MAKE) -C ./ft_printf
	cc $(CCFLAGS) $(BNS_OBJ) $(BOTH_OBJ) ./ft_printf/libftprintf.a -o $(NAME_BNS)

$(BOTH_OBJ):
	cc -c $(BOTH_SRC) $(CCFLAGS)

$(BNS_OBJ):
	cc -c $(BNS_SRC) $(CCFLAGS)
clean:
	$(MAKE) clean -C ./ft_printf
	rm -f $(OBJ) $(BNS_OBJ) $(BOTH_OBJ)
fclean: clean
	$(MAKE) fclean -C ./ft_printf
	rm -f $(NAME)
	rm -f $(NAME_BNS)
re: fclean all