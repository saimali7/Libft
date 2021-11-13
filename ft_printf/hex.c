/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sali <sali@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:02:22 by sali              #+#    #+#             */
/*   Updated: 2021/11/01 16:02:35 by sali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_phex(unsigned int n, int *i, t_list *plist)
{
	if (n == 0)
	{
		ft_putchar('0', plist);
		*i = *i + 1;
	}
	else
	{
		if (plist->hash == 1)
		{
			write(1, "0x", 2);
			plist->len += 2;
		}
		ft_putbase(n, "0123456789abcdef", plist);
		*i = *i + 1;
	}
}
