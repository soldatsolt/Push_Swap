#include "Push_Swap.h"

t_stack	*create_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->next = NULL;
	stack->n = 0;
	return (stack);
}

void    put_n_to_a(t_push *push, int n)
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

void    put_n_to_b(t_push *push, int n)
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

void	sa(t_push *push)
{
	int	tmp;

	if (!(push->start_a->n) || !(push->start_a->next->n))
		return ;
	tmp = push->start_a->next->n;
	push->start_a->next->n = push->start_a->n;
	push->start_a->n = tmp;
}

void	sb(t_push *push)
{
	int	tmp;

	if (!(push->start_b->n) || !(push->start_b->next->n))
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

void    free_all_stack(t_stack *start)
{
	t_stack   *tmp;
	t_stack   *store;

	tmp = start;
	while (tmp)
	{
		store = tmp->next;
		free(tmp);
		tmp = store;
	}
}

void	free_push(t_push *push)
{
	free_all_stack(push->start_a);
	free_all_stack(push->start_b);
	free(push);
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

void	pa(t_push *push)
{
	t_stack	*tmp_b;
	t_stack	*tmp_a;

	if (!push->start_b->n)
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

	if (!push->start_a->n)
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

int		main(int argc, char **argv)
{
	t_push	*push;
	int 	i;

	i = 1;
	push = create_push();

	ft_putstr("Hi, it's Push_Swap\n");
	if (argc >= 2)
	{
		while (i < argc)
		{
			put_n_to_a(push, ft_atoi(argv[i]));
			i++;
		}
	}
	ft_putstr("BEFORE RRR\n");
	krasivo_vivod_check(push);
	sa(push);
	pb(push);
	pb(push);
	pb(push);
	rr(push);
	rrr(push);
	sa(push);
	pa(push);
	pa(push);
	pa(push);
	ft_putstr("AFTER RRR\n");
	krasivo_vivod_check(push);
	free_push(push);
	return (0);
}
