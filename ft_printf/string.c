#include "ft_printf.h"

void	ft_pstr(char *str, int *i)
{
	size_t len;

	if(str == NULL)
	{
		write(1,"(null)",6);
		*i = *i + 2;
	}
	else
	{		
		len = ft_strlen(str);
		write(1 ,str ,len);
		*i = *i + 2;
	}
}