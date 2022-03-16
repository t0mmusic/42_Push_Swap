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

/*	Used to create new grouplist structures. Each group is contains
	a range of numbers, so a grouplist is used to determine the
	maximum and minimum limits of a group. */

t_grouplist	*new_grouplist(int min, int max)
{
	t_grouplist	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->min = min;
	new->max = max;
	new->next = NULL;
	return (new);
}
/*	This function should dynamically assign groups based on quantity of stack 
	Consider also using average to determine min and max */

t_grouplist	*group_divide(int min, int max)
{
	t_grouplist	*group;
	t_grouplist	*head;
	int			small;
	int			medium;
	int			large;

	small = max / 4;
	medium = max / 2;
	large = small + medium;
	group = new_grouplist(large - 1, max + 1);
	head = group;
	group->next = new_grouplist(medium - 1, large);
	group = group->next;
	group->next = new_grouplist(small - 1, medium);
	group = group->next;
	group->next = new_grouplist(min - 1, small);
	return (head);
}

/*	Initially used to find the maximum and minimum values
	input to the program, and then splits the numbers into
	4 groups. NOTE: This should be combined with group divide */

t_grouplist	*find_min_max(t_list *a)
{
	int			min;
	int			max;

	min = find_min(a);
	max = find_max(a);
	return (group_divide(min, max));
}

/*	Pushes everything from stack b into stack a, always
	pushing the largest number first. */

void	sort_group(t_list *a, t_list *b)
{
	int	max;

	if (b->next)
	{
		max = find_max(b);
		smart_rotate(b, max);
		push(b, a);
		sort_group(a, b);
	}
}

/*	Recursively moves groups from stack a to stack b, sorts them, 
	and then returns them to an appropriate position in stack a. */

void	push_group(t_list *a, t_list *b, t_grouplist *group)
{
	char	*num;

	while (find_range(a, group))
	{
		num = find_range(a, group);
		smart_rotate(a, ft_atoi(num));
		push(a, b);
	}
	smart_rotate(b, find_max(b)); //when find_max is modified to return string delete this
	smart_rotate(a, find_next(a, b->next->content)); //this should use find_max(b) as last paramater
	sort_group(a, b);
	group = group->next;
	if (group)
	{
		push_group(a, b, group);
	}
}
