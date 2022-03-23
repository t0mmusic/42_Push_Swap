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
	in a stack. */

/*	Returns the value of a number within a specified range. This
	is used to find values that will be pushed into stack b from
	stack a. */

char	*find_range(t_list *a, t_list *group, int groupsize)
{
	char	*current;
	t_list	*head;
	t_list	*tmp;
	int		i;

	head = group;
	current = find_min(a);
	tmp = ft_lstnew("temporary");
	while (group->next)
	{
		group = group->next;
		if (ft_atoi(current) == ft_atoi(group->content))
		{
			group = head;
			current = find_next(a, current);
		}
	}
	i = 1;
	while (i <= groupsize)
	{
		ft_lstadd_back(&tmp, ft_lstnew(current));
		current = find_next(a, current);
		i++;
	}
	current = closest_to_edge(a, tmp);
	//free tmp;
	return (current);
}

/*	Finds and returns the largest number in a stack. */

char	*find_max(t_list *stack)
{
	char	*max;

	stack = stack->next;
	max = stack->content;
	while (stack->next)
	{
		if (ft_atoi(stack->next->content) > ft_atoi(max))
			max = stack->next->content;
		stack = stack->next;
	}
	return (max);
}

/*	Finds and returns the smallest number in a stack. */

char	*find_min(t_list *stack)
{
	char	*min;

	stack = stack->next;
	min = stack->content;
	while (stack->next)
	{
		if (ft_atoi(stack->next->content) < ft_atoi(min))
			min = stack->next->content;
		stack = stack->next;
	}
	return (min);
}

/*	Finds next number in stack, in ascending order of size. */

char	*find_next(t_list *stack, char *current)
{
	char	*next;
	t_list	*head;

	head = stack;
	next = find_max(stack);
	while (stack->next)
	{
		if (ft_atoi(next) > ft_atoi(stack->next->content) \
			&& ft_atoi(current) < ft_atoi(stack->next->content))
			next = stack->next->content;
		stack = stack->next;
	}
	if (ft_atoi(current) > ft_atoi(next))
	{
		return (find_min(head));
	}
	return (next);
}

/*	Finds previous number in stack, in descending order of size. */

char	*find_previous(t_list *stack, char *current)
{
	char	*previous;

	previous = find_min(stack);
	while (stack->next)
	{
		if (ft_atoi(previous) < ft_atoi(stack->next->content) \
			&& ft_atoi(current) > ft_atoi(stack->next->content))
			previous = stack->next->content;
		stack = stack->next;
	}
	return (previous);
}
