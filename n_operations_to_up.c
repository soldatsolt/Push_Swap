/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_operations_to_up.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 18:35:57 by kmills            #+#    #+#             */
/*   Updated: 2019/09/04 18:36:08 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		kol_vo_elementov_v_stacke(t_stack *stack)
{
	int	n;

	n = 0;
	if (stack)
	{
		while (stack)
		{
			stack = stack->next;
			n++;
		}
		return (n);
	}
	return (n);
}

int		n_operations_to_up_b_by_rrb(t_push *push, t_stack *b)
{
	int		kolvo;
	t_stack	*tmp;

	tmp = push->start_b;
	kolvo = 0;
	while (tmp != b && tmp)
	{
		tmp = tmp->next;
		kolvo++;
	}
	if (tmp == NULL)
		return (-1);
	return (kol_vo_elementov_v_stacke(push->start_b) - kolvo);
}

int		n_operations_to_up_b_by_rb(t_push *push, t_stack *b)
{
	int		kolvo;
	t_stack	*tmp;

	tmp = push->start_b;
	kolvo = 0;
	while (tmp != b && tmp)
	{
		tmp = tmp->next;
		kolvo++;
	}
	if (tmp == NULL)
		return (-1);
	return (kolvo);
}

int		n_operations_to_up_a_by_rra(t_push *push, t_stack *a)
{
	int		kolvo;
	t_stack	*tmp;

	tmp = push->start_a;
	kolvo = 0;
	while (tmp != a && tmp)
	{
		tmp = tmp->next;
		kolvo++;
	}
	if (tmp == NULL)
		return (-1);
	return (kol_vo_elementov_v_stacke(push->start_a) - kolvo);
}

int		n_operations_to_up_a_by_ra(t_push *push, t_stack *a)
{
	int		kolvo;
	t_stack	*tmp;

	tmp = push->start_a;
	kolvo = 0;
	while (tmp != a && tmp)
	{
		tmp = tmp->next;
		kolvo++;
	}
	if (tmp == NULL)
		return (-1);
	return (kolvo);
}
