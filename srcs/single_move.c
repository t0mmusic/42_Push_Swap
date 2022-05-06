/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <jbrown@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 10:38:35 by jbrown            #+#    #+#             */
/*   Updated: 2022/05/06 16:04:37 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	These are shared by both push_swap and the checker program. Because
	push_swap needs to print the operation and the checker doesn't,
	each function has a 'print' integer telling it whether or not it will
	print on this call.	*/

/*	Takes the first element from src stack and moves it to the top of dst stack.
	Everything in src moves up one element, everything in dst moves down one. */

void	push(t_list *src, t_list *dst, int print)
{
	t_list	*new;
	char	*name;

	if (!src->next)
		return ;
	name = dst->content;
	new = src->next;
	src->next = new->next;
	new->next = dst->next;
	dst->next = new;
	if (print)
		ft_printf("p%s\n", name);
}

/*	Swaps first element in stack with second element in stack. */

void	swap(t_list *stack, int print)
{
	char	*tmp;
	char	*name;

	if (!(stack->next && stack->next->next))
		return ;
	name = stack->content;
	stack = stack->next;
	tmp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = tmp;
	if (print)
		ft_printf("s%s\n", name);
}

/*	Takes first number in list and moves it to last */

void	rotate(t_list *stack, int print)
{
	t_list	*rot;
	char	*name;

	if (!(stack->next && stack->next->next))
		return ;
	name = stack->content;
	rot = stack->next;
	stack->next = stack->next->next;
	rot->next = NULL;
	ft_lstadd_back(&stack, rot);
	if (print)
		ft_printf("r%s\n", name);
}

/* Takes last number in list and moves it to first */

void	rev_rotate(t_list *stack, int print)
{
	char	*name;
	t_list	*head;
	t_list	*rot;

	if (!(stack->next && stack->next->next))
		return ;
	head = stack;
	name = stack->content;
	rot = ft_lstlast(stack);
	while (stack->next->next)
		stack = stack->next;
	stack->next = NULL;
	ft_lstadd_front(&head->next, rot);
	if (print)
		ft_printf("rr%s\n", name);
}
