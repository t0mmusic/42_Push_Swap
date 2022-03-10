#include "ft_printf.h"

void	print_stacks(t_list **a, t_list **b)
{
	t_list	*current_a;
	t_list	*current_b;

	current_a = *a;
	current_b = *b;
	while (current_a->next || current_b->next)
	{
		if (current_a)
		{
			ft_printf("%s ", current_a->content);
			if (current_a->next)
				current_a = current_a->next;
			else
				current_a->content = "";
		}
		else
			ft_printf("  ");
		if (current_b && current_b->content)
		{
			ft_printf("%s", current_b->content);
			if (current_b->next)
				current_b = current_b->next;
			else
				current_b->content = "";
		}
		ft_printf("\n");
		if (current_b->next)
			current_b = current_b->next;
	}
	ft_printf("%s\n", current_a->content);
	ft_printf("_ _\na b\n");
	ft_printf("----------------------------\n");
}

void	swap_a(t_list *stack)
{
	char	*tmp;

	tmp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = tmp;
	ft_printf("Execute sa:\n");
}

t_list	*push_b(t_list *a, t_list *b)
{
	t_list	*new;

	b->content = a->content;
	new = a->next;
	free(a);
	ft_printf("Execute pb:\n");
	return (new);
}
/*
void	rotate_b(int *b, int ac)
{
	int	i;
	int	t;

	t = b[0];
	i = 0;
	while (i < ac)
	{
		b[i] = b[i + 1];
		i++;
	}
	b[ac - 1] = t;
	ft_printf("Excecute rb:\n");
}
*/

t_list	*lst_init(t_list *a, int ac, char **av)
{
	int		i;
	t_list	*first;
	t_list	*current;

	i = 1;
	first = ft_lstnew(av[i]);
	current = first;
	while (i < ac - 1)
	{
		if (av[i + 1])
		{
			current = ft_lstnew(av[i + 1]);
			ft_lstadd_back(&first, current);
		}
		i++;
	}
	return (first);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	t_list	*current;

	if (ac == 1)
		return (1);
	a = lst_init(a, ac, av);
	b = ft_lstnew("");
	print_stacks(&a, &b);
	swap_a(a);
	print_stacks(&a, &b);
	a = push_b(a, b);
	print_stacks(&a, &b);
//	rotate_b(b, ac - 1);
//	print_stacks(a, b, ac - 1);
//	rotate_b(a, ac - 1);
//	print_stacks(a, b, ac - 1);
//	a[i] = 0;
	return (0);
}
