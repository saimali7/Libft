/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sali <sali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 13:48:59 by sali              #+#    #+#             */
/*   Updated: 2021/10/12 11:40:05 by sali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	d_len;
	size_t	s_len;
	size_t	t_len;

	i = 0;
	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	t_len = d_len;
	if (dstsize == 0)
		t_len = s_len;
	if (d_len < dstsize)
		t_len += s_len;
	else
		t_len = dstsize + s_len;
	while (src[i] != '\0' && d_len + 1 < dstsize)
	{
		dst[d_len] = src[i];
		d_len++;
		i++;
	}
	dst[d_len] = '\0';
	return (t_len);
}
