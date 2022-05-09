/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <jbrown@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 16:23:58 by jbrown            #+#    #+#             */
/*   Updated: 2022/05/09 12:26:14 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	Creates a stack with the index values of stack a rather than the actual
	value. For instance, if the third number in stack a is 127, it will have
	an index of 3. This will sort in a much smaller number of moves using
	radix sort than an unindexed stack.	*/

t_list	*index_list(t_list *stack)
{
	t_list	*index;
	t_list	*head;
	int		*current;
	int		*number;
	int		count;

	index = ft_lstnew(ft_strdup("c"));
	head = stack;
	while (stack->next)
	{
		count = 0;
		current = find_min(head);
		number = stack->next->content;
		while (*number != *current)
		{
			current = find_next(head, current);
			count++;
		}
		ft_lstadd_back(&index, list_add_int(count));
		stack = stack->next;
	}
	return (index);
}

/*	These two functions are just used to make radix_loop less than 25
	lines. They will print when stacks a and b have an operation, but
	not when c or d do.	*/

void	rotate_two(t_list *a, t_list *c)
{
	rotate(a, 1);
	rotate(c, 0);
}

void	push_two(t_list *s1, t_list *d1, t_list *s2, t_list *d2)
{
	push(s1, d1, 1);
	push(s2, d2, 0);
}

/*	Checks the binary value of the current number against a bitshifted 1. If it
	returns 1, it will move to the next, othewise it will push that number into
	stack b. It checks each binary radix starting with the least significant. */

void	radix_loop(t_list *a, t_list *b, t_list *c, t_list *d)
{
	int		bit;
	int		count;
	int		*current;

	bit = 1;
	while (final_order(a, b))
	{
		count = ft_lstsize(a) - 1;
		while (count)
		{
			current = c->next->content;
			if (bit & *current)
				rotate_two(a, c);
			else
				push_two(a, b, c, d);
			count--;
		}
		while (b->next)
			push_two(b, a, d, c);
		bit = bit << 1;
	}
}

/*	Sets up lists c and d for the radix sort, which will work with index numbers
	rather than actual values. Once the list is sorted, it frees these stacks.*/

void	radix_sort(t_list *a, t_list *b)
{
	t_list	*c;
	t_list	*d;

	c = index_list(a);
	d = ft_lstnew(ft_strdup("c"));
	radix_loop(a, b, c, d);
	free_list(c);
	free_list(d);
}
