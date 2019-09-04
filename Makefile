NAME1 = checker
NAME2 = push_swap
NAME = $(NAME1) $(NAME2)
MAKE = make
override G += 
FLAGS = -Wall -Wextra -Werror
SRCS1 = main_checker.c stacks_operations.c rr_.c checker.c frees.c atoi_for_checker.c s_.c r_.c
SRCS2 = main_push_swap.c stacks_operations.c rr_.c checker.c frees.c atoi_for_checker.c s_.c r_.c\
p_operations.c n_operations_to_up.c start_alg.c move_stacks.c elements_of_stack.c\
p_operations1.c p_operations2.c p_operations3.c
OBJS1 = $(SRCS1:.c=.o)
OBJS2 = $(SRCS2:.c=.o)
LIBFT = ./libft/libft.a
all: $(NAME)

$(NAME):
	@gcc ./libft/libft.a $(SRCS1) -o $(NAME1)
	@gcc ./libft/libft.a $(SRCS2) -o $(NAME2)

g:
	@gcc ./libft/libft.a $(SRCS1) -g -o $(NAME1)
	@gcc ./libft/libft.a $(SRCS2) -g -o $(NAME2)

clean:
	@$(MAKE) -C ./libft clean
	@rm -f *.o

fclean: clean
	@rm -f $(NAME1)
	@rm -f $(NAME2)

re: fclean all

rerun: re
	@./$(NAME1)

lib:
	@$(MAKE) -C ./libft re
	@$(MAKE) -C ./libft clean

git:
	git add .
	git commit -am "$(G)"
	git push
