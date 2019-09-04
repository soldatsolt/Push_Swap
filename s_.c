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
