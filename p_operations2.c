#include "push_swap.h"

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

void	rra_n_times(t_push *push, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		rra(push);
		ft_putstr("rra\n");
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

void	p_sa(t_push *push)
{
	sa(push);
	ft_putstr("sa\n");
}

void	p_pa(t_push *push)
{
	pa(push);
	ft_putstr("pa\n");
}
