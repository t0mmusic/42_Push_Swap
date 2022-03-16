/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 21:12:31 by jbrown            #+#    #+#             */
/*   Updated: 2022/03/16 21:12:35 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	All of these functions are used to find specific numbers
	in a stack. Currently most return integers, but should
	be modified to return char pointers to account for zero. */

/*	Returns the value of a number within a specified range. This
	is used to find values that will be pushed into stack b from
	stack a. NOTE: This is not efficient as it always checks list
	from top to bottom. Should be modified to find closest value to
	edge of stack rather than first number it encounters. */

char	*find_range(t_list *a, t_grouplist *group)
{
	char	*num;

	a = a->next;
	while (a->next)
	{
		num = a->next->content;
		if (ft_atoi(num) > group->min && ft_atoi(num) < group->max)
			return (num);
		a = a->next;
	}
	return (NULL);
}

/* change to return char* to account for zero ??? */
/*	Finds and returns the largest number in a stack. */

int	find_max(t_list *stack)
{
	int	max;

	stack = stack->next;
	max = ft_atoi(stack->content);
	while (stack->next)
	{
		if (ft_atoi(stack->next->content) > max)
			max = ft_atoi(stack->next->content);
		stack = stack->next;
	}
	return (max);
}

/*	Finds and returns the smallest number in a stack. */

int	find_min(t_list *stack)
{
	int	min;

	stack = stack->next;
	min = ft_atoi(stack->content);
	while (stack->next)
	{
		if (ft_atoi(stack->next->content) < min)
			min = ft_atoi(stack->next->content);
		stack = stack->next;
	}
	return (min);
}

/*	Finds the number in stack a that is closest in size
	to the number in stack b while still being larger.
	This is used to push values from stack b into the 
	correct position in stack a. */

int	find_next(t_list *stack, char *current)
{
	int	next;

	next = find_max(stack);
	while (stack->next)
	{
		if (next > ft_atoi(stack->next->content) \
			&& ft_atoi(current) < ft_atoi(stack->next->content))
			next = ft_atoi(stack->next->content);
		stack = stack->next;
	}
	return (next);
}
