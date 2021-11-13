/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sali <sali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 20:50:13 by sali              #+#    #+#             */
/*   Updated: 2021/10/10 21:21:07 by sali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_checklen(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len++;
	}
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static	char	*ft_printnbr(char *ptr, int n, int len)
{
	int	i;
	int	hold;

	hold = 0;
	i = 0;
	ptr[len] = '\0';
	if (n < 0)
	{
		ptr[0] = '-';
		i++;
	}
	while (len != i)
	{
		hold = n % 10;
		if (hold < 0)
			hold = hold * -1;
		ptr[len - 1] = hold + '0';
		n = n / 10;
		len--;
	}
	return (ptr);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*ptr;

	if (n == 0)
	{
		ptr = malloc(2 * sizeof(char));
		if (ptr == NULL)
			return (NULL);
		ptr[0] = '0';
		ptr[1] = '\0';
		return (ptr);
	}
	len = ft_checklen(n);
	ptr = (char *) malloc(len + 1 * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ptr = ft_printnbr(ptr, n, len);
	return (ptr);
}
