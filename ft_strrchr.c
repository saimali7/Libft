/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sali <sali@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 14:24:05 by sali              #+#    #+#             */
/*   Updated: 2021/10/07 12:01:52 by sali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
	size_t i;
	int h;

	h = -1;
	i = 0;
	while(s[i] != '\0')
	{
		if(s[i] == (unsigned char)c)
			h = i;
		i++;
	}
	if(s[i] == (unsigned char)c)
		h = i;
	if(h > -1)
		return (&((char *)s)[h]);
	return (NULL);
}
