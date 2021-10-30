#include "ft_printf.h"

void	ft_phex(unsigned int n, int *i)
{
	ft_putbase(n, "0123456789abcdef");
	*i = *i + 2;
}