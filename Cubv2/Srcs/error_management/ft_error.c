/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebellon <ebellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 13:04:27 by ebellon           #+#    #+#             */
/*   Updated: 2021/05/07 17:29:19 by ebellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/cub3d.h"

void	ft_error_res(char **res, t_game *game, char *line)
{
	ft_free_strs(res);
	ft_error("There is a problem with the Resolution", game, line);
}

void	ft_map_error(t_game *game)
{
	ft_free_strs(game->data.map);
	ft_error("The player is not surrounded by walls", game, NULL);
}

void	ft_error(char *error_msg, t_game *game, void *data_to_free)
{
	printf("Error\n%s\n", error_msg);
	game->stop = 1;
	if (data_to_free != NULL)
		free(data_to_free);
	exit(1);
}