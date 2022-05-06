/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <jbrown@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 21:12:21 by jbrown            #+#    #+#             */
/*   Updated: 2022/05/06 16:07:47 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	Rotates both stacks at once. It will not print the rotations indivually,
	instead printing "rr".	*/

void	rotate_both(t_list *a, t_list *b, int print)
{
	rotate(a, 0);
	rotate(b, 0);
	if (print)
		ft_printf("rr\n");
}

/*	Reverse rotates both stacks at once. It will not print the rotations
	indivually, instead printing "rrr".	*/

void	rev_rotate_both(t_list *a, t_list *b, int print)
{
	rev_rotate(a, 0);
	rev_rotate(b, 0);
	if (print)
		ft_printf("rrr\n");
}

/*	Will either rotate or reverse rotate both stacks depending on input
	function. Once either stack a has the next value up from the largest
	value in stack b at the top, or stack b has it's largest value at the
	top, it will check if the other condition is met. If it is not, it will
	rotate the other stack accordingly. It will then push everything from
	stack b to stack a in sorted order.	*/

void	twin_rotate(t_list *a, t_list *b, void (f)(t_list *, t_list *, int))
{
	while (b->next->content != find_max(b)
		&& find_last(a) != find_previous(a, find_max(b)))
	{
		f(a, b, 1);
	}
	if (find_last(a) != find_previous(a, find_max(b)))
	{
		smart_rotate(a, find_previous(a, find_max(b)));
		rotate(a, 1);
	}
	if (b->next->content != find_max(b))
	{
		smart_rotate(b, find_max(b));
	}
	return_stack(a, b);
}

/*	When numbers are being returned from group b to group a, this function
	will check to see if both stacks can be rotated in the same direction
	to get them to where they need to be. If they can, it will rotate both
	in the correct direction. If not, it will rotate them separately.	*/

void	double_rotate(t_list *a, t_list*b)
{
	int	*min_a;
	int	*min_b;

	min_a = find_min(a);
	min_b = find_min(b);
	if (*min_a > *min_b)
		return_stack(a, b);
	else if (shortest_rotate(a, find_previous(a, find_min(b))) > 0
		&& shortest_rotate(b, find_max(b)) > 0)
	{
		twin_rotate(a, b, rotate_both);
	}
	else if (!(shortest_rotate(a, find_previous(a, find_min(b))) < 0
			&& shortest_rotate(b, find_max(b)) < 0))
	{
		twin_rotate(a, b, rev_rotate_both);
	}
	else
	{
		smart_rotate(a, find_previous(a, find_min(b)));
		rotate(a, 1);
		smart_rotate(b, find_max(b));
		return_stack(a, b);
	}
}
