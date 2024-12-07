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

static int hexstr_length(unsigned int n) {
    if (n == 0) 
        return 1;
    int bit_length = 0;
    while (n > 0) {
        bit_length++;
        n >>= 1;
    }
    return (bit_length + 3) / 4;
}
// TODO: negative values
// case param: 1 - lowercase, 2 - uppercase
void	print_hex(int arg, int case_p)
{
	char	*hex_dict;
	char	*res;
	int		mod;
	int		i;

	res = ft_calloc(hexstr_length(arg) + 1, sizeof(char));
	if (!res)
		return ;
	if (case_p == 1)
		hex_dict = "0123456789abcdef";
	else
		hex_dict = "0123456789ABCDEF";
	if (!arg)
	{
		write(1, "0", 1);
		return ;
	}
	else if (arg < 0)
	{
		if (arg == INT_MIN)
		{
			write(1, "-2147483648", 11);
			return ;
		}
		write(1, "-", 1);
		arg = -arg;
	}
	i = 0;
	while (arg)
    {
        mod = arg % 16;
        res[i] = hex_dict[mod];
        arg /= 16;
        i++;
    }
    while (i > 0)
		write(1, &res[--i], 1);
	free(res);
}
