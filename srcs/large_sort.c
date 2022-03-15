#include "push_swap.h"

t_grouplist	*new_grouplist(int min, int max)
{
	t_grouplist	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->min = min;
	new->max = max;
	new->next = NULL;
	return (new);
}
/*	This function should dynamically assign groups based on quantity of stack 
	Consider also using average to determine min and max */
t_grouplist	*group_divide(int min, int max)
{
	t_grouplist	*group;
	t_grouplist	*head;
	int	small;
	int medium;
	int	large;
	
	small = max / 4;
	medium = max / 2;
	large = small + medium;

	group = new_grouplist(large - 1, max + 1);
	head = group;
	group->next = new_grouplist(medium - 1, large);
	group = group->next;
	group->next = new_grouplist(small - 1, medium);
	group = group->next;
	group->next = new_grouplist(min - 1, small);
	return (head);
}

t_grouplist	*find_min_max(t_list *a)
{
	int			min;
	int			max;

	/*min = ft_atoi(a->content);
	max = min;
	while (a->next)
	{
		if (ft_atoi(a->content) < min)
			min = ft_atoi(a->content);
		if (ft_atoi(a->content) > max)
			max = ft_atoi(a->content);
		a = a->next;
	}*/
	min = find_min(a);
	max = find_max(a);
	return (group_divide(min, max));
}
char	*find_range(t_list *a, t_grouplist *group)
{
	char	*num;

	a = a->next;
	while (a->next)
	{
		num = a->content;
		if (ft_atoi(num) > group->min && ft_atoi(num) < group->max)
			return (num);
		a = a->next;
	}
	return (NULL);
}

/* change to return char* to account for zero ??? */
int	find_max(t_list *stack)
{
	int	max;

	stack = stack->next;
	max = ft_atoi(stack->content);
	while (stack->next)
	{
		if (ft_atoi(stack->next->content) > max)
			max = ft_atoi(stack->next->content);
		stack = stack->next;
	}
	return (max);
}

int	find_min(t_list *stack)
{
	int	min;

	stack = stack->next;
	min = ft_atoi(stack->content);
	while (stack->next)
	{
		if (ft_atoi(stack->next->content) < min)
			min = ft_atoi(stack->next->content);
		stack = stack->next;
	}
	return (min);
}

/* Make better function for comparing two strings */
/* Honestly can't remember what this is for... */
/*
int	find_next(t_list *stack, char *current)
{
	char	*next;

	stack = stack->next;
	next = stack->next->content;
	while (stack->next)
	{
		if (ft_atoi(next) < ft_atoi(stack->next->content))
			next = stack->next->content;
		stack = stack->next;
	}
	return (ft_atoi(next));
}*/

void	sort_group(t_list *a, t_list *b)
{
	int	max;

	if (b->next)
	{
		max = find_max(b);
		smart_rotate(b, max);
		/*while (ft_atoi(b->next->content) != max)
		{
			rotate(b); //Make function smart_rotate which rotates in correct direction
		}*/
		push(b, a);
		sort_group(a, b);
	}
}

void	push_group(t_list *a, t_list *b, t_grouplist *group)
{
	char	*num;

	//ft_printf("Min: %i\nMax: %i\n", group->min, group->max);
	while (find_range(a, group))
	{
		num = find_range(a, group);
		smart_rotate(a, ft_atoi(num));
		/*while (a->next->content != num)
		{
			rotate(a); //Make function smart_rotate which rotates in correct direction
		}*/
		push(a, b);
	}
	//smart_rotate(b, find_max(b));
	smart_rotate(a, find_min(a));
	sort_group(a, b);
	group = group->next;
	if (group)
	{
		push_group(a, b, group);
	}
}