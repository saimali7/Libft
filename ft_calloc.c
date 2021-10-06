/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sali <sali@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:08:54 by sali              #+#    #+#             */
/*   Updated: 2021/10/06 16:14:14 by sali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t i;
	void *ptr;

	i = 0
	ptr = malloc(count * size);
	if (ptr = NULL)
		return (NULL);
	while (i < size * count)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
