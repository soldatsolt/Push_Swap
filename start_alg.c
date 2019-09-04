#include "push_swap.h"

int		is_push_sorted(t_push *push)
{
	t_stack	*tmp;

	if (push->start_b)
		return (0);
	if (push->start_a)
		tmp = push->start_a;
	else
		return (0);
	while (tmp->next)
	{
		if (tmp->n > tmp->next->n)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	algos_for_2_elems(t_push *push)
{
	if (is_push_sorted(push))
		return ;
	else
	{
		sa(push);
		ft_putstr("sa\n");
	}
}

int		define_case_only_for_3_in_stack(t_stack *a)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = a->n;
	n2 = a->next->n;
	n3 = a->next->next->n;
	if (n1 < n3 && n1 > n2)
		return (1);
	else if (n1 > n2 && n1 > n3 && n2 > n3)
		return (2);
	else if (n1 > n2 && n1 > n3 && n2 < n3)
		return (3);
	else if (n1 < n2 && n1 < n3 && n3 < n2)
		return (4);
	else if (n1 < n2 && n1 > n3)
		return (5);
	return (0);
}

void	algos_for_3_elems(t_push *push)
{
	int		c;

	c = define_case_only_for_3_in_stack(push->start_a);
	if (c == 1)
		p_sa(push);
	else if (c == 2)
	{
		p_sa(push);
		p_rra(push);
	}
	else if (c == 3)
		p_ra(push);
	else if (c == 4)
	{
		p_sa(push);
		p_ra(push);
	}
	else if (c == 5)
		p_rra(push);
	return ;
}

void	choose_algos(t_push *push)
{
	int	kol_vo;

	kol_vo = kol_vo_elementov_v_stacke(push->start_a);
	if (!push->start_a || kol_vo == 1 || is_push_sorted(push))
		return ;
	else if (kol_vo == 2)
		algos_for_2_elems(push);
	else if (kol_vo == 3)
		algos_for_3_elems(push);
	else
		algos_for_more_elems(push);
}
