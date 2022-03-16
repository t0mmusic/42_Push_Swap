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
	while (ft_atoi(head->next->content) != match)
	{
		if (count < (size / 2) + 1)
			rotate(head);
		else
			rev_rotate(head);
	}
}

/*	Add function to see if stack can be put in order by rotating. */
/*	Add function to see if stack can be put in order by swapping a small number of times. */
/*	Add function that checks both stacks to see if rotating both at once would be possible. */