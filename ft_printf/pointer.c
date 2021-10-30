#include "ft_printf.h"

void	ft_ppoint(unsigned long long int s, int *i)
{
	write(1,"0x",2);
	ft_putbase(s,"0123456789abcdef");
	*i = *i + 2;
}