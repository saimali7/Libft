/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sali <sali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:57:43 by sali              #+#    #+#             */
/*   Updated: 2021/10/12 16:36:02 by sali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_splitsize(char const *s, char c)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i - 1] != c)
			len++;
		i++;
	}
	if (s[i] == '\0' && s[i - 1] != c)
		len++;
	return (len);
}

static	char	**ft_nullfree(char **ptr, int j)
{
	while (j >= 0 && ptr[j] == NULL)
	{
		free (ptr[j]);
		j--;
	}
	free(ptr);
	ptr = NULL;
	return (NULL);
}

static	char	**ft_splitnow(char const *s, char c, char **ptr)
{
	size_t	i;
	int		j;
	int		size;

	size = 0;
	i = 0;
	j = 0;
	while (s[i] == c && i <= ft_strlen(s))
		i++;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && s[i] != '\0')
			size++;
		if ((s[i] == '\0' || s[i] == c) && s[i - 1] != c)
		{
			ptr[j] = ft_substr(s, i - size, size);
			if (ptr[j] == NULL)
				return (ft_nullfree(ptr, j));
			size = 0;
			j++;
		}
		i++;
	}
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		arrysize;

	if (s)
	{
		arrysize = 0;
		if (s[0] != '\0')
			arrysize = ft_splitsize(s, c);
		ptr = (char **) malloc((arrysize + 1) * sizeof(char *));
		if (ptr == NULL)
			return (NULL);
		if (s[0] != '\0')
			ptr = ft_splitnow(s, c, ptr);
		ptr[arrysize] = NULL;
		return (ptr);
	}
	return (0);
}
