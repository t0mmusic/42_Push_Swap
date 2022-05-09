/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wishful_thinking.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <jbrown@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 10:05:15 by jbrown            #+#    #+#             */
/*   Updated: 2022/05/09 10:10:02 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	These functions were made while I was figuring out how I wanted to do the
	project. The idea was that any time a number was found to be larger than
	the number after it, it would be pushed to stack b. Once all of the out of
	order numbers were removed, they would be placed back into stack a in the
	correct order. Unfortunately, this was not very efficient and ended up not
	being used in the final project.	*/

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
