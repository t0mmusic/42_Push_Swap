/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <jbrown@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 21:11:41 by jbrown            #+#    #+#             */
/*   Updated: 2022/05/02 15:45:31 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	Checks if an out of order number at the top of the stack is the next value
	up from the one below it. If it is, it will swap them.	*/

int	swap_check(t_list *stack, int *check)
{
	int	*next;

	if (!stack->next->next)
		return (0);
	next = stack->next->next->content;
	if (check == find_next(stack, next))
	{
		swap(stack, 1);
		return (1);
	}
	return (0);
}

void	go_time(t_list *a, t_list *b)
{
	int	*min;

	min = find_min(a);
	if (min)
		push_group(a, b, min, group_size(a));
}

int	main(int ac, char **av)
{
	t_list		*a;
	t_list		*b;

	if (ac == 1)
	{
		ft_printf("Error\n");
		return (1);
	}
	if (error_check(ac, av))
		return (1);
	a = ft_lstnew(ft_strdup("a"));
	list_type(a, ac, av);
	b = ft_lstnew(ft_strdup("b"));
	go_time(a, b);
	print_stacks(a, b);
	free_list(a);
	free_list(b);
	return (0);
}
