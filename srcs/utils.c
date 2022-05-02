/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <jbrown@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 09:28:56 by jbrown            #+#    #+#             */
/*   Updated: 2022/05/02 10:39:38 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	Finds and returns the smallest out of order value that is closest to the
	the edge (least number of rotations) to push from one stack to the other.
	This is set within a range of numbers determined by a groupsize, so even
	if a larger number is out of order and on top of the stack, it will not
	have priority over smaller numbers.	*/

int	*find_push(t_list *stack, int *min, int groupsize)
{
	int	*next;

	next = ooo_next(stack, min);
	while (groupsize && next)
	{
		if (ft_abs(shortest_rotate(stack, next))
			< ft_abs(shortest_rotate(stack, min)))
			min = next;
		next = ooo_next(stack, next);
		groupsize--;
	}
	return (min);
}

/*	Finds next out of order value in group.	*/

int	*ooo_next(t_list *stack, int *min)
{
	int	*current;
	int	size;

	current = find_next(stack, min);
	size = ft_lstsize(stack);
	while (size)
	{
		if (out_of_order(stack, current))
			return (current);
		current = find_next(stack, current);
		size--;
	}
	return (NULL);
}

/*	Finds the smallest value in the stack that is out of order.	*/

int	*ooo_smallest(t_list *stack)
{
	int	*min;

	min = find_min(stack);
	if (!out_of_order(stack, min))
		min = ooo_next(stack, min);
	return (min);
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

/*	Searches through a stack and returns the first number it finds that
	is out of order, meaning it is larger than the number it preceeds. 
	Returns NULL if stack is sorted.	*/

int	*out_of_order(t_list *stack, int *current)
{
	int	*next;

	while (stack->content != current)
		stack = stack->next;
	if (stack->next)
	{
		next = stack->next->content;
		if (*current > *next)
			return (current);
	}
	return (NULL);
}
