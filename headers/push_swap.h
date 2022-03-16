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

typedef struct s_grouplist
{
	int					min;
	int					max;
	struct s_grouplist	*next;
}	t_grouplist;

/*	Initialisation/printing */
void	print_stacks(t_list **a, t_list **b);
void	lst_init(t_list *a, int ac, char **av);

/*	Stack movement */
void	swap(t_list *stack);
void	push(t_list *src, t_list *dst);
void	rotate(t_list *a);
void	rotate_both(t_list *a, t_list *b);
void	rev_rotate(t_list *a);
void	rev_rotate_both(t_list *a, t_list *b);

/*	Small sort functions */
void	three_nums(t_list *a, t_list *b);
void	five_nums(t_list *a, t_list *b);

/*	Group allocation functions */
t_grouplist	*find_min_max(t_list *a);
void		push_group(t_list *a, t_list *b, t_grouplist *group);

/*	Functions for finding specific numbers */
int		find_max(t_list *stack);
int		find_min(t_list *stack);
char	*find_range(t_list *a, t_grouplist *group);
int		find_next(t_list *stack, char *current);


/* Logic Functions */
void	smart_rotate(t_list *stack, int match);

#endif
