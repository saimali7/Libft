/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sali <sali@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:46:22 by sali              #+#    #+#             */
/*   Updated: 2021/10/09 16:31:53 by sali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_setcheck(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*ptr;

	if (!set || !s1)
		return (NULL);
	j = ft_strlen(s1) - 1;
	i = 0;
	while (ft_setcheck(s1[i], set) == 1)
		i++;
	while (ft_setcheck(s1[j], set) == 1)
		j--;
	ptr = ft_substr(s1, i, j - i + 1);
	if (ptr == NULL)
		return (NULL);
	return (ptr);
}
