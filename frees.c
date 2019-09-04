/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 18:35:49 by kmills            #+#    #+#             */
/*   Updated: 2019/09/04 18:36:13 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all_stack(t_stack *start)
{
	t_stack		*tmp;
	t_stack		*store;

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
	free(push);
}

void	free_all_str(char **all_str)
{
	int i;
	int	j;

	j = 0;
	i = 0;
	while (all_str[i])
	{
		while (all_str[i][j])
		{
			all_str[i][j] = '\0';
			j++;
		}
		j = 0;
		free(all_str[i]);
		all_str[i] = NULL;
		i++;
	}
	free(all_str);
	all_str = NULL;
}

void	error_checker_stder(t_push *push, char *str)
{
	write(2, "Error\n", 6);
	free_push(push);
	if (str)
		free(str);
	exit(0);
}

void	error_checker_stder1(char **all_str, t_push *push, char *str)
{
	write(2, "Error\n", 6);
	free_push(push);
	free(str);
	free_all_str(all_str);
	exit(0);
}
