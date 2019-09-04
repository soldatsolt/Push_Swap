/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 18:35:54 by kmills            #+#    #+#             */
/*   Updated: 2019/09/04 18:36:09 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_stack_a_to_top(t_push *push, t_stack *a)
{
	int	ra;
	int	rra;

	ra = n_operations_to_up_a_by_ra(push, a);
	rra = n_operations_to_up_a_by_rra(push, a);
	if (ra < rra)
		ra_n_times(push, ra);
	else
		rra_n_times(push, rra);
}

void	move_stack_b_to_top(t_push *push, t_stack *b)
{
	int	rb;
	int	rrb;

	rb = n_operations_to_up_b_by_rb(push, b);
	rrb = n_operations_to_up_b_by_rrb(push, b);
	if (rb < rrb)
		rb_n_times(push, rb);
	else
		rrb_n_times(push, rrb);
}

void	move_stacks_a_b_to_top(t_push *push, t_stack *a, t_stack *b)
{
	int	ra;
	int	rra;
	int	rb;
	int	rrb;

	ra = n_operations_to_up_a_by_ra(push, a);
	rra = n_operations_to_up_a_by_rra(push, a);
	rb = n_operations_to_up_b_by_rb(push, b);
	rrb = n_operations_to_up_b_by_rrb(push, b);
	if (rb < rrb && ra < rra)
		rr_n_times(push, (rb < ra) ? rb : ra);
	else if (rb > rrb && ra > rra)
		rrr_n_times(push, (rrb < rra) ? rrb : rra);
	move_stack_a_to_top(push, a);
	move_stack_b_to_top(push, b);
}

int		number_operations_to_put_b_to_a(t_push *push, t_stack *a, t_stack *b)
{
	int	n;

	n = min_of_2(n_operations_to_up_a_by_ra(push, a), \
	n_operations_to_up_a_by_rra(push, a));
	n += min_of_2(n_operations_to_up_b_by_rb(push, b), \
	n_operations_to_up_b_by_rrb(push, b));
	n++;
	return (n);
}

void	choose_best_a_b_stacks_to_move(t_push *push, \
t_stack **a_stack_to_move, t_stack **b_stack_to_move)
{
	t_stack	*tmp_b;
	t_stack	*tmp_a;
	int		n;

	n = INT_MAX;
	tmp_b = push->start_b;
	while (tmp_b)
	{
		tmp_a = stack_a_to_put_b_on_it(push, tmp_b);
		if (number_operations_to_put_b_to_a(push, tmp_a, tmp_b) < n)
		{
			n = number_operations_to_put_b_to_a(push, tmp_a, tmp_b);
			*b_stack_to_move = tmp_b;
			*a_stack_to_move = tmp_a;
		}
		tmp_b = tmp_b->next;
	}
}
