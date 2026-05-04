#include "push_swap.h"

void	clear_stack(t_stack *stack)
{
	t_num	*now;
	t_num	*next;

	if (!stack || !stack->top)
		return ;
	stack->top->prev->next = NULL;
	stack->top->prev = NULL;
	now = stack->top;
	while (now)
	{
		next = now->next;
		free(now);
		now = next;
	}
	stack_init(stack);
}
