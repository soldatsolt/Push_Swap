#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"

typedef	struct		s_stack
{
	int				n;
	struct s_stack	*next;
}					t_stack;

typedef	struct		s_push
{
	t_stack			*a;
	t_stack			*b;
	t_stack			*start_a;
	t_stack			*start_b;
}					t_push;

#endif
