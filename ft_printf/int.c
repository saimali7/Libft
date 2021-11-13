/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sali <sali@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:03:08 by sali              #+#    #+#             */
/*   Updated: 2021/11/01 16:03:10 by sali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pint(int num, int *i, t_list *plist)
{
	if (plist->space == 1 && num >= 0 && plist->plus == 0)
	{
		write(1, " ", 1);
		plist->len += 1;
	}
	else if (plist->plus == 1 && num >= 0)
	{
		write(1, "+", 1);
		plist->len += 1;
	}
	ft_putnbr(num, plist);
	*i = *i + 1;
}
