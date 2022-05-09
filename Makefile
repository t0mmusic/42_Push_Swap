# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbrown <jbrown@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/09 11:25:29 by jbrown            #+#    #+#              #
#    Updated: 2022/05/09 12:35:28 by jbrown           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker
VISUAL = visual_checker
CC = gcc
CFLAGS = -Wall -Werror -Wextra -Iheaders

PRINTF = printf/libftprintf.a

RM = rm -f

SRCS = srcs/double_move.c srcs/find_number.c srcs/groups.c \
	srcs/list_initialise.c srcs/logic.c srcs/order.c \
	srcs/push_swap.c srcs/single_move.c srcs/small_sort.c \
	srcs/utils.c srcs/radix_sort.c

MAIN = srcs/main.c

CHECKER = tester/checker.c
VISUAL_CHECKER = tester/visual_checker.c

GET_NEXT_LINE = tester/get_next_line.c

CLEAN_MESSAGE = echo "Removing Object Files"
FCLEAN_MESSAGE = echo "Removing Archive Files"
COMPILING_MESSAGE = echo "Compiling push_swap"
PRINTF_MESSAGE = echo "printf archive compiled"
COMPLETE_MESSAGE = echo "push_swap program compiled"
CHECKER_MESSAGE = echo "compiling checker"
VISUAL_MESSAGE = echo "compiling visual checker"
REMOVE_MESSAGE = echo "Removing Programs"

all: $(NAME)

$(NAME):
	@$(COMPILING_MESSAGE)
	@$(MAKE) bonus -C ./printf >/dev/null
	@$(PRINTF_MESSAGE)
	@$(CC) $(CFLAGS) $(MAIN) $(SRCS) $(PRINTF) -o $(NAME)
	@$(COMPLETE_MESSAGE)


bonus: all $(BONUS)

$(BONUS):
	@$(CHECKER_MESSAGE)
	@$(CC) $(CFLAGS) $(CHECKER) $(GET_NEXT_LINE) $(SRCS) $(PRINTF) -D BUFFER_SIZE=10 -o $(BONUS)

visual: $(VISUAL)

$(VISUAL):
	@$(VISUAL_MESSAGE)
	@$(CC) $(CFLAGS) $(VISUAL_CHECKER) $(GET_NEXT_LINE) $(SRCS) $(PRINTF) -D BUFFER_SIZE=10 -o $(VISUAL)

clean:
	@$(MAKE) clean -C ./printf >/dev/null
	@$(MAKE) clean -C ./printf/libft >/dev/null
	@$(CLEAN_MESSAGE)

fclean: clean
	@$(MAKE) fclean -C ./printf >/dev/null
	@$(MAKE) fclean -C ./printf/libft >/dev/null
	@$(RM) $(NAME)
	@$(RM) $(BONUS)
	@$(RM) $(VISUAL)
	@$(FCLEAN_MESSAGE)
	@$(REMOVE_MESSAGE)

re: fclean all

.PHONY: all clean fclean bonus visual re
