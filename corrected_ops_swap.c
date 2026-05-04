#include "push_swap.h"

static void	swap(t_stack *stack);

void	sa(t_stack *stack_a, t_stats *stats)
{
	if (stack_a->top == NULL || stack_a->top->next == stack_a->top)
		return ;
	swap(stack_a);
	write(1, "sa\n", 3);
	stats->sa_count++;
	stats->total_operation_count++;
}

void	sb(t_stack *stack_b, t_stats *stats)
{
	if (stack_b->top == NULL || stack_b->top->next == stack_b->top)
		return ;
	swap(stack_b);
	write(1, "sb\n", 3);
	stats->sb_count++;
	stats->total_operation_count++;
}

void	ss(t_stack *stack_a, t_stack *stack_b, t_stats *stats)
{
	if (stack_a->top == NULL || stack_a->top->next == stack_a->top)
		return ;
	if (stack_b->top == NULL || stack_b->top->next == stack_b->top)
		return ;
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
	stats->ss_count++;
	stats->total_operation_count++;
}

static void	swap(t_stack *stack)
{
	t_num	*bottom;
	t_num	*first;
	t_num	*second;
	t_num	*third;

	if (stack->top->next->next == stack->top)
		stack->top = stack->top->next;
	else
	{
		bottom = stack->top->prev;
		first = stack->top;
		second = stack->top->next;
		third = stack->top->next->next;
		bottom->next = second;
		first->prev = second;
		first->next = third;
		second->prev = bottom;
		second->next = first;
		third->prev = first;
		stack->top = second;
	}
}
