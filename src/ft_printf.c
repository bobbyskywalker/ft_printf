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

// error handling?
// tester: throw the output to a file, compare the outputs (python?)
// with C assert look check the return values
static void	cnv(const char *format, int *printed_chars, va_list args)
{
	if (*format == 'c')
		*printed_chars += print_char(va_arg(args, int));
	else if (*format == 's')
		*printed_chars += print_str(va_arg(args, char *));
	else if (*format == 'p')
		*printed_chars += print_ptr(va_arg(args, uintptr_t));
	else if (*format == 'd' || *format == 'i')
		*printed_chars += print_int(va_arg(args, int));
	else if (*format == 'u')
		*printed_chars += print_uint(va_arg(args, unsigned int));
	else if (*format == 'x')
		*printed_chars += print_hex(va_arg(args, unsigned int), 1);
	else if (*format == 'X')
		*printed_chars += print_hex(va_arg(args, unsigned int), 2);
	else if (*format == '%')
		*printed_chars += print_char('%');
}

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
	ft_printf("integer: %i\n", 42);
	ft_printf("unsigned int: %u\n", -42);
	printf("og unsigned int: %i\n", -42);
	ft_printf("pointer: %p\n", 42);
	return 0;
}