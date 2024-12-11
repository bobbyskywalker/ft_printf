/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarbacz <agarbacz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:26:50 by agarbacz          #+#    #+#             */
/*   Updated: 2024/12/06 18:00:28 by agarbacz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// SECTION: INCLUDES
# include "../lib/libft/libft.h"
# include <assert.h>
# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// SECTION: FUNCS
int	ft_printf(const char *format, ...);
int	print_char(char c);
int	print_str(char *str);
int	print_hex(uintptr_t arg, int case_p);
int	print_ptr(uintptr_t ptr);
int	print_int(int nb);
int	print_uint(unsigned int nb);

#endif