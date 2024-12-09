#include "../includes/printf.h"

int print_char(char c)
{
    return (write(1, &c, 1));
}

int print_str(char *str)
{
    if (!str)
        return (write(1, "(null)", 6));
    return (write(1, str, ft_strlen(str)));
}