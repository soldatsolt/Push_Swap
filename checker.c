/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 18:35:47 by kmills            #+#    #+#             */
/*   Updated: 2019/09/04 18:49:04 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checker_stdin(t_push *push, char *str)
{
	if (!ft_strcmp(str, "sa"))
		sa(push);
	else if (!ft_strcmp(str, "sb"))
		sb(push);
	else if (!ft_strcmp(str, "ss"))
		ss(push);
	else if (!ft_strcmp(str, "pa"))
		pa(push);
	else if (!ft_strcmp(str, "pb"))
		pb(push);
	else if (!ft_strcmp(str, "ra"))
		ra(push);
	else if (!ft_strcmp(str, "rb"))
		rb(push);
	else if (!ft_strcmp(str, "rr"))
		rr(push);
	else if (!ft_strcmp(str, "rra"))
		rra(push);
	else if (!ft_strcmp(str, "rrb"))
		rrb(push);
	else if (!ft_strcmp(str, "rrr"))
		rrr(push);
	else
		error_checker_stder(push, str);
}

void	check_ok(t_push *push)
{
	write(1, "OK\n", 3);
	free_push(push);
	exit(0);
}

void	check_ko(t_push *push)
{
	write(1, "KO\n", 3);
	free_push(push);
	exit(0);
}

void	checker(t_push *push)
{
	t_stack	*tmp;

	tmp = push->start_a;
	if (push->start_a && !push->start_b)
		tmp = push->start_a;
	else if (push->start_b)
		check_ko(push);
	else
		check_ok(push);
	if (push->b || push->start_b)
		check_ko(push);
	while (tmp->next)
	{
		if (tmp->n > tmp->next->n)
			check_ko(push);
		tmp = tmp->next;
	}
	check_ok(push);
}

void	check_for_duplicates(t_push *push)
{
	int		n;
	t_stack	*tmp;
	t_stack	*tmp1;

	if (!push->start_a && !push->start_b)
	{
		free_push(push);
		exit(0);
	}
	if (push->start_a)
		tmp = push->start_a;
	else
		return ;
	while (tmp->next)
	{
		n = tmp->n;
		tmp1 = tmp->next;
		while (tmp1)
		{
			if (n == tmp1->n)
				error_checker_stder(push, NULL);
			tmp1 = tmp1->next;
		}
		tmp = tmp->next;
	}
}
