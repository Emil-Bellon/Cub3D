/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebellon <ebellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 15:46:21 by ebellon           #+#    #+#             */
/*   Updated: 2020/12/07 19:12:56 by ebellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start;
	t_list	*flst;

	start = NULL;
	while (lst)
	{
		if (!(flst = ft_lstnew((*f)(lst->content))))
		{
			ft_lstclear(&start, (*del));
			return (NULL);
		}
		ft_lstadd_back(&start, flst);
		lst = lst->next;
	}
	return (start);
}
