/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <jbrown@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 12:10:07 by jbrown            #+#    #+#             */
/*   Updated: 2022/05/05 15:59:46 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	return (((size - count) * -1) + 1);
}
