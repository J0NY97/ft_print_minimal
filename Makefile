NAME = libprintf.a
SRCS =	./ft_printf.c\
		./input_parser.c\
		./str_modification.c\
		./special_functions.c\
		./put_functions.c
OBJS = $(SRCS:.c=.o)
INCLUDES = ./libft/libft.a
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) -c $(SRCS) -I $(INCLUDES) 
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJS)
	@make -C libft/ clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all

.PHONY: clean, all, re, fclean
