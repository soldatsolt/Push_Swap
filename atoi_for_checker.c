/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_for_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <kmills@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 18:35:46 by kmills            #+#    #+#             */
/*   Updated: 2019/09/05 23:27:17 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_for_letters(char **all_str, t_push *push, const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == '-' || str[i] == '+') && ((i != 0) || !str[i + 1]))
		{
			write(2, "Error\n", 6);
			free_push(push);
			free_all_str(all_str);
			exit(0);
		}
		if (!(str[i] >= '0' && str[i] <= '9') && str[i] != '-' && str[i] != '+')
		{
			write(2, "Error\n", 6);
			free_push(push);
			free_all_str(all_str);
			exit(0);
		}
		i++;
	}
}

int		ft_atoi_for_checker(char **all_str, t_push *push, char *str)
{
	long	res;
	long	z;

	check_for_letters(all_str, push, str);
	res = 0;
	z = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r' ||\
	*str == '\v' || *str == '\f')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			z = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10;
		res = res + (int)(*str - '0');
		str++;
		if ((res * z) > INT_MAX || (res * z) < INT_MIN)
			error_checker_stder1(all_str, push, ft_strdup(str));
	}
	return ((int)(res * z));
}

void	start_atoi_for_checker(t_push *push, char *str)
{
	char	**all_str;
	int		i;

	i = 0;
	all_str = ft_strsplit(str, ' ');
	if (all_str)
	{
		while (all_str[i])
		{
			put_n_to_a(push, ft_atoi_for_checker(all_str, push, all_str[i]));
			i++;
		}
		free_all_str(all_str);
	}
}
