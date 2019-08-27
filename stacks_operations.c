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
	stack->f = 0;
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

void	print_stack(t_stack *stack)
{
	while (stack)
	{
		ft_putnbr(stack->n);
		ft_putchar('\n');
		stack = stack->next;
	}
}

void	krasivo_vivod_check(t_push *push)
{
	t_stack *tmp_a;
	t_stack *tmp_b;

	tmp_a = push->start_a;
	tmp_b = push->start_b;
	ft_putstr("__A__|__B__\n");
	while (tmp_a || tmp_b)
	{
		ft_putstr("__");
		if (tmp_a)
			ft_putnbr(tmp_a->n);
		else
			ft_putstr("^");
		if (tmp_a && tmp_a->n < 10)
			ft_putstr("__|__");
		else
			ft_putstr("_|__");
		if (tmp_b)
			ft_putnbr(tmp_b->n);
		else
			ft_putstr("^");
		if (tmp_b && tmp_b->n < 10)
			ft_putstr("__\n");
		else
			ft_putstr("_\n");
		if (tmp_a)
			tmp_a = tmp_a->next;
		if (tmp_b)
			tmp_b = tmp_b->next;
	}
}
