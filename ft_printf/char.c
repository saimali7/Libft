#include "printf.h"

void	ft_pchar(int c, int *i)
{
	write(1,&c,1);
	*i =  *i + 2;
}