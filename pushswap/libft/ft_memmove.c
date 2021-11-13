/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sali <sali@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 13:05:21 by sali              #+#    #+#             */
/*   Updated: 2021/10/09 16:20:02 by sali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*d_dst;
	char	*s_src;

	d_dst = (char *)dst;
	s_src = (char *)src;
	i = 0;
	if (!d_dst && !s_src)
		return (NULL);
	if (s_src < d_dst)
	{
		while (len > 0)
		{
			(d_dst)[len - 1] = (s_src)[len - 1];
			len--;
		}
	}
	while (i < len)
	{
		(d_dst)[i] = (s_src)[i];
		i++;
	}
	return (d_dst);
}
