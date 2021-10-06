/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sali <sali@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:51:16 by sali              #+#    #+#             */
/*   Updated: 2021/10/06 17:33:52 by sali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(const char str)
{
	if(str == '\t' || str == '\n' || str == '\v' || str == '\r' || str == '\f'
			|| str == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	size_t i;
	unsigned int nb;
	int sign;

	i = 0;
	nb = 0;
	sign = 1;
	while (ft_isspace(str[i]) == 1)
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
	}
	if(nb > 2147483647)
		return (0);
	else if (nb > 2147483648)
		return (-1);
	return (nb);
}
