#include "push_swap.h"

int	main(void)
{
	int		o;
	char	*str;
	int		n;
	int		tmp;
	int		i;

	n = 0;
	i = 0;
	o = open("res", O_RDONLY);
	while (get_next_line(o, &str))
	{
		tmp = ft_atoi(str);
		n += tmp;
		i++;
		ft_strdel(&str);
	}
	close(o);
	printf("MEAN IS %d\n", n / i);
	return (0);
}
