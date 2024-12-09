NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -I lib/libft

SOURCES = src/ft_printf.c src/print_hex.c src/print_nums.c src/print_ptr.c src/print_str.c
OBJECTS = $(SOURCES:.c=.o)

LIBFT_MAKEFILE = lib/libft/Makefile
LIBFT = lib/libft/libft.a

LIBFT_DIR = lib/libft

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT)
	ar -rc $(NAME) $(OBJECTS) $(LIBFT)

clean:
	rm -f $(OBJECTS)
	make -C lib/libft clean  # Clean libft as well

fclean: clean
	rm -f $(NAME)
	make -C lib/libft fclean  # Fully clean libft

re: fclean all

$(LIBFT):
	make -C lib/libft

.PHONY: all clean fclean re bonus
