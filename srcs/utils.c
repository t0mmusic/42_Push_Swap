/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <jbrown@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 09:28:56 by jbrown            #+#    #+#             */
/*   Updated: 2022/05/09 10:12:00 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	Returns absolute value of a number. This will be used to determine
	whether it is better to rotate of reverse rotate a stack.	*/

int	ft_abs(int nbr)
{
	if (nbr < 0)
		return (nbr * -1);
	return (nbr);
}

/*	This is identical to ft_atoi except that it returns a long int instead
	of an int. This is used to check if the user has entered a value that
	is outside of the integer range.	*/

long int	ft_atoli(const char *str)
{
	int			i;
	int			neg;
	long int	r;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	neg = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = 1;
		i++;
	}
	r = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + (str[i] - '0');
		i++;
	}
	if (neg)
		return (-r);
	return (r);
}
