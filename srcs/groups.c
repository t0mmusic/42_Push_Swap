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

/*	Calculates the number of groups the numbers will be broken into based on
	the size of the stack. Should scale with larger stacks.	*/

int	group_size(t_list *stack)
{
	int	total;

	total = ft_lstsize(stack);
	if (total < 4)
		return (total);
	if (total < 50)
		return (total);
	return (total / 4);
}

/*	Finds the smallest number not already sorted. Group size will get
	smaller each time until every value in the group range has been
	sent from a to b. NOT CURRENTLY IN USE, REPLACED BY FIND_PUSH	*/

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
	int	*send;
	int	size;

	size = groupsize;
	while (groupsize && !rotate_order(a))
	{
		send = find_group(a, min, groupsize);
		smart_rotate(a, send);
		swap_check(a, send);
		if (!rotate_order(a))
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
