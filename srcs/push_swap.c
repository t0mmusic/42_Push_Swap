/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <jbrown@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 10:38:07 by jbrown            #+#    #+#             */
/*   Updated: 2022/05/06 13:54:37 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	Checks if numbers entered are larger than integer max or smaller than
	integer min.	*/

int	int_range(long int num)
{
	long int	min;
	long int	max;

	max = 2147483647;
	min = max * -1 - 1;
	if (num > max || num < min)
		return (0);
	return (1);
}

/*	Checks if there are any duplicates in the current list.	*/

int	duplicate_check(t_list *stack)
{
	int		*current;
	int		*next;
	t_list	*top;

	stack = stack->next;
	top = stack;
	while (stack)
	{
		current = stack->content;
		while (stack->next)
		{
			next = stack->next->content;
			if (*next == *current)
			{
				ft_printf("Error\n");
				return (1);
			}
			stack = stack->next;
		}
		top = top->next;
		stack = top;
	}
	return (0);
}

/*	Checks to see if the arguments added from command line are valid for 
	sorting. The only valid characters are numbers, spaces, and minus signs. */

int	error_check(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (!(ft_isdigit(av[i][j]) || ft_isspace(av[i][j]))
				&& av[i][j] != '-')
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

void	print_stacks(t_list *a, t_list *b)
{
	int	*current_a;
	int	*current_b;

	a = a->next;
	b = b->next;
	while (a || b)
	{
		if (a)
		{
			current_a = a->content;
			ft_printf("%-10i|", *current_a);
			a = a->next;
		}
		else
			ft_printf("          |");
		if (b)
		{
			current_b = b->content;
			ft_printf("%i", *current_b);
			b = b->next;
		}
		ft_printf("\n");
	}
	ft_printf("_          _\na          b\n");
	ft_printf("----------------------------\n");
}

/*	Checks if the current character is a number or a '-'.	*/

int	is_valid(char c)
{
	if (ft_isdigit(c) || c == '-')
		return (1);
	return (0);
}
