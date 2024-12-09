
#include "../includes/printf.h"

static int get_len(uintptr_t ptr)
{
    int p_len;

    p_len = 0;
    while (ptr)
    {
        p_len++;
        ptr /= 16;
    }
    return (p_len);
}

int print_ptr(uintptr_t ptr)
{
    int len;

    if (!ptr)
        return (write(1, "(nil)", 5));
    else
    {
        len = write(1, "0x", 2);
        print_hex(ptr, 1);
        len += get_len(ptr);
    }
    return (len);
}

// int main()
// {
//     int *ptr;
//     int a = 16;
//     ptr = &a;
//     printf("%p", ptr);
//     return 0;
// }