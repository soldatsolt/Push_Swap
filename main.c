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
	t_stack   *tmp;

	tmp = push->a;
	push->a = create_stack();
	tmp->n = n;
	tmp->next = push->a;
}

void    put_n_to_b(t_push *push, int n)
{
	t_stack   *tmp;

	tmp = push->b;
	push->b = create_stack();
	tmp->n = n;
	tmp->next = push->b;
}

t_push	*create_push(void)
{
	t_push	*push;

	push = (t_push *)malloc(sizeof(t_push));
	push->a = create_stack();
	push->b = create_stack();
	push->start_a = push->a;
	push->start_b = push->b;
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
	while (stack->next)
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
	while (tmp_a->next || tmp_b->next)
	{
		ft_putstr("__");
		if (tmp_a->n)
			ft_putnbr(tmp_a->n);
		else
			ft_putstr("^");
		if (tmp_a->n < 10)
			ft_putstr("__|__");
		else
			ft_putstr("_|__");
		if (tmp_b->n)
			ft_putnbr(tmp_b->n);
		else
			ft_putstr("^");
				if (tmp_b->n < 10)
			ft_putstr("__\n");
		else
			ft_putstr("_\n");
		if (tmp_a->next)
			tmp_a = tmp_a->next;
		if (tmp_b->next)
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
	put_n_to_b(push, 9);
	put_n_to_b(push, 53);
	sa(push);
	sb(push);
	ss(push);
	pa(push);
	pa(push);
	pa(push);
	pb(push);	
	pb(push);
	pb(push);
	pb(push);
	pb(push);
	krasivo_vivod_check(push);
	free_push(push);
	return (0);
}
