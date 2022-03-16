/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 21:12:21 by jbrown            #+#    #+#             */
/*   Updated: 2022/03/16 21:12:23 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_list *a, t_list *b)
{
	char	*t;

	t = a->content;
	while (a->next)
	{
		a->content = a->next->content;
		a = a->next;
	}
	a->content = t;
	t = b->content;
	while (b->next)
	{
		b->content = b->next->content;
		b = b->next;
	}
	b->content = t;
	ft_printf("Excecute rr:\n");
}

void	rev_rotate_both_2(t_list *b)
{
	char	*t1;
	char	*t2;
	t_list	*first;

	first = b;
	t1 = b->next->content;
	b->next->content = b->content;
	b = b->next;
	while (b->next)
	{
		t2 = b->next->content;
		b->next->content = t1;
		t1 = t2;
		b = b->next;
	}
	first->content = t1;
}

void	rev_rotate_both(t_list *a, t_list *b)
{
	char	*t1;
	char	*t2;
	t_list	*first;

	first = a;
	t1 = a->next->content;
	a->next->content = a->content;
	a = a->next;
	while (a->next)
	{
		t2 = a->next->content;
		a->next->content = t1;
		t1 = t2;
		a = a->next;
	}
	first->content = t1;
	rev_rotate_both_2(b);
	ft_printf("Excecute rrr:\n");
}
