#include "push_swap.h"

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
			all_str[i][j] = '\0'; // Очень костыльный метод избежать
			j++;	// баг. 28.08.19 09:39
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
	free_push(push); // ОШИБКА ЗАХОДИТ СЮДА
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
		error_checker_stder(push, str); // ОТСЮДА (ВВЕРХ СМОТРИ)
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

	if (push->start_a && !push->start_b)
		tmp = push->start_a;
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
	}
	if ((res * z) > INT_MAX || (res * z) < INT_MIN)
		error_checker_stder1(all_str, push, ft_strdup(str));
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
