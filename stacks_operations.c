#include "push_swap.h"

void	free_all_stack(t_stack *start)
{
	t_stack		*tmp;
	t_stack		*store;

	tmp = start;
	while (tmp)
	{
		store = tmp->next;
		free(tmp);
		tmp = store;
	}
}

t_stack	*create_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->next = NULL;
	stack->n = 0;
	return (stack);
}

void	free_push(t_push *push)
{
	free_all_stack(push->start_a);
	free_all_stack(push->start_b);
	free(push);
}

void	put_n_to_a(t_push *push, int n)
{
	static int	k = 0;

	if (k)
	{
		push->a->next = create_stack();
		push->a = push->a->next;
		push->a->n = n;
		push->a->next = NULL;
	}
	else
	{
		push->a = create_stack();
		push->start_a = push->a;
		push->a->n = n;
		push->a->next = NULL;
		k++;
	}
}

void	put_n_to_b(t_push *push, int n)
{
	static int	k = 0;

	if (k)
	{
		push->b->next = create_stack();
		push->b = push->b->next;
		push->b->n = n;
		push->b->next = NULL;
	}
	else
	{
		push->b = create_stack();
		push->start_b = push->b;
		push->b->n = n;
		push->b->next = NULL;
		k++;
	}
}

t_push	*create_push(void)
{
	t_push	*push;

	push = (t_push *)malloc(sizeof(t_push));
	push->a = NULL;
	push->b = NULL;
	push->start_a = NULL;
	push->start_b = NULL;
	return (push);
}