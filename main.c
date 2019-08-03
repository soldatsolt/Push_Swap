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

int		main(int argc, char **argv)
{
	t_push	*push;
	int 	i;

	i = 1;
	push = create_push();

	printf("Hi, it's Push_Swap\n");
	if (argc >= 2)
	{
		while (i < argc)
		{
			put_n_to_a(push, ft_atoi(argv[i]));
			i++;
		}
	}
	sa(push);
	print_stack(push->start_a);
	return (0);
}
