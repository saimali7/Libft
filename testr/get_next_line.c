/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sali <sali@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 13:08:29 by sali              #+#    #+#             */
/*   Updated: 2021/10/24 13:08:34 by sali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	new_line(char *main)
{
	int	i;
	int	hold;

	hold = 0;
	i = 0;
	if (main == NULL)
		return (0);
	while (main[i] != '\0')
	{
		if (main[i] == '\n')
		{
			hold = 1;
			i++;
			break ;
		}
		i++;
	}
	if (hold == 1)
		return (i);
	return (0);
}

char	*ft_rtstr(char **main, int *rd)
{
	int		i;
	int		len;
	char	*ptr;
	char	*buff;

	ptr = NULL;
	buff = NULL;
	i = 0;
	len = (new_line(*main));
	if (len > 0)
	{
		ptr = ft_substr(*main, 0, len);
		buff = ft_substr(*main, len, ft_strlen(*main) - len);
		ft_free(main);
		*main = buff;
	}
	else if (*rd == 0 && main != NULL)
	{
		ptr = ft_substr(*main, 0, ft_strlen(*main));
		ft_free(main);
	}
	return (ptr);
}

char	*ft_rd(int fd, char *buff, int *rd)
{
	if (*rd > 0)
	{
		buff = (char *) ft_calloc(BUFFER_SIZE + 1, 1);
		*rd = read(fd, buff, BUFFER_SIZE);
		if (*rd <= 0)
		{
			ft_free (&buff);
			return (NULL);
		}
		return (buff);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*main;
	char		*buff;
	int			rd;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	rd = 1;
	buff = NULL;
	while (rd > 0)
	{
		ft_free(&buff);
		buff = ft_rd(fd, buff, &rd);
		main = ft_strjoin(main, buff, &main);
		if (new_line(main) != 0)
		{
			ft_free(&buff);
			return (ft_rtstr(&main, &rd));
		}
	}
	if (new_line(main) != 0 || ft_strlen(main) > 0)
		return (ft_rtstr(&main, &rd));
	else
		ft_free(&main);
	return (NULL);
}
