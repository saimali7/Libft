/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sali <sali@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 13:48:59 by sali              #+#    #+#             */
/*   Updated: 2021/10/06 18:02:24 by sali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t d_len;
	size_t s_len;
	size_t t_len;

	i = 0;
	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	t_len = d_len + s_len;
	if(!src)
		return (d_len);
	if(d_len > dstsize)
		return (d_len + dstsize);
	while(src[i] != '\0' && i < dstsize - d_len - 1)
	{
		dst[d_len] = src[i];
		d_len++;
		i++;
	}
	dst[i] = '\0';
	return (t_len);
}
