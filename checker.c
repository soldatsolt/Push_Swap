#include "push_swap.h"

void	error_checker_stdin(t_push *push, char *str)
{
	write(2, "Error\n", 6);
	free_push(push);
	free(str);
	exit(0);
}

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
		error_checker_stdin(push, str);
}

void	checker(t_push *push)
{
	t_stack	*tmp;

	tmp = push->start_a;
	if (push->b || push->start_b)
	{
		write(1, "KO\n", 3);
		free_push(push);
		exit(0);
	}
	while (tmp->next)
	{
		if (tmp->n > tmp->next->n)
		{
			write(1, "KO\n", 3);
			free_push(push);
			exit(0);
		}
		tmp = tmp->next;
	}
	write(1, "OK\n", 3);
	free_push(push);
	exit(0);
}

void	check_for_duplicates(t_push *push)
{
	int	n;
	t_stack	*tmp;
	t_stack	*tmp1;

	tmp = push->start_a;
	while (tmp->next)
	{
		n = tmp->n;
		tmp1 = tmp->next;
		while (tmp1)
		{
			if (n == tmp1->n)
			{
				write(2, "Error\n", 6);
				free_push(push);
				exit(0);
			}
			tmp1 = tmp1->next;
		}
		tmp = tmp->next;
	}
}

void	check_for_letters(t_push *push, const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == '-' || str[i] == '+') && ((i != 0) || !str[i + 1]))
		{
			write(2, "Error\n", 6);
			free_push(push);
			exit(0);
		}
		if (!(str[i] >= '0' && str[i] <= '9') && str[i] != '-' && str[i] != '+')
		{
			write(2, "Error\n", 6);
			free_push(push);
			exit(0);
		}
		i++;
	}
}

int		ft_atoi_for_checker(t_push *push, char *str)
{
	long	res;
	long	z;

	check_for_letters(push, str);
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
	}
	if ((res * z) > INT_MAX || (res * z) < INT_MIN)
		error_checker_stdin(push, ft_strdup(str));
	return ((int)(res * z));
}
