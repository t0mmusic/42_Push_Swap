NAME = push_swap.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra -Iheaders -I . -c

RM = rm -f

SRCS = srcs/*.c

OBJ_DEST = mv *.o srcs

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	$(MAKE) bonus -C ./printf
	cp printf/libftprintf.a $(NAME)
	$(CC) $(CFLAGS) $(SRCS)
	$(OBJ_DEST)
	ar rcs $(NAME) $(OBJS)

bonus: $(NAME)

clean:
	$(MAKE) clean -C ./printf
	$(MAKE) clean -C ./printf/libft
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./printf
	$(MAKE) clean -C ./printf/libft
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
