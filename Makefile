NAME = push_swap
BONUS = checker
CC = gcc
CFLAGS = -Wall -Werror -Wextra -Iheaders

LEAKS = leaks.c

PRINTF = printf/libftprintf.a

RM = rm -f

SRCS = srcs/double_move.c srcs/find_number.c srcs/groups.c \
	srcs/list_initialise.c srcs/logic.c srcs/order.c \
	srcs/push_swap.c srcs/single_move.c srcs/small_sort.c \
	srcs/utils.c srcs/radix_sort.c

MAIN = srcs/main.c

CHECKER = tester/checker.c

GET_NEXT_LINE = tester/get_next_line.c

CLEAN_MESSAGE = echo "Removing Object Files"
FCLEAN_MESSAGE = echo "Removing Archive Files"
COMPILING_MESSAGE = echo "Compiling push_swap"
PRINTF_MESSAGE = echo "printf archive compiled"
COMPLETE_MESSAGE = echo "push_swap program compiled"

all: $(NAME) $(BONUS)

$(NAME):
	@$(COMPILING_MESSAGE)
	@$(MAKE) bonus -C ./printf >/dev/null
	@$(PRINTF_MESSAGE)
	@$(CC) $(CFLAGS) $(MAIN) $(SRCS) $(LEAKS) $(PRINTF) -o $(NAME)
	@$(COMPLETE_MESSAGE)


bonus: all $(BONUS)

$(BONUS):
	@$(CC) $(CFLAGS) $(CHECKER) $(GET_NEXT_LINE) $(LEAKS) $(SRCS) $(PRINTF) -D BUFFER_SIZE=10 -o $(BONUS)

clean:
	@$(MAKE) clean -C ./printf >/dev/null
	@$(MAKE) clean -C ./printf/libft >/dev/null
	@$(CLEAN_MESSAGE)

fclean: clean
	@$(MAKE) fclean -C ./printf >/dev/null
	@$(MAKE) fclean -C ./printf/libft >/dev/null
	@$(RM) $(NAME)
	@$(RM) $(BONUS)
	@$(FCLEAN_MESSAGE)

re: fclean all

.PHONY: all clean fclean bonus re
