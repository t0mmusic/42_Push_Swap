/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <jbrown@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 10:39:27 by jbrown            #+#    #+#             */
/*   Updated: 2022/05/01 12:19:09 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"

/*	Unused in final	*/
void	print_stacks(t_list *a, t_list *b);

/*	Initialisation */
int		error_check(int ac, char **av);
void	multiple_strings(t_list *a, int ac, char **av);
void	single_string(t_list *a, char *str);
void	list_type(t_list *a, int ac, char **av);

/*	Stack movement */
void	push(t_list *src, t_list *dst, int print);
void	swap(t_list *stack, int print);
void	rotate(t_list *a, int print);
void	rotate_both(t_list *a, t_list *b, int print);
void	rev_rotate(t_list *a, int print);
void	rev_rotate_both(t_list *a, t_list *b, int print);

/*	Order checking	*/
int		final_order(t_list *a, t_list *b);
t_list	*ascending_order(t_list *list);
int		rotate_order(t_list *list);

/*	Logic functions	*/
void	smart_rotate(t_list *stack, int *match);
int		*find_min(t_list *stack);
int		*find_max(t_list *stack);
int		shortest_rotate(t_list *stack, int *match);
int		*find_next(t_list *stack, int *previous);

/*	Find and push groups	*/
void	push_group(t_list *a, t_list *b, int *min);
int		*find_group(t_list *a, int *last_sorted, int groupsize);
int		group_size(t_list *stack);

/*	double rotation functions	*/
void	twin_rotate(t_list *a, t_list *b, void (f)(t_list *, t_list *, int));
void	double_rotate(t_list *a, t_list*b);

/*	Free data	*/
void	free_list(t_list *list);

/*	utilities	*/
int		is_valid(char c);
int		ft_abs(int nbr);

#endif
