#include "push_swap.h"

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
