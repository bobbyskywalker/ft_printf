/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarbacz <agarbacz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:26:50 by agarbacz          #+#    #+#             */
/*   Updated: 2024/12/06 18:00:28 by agarbacz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

// SECTION: INCLUDES
# include "../lib/libft/libft.h"
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// SECTION: FUNCS
int		ft_printf(const char *format, ...);
void	print_hex(char *arg, int case_p);
void	print_address(char *arg);

#endif