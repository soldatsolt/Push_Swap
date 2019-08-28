#include "push_swap.h"

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

void	algos1(t_push *push)
{
	t_stack	*tmp;
	int		kol_vo_elementov;
	int		i;

	i = 0;
	kol_vo_elementov = 0;
	if (push->start_a)
		tmp = push->start_a;
	else
		return ;	
	while (tmp)
	{
		tmp = tmp->next;
		kol_vo_elementov++;
	}
	tmp = push->start_a;
	while (tmp && tmp->next)
	{
		if (push->start_a && push->start_a->next && push->start_a->n > push->start_a->next->n)
		{
			sa(push);
			ft_putstr("sa\n");
		}
		while (tmp->next && tmp->n < tmp->next->n)
		{
			tmp = tmp->next;
			i++;
		}
		if (tmp && tmp->next && (tmp->n > tmp->next->n))
		{
			pb_n_times(push, i);
			i = 0;
		}
	}
	pa_n_times(push, kol_vo_elementov_v_stacke(push->start_b));
}

void	algos2(t_push *push)
{
	t_stack	*tmp;
	int		n;
	int		max_element;
	int		min_element;

	min_element = 0;
	if (push->start_a)
		tmp = push->start_a;
	else
		return ;
	max_element = kol_vo_elementov_v_stacke(push->start_a) - 1;
	while (min_element < max_element)
	{
		while (push->start_a->n != min_element)
		{
			if (push->start_a->n - push->start_a->next->n == 1)
			{
				sa(push);
				ft_putstr("sa\n"); // весь этот иф очень спорный
				ra(push);
				ft_putstr("ra\n");
			}
			ra(push);
			ft_putstr("ra\n");
		}
		pb_n_times(push, 1);
		min_element++;
	}
	pa_n_times(push, kol_vo_elementov_v_stacke(push->start_b));
}

/*
**
**
**
*/

void	make_norm_stack(t_push *push)
{
	int		nomer;
	t_stack	*tmp;
	t_stack	*min_tmp;
	int		kol_vo_elementov_v_stacke_a;

	nomer = 0;
	kol_vo_elementov_v_stacke_a = kol_vo_elementov_v_stacke(push->start_a);
	if (push->start_a)
		tmp = push->start_a;
	else
		return ;
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
	algos2(push);
	// krasivo_vivod_check(push);
	return (0);
}
