/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 10:39:27 by jbrown            #+#    #+#             */
/*   Updated: 2022/03/11 10:39:29 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"

void	print_stacks(t_list **a, t_list **b);
void	lst_init(t_list *a, int ac, char **av);
void	swap(t_list *stack);
void	push(t_list *src, t_list *dst);
void	rotate(t_list *a);
void	rev_rotate(t_list *a);
void	rev_rotate_both(t_list *a, t_list *b);
void	rotate_both(t_list *a, t_list *b);
void	three_nums(t_list *a, t_list *b);
void	five_nums(t_list *a, t_list *b);

#endif
