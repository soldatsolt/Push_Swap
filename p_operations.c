/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 18:35:58 by kmills            #+#    #+#             */
/*   Updated: 2019/09/04 18:36:07 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	p_pb(t_push *push)
{
	pb(push);
	ft_putstr("pb\n");
}

void	p_ra(t_push *push)
{
	ra(push);
	ft_putstr("ra\n");
}

void	p_rb(t_push *push)
{
	rb(push);
	ft_putstr("rb\n");
}
