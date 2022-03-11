#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	if (ac == 1)
		return (1);
	a = ft_lstnew("a");
	lst_init(a, ac, av);
	b = ft_lstnew("b");
	print_stacks(&a->next, &b->next);
	five_nums(a, b);
/*	swap(a);
	print_stacks(&a->next, &b->next);
	push(a, b);
	print_stacks(&a->next, &b->next);
	rotate(a);
	print_stacks(&a->next, &b->next);
	rev_rotate(a);
	print_stacks(&a->next, &b->next);
	push(a, b);
	print_stacks(&a->next, &b->next);
	rotate_both(a->next, b->next);
	print_stacks(&a->next, &b->next);
	rev_rotate_both(a->next, b->next);
	print_stacks(&a->next, &b->next);*/
	return (0);
}