/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <jbrown@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 12:10:07 by jbrown            #+#    #+#             */
/*   Updated: 2022/05/01 16:31:13 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	Finds and returns the largest number in a stack.	*/

int	*find_max(t_list *stack)
{
	int	*max;
	int	*current;

	stack = stack->next;
	max = stack->content;
	while (stack->next)
	{
		current = stack->next->content;
		if (*max < *current)
			max = current;
		stack = stack->next;
	}
	return (max);
}

/*	Finds and returns the smallest number in a stack.	*/

int	*find_min(t_list *stack)
{
	int	*min;
	int	*current;

	stack = stack->next;
	min = stack->content;
	while (stack->next)
	{
		current = stack->next->content;
		if (*min > *current)
			min = current;
		stack = stack->next;
	}
	return (min);
}

/*	Searches through a stack to find the next number up from
	the one entered and returns the pointer to that number.	*/

int	*find_next(t_list *stack, int *previous)
{
	int	*current;
	int	*max;

	max = find_max(stack);
	stack = stack->next;
	while (stack)
	{
		current = stack->content;
		if (*current <= *max && *current > *previous)
			max = current;
		stack = stack->next;
	}
	return (max);
}

/*	Rotates to an input value based on the number of possible
	rotations. If it will take fewer rotations than reverse
	rotations to reach the top of the stack, it will do that.	*/

void	smart_rotate(t_list *stack, int *match)
{
	if (shortest_rotate(stack, match) > 0)
	{
		while (stack->next && stack->next->content != match)
		{
			rotate(stack, 1);
		}
	}
	else
	{
		while (stack->next && stack->next->content != match)
		{
			rev_rotate(stack, 1);
		}
	}
}

/*	Returns the shortest number of moves it will take for an input
	value to reach the top of the stack. It will return a positive
	value for rotations and a negative for reverse rotations.	*/

int	shortest_rotate(t_list *stack, int *match)
{
	int		*num;
	int		size;
	int		count;

	size = ft_lstsize(stack);
	count = 1;
	num = stack->next->content;
	while (stack->next && *num != *match)
	{
		count++;
		stack = stack->next;
		num = stack->next->content;
	}
	if (count < (size / 2) + 1)
		return (count);
	return ((size - count) * -1);
}
