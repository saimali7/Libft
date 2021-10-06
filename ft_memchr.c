/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sali <sali@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:09:57 by sali              #+#    #+#             */
/*   Updated: 2021/10/06 15:20:10 by sali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

void	*memchr(const void *s, int c, size_t n)
{
	size_t i;

	i = 0
	while (i < n)
	{
		if(((unsigned char *)s)[i] == (unsigned char)c)
			return (&s[i]);
		i++;
	}
	return (NULL);
}
