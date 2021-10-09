/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sali <sali@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 11:28:58 by sali              #+#    #+#             */
/*   Updated: 2021/10/09 11:46:40 by sali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int 	i;
	char 	*ptr;

	if(!s)
		return (NULL);
	i = 0;
	ptr = (char *) malloc(ft_strlen(s) + 1 * sizeof(char));
	if(ptr == NULL)
		return (NULL);
	while(s[i] != '\0')
	{
		ptr[i] = f(i, s[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
