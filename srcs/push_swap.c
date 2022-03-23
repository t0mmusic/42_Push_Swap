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

/*	Checks to see if the arguments added from command line are valid for 
	sorting. */

int	error_check(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < ac - 1)
	{
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]) || ft_isspace(av[i][j]))
			{
				ft_printf("Error\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

/*	Used to print the content of both stacks. Currently only for testing
	but I may add it as a feature with a Makefile rule. */

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

void	split_list(t_list *stack, char *str)
{
	int		i;
	char	*current;

	i = 0;
	while (str[i])
	{
		while (ft_isspace(str[i]))
		{
			str[i] = 0;
			i++;
		}
		if (ft_isdigit(str[i]))
		{
			current = &str[i];
			while (ft_isdigit(str[i]))
				i++;
			if (str[i])
			{
				str[i] = 0;
				ft_lstadd_back(&stack, ft_lstnew(current));
			}
			else
			{
				ft_lstadd_back(&stack, ft_lstnew(current));
				return ;
			}
		}
		i++;
	}
}

/*	Fills the first stack with all the numbers passes as arguments from
	the command line. Should work if first agument is a string containing 
	the numbers, or if the numbers are seperate arguments. */

void	lst_init(t_list *a, int ac, char **av)
{
	int		i;
	t_list	*first;
	t_list	*current;

	i = 0;
	while (av[1][i])
	{
		if (ft_isspace(av[1][i]))
		{
			split_list(a, av[1]);
			return ;
		}
		i++;
	}
	i = 1;
	first = ft_lstnew(av[i]);
	current = first;
	while (i < ac - 1)
	{
		if (av[i + 1])
		{
			current = ft_lstnew(av[i + 1]);
			ft_lstadd_back(&first, current);
		}
		i++;
	}
	ft_lstadd_back(&a, first);
}
