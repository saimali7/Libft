#include "ft_printf.h"

void	ft_punsinged(unsigned int n, int *i)
{
	ft_putun(n);
	*i = *i + 2;
}