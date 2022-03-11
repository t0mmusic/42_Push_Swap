#include "push_swap.h"

void	three_two_one(t_list *a, t_list *b)
{
	swap(a);
	print_stacks(&a->next, &b->next);
	rev_rotate(a);
	print_stacks(&a->next, &b->next);
}

void	two_three_one(t_list *a, t_list *b)
{
	rotate(a);
	print_stacks(&a->next, &b->next);
}

void	two_one_three(t_list *a, t_list *b)
{
	swap(a);
	print_stacks(&a->next, &b->next);
}

void	three_nums(t_list *a, t_list *b)
{
	int	one;
	int	two;
	int	three;

	one = ft_atoi(a->next->content);
	two = ft_atoi(a->next->next->content);
	three = ft_atoi(a->next->next->next->content);
	if (one > two)
	{
		if (two > three) //case 2
		{
			three_two_one(a, b);
		}
		else if (one > three) //case 3
		{
			two_three_one(a, b);
		}
		else //case 1
		{
			two_one_three(a, b);
		}
	}
	else if (two > three)
	{
		if (one > three) //case 5
		{
			rev_rotate(a);
			print_stacks(&a->next, &b->next);
		}
		else //case 4
		{
			swap(a);
			print_stacks(&a->next, &b->next);
			rotate(a);
			print_stacks(&a->next, &b->next);
		}
	}
}

void	five_nums(t_list *a, t_list *b)
{
	push(a, b);
	print_stacks(&a->next, &b->next);
	push(a, b);
	print_stacks(&a->next, &b->next);
	three_nums(a, b);
	push(b, a);
	print_stacks(&a->next, &b->next);
	three_nums(a, b);
	push(b, a);
	print_stacks(&a->next, &b->next);
	three_nums(a, b);
}