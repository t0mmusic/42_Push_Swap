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
	//t_grouplist	*group;

	if (ac == 1)
		return (1);
	a = ft_lstnew("a");
	lst_init(a, ac, av);
	b = ft_lstnew("b");
	print_stacks(&a->next, &b->next);
	if (rotate_check(a))
		{
			print_stacks(&a->next, &b->next);
			return (0);
		}
	//group = find_min_max(a);
	no_in_group = group_split(a);
	group = ft_lstnew("group");
	group_push(a, b, group, no_in_group);
	//push_group(a, b, group);
	print_stacks(&a->next, &b->next);
	return (0);
}
