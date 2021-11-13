/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sali <sali@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:59:35 by sali              #+#    #+#             */
/*   Updated: 2021/11/01 16:09:51 by sali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putun(unsigned n, t_list *plist)
{
	if (n < 0)
	{
		n = n * -1;
		ft_putchar('-', plist);
	}
	if (n >= 10)
	{
		ft_putun(n / 10, plist);
		ft_putchar(n % 10 + '0', plist);
	}
	if (n < 10)
		ft_putchar(n + '0', plist);
}

void	ft_putnbr(int n, t_list *plist)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		plist->len += 11;
	}
	else
	{
		if (n < 0)
		{
			n = n * -1;
			ft_putchar('-', plist);
		}
		if (n >= 10)
		{
			ft_putnbr(n / 10, plist);
			ft_putchar(n % 10 + '0', plist);
		}
		if (n < 10)
			ft_putchar(n + '0', plist);
	}
}
