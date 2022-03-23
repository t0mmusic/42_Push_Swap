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
	The smaller the quantity of numbers in the stack, the fewer groups
	are needed to solve. */

int	group_split(t_list *stack)
{
	int	size_of_stack;
	int	size_of_group;
	int	no_of_groups;
	int	no_in_group;

	size_of_stack = ft_lstsize(stack);
	size_of_group = 11;
	no_of_groups = 2;
	while (size_of_stack > size_of_group)
	{
		size_of_group += 10;
		no_of_groups += 2;
	}
	no_in_group = size_of_group / no_of_groups;
	return (no_in_group);
}

/*	Assigns numbers in the stack into groups based on their size. It
	Then pushes them into stack 'b' before returning them to stack 'a'
	in the correct order. */

void	group_push(t_list *a, t_list *b, t_list *group, int groupsize)
{
	char	*current;
	int		current_size;

	current_size = groupsize;
	if (ft_lstsize(a) < ft_lstsize(group) + current_size)
		current_size = ft_lstsize(a) - ft_lstsize(group);
	while (current_size && a->next && !rotate_check(a))
	{
		current = find_range(a, group, current_size);
		smart_rotate(a, ft_atoi(current));
		push(a, b);
		//print_stacks(&a->next, &b->next);
		ft_lstadd_back(&group, ft_lstnew(current));
		current_size--;
	}
	if (a->next)
		smart_rotate(a, ft_atoi(find_next(a, find_max(b))));
	sort_group(a, b);
	if (ft_lstsize(a) != ft_lstsize(group) && !rotate_check(a))
		group_push(a, b, group, groupsize);
	rotate_check(a);
}

/*	Pushes everything from stack b into stack a, always
	pushing the largest number first. */

void	sort_group(t_list *a, t_list *b)
{
	if (b->next)
	{
		smart_rotate(b, ft_atoi(find_max(b)));
		push(b, a);
		//print_stacks(&a->next, &b->next);
		sort_group(a, b);
	}
}
