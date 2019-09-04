/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 18:35:44 by kmills            #+#    #+#             */
/*   Updated: 2019/09/04 18:36:16 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->next = NULL;
	stack->n = 0;
	stack->f = 0;
	return (stack);
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
