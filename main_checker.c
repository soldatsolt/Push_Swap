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
			start_atoi_for_checker(push, argv[i]);
			i++;
		}
	}
	check_for_duplicates(push);
	if (argc >= 2)
		while (get_next_line(0, &str) > 0)
		{
			checker_stdin(push, str);
			free(str);
			str = NULL;
		}
	checker(push);
	free_push(push);
	return (0);
}
