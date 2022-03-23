/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 21:13:31 by jbrown            #+#    #+#             */
/*   Updated: 2022/03/16 21:13:33 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_nums_else(t_list *stack, int one, int three)
{
	if (one > three)
		rev_rotate(stack);
	else
	{
		swap(stack);
		rotate(stack);
	}
}

void	three_nums(t_list *a)
{
	int	one;
	int	two;
	int	three;

	one = ft_atoi(a->next->content);
	two = ft_atoi(a->next->next->content);
	three = ft_atoi(a->next->next->next->content);
	if (one > two)
	{
		if (two > three)
		{
			swap(a);
			rev_rotate(a);
		}
		else if (one > three)
			rotate(a);
		else
			swap(a);
	}
	else if (two > three)
		three_nums_else(a, one, three);
}

void	small_sort(t_list *a, t_list *b, t_list *group)
{
	int		i;
	int		size;
	char	*current;

	size = ft_lstsize(a);
	i = size - 4;
	while (i > 0)
	{
		current = find_range(a, group, i);
		smart_rotate(a, ft_atoi(current));
		push(a, b);
		i--;
	}
	three_nums(a);
	sort_group(a, b);
	rotate_check(a);
}
