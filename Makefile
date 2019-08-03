NAME = push_swap
MAKE = make
override G += 
FLAGS = -Wall -Wextra -Werror
SRCS = main.c
OBJS = $(SRCS:.c=.o)
LIBFT = ./libft/libft.a
all: $(NAME)

$(NAME): $(LIBFT)
	@gcc -I /usr/local/include ./libft/libft.a $(FLAGS) $(SRCS) -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit -o $(NAME)

g:
	@gcc -g $(SRCS) -o $(NAME)

clean:
	@$(MAKE) -C ./libft clean

fclean: clean
	@rm -f $(NAME)

re: fclean all

rerun: re
	@./$(NAME)

$(LIBFT):
	@$(MAKE) -C ./libft re

git:
	git add .
	git commit -am "$(G)"
	git push
