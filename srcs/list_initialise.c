/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_initialise.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <jbrown@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 10:51:05 by jbrown            #+#    #+#             */
/*   Updated: 2022/05/09 13:05:53 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	takes an integer and converts it into a pointer to add as a list element.
	the pointer is allocated in heap memory. */

t_list	*list_add_int(int num)
{
	long int	*num_pointer;
	t_list		*new;

	num_pointer = malloc(sizeof(*num_pointer));
	ft_memcpy(num_pointer, &num, sizeof(int));
	new = ft_lstnew(num_pointer);
	return (new);
}

/*	Checks if the command line arguments added are a single string containing
	all of the numbers or if the numbers are in indivual strings.	*/

int	list_type(t_list *a, int ac, char **av)
{
	int	i;

	i = 0;
	while (av[1][i])
	{
		if (ft_isspace(av[1][i]))
		{
			return (single_string(a, av[1]));
		}
		i++;
	}
	return (multiple_strings(a, ac, av));
}

/*	Breaks one string into individual values seperated by spaces. Each
	new value is added to the end of the list.	*/

int	single_string(t_list *a, char *str)
{
	int			i;
	long int	num;

	i = 0;
	while (str[i])
	{
		while (ft_isspace(str[i]))
		{
			i++;
		}
		if (is_valid(str[i]))
		{
			num = ft_atoli(&str[i]);
			if (!int_range(num))
				return (1);
			ft_lstadd_back(&a, list_add_int(num));
			while (is_valid(str[i]))
				i++;
		}
	}
	return (0);
}

/*	If the numbers are added from command line as individual strings,
	this function will convert each string to an integer and add it
	to the end of the list.	*/

int	multiple_strings(t_list *a, int ac, char **av)
{
	int			i;
	long int	num;

	i = 0;
	while (i < ac - 1)
	{
		if (av[i + 1])
		{
			num = ft_atoli(av[i + 1]);
			if (!int_range(num))
				return (1);
			ft_lstadd_back(&a, list_add_int(num));
		}
		i++;
	}
	return (0);
}

/*	Frees the list memory. Because the content of each list element
	is allocated in the heap, it first frees the content, then the
	element itself.	*/

void	free_list(t_list *list)
{
	t_list	*previous;

	while (list)
	{
		previous = list;
		list = list->next;
		free (previous->content);
		free (previous);
	}
}
