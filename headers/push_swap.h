/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrown <jbrown@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 10:39:27 by jbrown            #+#    #+#             */
/*   Updated: 2022/05/09 11:23:29 by jbrown           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"

/*	Initialisation */
int			multiple_strings(t_list *a, int ac, char **av);
int			single_string(t_list *a, char *str);
int			list_type(t_list *a, int ac, char **av);
t_list		*list_add_int(int num);

/*	Error checking	*/
int			int_range(long int num);
int			error_check(int ac, char **av);
int			duplicate_check(t_list *stack);

/*	Stack movement */
void		push(t_list *src, t_list *dst, int print);
void		swap(t_list *stack, int print);
void		rotate(t_list *a, int print);
void		rotate_both(t_list *a, t_list *b, int print);
void		rev_rotate(t_list *a, int print);
void		rev_rotate_both(t_list *a, t_list *b, int print);

/*	Order checking	*/
int			final_order(t_list *a, t_list *b);
t_list		*ascending_order(t_list *list);
int			rotate_order(t_list *list);
int			swap_check(t_list *stack, int *check);

/*	Logic functions	*/
void		smart_rotate(t_list *stack, int *match);
int			shortest_rotate(t_list *stack, int *match);
void		small_sort(t_list *a, t_list *b, int size);

/*	Find numbers	*/
int			*find_min(t_list *stack);
int			*find_max(t_list *stack);
int			*find_next(t_list *stack, int *previous);
int			*find_previous(t_list *stack, int *next);
int			*find_last(t_list *stack);

/*	Radix sort	*/
void		radix_sort(t_list *a, t_list *b);

/*	Find and push groups	*/
void		push_group(t_list *a, t_list *b, int *min, int groupsize);
int			*find_group(t_list *a, int *last_sorted, int groupsize);
int			group_size(t_list *stack);
void		return_stack(t_list *a, t_list *b);

/*	double rotation functions	*/
void		twin_rotate(t_list *a, t_list *b,
				void (f)(t_list *, t_list *, int));
void		double_rotate(t_list *a, t_list *b);

/*	Free data	*/
void		free_list(t_list *list);

/*	utilities	*/
int			is_valid(char c);
int			ft_abs(int nbr);
long int	ft_atoli(const char *str);

/*	Unused in final	*/
void		print_stacks(t_list *a, t_list *b);

/*	Out of order Functions	*/
int			*out_of_order(t_list *stack, int *current);
int			*ooo_smallest(t_list *stack);
int			*ooo_next(t_list *stack, int *min);
int			*find_push(t_list *stack, int *min, int groupsize);

#endif
