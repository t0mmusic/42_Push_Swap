/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <jbrown@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 09:20:56 by jbrown            #+#    #+#             */
/*   Updated: 2022/05/06 15:54:16 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	Returns the value of the number at the bottom of the stack.	*/

int	*find_last(t_list *stack)
{
	while (stack->next)
	{
		stack = stack->next;
	}
	return (stack->content);
}

/*	Finds and returns the largest number in a stack.	*/

int	*find_max(t_list *stack)
{
	int	*max;
	int	*current;

	stack = stack->next;
	if (!stack)
		return (NULL);
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
	if (!stack)
		return (NULL);
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
	the one entered and returns the pointer to that number.	
	If the value of previous is larger than anything else in
	the stack it is searching, it will return the minimum value
	instead.	*/

int	*find_next(t_list *stack, int *previous)
{
	int	*current;
	int	*max;

	max = find_max(stack);
	if (*max < *previous)
		return (find_max(stack));
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

/*	Searches stack for value immediately preceeding 'next' and
	returns it.	*/

int	*find_previous(t_list *stack, int *next)
{
	int	*min;
	int	*current;

	min = find_min(stack);
	stack = stack->next;
	while (stack)
	{
		current = stack->content;
		if (*current >= *min && *current < *next)
			min = current;
		stack = stack->next;
	}
	return (min);
}
