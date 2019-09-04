/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 18:35:52 by kmills            #+#    #+#             */
/*   Updated: 2019/09/04 18:36:10 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algos_for_more_elems(t_push *push)
{
	t_stack	*b_stack_to_move;
	t_stack	*a_stack_to_move;
	int		n;

	n = INT_MAX;
	while (kol_vo_elementov_v_stacke(push->start_a) > 3)
		p_pb(push);
	algos_for_3_elems(push);
	while (push->start_b)
	{
		choose_best_a_b_stacks_to_move(push, \
		&(a_stack_to_move), &(b_stack_to_move));
		move_stacks_a_b_to_top(push, a_stack_to_move, b_stack_to_move);
		if (push->start_b)
			p_pa(push);
		n = INT_MAX;
	}
	move_stack_a_to_top(push, min_elem_of_stack(push->start_a));
}

int		min_of_2(int a, int b)
{
	if (a == b)
		return (a);
	return ((a > b) ? b : a);
}

void	make_norm_stack(t_push *push)
{
	int		nomer;
	t_stack	*tmp;
	t_stack	*min_tmp;
	int		kol_vo_elementov_v_stacke_a;

	nomer = 0;
	kol_vo_elementov_v_stacke_a = kol_vo_elementov_v_stacke(push->start_a);
	tmp = push->start_a;
	while (nomer < kol_vo_elementov_v_stacke_a)
	{
		tmp = push->start_a;
		while (tmp->f)
			tmp = tmp->next;
		min_tmp = tmp;
		tmp = push->start_a;
		while (tmp)
		{
			if (min_tmp->n > tmp->n && !tmp->f)
				min_tmp = tmp;
			tmp = tmp->next;
		}
		min_tmp->n = nomer;
		min_tmp->f = 1;
		nomer++;
	}
}

int		main(int argc, char **argv)
{
	t_push	*push;
	int		i;

	i = 1;
	push = create_push();
	if (argc >= 2)
	{
		while (i < argc)
		{
			start_atoi_for_checker(push, argv[i]);
			i++;
		}
	}
	check_for_duplicates(push);
	make_norm_stack(push);
	choose_algos(push);
	free_push(push);
	return (0);
}
