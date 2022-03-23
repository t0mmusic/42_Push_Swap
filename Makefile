NAME = push_swap
CC = gcc
CFLAGS = -Wall -Werror -Wextra -Iheaders

RM = rm -f

SRCS = srcs/*.c

CHECKER = tester/checker.c

GET_NEXT_LINE = tester/get_next_line/get_next_line.c tester/get_next_line/get_next_line_utils.c


all: $(NAME)

$(NAME):
	$(MAKE) bonus -C ./printf
	$(CC) $(CFLAGS) $(SRCS) printf/libftprintf.a -o $(NAME)


bonus: all
	$(CC) $(CHECKER) $(GET_NEXT_LINE) printf/libftprintf.a -D BUFFER_SIZE=10 -Iheaders -o checker

clean:
	$(MAKE) clean -C ./printf
	$(MAKE) clean -C ./printf/libft

fclean: clean
	$(MAKE) fclean -C ./printf
	$(MAKE) clean -C ./printf/libft
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean bonus re
