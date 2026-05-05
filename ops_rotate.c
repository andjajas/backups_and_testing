#include "push_swap.h"

void	ra(t_stack *stack_a, t_stats *stats)
{
	if (!stack_a || !stack_a->top || stack_a->top->next == stack_a->top)
		return ;
	stack_a->top = stack_a->top->next;
	write(1, "ra\n", 3);
	stats->ra_count++;
	stats->total_operation_count++;
}

void	rb(t_stack *stack_b, t_stats *stats)
{
	if (!stack_b || !stack_b->top || stack_b->top->next == stack_b->top)
		return ;
	stack_b->top = stack_b->top->next;
	write(1, "rb\n", 3);
	stats->rb_count++;
	stats->total_operation_count++;
}

void	rr(t_stack *stack_a, t_stack *stack_b, t_stats *stats)
{
	if (!stack_a || !stack_a->top || stack_a->top->next == stack_a->top)
		return ;
	if (!stack_b || !stack_b->top || stack_b->top->next == stack_b->top)
		return ;
	stack_a->top = stack_a->top->next;
	stack_b->top = stack_b->top->next;
	write(1, "rr\n", 3);
	stats->rr_count++;
	stats->total_operation_count++;
}

void	rra(t_stack *stack_a, t_stats *stats)
{
	if (!stack_a || !stack_a->top || stack_a->top->next == stack_a->top)
		return ;
	stack_a->top = stack_a->top->prev;
	write(1, "rra\n", 3);
	stats->rra_count++;
	stats->total_operation_count++;
}

void	rrb(t_stack *stack_b, t_stats *stats)
{
	if (!stack_b || !stack_b->top || stack_b->top->next == stack_b->top)
		return ;
	stack_b->top = stack_b->top->prev;
	write(1, "rrb\n", 3);
	stats->rrb_count++;
	stats->total_operation_count++;
}

void	rrr(t_stack *stack_a, t_stack *stack_b, t_stats *stats)
{
	if (!stack_a || !stack_a->top || stack_a->top->next == stack_a->top)
		return ;
	if (!stack_b || !stack_b->top || stack_b->top->next == stack_b->top)
		return ;
	stack_a->top = stack_a->top->prev;
	stack_b->top = stack_b->top->prev;
	write(1, "rrr\n", 3);
	stats->rrr_count++;
	stats->total_operation_count++;
}
