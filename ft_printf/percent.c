#include "ft_printf.h"

void	ft_ppercent(int a, int *i)
{
	write(1,"%",1);
	*i = *i + 2;
}