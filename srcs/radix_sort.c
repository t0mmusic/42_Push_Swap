/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <jbrown@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 16:23:58 by jbrown            #+#    #+#             */
/*   Updated: 2022/05/06 17:33:41 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	WIP. Something weird is going on where it skips the value of the number I'm
	looking for??? Figure out later.	*/

t_list	*index_list(t_list *stack)
{
	t_list	*index;
	int		*current;
	int		*number;
	int		count;

	index = ft_lstnew("c");
	stack = stack->next;
	while (stack)
	{
		count = 0;
		current = find_min(stack);
		number = stack->content;
		while (*number != *current)
		{
			ft_printf("Current: %i\nNumber %i\n", *current, *number);
			current = find_next(stack, current);
			count++;
			if (count > 500)
				exit (1);
		}
		ft_lstadd_back(&index, ft_lstnew(&count));
		stack = stack->next;
	}
	return (index);
}

/*	Checks the binary value of the current number against a bitshifted 1. If it
	returns 1, it will move to the next, othewise it will push that number into
	stack b. It checks each binary radix starting with the least significant. */

void	radix_sort(t_list *a, t_list *b)
{
	int		bit;
	int		count;
	int		*current;
	t_list	*c;
	t_list	*d;

	c = index_list(a);
	d = ft_lstnew("c");
	print_stacks(c, d);
	exit (1);
	bit = 1;
	while (final_order(a, b))
	{
		count = ft_lstsize(a) - 1;
		while (count)
		{
			current = c->next->content;
			if (bit & *current)
			{
				rotate(a, 1);
				rotate(c, 0);
			}
			else
			{
				push(a, b, 1);
				push(c, d, 0);
			}
			count--;
		}
		while (b->next)
		{
			push(b, a, 1);
			push(d, c, 0);
		}
		bit = bit << 1;
	}
}
