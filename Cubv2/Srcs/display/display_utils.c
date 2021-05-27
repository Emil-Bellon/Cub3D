/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebellon <ebellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 17:33:00 by ebellon           #+#    #+#             */
/*   Updated: 2021/05/27 17:42:56 by ebellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/cub3d.h"

void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

t_size_wall	ft_get_wall_size(int x_win, t_game *game)
{
	t_size_wall	size_wall;

	size_wall.height = (int)(game->data.ry
			/ ft_dda(game, x_win, &(game->txtr->var)));
	if (game->trip > 0)
		size_wall.height = (size_wall.height * game->trip / 5)
			+ 10 * cos((x_win / 10) * game->trip);
	size_wall.start = game->data.ry / 2 - size_wall.height / 2;
	if (size_wall.start < 0)
		size_wall.start = 0;
	size_wall.stop = game->data.ry / 2 + size_wall.height / 2;
	if (size_wall.stop >= game->data.ry)
		size_wall.stop = game->data.ry;
	return (size_wall);
}
