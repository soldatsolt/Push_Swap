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

void	rb_n_times(t_push *push, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		rb(push);
		ft_putstr("rb\n");
		i++;
	}
}

void	ra_n_times(t_push *push, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ra(push);
		ft_putstr("ra\n");
		i++;
	}
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

void	p_sa(t_push *push)
{
	sa(push);
	ft_putstr("sa\n");
}

void	p_sb(t_push *push)
{
	sb(push);
	ft_putstr("sb\n");
}

void	p_ss(t_push *push)
{
	ss(push);
	ft_putstr("ss\n");
}

void	p_pa(t_push *push)
{
	pa(push);
	ft_putstr("pa\n");
}

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

void	p_rr(t_push *push)
{
	rr(push);
	ft_putstr("rr\n");
}

void	p_rra(t_push *push)
{
	rra(push);
	ft_putstr("rra\n");
}

void	p_rrb(t_push *push)
{
	rrb(push);
	ft_putstr("rrb\n");
}

void	p_rrr(t_push *push)
{
	rrr(push);
	ft_putstr("rrr\n");
}

int		min_of_2(int a, int b)
{
	if (a == b)
		return (a);
	return ((a > b) ? b : a);
}

int		n_operations_to_up_b_by_rrb(t_push *push, t_stack *b)
{
	int		kolvo;
	t_stack	*tmp;

	tmp = push->start_b;
	kolvo = 0;
	while (tmp != b && tmp)
	{
		tmp = tmp->next;
		kolvo++;
	}
	if (tmp == NULL)
		return (-1);
	return (kol_vo_elementov_v_stacke(push->start_b) - kolvo);
}

int		n_operations_to_up_b_by_rb(t_push *push, t_stack *b)
{
	int		kolvo;
	t_stack	*tmp;

	tmp = push->start_b;
	kolvo = 0;
	while (tmp != b && tmp)
	{
		tmp = tmp->next;
		kolvo++;
	}
	if (tmp == NULL)
		return (-1);
	return (kolvo);
}

int		n_operations_to_up_a_by_rra(t_push *push, t_stack *a)
{
	int		kolvo;
	t_stack	*tmp;

	tmp = push->start_a;
	kolvo = 0;
	while (tmp != a && tmp)
	{
		tmp = tmp->next;
		kolvo++;
	}
	if (tmp == NULL)
		return (-1);
	return (kol_vo_elementov_v_stacke(push->start_a) - kolvo);
}

int		n_operations_to_up_a_by_ra(t_push *push, t_stack *a)
{
	int		kolvo;
	t_stack	*tmp;

	tmp = push->start_a;
	kolvo = 0;
	while (tmp != a && tmp)
	{
		tmp = tmp->next;
		kolvo++;
	}
	if (tmp == NULL)
		return (-1);
	return (kolvo);
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
	while (min_element < max_element && !is_push_sorted(push))
	{
		while (push->start_a->n != min_element)
		{
			ra(push);
			ft_putstr("ra\n");
		}
		pb_n_times(push, 1);
		min_element++;
	}
	pa_n_times(push, kol_vo_elementov_v_stacke(push->start_b));
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

t_stack	*find_that_b_stack(t_push *push, int n)
{
	t_stack	*tmp_b;

	tmp_b = push->start_b;
	while (tmp_b && n)
	{
		tmp_b = tmp_b->next;
		n--;
	}
	return (tmp_b);
}



int		number_operations_to_put_b_to_a(t_push *push, int n)
{
	int		number;
	t_stack	*tmp_b;
	t_stack	*tmp_a;
	int		min_a;
	int		min_diffirence;

	number = 0;
	min_a = INT_MAX;
	tmp_a = push->start_a;
	if (push->start_b)
		tmp_b = find_that_b_stack(push, n);
	else
		return (0);
	while (tmp_a && min_a > 1)
	{
		if ((tmp_b->n > tmp_a->n) && (tmp_b->n - tmp_a->n < min_a)) // нужно считать для подходящего места (В > А = min)
		{
			min_a = number;
		}
		tmp_a = tmp_a->next;
		number++;
	}
	number += n;
	return (number);
}

t_stack	*elem_n_of_stack(t_stack *stack, int n)
{
	int	i;

	i = 0;
	if (!stack)
		return (NULL);
	while (i < n && stack)
	{
		stack = stack->next;
		i++;
	}
	return (stack);
}

void	algos_for_5_elems(t_push *push)
{
	int	i;
	int	min_number_op;
	int	min_number_op_a;

	i = 0;
	min_number_op = INT_MAX;
	// if (push->start_a->n > push->start_a->next->n)
	// 	p_sa(push);
	// while (kol_vo_elementov_v_stacke(push->start_a) > 3)
	// 	p_pb(push);
	// algos_for_3_elems(push);

	// TODO: НУЖНО НАЙТИ, КОНКРЕТНО В КАКОЕ МЕСТО В А ВСТАВИТЬ ДАННЫЙ ЭЛЕМЕНТ СТЕКА В

	// while (push->start_b)
	// {
	// 	while (i < kol_vo_elementov_v_stacke(push->start_b))
	// 	{
	// 		if (min_number_op > number_operations_to_put_b_to_a(push, i))
	// 		{
	// 			min_number_op = i;
	// 			min_number_op_a = number_operations_to_put_b_to_a(push, i);
	// 		}
	// 		i++;
	// 	}
	// 	ra_n_times(push, min_number_op);
	// 	rb_n_times(push, min_number_op_a - min_number_op - 1);
	// 	p_pa(push);
	// 	i = 0;
	// 	min_number_op = INT_MAX;
	// }
	// printf("elem %d\nrb %d\nrrb %d\n", elem_n_of_stack(push->start_b, 4)->n, n_operations_to_up_b_by_rb(push, elem_n_of_stack(push->start_b, 4)), n_operations_to_up_b_by_rrb(push, elem_n_of_stack(push->start_b, 4)));
	krasivo_vivod_check(push);
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
	else if (kol_vo <= 5)// ТУТ ДОДЕЛАТЬ НОРМАЛЬНО
		algos_for_5_elems(push);
	else
		algos2(push);
}

/*
**
**
**
*/

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
	choose_algos(push);
	free_push(push);
	// krasivo_vivod_check(push);
	return (0);
}
