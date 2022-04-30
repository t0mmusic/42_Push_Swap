/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_initialise.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <jbrown@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 10:51:05 by jbrown            #+#    #+#             */
/*   Updated: 2022/04/29 11:28:38 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	takes an integer and converts it into a pointer to add as a list element.
	the pointer is allocated in heap memory. */

t_list	*list_add_int(int num)
{
	int		*num_pointer;
	t_list	*new;

	num_pointer = malloc(sizeof(*num_pointer));
	ft_memcpy(num_pointer, &num, sizeof(int));
	new = ft_lstnew(num_pointer);
	return (new);
}

/*	Checks if the command line arguments added are a single string containing
	all of the numbers or if the numbers are in indivual strings.	*/

void	list_type(t_list *a, int ac, char **av)
{
	int	i;

	i = 0;
	while (av[1][i])
	{
		if (ft_isspace(av[1][i]))
		{
			single_string(a, av[1]);
			return ;
		}
		i++;
	}
	multiple_strings(a, ac, av);
}

/*	Breaks the string into individual values seperated by spaces. Each
	new value is added to the end of the list.	*/

void	single_string(t_list *a, char *str)
{
	int		i;
	int		num;

	i = 0;
	while (str[i])
	{
		while (ft_isspace(str[i]))
		{
			i++;
		}
		if (is_valid(str[i]))
		{
			num = ft_atoi(&str[i]);
			ft_lstadd_back(&a, list_add_int(num));
			while (is_valid(str[i]))
				i++;
		}
	}
}

/*	Each string will be converted into an integer and then added to the
	end of the list.	*/

void	multiple_strings(t_list *a, int ac, char **av)
{
	int		i;
	int		num;

	i = 0;
	while (i < ac - 1)
	{
		if (av[i + 1])
		{
			num = ft_atoi(av[i + 1]);
			ft_lstadd_back(&a, list_add_int(num));
		}
		i++;
	}
}

/*	Frees the list memory. This will be the content of the lists
	and the lists themselves.	*/

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
