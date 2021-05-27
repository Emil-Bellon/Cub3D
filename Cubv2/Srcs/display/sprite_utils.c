/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebellon <ebellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 15:54:26 by ebellon           #+#    #+#             */
/*   Updated: 2021/05/27 17:42:53 by ebellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/cub3d.h"

void	ft_lstadd_frt(t_lst_sprite **lst, t_lst_sprite *new)
{
	new->next = *lst;
	*lst = new;
}

t_lst_sprite	*ft_lst_new(float x, float y, int id)
{
	t_lst_sprite	*lst;

	lst = malloc(sizeof(t_lst_sprite));
	if (lst)
	{
		lst->x = x;
		lst->y = y;
		lst->id = id;
		lst->next = NULL;
	}
	return (lst);
}

void	ft_clear_lst(t_lst_sprite **lst)
{
	t_lst_sprite	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}

int	ft_in_lst(t_lst_sprite *lst, float x, float y)
{
	while (lst)
	{
		if (lst->x == x && lst->y == y)
			return (1);
		lst = lst->next;
	}
	return (0);
}

int	ft_lst_size(t_lst_sprite *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}
