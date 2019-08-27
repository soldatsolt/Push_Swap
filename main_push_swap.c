#include "push_swap.h"































void	algos1(t_push *push)
{
	t_stack	*tmp;
	int		kol_vo_elementov;

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
	while (kol_vo_elementov > -100)
	{
		pb(push);
		kol_vo_elementov -= 2;
	}
	krasivo_vivod_check(push);

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
			put_n_to_a(push, ft_atoi_for_checker(push, argv[i]));
			i++;
		}
	}
	check_for_duplicates(push);
	algos1(push);











	return (0);
}