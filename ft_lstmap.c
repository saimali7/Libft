/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sali <sali@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 20:36:11 by sali              #+#    #+#             */
/*   Updated: 2021/10/12 16:24:32 by sali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*hold;
	t_list	*temp;

	temp = NULL;
	while (lst != NULL)
	{
		hold = ft_lstnew(f(lst->content));
		if (hold == NULL)
		{
			ft_lstclear(&temp, del);
			return (NULL);
		}
		ft_lstadd_back(&temp, hold);
		lst = lst->next;
	}
	return (temp);
}
