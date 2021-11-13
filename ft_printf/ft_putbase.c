/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sali <sali@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:57:24 by sali              #+#    #+#             */
/*   Updated: 2021/11/01 15:58:45 by sali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putbase(unsigned long long num, char *base, t_list *plist)
{
	int	baselen;

	baselen = 0;
	baselen = ft_strlen(base);
	if (num > 0)
	{
		ft_putbase(num / baselen, base, plist);
		ft_putchar(base[num % baselen], plist);
	}
}
