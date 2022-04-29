NAME = push_swap
CC = gcc
CFLAGS = -Wall -Werror -Wextra -Iheaders

PRINTF = printf/libftprintf.a

RM = rm -f

SRCS = srcs/*.c

CHECKER = tester/checker.c

GET_NEXT_LINE = tester/get_next_line/get_next_line.c tester/get_next_line/get_next_line_utils.c

CLEAN_MESSAGE = echo "Removing Object Files"
FCLEAN_MESSAGE = echo "Removing Archive Files"
COMPILING_MESSAGE = echo "Compiling push_swap"
PRINTF_MESSAGE = echo "printf archive compiled"
COMPLETE_MESSAGE = echo "push_swap program compiled"

all: $(NAME)

$(NAME):
	@$(COMPILING_MESSAGE)
	@$(MAKE) bonus -C ./printf >/dev/null
	@$(PRINTF_MESSAGE)
	@$(CC) $(CFLAGS) $(SRCS) $(PRINTF) -o $(NAME)
	@$(COMPLETE_MESSAGE)


bonus: all
	@$(CC) $(CHECKER) $(GET_NEXT_LINE) printf/libftprintf.a -D BUFFER_SIZE=10 -Iheaders -o checker

clean:
	@$(MAKE) clean -C ./printf >/dev/null
	@$(MAKE) clean -C ./printf/libft >/dev/null
	@$(CLEAN_MESSAGE)

fclean: clean
	@$(MAKE) fclean -C ./printf >/dev/null
	@$(MAKE) fclean -C ./printf/libft >/dev/null
	@$(RM) $(NAME)
	@$(FCLEAN_MESSAGE)

re: fclean all

.PHONY: all clean fclean bonus re
