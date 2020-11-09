/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwoodwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 19:07:59 by hwoodwri          #+#    #+#             */
/*   Updated: 2020/11/09 20:45:26 by hwoodwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	**list;
	t_list	*tmp;

	if (!lst || !f)
		return (NULL);
	tmp = NULL;
	list = &tmp;
	while (lst)
	{
		new = ft_lstnew(f(lst->content));
		if (!new)
		{
			ft_lstclear(list, del);
			return (NULL);
		}
		ft_lstadd_back(list, new);
		lst = lst->next;
	}
	return (*list);
}
