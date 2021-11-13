/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sali <sali@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:05:26 by sali              #+#    #+#             */
/*   Updated: 2021/11/01 16:05:59 by sali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pstr(char *str, int *i, t_list *plist)
{
	size_t	len;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		plist->len += 6;
		*i = *i + 1;
	}
	else
	{		
		len = ft_strlen(str);
		write(1, str, len);
		plist->len += len;
		*i = *i + 1;
	}
}
