/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sali <sali@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:03:45 by sali              #+#    #+#             */
/*   Updated: 2021/11/01 16:04:37 by sali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_ppoint(unsigned long long int s, int *i, t_list *plist)
{
	if (s == 0)
	{
		write(1, "0x0", 3);
		plist-> len += 3;
		*i = *i + 1;
	}
	else
	{
		write(1, "0x", 2);
		plist-> len += 2;
		ft_putbase(s, "0123456789abcdef", plist);
		*i = *i + 1;
	}
}
