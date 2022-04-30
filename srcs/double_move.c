/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <jbrown@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 21:12:21 by jbrown            #+#    #+#             */
/*   Updated: 2022/04/29 16:31:53 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	These call the rotate and reverse rotate functions for both stack without 
	printing the function calls. Instead they print that both stacks were
	rotated together.	*/

void	rotate_both(t_list *a, t_list *b, int print)
{
	rotate(a, 0);
	rotate(b, 0);
	if (print)
		ft_printf("rr\n");
}

void	rev_rotate_both(t_list *a, t_list *b, int print)
{
	rev_rotate(a, 0);
	rev_rotate(b, 0);
	if (print)
		ft_printf("rrr\n");
}

/*	uses the function input to rotate both stacks until one of them has
	reached the right configuration. If the other stack has not gotten
	to the place it shoul be, it will then rotate that stack on its own.	*/

void	twin_rotate(t_list *a, t_list *b, void (f)(t_list *, t_list *, int))
{
	while (b->next->content != find_max(b)
		&& a->next->content != find_next(a, find_max(b)))
	{
		f(a, b, 1);
	}
	if (a->next->content != find_next(a, find_max(b)))
	{
		smart_rotate(a, find_next(a, find_max(b)));
	}
	if (b->next->content != find_max(b))
		smart_rotate(b, find_max(b));
	push(b, a, 1);
	if (b->next)
		double_rotate(a, b);
}

/*	When numbers are being returned from group b to group a, this function
	will check to see if both stacks can be rotated in the same direction
	to get them to where they need to be. If they can, it will rotate both
	in the correct direction. If not, it will rotate them separately.	*/

void	double_rotate(t_list *a, t_list*b)
{
	if (shortest_rotate(a, find_next(a, find_max(b)))
		&& shortest_rotate(b, find_max(b)))
		twin_rotate(a, b, rotate_both);
	else if (!(shortest_rotate(a, find_next(a, find_max(b)))
			&& shortest_rotate(b, find_max(b))))
		twin_rotate(a, b, rev_rotate_both);
	else
	{
		smart_rotate(a, find_next(a, find_max(b)));
		smart_rotate(b, find_max(b));
	}
}
