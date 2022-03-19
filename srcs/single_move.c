/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 10:38:35 by jbrown            #+#    #+#             */
/*   Updated: 2022/03/11 10:39:09 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	Takes the first element from src stack and
	moves it to the top of dst stack. Everything
	in src moves up one element, everything in dst
	moves down one. */

void	push(t_list *src, t_list *dst)
{
	t_list	*new;
	t_list	*back;
	char	*name;

	name = dst->content;
	back = ft_lstnew(src->next->content);
	ft_lstadd_front(&dst->next, back);
	new = src->next->next;
	src->next = NULL;
	ft_lstadd_back(&src, new);
	ft_printf("Execute p%s:\n", name);
	/*if (!ft_strncmp(name, "b", 1))
		print_stacks(&src->next, &dst->next);
	else
		print_stacks(&dst->next, &src->next);*/
}

/*	Swaps first element in stack with second
	Element in stack. */

void	swap(t_list *stack)
{
	char	*tmp;
	char	*name;

	name = stack->content;
	stack = stack->next;
	tmp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = tmp;
	ft_printf("Execute s%s:\n", name);
}

/*	Takes first number in list and moves it to last */

void	rotate(t_list *stack)
{
	t_list	*rot;
	char	*name;

	name = stack->content;
	rot = stack->next;
	stack->next = stack->next->next;
	rot->next = NULL;
	ft_lstadd_back(&stack, rot);
	ft_printf("Excecute r%s:\n", name);
}

/* Takes last number in list and moves it to first */

void	rev_rotate(t_list *stack)
{
	char	*name;
	t_list	*head;
	t_list	*rot1;
	t_list	*rot2;

	name = stack->content;
	head = stack;
	rot1 = stack->next;
	rot2 = ft_lstlast(stack);
	while(stack->next->next)
		stack = stack->next;
	stack->next = NULL;
	head->next = rot2;
	rot2->next = rot1;
	ft_printf("Excecute rr%s:\n", name);
}
