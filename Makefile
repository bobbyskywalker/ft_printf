NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I includes -I lib/libft/includes

SOURCES = src/ft_printf.c
OBJECTS = $(SOURCES:.c=.o)

LIBFT_MAKEFILE = lib/libft/Makefile
LIBFT = lib/libft/libft.a

LIBFT_DIR = lib/libft

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT)
	ar rcs $(NAME) $(OBJECTS) $(LIBFT)

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
