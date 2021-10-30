#include "ft_printf.h"

void	ft_pint(int num, int *i)
{
	ft_putnbr(num);
	*i = *i + 2;
}