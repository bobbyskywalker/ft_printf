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

// TODO: 1.to hex conversion, to unsigned int conversion,
// 2.to hex address conversion,
// 3.error handling
static void	cnv(const char *format, va_list args)
{
	if (*format == 'c')
		ft_putchar_fd(va_arg(args, char), 1);
	else if (*format == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (*format == 'p')
		return ;
	else if (*format == 'd' || *format == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (*format == 'u')
		// putnbr modify to print unsigned only
		ft_putnbr_fd(va_arg(args, unsigned int), 1);
	else if (*format == 'x')
		return ;
	else if (*format == 'X')
		return ;
	else if (*format == '%')
		ft_putchar_fd('%', 1);
	else
		return ;
}

// retval: no_read chars OR EOF on error
int	ft_printf(const char *format, ...)
{
	va_list	arg_list;

	va_start(arg_list, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (ft_strchr("cspdiuxX%", format[0]))
				cnv(format, arg_list);
		}
		else
			ft_putchar_fd(*format, 1);
		format++;
	}
	va_end(arg_list);
	return (0);
}
