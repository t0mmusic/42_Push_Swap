/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 10:38:07 by jbrown            #+#    #+#             */
/*   Updated: 2022/03/11 10:38:10 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_list **a, t_list **b)
{
	t_list	*current_a;
	t_list	*current_b;

	current_a = *a;
	current_b = *b;
	while (current_a || current_b)
	{
		if (current_a)
		{
			ft_printf("%s ", current_a->content);
			current_a = current_a->next;
		}
		else
			ft_printf("  ");
		if (current_b)
		{
			ft_printf("%s", current_b->content);
			current_b = current_b->next;
		}
		ft_printf("\n");
	}
	ft_printf("_ _\na b\n");
	ft_printf("----------------------------\n");
}

void	lst_init(t_list *a, int ac, char **av)
{
	int		i;
	t_list	*first;
	t_list	*current;

	i = 1;
	first = ft_lstnew(av[i]);
	current = first;
	while (i < ac - 1)
	{
		if (av[i + 1] && ft_isdigit(av[i + 1][0]))//modify this to check for numbers and spaces
		{
			current = ft_lstnew(av[i + 1]);
			ft_lstadd_back(&first, current);
		}
		i++;
	}
	ft_lstadd_back(&a, first);
	//ft_printf("Init a and b:\n");
}
