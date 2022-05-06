/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <jbrown@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:10:35 by jbrown            #+#    #+#             */
/*   Updated: 2022/05/05 13:28:51 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	For smaller stacks, this function is used to optimise the algorithim. It
	will reduce the stack down until there are only 3 numbers left, then swap
	and/or rotate them into the correct position before returning the other
	numbers to the stack.	*/

void	small_sort(t_list *a, t_list *b, int size)
{
	int	*large;
	int	*current;

	large = find_previous(a, find_max(a));
	large = find_previous(a, large);
	while (size > 4)
	{
		current = a->next->content;
		if (*current < *large)
		{
			push(a, b, 1);
			size--;
		}
		else
			rotate(a, 1);
	}
	if (!rotate_order(a))
		swap(a, 1);
	rotate_order(a);
	while (b->next)
	{
		smart_rotate(b, find_max(b));
		push(b, a, 1);
	}
}
