/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 21:13:08 by jbrown            #+#    #+#             */
/*   Updated: 2022/03/16 21:13:10 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	Finds the centre of a stack and either rotates or 
	reverse rotates the stack to get desired number to
	the top. */

void	smart_rotate(t_list *stack, int match)
{
	t_list	*head;
	int		size;
	int		count;

	head = stack;
	size = ft_lstsize(stack);
	count = 1;
	while (stack->next && ft_atoi(stack->next->content) != match)
	{
		count++;
		stack = stack->next;
	}
	while (head->next && ft_atoi(head->next->content) != match)
	{
		if (count < (size / 2) + 1)
			rotate(head);
		else
			rev_rotate(head);
	}
}

/*	Returns list at point where it is out of order. */

t_list	*order_check(t_list *stack)
{
	int	current;
	int	next;

	if (stack->next->next)
		next = ft_atoi(stack->next->next->content);
	else
		return (stack);
	current = ft_atoi(stack->next->content);
	while (stack->next->next && current < next)
	{
		current = next;
		stack = stack->next;
		if (stack->next->next)
			next = ft_atoi(stack->next->next->content);
	}
	return (stack);
}

/*	Checks to see if the current stack can be put in the right order
	By rotating it. */

int	rotate_check(t_list *stack)
{
	t_list	*head;
	int		pivot;

	head = stack;
	stack = order_check(stack);
	if (!stack->next->next)
		return (1);
	stack = stack->next;
	pivot = ft_atoi(stack->next->content);
	stack = order_check(stack);
	if (!stack->next->next)
	{
		smart_rotate(head, pivot);
		return (1);
	}
	return (0);
}

/*	Figures out how close to the edge current number is
	and if it is closer than the previous closest. */

int	find_closest(int current, int check, int total)
{
	int	middle;
	int current_return;
	int	check_return;

	middle = total / 2 + 1;
	check_return = check;
	current_return = current;
	if (current > middle)
		current = total - current + 1;
	if (check > middle)
		check = total - check + 1;
	if (check < current)
		return (check_return);
	return (current_return);
}

/*	checks a stack against a reference list to see which number matched 
	will be able to be pushed with the fewest number of rotations. */

char	*closest_to_edge(t_list *stack, t_list *reference)
{
	int		size;
	int		closest;
	int		match;
	t_list	*head;

	head = stack;
	size = ft_lstsize(stack);
	closest = size / 2 + 1;
	while (reference->next)
	{
		match = 0;
		while (ft_atoi(stack->next->content) != ft_atoi(reference->next->content))
		{
			stack = stack->next;
			match++;
		}
		reference = reference->next;
		stack = head;
		closest = find_closest(closest, match, size);
	}
	match = 0;
	while (match < closest)
	{
		stack = stack->next;
		match++;
	}
	return (stack->next->content);
}

/*	Add function to see if stack can be put in order by swapping a small number of times. */
/*	Add function that checks both stacks to see if rotating both at once would be possible. */
