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
	t_grouplist	*group;

	if (ac == 1)
		return (1);
	a = ft_lstnew("a");
	lst_init(a, ac, av);
	b = ft_lstnew("b");
	print_stacks(&a->next, &b->next);
	group = find_min_max(a);
	push_group(a, b, group);
	return (0);
}
