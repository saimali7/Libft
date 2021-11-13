#include "pushswap.h"

int	zero_one(char *str)
{
	if (ft_strncmp(str, "0", 2) == 0)
		return (1);
	else if (ft_strncmp(str, "-1", 3) == 0)
		return (1);
	return (0);
}

int	digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}