/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarbacz <agarbacz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:26:52 by agarbacz          #+#    #+#             */
/*   Updated: 2024/12/06 18:02:45 by agarbacz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"
#include "../lib/libft/libft.h"

// TODO: putnbr & unsigned num func with printed chars return value
// error handling
static void	cnv(const char *format, int *printed_chars, va_list args)
{
	if (*format == 'c')
		*printed_chars += print_char(va_arg(args, int));
	else if (*format == 's')
		*printed_chars += print_str(va_arg(args, char *));
	else if (*format == 'p')
		*printed_chars += print_ptr(va_arg(args, uintptr_t));
	else if (*format == 'd' || *format == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (*format == 'u')
		// putnbr modify to print unsigned only
		ft_putnbr_fd(va_arg(args, unsigned int), 1);
	else if (*format == 'x')
		*printed_chars += print_hex(va_arg(args, unsigned int), 1);
	else if (*format == 'X')
		*printed_chars += print_hex(va_arg(args, unsigned int), 2);
	else if (*format == '%')
		*printed_chars += print_char('%');
}

// retval: no_read chars OR EOF on error
int	ft_printf(const char *format, ...)
{
	va_list	arg_list;
	int	printed_chars;

	printed_chars = 0;
	va_start(arg_list, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (ft_strchr("cspdiuxX%", format[0]))
				cnv(format, &printed_chars, arg_list);
		}
		else
		{
			print_char(*format);
			printed_chars++;
		}
		format++;
	}
	va_end(arg_list);
	return (printed_chars);
}
// debug compilation
// cc -Wall -Wextra -Werror ft_printf.c print_hex.c print_ptr.c  ../lib/libft/libft.a -o tescik
int main()
{
	ft_printf("single char: %c\n", 'A');
	ft_printf("string: %s\n", "Forty-two");
	ft_printf("hexadecimal lowercase: %x\n", 42);
	ft_printf("hexadecimal uppercase: %x\n", 42);
	ft_printf("decimal: %d\n", 42);
	ft_printf("integer: %u\n", 42);
	ft_printf("pointer: %p\n", 42);
	return 0;
}