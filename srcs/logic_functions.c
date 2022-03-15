#include "push_swap.h"

void	smart_rotate(t_list *stack, int match)
{
	t_list	*head;
	int		size;
	int		count;

	head = stack;
	size = ft_lstsize(stack);
	count = 0;
	while (stack->next && ft_atoi(stack->next->content) != match)
	{
		count++;
		stack = stack->next;
	}
	if (count <= (size / 2) + 1)
	{
		while (ft_atoi(head->next->content) != match)
		{
			rotate(head);
		}
	}
	else
	{
		while (ft_atoi(head->next->content) != match)
		{
			rev_rotate(head);
		}
	}
	ft_printf("Match: %i\nOther: %s\n", match, head->next->content);
}