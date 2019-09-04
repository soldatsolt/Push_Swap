/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 18:35:41 by kmills            #+#    #+#             */
/*   Updated: 2019/09/04 18:36:17 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
