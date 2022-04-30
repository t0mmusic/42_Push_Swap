/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <jbrown@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 21:11:41 by jbrown            #+#    #+#             */
/*   Updated: 2022/04/29 16:38:15 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_all(t_list *a, t_list *b)
{
	while (ascending_order(a))
	{
		push(a, b, 1);
	}
	double_rotate(a, b);
}

void	go_time(t_list *a, t_list *b)
{
	while (final_order(a, b))
	{
		push_all(a, b);
		if (!b->next)
			rotate_order(a);
		else
		{
			double_rotate(a, b);
		}
	}
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
