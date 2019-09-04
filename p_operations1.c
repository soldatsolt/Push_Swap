/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_operations1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 18:35:59 by kmills            #+#    #+#             */
/*   Updated: 2019/09/04 18:36:07 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa_n_times(t_push *push, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		pa(push);
		ft_putstr("pa\n");
		i++;
	}
}

void	pb_n_times(t_push *push, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		pb(push);
		ft_putstr("pb\n");
		i++;
	}
}

void	rrb_n_times(t_push *push, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		rrb(push);
		ft_putstr("rrb\n");
		i++;
	}
}

void	rr_n_times(t_push *push, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		rr(push);
		ft_putstr("rr\n");
		i++;
	}
}

void	rrr_n_times(t_push *push, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		rrr(push);
		ft_putstr("rrr\n");
		i++;
	}
}
