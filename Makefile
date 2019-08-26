NAME1 = checker
NAME2 = push_swap
NAME = $(NAME1) $(NAME2)
MAKE = make
override G += 
FLAGS = -Wall -Wextra -Werror
SRCS = main.c stacks_operations.c operations.c checker.c
OBJS = $(SRCS:.c=.o)
LIBFT = ./libft/libft.a
all: $(NAME)

$(NAME):
	@gcc ./libft/libft.a $(SRCS) -g -o $(NAME1)

g:
	@gcc -g $(SRCS) -o $(NAME1)

clean:
	@$(MAKE) -C ./libft clean

fclean: clean
	@rm -f $(NAME1)

re: fclean all

rerun: re
	@./$(NAME1)

$(LIBFT):
	@$(MAKE) -C ./libft re
	@$(MAKE) -C ./libft clean

git:
	git add .
	git commit -am "$(G)"
	git push
