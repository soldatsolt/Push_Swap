#include "push_swap.h"

void	sa(t_push *push)
{
	int	tmp;

	if (!(push->start_a) || !(push->start_a->next))
		return ;
	tmp = push->start_a->next->n;
	push->start_a->next->n = push->start_a->n;
	push->start_a->n = tmp;
}

void	sb(t_push *push)
{
	int	tmp;

	if (!(push->start_b) || !(push->start_b->next))
		return ;
	tmp = push->start_b->next->n;
	push->start_b->next->n = push->start_b->n;
	push->start_b->n = tmp;
}

void	ss(t_push *push)
{
	sa(push);
	sb(push);
}

void	pa(t_push *push)
{
	t_stack	*tmp_b;
	t_stack	*tmp_a;

	if (!push->start_b)
		return ;
	tmp_b = push->start_b->next;
	tmp_a = create_stack();
	tmp_a->n = push->start_b->n;
	push->start_b->next = NULL;
	free(push->start_b);
	push->start_b = tmp_b;
	tmp_a->next = push->start_a;
	push->start_a = tmp_a;
}

void	pb(t_push *push)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	if (!push->start_a)
		return ;
	tmp_a = push->start_a->next;
	tmp_b = create_stack();
	tmp_b->n = push->start_a->n;
	push->start_a->next = NULL;
	free(push->start_a);
	push->start_a = tmp_a;
	tmp_b->next = push->start_b;
	push->start_b = tmp_b;
}

void	ra(t_push *push)
{
	t_stack	*tmp_a;

	if (!(push->start_a) || !(push->start_a->next))
		return ;
	tmp_a = push->start_a;
	while (tmp_a->next)
		tmp_a = tmp_a->next;
	tmp_a->next = push->start_a;
	push->start_a = push->start_a->next;
	tmp_a->next->next = NULL;
}

void	rb(t_push *push)
{
	t_stack	*tmp_b;

	if (!(push->start_b) || !(push->start_b->next))
		return ;
	tmp_b = push->start_b;
	while (tmp_b->next)
		tmp_b = tmp_b->next;
	tmp_b->next = push->start_b;
	push->start_b = push->start_b->next;
	tmp_b->next->next = NULL;
}

void	rr(t_push *push)
{
	ra(push);
	rb(push);
}

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
