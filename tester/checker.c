#include "push_swap.h"
#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

/*	Compares the current line to the possible commands that
	push_swap can use. It will then apply that command to stacks
	a and b. */

void	movement_check(char *str, t_list *a, t_list *b)
{
	if (!strcmp(str, "sa\n"))
		swap(a);
	if (!strcmp(str, "ra\n"))
		rotate(a);
	if (!strcmp(str, "rb\n"))
		rotate(b);
	if (!strcmp(str, "pa\n"))
		push(b, a);
	if (!strcmp(str, "pb\n"))
		push(a, b);
	if (!strcmp(str, "rra\n"))
		rev_rotate(a);
	if (!strcmp(str, "rrb\n"))
		rev_rotate(b);
}

/*	Using get next line, this function reads from the standard
	output all of the commands used to sort the stacks. It then
	applies those commands to the same stacks, checking to see
	if the numbers have been sorted correctly. */

int	main(int ac, char **av)
{
	char	*str;
	t_list *a;
	t_list *b;

	a = ft_lstnew("a");
	b = ft_lstnew("b");
	lst_init(a, ac, av);
	str = get_next_line(0);
	while (str)
	{
		movement_check(str, a, b);
		str = get_next_line(0);
	}
	ft_printf("result:\n");
	print_stacks(&a->next, &b->next);
	if (rotate_check(a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (0);
}