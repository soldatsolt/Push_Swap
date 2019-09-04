#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"
# define INT_MAX (2147483647)
# define INT_MIN (-2147483648)
typedef	struct		s_stack
{
	int				n;
	int				f;
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
void				check_for_duplicates(t_push *push);
void				checker(t_push *push);
void				checker_stdin(t_push *push, char *str);
void				error_checker_stder(t_push *push, char *str);
void				krasivo_vivod_check(t_push *push);
void				start_atoi_for_checker(t_push *push, char *str);
int					ft_atoi_for_checker(char **all_str, t_push *push, char *str);
int					is_push_sorted(t_push *push);
void				free_all_str(char **all_str);
void				error_checker_stder1(char **all_str, t_push *push, char *str);
void				pa_n_times(t_push *push, int n);
void				pb_n_times(t_push *push, int n);
void				rrb_n_times(t_push *push, int n);
void				rr_n_times(t_push *push, int n);
void				rrr_n_times(t_push *push, int n);
void				rb_n_times(t_push *push, int n);
void				rra_n_times(t_push *push, int n);
void				ra_n_times(t_push *push, int n);
void				p_sa(t_push *push);
void				p_pa(t_push *push);
void				p_pb(t_push *push);
void				p_ra(t_push *push);
void				p_rb(t_push *push);
void				p_rr(t_push *push);
void				p_rra(t_push *push);
void				p_rrb(t_push *push);
void				p_rrr(t_push *push);
int					n_operations_to_up_b_by_rrb(t_push *push, t_stack *b);
int					n_operations_to_up_b_by_rb(t_push *push, t_stack *b);
int					n_operations_to_up_a_by_rra(t_push *push, t_stack *a);
int					n_operations_to_up_a_by_ra(t_push *push, t_stack *a);
int					kol_vo_elementov_v_stacke(t_stack *stack);
void				choose_algos(t_push *push);
void				algos_for_3_elems(t_push *push);
void				algos_for_more_elems(t_push *push);
void				move_stacks_a_b_to_top(t_push *push, t_stack *a, t_stack *b);
void				move_stack_b_to_top(t_push *push, t_stack *b);
void				move_stack_a_to_top(t_push *push, t_stack *a);
int					number_operations_to_put_b_to_a(t_push *push, t_stack *a, t_stack *b);
int					min_of_2(int a, int b);
void				choose_best_a_b_stacks_to_move(t_push *push, \
t_stack 			**a_stack_to_move, t_stack **b_stack_to_move);
t_stack				*min_elem_of_stack(t_stack *stack);
t_stack				*on_min_elem_a(t_push *push);
t_stack				*elem_n_of_stack(t_stack *stack, int n);
t_stack				*stack_a_to_put_b_on_it(t_push *push, t_stack *b);

#endif
