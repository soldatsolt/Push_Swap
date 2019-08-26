#include "push_swap.h"

void	krasivo_vivod_check(t_push *push)
{
	t_stack *tmp_a;
	t_stack *tmp_b;

	tmp_a = push->start_a;
	tmp_b = push->start_b;
	ft_putstr("__A__|__B__\n");
	while (tmp_a || tmp_b)
	{
		ft_putstr("__");
		if (tmp_a)
			ft_putnbr(tmp_a->n);
		else
			ft_putstr("^");
		if (tmp_a && tmp_a->n < 10)
			ft_putstr("__|__");
		else
			ft_putstr("_|__");
		if (tmp_b)
			ft_putnbr(tmp_b->n);
		else
			ft_putstr("^");
		if (tmp_b && tmp_b->n < 10)
			ft_putstr("__\n");
		else
			ft_putstr("_\n");
		if (tmp_a)
			tmp_a = tmp_a->next;
		if (tmp_b)
			tmp_b = tmp_b->next;
	}
}

int		main(int argc, char **argv)
{
	t_push	*push;
	int		i;
	char	*str;

	i = 1;
	push = create_push();
	if (argc >= 2)
	{
		while (i < argc)
		{
			put_n_to_a(push, ft_atoi_for_checker(push, argv[i]));
			i++;
		}
	}
	check_for_duplicates(push);
	while (get_next_line(0, &str) > 0)
	{
		checker_stdin(push, str);
		free(str);
	}
	checker(push);
	free_push(push);
	return (0);
}
