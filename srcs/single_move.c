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

/* modify all functions here to print result */

void	push(t_list *src, t_list *dst)
{
	t_list	*new;
	t_list	*back;
	char	*name;

	name = dst->content;
	back = ft_lstnew(src->next->content);
	ft_lstadd_front(&dst->next, back);
	new = src->next->next;
	free(src->next);
	src->next = NULL;
	ft_lstadd_back(&src, new);
	ft_printf("Execute p%s:\n", name);
	if (!ft_strncmp(name, "b", 1))
		print_stacks(&src->next, &dst->next);
	else
		print_stacks(&dst->next, &src->next);
}

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

/*	Moves content of list up one position 
	Modify these to change list pointers
	instead of content */

void	rotate(t_list *a)
{
	char	*t;
	char	*name;

	name = a->content;
	a = a->next;
	t = a->content;
	while (a->next)
	{
		a->content = a->next->content;
		a = a->next;
	}
	a->content = t;
	ft_printf("Excecute r%s:\n", name);
}

/* Moves content of list down one position */

void	rev_rotate(t_list *a)
{
	char	*t1;
	char	*t2;
	char	*name;
	t_list	*first;

	name = a->content;
	a = a->next;
	first = a;
	if (a->next)
	{
		t1 = a->next->content;
		a->next->content = a->content;
		a = a->next;
	}
	while (a->next)
	{
		t2 = a->next->content;
		a->next->content = t1;
		t1 = t2;
		a = a->next;
	}
	first->content = t1;
	ft_printf("Excecute rr%s:\n", name);
}
