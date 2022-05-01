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
	if (total < 11)
		return (total / 2);
	return (total / 4);
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

void	push_group(t_list *a, t_list *b, int *min)
{
	int	groupsize;
	int	*send;

	groupsize = group_size(a);
	while (groupsize && !rotate_order(a))
	{
		send = find_group(a, min, groupsize);
		smart_rotate(a, send);
		push (a, b, 1);
		groupsize--;
	}
	min = find_max(b);
	double_rotate(a, b);
	if (!rotate_order(a))
		push_group(a, b, min);
}

/*	Returns absolute value of a number. It actually doesn't though;
	this function is used to see how close a number is to the edge
	of the stack. Being at the top of the stack is better than
	being at the bottom, so the negative absolute gets an extra
	1 added.	*/

int	ft_abs(int nbr)
{
	if (nbr < 0)
		return ((nbr * -1) + 1);
	return (nbr);
}
