/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 21:11:41 by jbrown            #+#    #+#             */
/*   Updated: 2022/03/16 21:11:53 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list		*a;
	t_list		*b;
	t_list		*group;
	int			no_in_group;

	if (ac == 1)
	{
		ft_printf("Error\n");
		return (1);
	}
	//need error checker for non numerical characters
	a = ft_lstnew("a");
	lst_init(a, ac, av);
	b = ft_lstnew("b");
	group = ft_lstnew("group");
	//print_stacks(&a->next, &b->next);
	if (rotate_check(a))
	{
		return (0);
	}
	if (ft_lstsize(a) < 7)
	{
		small_sort(a, b, group);
		return (0);
	}
	no_in_group = group_split(a);
	group_push(a, b, group, no_in_group);
	//print_stacks(&a->next, &b->next);
	return (0);
}
