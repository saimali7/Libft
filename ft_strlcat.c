/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sali <sali@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 13:48:59 by sali              #+#    #+#             */
/*   Updated: 2021/10/07 13:14:44 by sali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t d_len;
	size_t s_len;
	size_t t_len;
	size_t temp;

	i = 0;
	d_len = ft_strlen(dst);
	temp = d_len;
	s_len = ft_strlen(src);
	t_len = d_len + s_len;
	if(!src[i])
		return (d_len);
	if(d_len > dstsize)
		return (s_len + dstsize);
	while(src[i] != '\0' && i < dstsize - temp - 1)
	{
		dst[d_len] = src[i];
		d_len++;
		i++;
	}
	dst[d_len] = '\0';
	return (t_len);
}
