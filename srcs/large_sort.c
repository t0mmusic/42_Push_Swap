/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 21:12:44 by jbrown            #+#    #+#             */
/*   Updated: 2022/03/16 21:12:56 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	This function dynamically assigns groups based on quantity of stack 
	Consider also using average to determine min and max. It also need to make
	sure that there are going to be numbers in that range. */

int	group_split(t_list *stack)
{
	int	size_of_stack;
	int	size_of_group;
	int	no_of_groups;
	int	no_in_group;

	size_of_stack = ft_lstsize(stack);
	size_of_group = 10;
	no_of_groups = 2;
	while (size_of_stack > size_of_group)
	{
		size_of_group *= 5;
		no_of_groups *= 2;
	}
	no_in_group = size_of_stack / no_of_groups;
	return (no_in_group);
}

void	group_push(t_list *a, t_list *b, t_list *group, int groupsize)
{
	int		i;
	char	*current;

	i = 1;
	while (i < groupsize)
	{
		current = find_range(a, group);
		smart_rotate(a, ft_atoi(current));
		push(a, b);
		ft_lstadd_back(&group, ft_lstnew(current));
		i++;
	}
	smart_rotate(a, ft_atoi(find_next(a, find_max(b))));
	sort_group(a, b);
	if (ft_atoi(find_min(a)) != ft_atoi(find_min(group)))
		group_push(a, b, group, groupsize);
}

/*	Pushes everything from stack b into stack a, always
	pushing the largest number first. */

void	sort_group(t_list *a, t_list *b)
{

	if (b->next)
	{
		smart_rotate(b, ft_atoi(find_max(b)));
		push(b, a);
		sort_group(a, b);
	}
}
