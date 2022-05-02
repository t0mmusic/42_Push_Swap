/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <jbrown@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 11:53:05 by jbrown            #+#    #+#             */
/*   Updated: 2022/05/02 09:08:35 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	Confirms that stack b is empty and stack a is in the correct order.	*/

int	final_order(t_list *a, t_list *b)
{
	if (b->next)
	{
		return (1);
	}
	if (!ascending_order(a))
		return (0);
	return (1);
}

/*	Iterates through a stack to see if all of the numbers are listed
	in ascending order. If they are, it will return NULL. If they are not,
	it will return a pointer to the location where the order is incorrect.	*/

t_list	*ascending_order(t_list *list)
{
	int	*num_one;
	int	*num_two;

	list = list->next;
	while (list->next)
	{
		num_one = list->content;
		num_two = list->next->content;
		if (*num_one > *num_two)
		{
			return (list);
		}
		list = list->next;
	}
	return (NULL);
}

/*	Checks if a stack can be rotated into the correct order. If it finds
	that the beginning of a stack is ordered correctly, it will check if
	the number it reached is the maximum and the next is the minimum. If
	they are, it will check that the remaining stack is in order and then
	rotate until the minimum is at the top.	Returns a 1 to confirm stack
	is sorted or a zero if it is not.	*/

int	rotate_order(t_list *list)
{
	t_list	*head;
	t_list	*pivot;
	int		*min;
	int		*max;

	head = list;
	list = ascending_order(list);
	if (!list)
		return (1);
	max = list->content;
	min = list->next->content;
	if (*min != *find_min(head) || *max != *find_max(head))
		return (0);
	pivot = list->next;
	list = ascending_order(list);
	if (!list)
	{
		smart_rotate(head, pivot->content);
		return (1);
	}
	return (0);
}
