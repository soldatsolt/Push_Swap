#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"
# define INT_MAX (2147483647)
# define INT_MIN (-2147483648)
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

void				free_push(t_push *push);
t_push				*create_push(void);
void				put_n_to_a(t_push *push, int n);
void				put_n_to_b(t_push *push, int n);
t_stack				*create_stack(void);
void				sa(t_push *push);
void				sb(t_push *push);
void				ss(t_push *push);
void				pa(t_push *push);
void				pb(t_push *push);
void				ra(t_push *push);
void				rb(t_push *push);
void				rr(t_push *push);
void				rra(t_push *push);
void				rrb(t_push *push);
void				rrr(t_push *push);
void				print_stack(t_stack *stack);	
int					ft_atoi_for_checker(t_push *push, char *str);
void				check_for_duplicates(t_push *push);
void				checker(t_push *push);
void				checker_stdin(t_push *push, char *str);
void				error_checker_stder(t_push *push, char *str);

#endif
