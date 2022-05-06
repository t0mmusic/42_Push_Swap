/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <jbrown@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 21:11:41 by jbrown            #+#    #+#             */
/*   Updated: 2022/05/06 16:48:18 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	Checks the size of the stack. If it has less than 20 numbers, we will use
	small sort. Otherwise, the stack is broken into smaller groups based on the
	size of the numbers.	*/

void	go_time(t_list *a, t_list *b)
{
	int	*min;
	int	size;

	min = find_min(a);
	size = ft_lstsize(a);
	if (size < 22)
		small_sort(a, b, ft_lstsize(a));
	else if (size < 202)
	{
		push_group(a, b, min, group_size(a));
	}
	else
	{
		radix_sort(a, b);
	}
}

/*	Imports the arguments from command line and runs a few error checks. Once
	the stack has been sorted, it frees the memory and exits the program.	*/

int	main(int ac, char **av)
{
	t_list		*a;
	t_list		*b;

	if (ac == 1)
		return (0);
	if (error_check(ac, av))
		return (1);
	a = ft_lstnew(ft_strdup("a"));
	b = ft_lstnew(ft_strdup("b"));
	if (list_type(a, ac, av))
	{
		ft_printf("Error\n");
		return (1);
	}
	else if (!duplicate_check(a))
	{
		go_time(a, b);
	}
	free_list(a);
	free_list(b);
	return (0);
}
