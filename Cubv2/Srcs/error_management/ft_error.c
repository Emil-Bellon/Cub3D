/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebellon <ebellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 13:04:27 by ebellon           #+#    #+#             */
/*   Updated: 2021/05/11 15:31:44 by ebellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/cub3d.h"

void	ft_error_res(char **res, t_game *game, char *line)
{
	ft_free_strs(res);
	ft_error("There is a problem with the Resolution", game, line);
}

void	ft_free_game(t_game *game)
{
	if (game->data.no != NULL)
		free(game->data.no);
	if (game->data.so != NULL)
		free(game->data.so);
	if (game->data.we != NULL)
		free(game->data.we);
	if (game->data.ea != NULL)
		free(game->data.ea);
	if (game->data.sprite != NULL)
		free(game->data.sprite);
	if (game->data.map != NULL)
		ft_free_strs(game->data.map);
}

void	ft_exit(t_game *game)
{
	ft_free_game(game);
	exit (0);
}

void	ft_error(char *error_msg, t_game *game, void *data_to_free)
{
	printf("Error\n%s\n", error_msg);
	ft_free_game(game);
	if (data_to_free != NULL)
		free(data_to_free);
	exit (1);
}