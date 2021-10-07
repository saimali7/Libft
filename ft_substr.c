/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sali <sali@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 09:11:12 by sali              #+#    #+#             */
/*   Updated: 2021/10/07 09:24:14 by sali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t i;
	char *ptr;
	
	i = 0;
	if(!s)
		return (NULL);
	if(ft_strlen(s) < len)
		return (ft_calloc(1 , 1));
	ptr = (char *) malloc(len + 1 * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	while(s[i] != '\0' && i < len)
	{
		ptr[i] = s[start];
		start++;
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
