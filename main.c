#include "Push_Swap.h"

t_stack	*create_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->next = NULL;
	return (stack);
}

void    put_n_to_stack(t_stack **stack, int n)
{
	t_stack   *tmp;

	tmp = *stack;
	(*stack) = create_stack();
	tmp->n = n;
	tmp->next = (*stack);
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

int		main(void)
{
	t_push	*push;

	push = create_push();

	printf("Hi, it's Push_Swap\n");
	return (0);
}
