NAME = push_swap.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra -Iheaders -I . -c

RM = rm -f

SRCS = srcs/*.c

OBJ_DEST = mv *.o srcs

CHECKER = tester/checker.c

GET_NEXT_LINE = tester/get_next_line/get_next_line.c tester/get_next_line/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	$(MAKE) bonus -C ./printf
	cp printf/libftprintf.a $(NAME)
	$(CC) $(CFLAGS) $(SRCS)
	$(OBJ_DEST)
	ar rcs $(NAME) $(OBJS)
	$(CC) main.c $(NAME) -Iheaders -o push_swap

bonus: all
	$(CC) $(CHECKER) $(GET_NEXT_LINE) $(NAME) -D BUFFER_SIZE=10 -Iheaders -o checker

clean:
	$(MAKE) clean -C ./printf
	$(MAKE) clean -C ./printf/libft
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./printf
	$(MAKE) clean -C ./printf/libft
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean bonus re
