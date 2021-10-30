#include "ft_printf.h"

void	ft_pcaphex(unsigned int n, int *i)
{
	ft_putbase(n, "0123456789ABCDEF");
	*i = *i + 2;
}