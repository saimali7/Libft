#include "ft_printf.h"

void	ft_putun(unsigned n)
{
		if(n < 0)
		{
			n = n * -1;
			ft_putchar('-');	
		}
		if (n >= 10)
		{
			ft_putun(n / 10);
			ft_putchar(n % 10 + '0');
		}
		if (n < 10)
			ft_putchar(n + '0');
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		write(1,"-2147483648",11);
	}
	else
	{
		if(n < 0)
		{
			n = n * -1;
			ft_putchar('-');	
		}
		if (n >= 10)
		{
			ft_putnbr(n / 10);
			ft_putchar(n % 10 + '0');
		}
		if (n < 10)
			ft_putchar(n + '0');
	}
}
