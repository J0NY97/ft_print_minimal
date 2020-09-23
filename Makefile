NAME = a.out
SRCS = ./main.c\
		./ft_printf.c\
		./input_parser.c\
		./put_functions.c
OBJS = ./*.o
INCLUDES = ./libft/libft.a
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@gcc -o $(NAME) $(SRCS) $(INCLUDES) 
	@echo "$(NAME) was successfully created."

clean:
	@/bin/rm -f $(OBJS)
	@echo "$(NAME) was cleaned."

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean, all, re, fclean
