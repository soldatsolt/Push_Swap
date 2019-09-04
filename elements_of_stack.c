#include "push_swap.h"

t_stack	*stack_a_to_put_b_on_it(t_push *push, t_stack *b)
{
	t_stack	*a;
	t_stack	*res_a;
	int		nb;
	int		na;

	nb = b->n;
	a = push->start_a;
	res_a = NULL;
	while (a)
	{
		na = a->n;
		res_a = (na > nb) ? a : res_a;
		a = a->next;
	}
	if (!res_a)
		return (on_min_elem_a(push));
	a = push->start_a;
	while (a)
	{
		na = a->n;
		if (res_a->n > nb && res_a->n > na && na > nb)
			res_a = a;
		a = a->next;
	}
	return (res_a);
}

t_stack	*elem_n_of_stack(t_stack *stack, int n)
{
	int	i;

	i = 0;
	if (!stack)
		return (NULL);
	while (i < n && stack)
	{
		stack = stack->next;
		i++;
	}
	return (stack);
}

t_stack	*on_min_elem_a(t_push *push)
{
	t_stack	*tmp;
	int		i;
	int		n;
	int		min_tmp;

	i = 0;
	n = 0;
	tmp = push->start_a;
	min_tmp = tmp->n;
	while (tmp)
	{
		if (tmp->n < min_tmp)
		{
			n = i;
			min_tmp = tmp->n;
		}
		i++;
		tmp = tmp->next;
	}
	tmp = elem_n_of_stack(push->start_a, n);
	return (tmp ? tmp : push->start_a);
}

t_stack	*min_elem_of_stack(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*min;

	tmp = stack;
	min = tmp;
	while (tmp)
	{
		if (min->n > tmp->n)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}
