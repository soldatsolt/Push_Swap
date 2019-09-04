#include "push_swap.h"

void	rra(t_push *push)
{
	t_stack	*tmp_a;
	t_stack	*start;

	if (!(push->start_a) || !(push->start_a->next))
		return ;
	tmp_a = push->start_a;
	start = push->start_a;
	while (tmp_a->next->next)
		tmp_a = tmp_a->next;
	push->start_a = tmp_a->next;
	push->start_a->next = start;
	tmp_a->next = NULL;
}

void	rrb(t_push *push)
{
	t_stack	*tmp_b;
	t_stack	*start;

	if (!(push->start_b) || !(push->start_b->next))
		return ;
	tmp_b = push->start_b;
	start = push->start_b;
	while (tmp_b->next->next)
		tmp_b = tmp_b->next;
	push->start_b = tmp_b->next;
	push->start_b->next = start;
	tmp_b->next = NULL;
}

void	rrr(t_push *push)
{
	rra(push);
	rrb(push);
}
