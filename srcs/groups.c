/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   groups.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <jbrown@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 11:59:13 by jbrown            #+#    #+#             */
/*   Updated: 2022/04/30 11:59:13 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	These functions are used to break all of the numbers in the initial stack
	into groups. The groups will contain sequential numbers based on size,
	starting with the minimum. Once the entire group has been moved to be, it
	can be put back into a in the correct order. Repeat until all of the groups
	have been sorted.	*/

/*	Calculates the number of groups the numbers will be broken into based on
	the size of the stack. Should scale with larger stacks.	2 groups for less 
	than 100 numbers, 8 for more.	*/

int	group_size(t_list *stack)
{
	int	total;

	total = ft_lstsize(stack);
	if (total < 52)
		return (total / 2);
	if (total < 102)
		return (total / 4);
	return (total / 8);
}

/*	Pushes the largest value from b to the top of a until b is empty.	*/

void	return_stack(t_list *a, t_list *b)
{
	int	count;

	count = 0;
	while (b->next)
	{
		smart_rotate(b, find_max(b));
		push(b, a, 1);
		count++;
	}
}

/*	Finds the smallest number not already sorted. Group size will get
	smaller each time until every value in the group range has been
	sent from a to b.	*/

int	*find_group(t_list *a, int *last_sorted, int groupsize)
{
	int	count;
	int	least;
	int	*send;
	int	*compare;

	count = 1;
	if (last_sorted == find_min(a))
		send = last_sorted;
	else
		send = find_next(a, last_sorted);
	compare = find_next(a, send);
	least = shortest_rotate(a, send);
	while (count < groupsize)
	{
		if (ft_abs(shortest_rotate(a, compare))
			< ft_abs(least))
		{
			least = shortest_rotate(a, compare);
			send = compare;
		}
		compare = find_next(a, compare);
		count++;
	}
	return (send);
}

/*	This function is the loop that runs the whole program. It pushes
	everything from a to b and back again. Once it has completed, the
	program will terminate.	*/

void	push_group(t_list *a, t_list *b, int *min, int groupsize)
{
	int			*send;
	int			size;

	size = groupsize;
	while (groupsize)
	{
		send = find_group(a, min, groupsize);
		smart_rotate(a, send);
		swap_check(a, send);
		push (a, b, 1);
		groupsize--;
	}
	min = find_max(b);
	if (final_order(a, b))
	{
		double_rotate(a, b);
	}
	if (!rotate_order(a))
	{
		push_group(a, b, min, size);
	}
}
