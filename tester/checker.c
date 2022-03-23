/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:37:16 by jbrown            #+#    #+#             */
/*   Updated: 2022/03/23 11:37:18 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

/*	Tests that list if in order. */

void	validity_check(t_list *stack)
{
	stack = stack->next;
	while (stack->next->next && ft_atoi(stack->next->content)
		< ft_atoi(stack->next->next->content))
	{
		stack = stack->next;
	}
	if (stack->next->next)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
}

/*	Compares the current line to the possible commands that
	push_swap can use. It will then apply that command to stacks
	a and b. */

void	movement_check(char *str, t_list *a, t_list *b)
{
	if (!ft_strcmp(str, "sa\n"))
		swap(a);
	if (!ft_strcmp(str, "ra\n"))
		rotate(a);
	if (!ft_strcmp(str, "rb\n"))
		rotate(b);
	if (!ft_strcmp(str, "pa\n"))
		push(b, a);
	if (!ft_strcmp(str, "pb\n"))
		push(a, b);
	if (!ft_strcmp(str, "rra\n"))
		rev_rotate(a);
	if (!ft_strcmp(str, "rrb\n"))
		rev_rotate(b);
}

/*	Using get next line, this function reads from the standard
	output all of the commands used to sort the stacks. It then
	applies those commands to the same stacks, checking to see
	if the numbers have been sorted correctly. */

int	main(int ac, char **av)
{
	char	*str;
	t_list	*a;
	t_list	*b;

	a = ft_lstnew("a");
	b = ft_lstnew("b");
	lst_init(a, ac, av);
	str = get_next_line(0);
	while (str)
	{
		movement_check(str, a, b);
		str = get_next_line(0);
	}
	print_stacks(&a->next, &b->next);
	validity_check(a);
	return (0);
}
