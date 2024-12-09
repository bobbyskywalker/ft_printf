/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarbacz <agarbacz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:07:00 by agarbacz          #+#    #+#             */
/*   Updated: 2024/12/06 18:03:07 by agarbacz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"
#include "../lib/libft/libft.h"

// function calculates the len of a potential
// hexstring based off an int argument
// bitwise right shift calculates the length
// +3 is used for rounding up
static int hexstr_length(unsigned int n) {
    int bit_length;

	bit_length = 0;
	if (!n) 
        return 1;
    while (n > 0) {
        bit_length++;
        n >>= 1;
    }
    return (bit_length + 3) / 4;
}

static int calc_hexstr(char *res, int arg, int case_p) 
{
	char *hex_dict;
	int	mod;
	int i;

	if (case_p == 1)
		hex_dict = "0123456789abcdef";
	else
		hex_dict = "0123456789ABCDEF";
	i = 0;
	while (arg)
    {
        mod = arg % 16;
        res[i] = hex_dict[mod];
        arg /= 16;
        i++;
    }
    return (i);
}

// case param: 1 - lowercase, 2 - uppercase
int	print_hex(int arg, int case_p)
{
	char	*res;
	int		i;

	if (!arg)
	{
		write(1, "0", 1);
		return 1;
	} 
	else if (arg == INT_MIN)
	{
		write(1, "-2147483648", 11);
		return 11;
	}
	if (arg < 0)
	{
		write(1, "-", 1);
		arg = -arg;
	}
	res = ft_calloc(hexstr_length(arg) + 1, sizeof(char));
	if (!res)
		return (-1);
	i = calc_hexstr(res, arg, case_p);
	while (i > 0)
		write(1, &res[--i], 1);
	free(res);
	return (hexstr_length(arg));
}
