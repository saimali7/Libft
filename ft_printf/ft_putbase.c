#include "ft_printf.h"

void    ft_putbase(unsigned long long int num, char *base)
{
    int baselen;

    baselen = 0;
    baselen = ft_strlen(base);
    if(num > 0)
    {
        ft_putbase(num / baselen, base);
        ft_putchar(base[num % baselen]);
    }
}