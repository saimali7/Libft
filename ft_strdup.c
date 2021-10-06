/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sali <sali@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:14:42 by sali              #+#    #+#             */
/*   Updated: 2021/10/06 17:59:27 by sali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t i;
	size_t len;
	char *ptr;

	i = 0;
	len = ft_strlen(s1);
	ptr = (char *) malloc((len + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	while(s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	return (ptr);
}
