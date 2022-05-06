/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <jbrown@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 16:42:29 by jbrown            #+#    #+#             */
/*   Updated: 2022/05/06 16:55:18 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

/*	Used for printing. Not the actual checker.	*/

void	print_info(t_list *a, t_list *b, int count)
{
	print_stacks(a, b);
	ft_printf("Number of Moves: %i\n", count);
	ft_printf("Enter Movement: \n");
	usleep(50000);
	a = a->next;
	b = b->next;
}

/*	Frees the lists and exits the program. If there was an error, it
	will print "Error". Otherwise it will diplay succuess "OK" or
	failure "KO".	*/

void	free_exit(t_list *a, t_list *b, int valid)
{
	if (!valid)
		ft_printf("Error\n");
	else if (final_order(a, b))
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	free_list(a);
	free_list(b);
	exit(0);
}

/*	Compares the current line to the possible commands that
	push_swap can use. It will then apply that command to stacks
	a and b. */

void	movement_check(char *str, t_list *a, t_list *b)
{
	if (!ft_strcmp(str, "sa\n"))
		swap(a, 0);
	else if (!ft_strcmp(str, "sb\n"))
		swap(b, 0);
	else if (!ft_strcmp(str, "ra\n"))
		rotate(a, 0);
	else if (!ft_strcmp(str, "rb\n"))
		rotate(b, 0);
	else if (!ft_strcmp(str, "pa\n"))
		push(b, a, 0);
	else if (!ft_strcmp(str, "pb\n"))
		push(a, b, 0);
	else if (!ft_strcmp(str, "rra\n"))
		rev_rotate(a, 0);
	else if (!ft_strcmp(str, "rrb\n"))
		rev_rotate(b, 0);
	else if (!ft_strcmp(str, "rr\n"))
		rotate_both(a, b, 0);
	else if (!ft_strcmp(str, "rrr\n"))
		rev_rotate_both(a, b, 0);
	else
		free_exit(a, b, 0);
}

/*	Using get next line, this function reads from the standard
	output all of the commands used to sort the stacks. It then
	applies those commands to the same stacks, checking to see
	if the numbers have been sorted correctly. */

int	main(int ac, char **av)
{
	char	*str;
	t_list	*a;
	t_list	*b;
	int		count;

	if (ac == 1)
		return (0);
	a = ft_lstnew(ft_strdup("a"));
	b = ft_lstnew(ft_strdup("b"));
	list_type(a, ac, av);
	count = 0;
	print_info(a, b, count);
	str = get_next_line(0);
	while (str)
	{
		count++;
		movement_check(str, a, b);
		print_info(a, b, count);
		str = get_next_line(0);
	}
	free_exit(a, b, 1);
	return (0);
}
