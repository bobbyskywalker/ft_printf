NAME = libftprintf.a
LIBFT = lib/libft/
SRCS = src/ft_printf.c src/print_hex.c src/print_ptr.c src/print_nums.c src/print_str.c
OBJS = $(SRCS:.c=.o)
all: $(NAME)

makelibft:
	make -C $(LIBFT) bonus
	cp $(LIBFT)libft.a .
	mv libft.a $(NAME)

$(NAME): $(OBJS) | makelibft
	ar rcs $(NAME) $(OBJS)

clean:
	make -C $(LIBFT) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(LIBFT) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all makelibft clean fclean re


