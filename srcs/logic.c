/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <jbrown@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 12:10:07 by jbrown            #+#    #+#             */
/*   Updated: 2022/04/29 16:28:50 by jbrown           ###   ########.fr       */
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

int	*find_next(t_list *stack, int *previous)
{
	int	*current;
	int	*max;

	max = find_max(stack);
	stack = stack->next;
	while (stack->next)
	{
		current = stack->content;
		if (*current < *max && *current > *previous)
			max = current;
		stack = stack->next;
	}
	return (max);
}

/*	Figures out whether the desired value will reach the top
	of the stack fastest if it is rotated or reverse rotated.	*/

void	smart_rotate(t_list *stack, int *match)
{
	int	*num;

	if (shortest_rotate(stack, match))
	{
		while (stack->next && stack->next->content != match)
		{
			num = stack->next->content;
			rotate(stack, 1);
			num = stack->next->content;
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

/*	Returns a 1 if a value is closer to the top of a stack
	and a zero if it is closer to the bottom.	*/

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
		return (1);
	return (0);
}
