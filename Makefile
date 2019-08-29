NAME1 = checker
NAME2 = push_swap
NAME = $(NAME1) $(NAME2)
MAKE = make
override G += 
FLAGS = -Wall -Wextra -Werror
SRCS1 = main_checker.c stacks_operations.c operations.c checker.c
SRCS2 = main_push_swap.c stacks_operations.c operations.c checker.c
OBJS1 = $(SRCS1:.c=.o)
OBJS2 = $(SRCS2:.c=.o)
LIBFT = ./libft/libft.a
all: $(NAME)

$(NAME):
	@gcc ./libft/libft.a $(SRCS1) -g -o $(NAME1)
	@gcc ./libft/libft.a $(SRCS2) -g -o $(NAME2)

g:
	@gcc -g $(SRCS1) -o $(NAME1)

clean:
	@$(MAKE) -C ./libft clean

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
