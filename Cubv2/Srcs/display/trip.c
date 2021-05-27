/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trip.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebellon <ebellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 14:37:18 by ebellon           #+#    #+#             */
/*   Updated: 2021/05/27 17:10:28 by ebellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/cub3d.h"

static void	draw_col2(t_col col, t_game *game)
{
	int	size;

	size = col.start;
	while (size < col.size_max)
	{
		if (game->trip > 0)
		{
			if (size % (int)game->trip == 0)
				my_mlx_pixel_put(game->mlx, col.x, size, col.color << 2);
			else if (size % (int)game->trip != 2)
				my_mlx_pixel_put(game->mlx, col.x, size, col.color);
		}
		else
			my_mlx_pixel_put(game->mlx, col.x, size, col.color);
		size++;
	}
}

static void	draw_col3(t_col col, t_game *game)
{
	int	size;

	size = col.start;
	while (size < col.size_max)
	{
		if (game->trip > 0)
		{
			if (size % (int)game->trip == 0)
				my_mlx_pixel_put(game->mlx, col.x, size, col.color >> 2);
			else if (size % (int)game->trip != 3)
				my_mlx_pixel_put(game->mlx, col.x, size, col.color);
		}
		else
			my_mlx_pixel_put(game->mlx, col.x, size, col.color);
		size++;
	}
}

void	draw_col(t_col col, t_game *game)
{
	int	size;

	size = col.start;
	while (size < col.size_max)
	{
		if (game->trip > 0)
		{
			if (size % (int)game->trip == 0)
				my_mlx_pixel_put(game->mlx, col.x, size, col.color);
			else if (size % (int)game->trip != 5)
				my_mlx_pixel_put(game->mlx, col.x, size, col.color << 2);
		}
		else
			my_mlx_pixel_put(game->mlx, col.x, size, col.color);
		size++;
	}
}

void	draw_trip(int x_win, t_game *game, t_size_wall size_wall)
{
	t_col	col;

	if (x_win % (int)game->trip == 0)
	{
		col = (t_col){x_win, size_wall.start, size_wall.stop, game->trip_color};
		draw_col(col, game);
	}
	else if (x_win % (int)game->trip == 2)
	{
		col = (t_col){x_win, size_wall.start, size_wall.stop, game->trip_color};
		draw_col2(col, game);
	}
	else if (x_win % (int)game->trip == 3)
	{
		col = (t_col){x_win, size_wall.start, size_wall.stop, game->trip_color};
		draw_col3(col, game);
	}
	col = (t_col){x_win, 0, size_wall.start, 0x00000000};
	draw_col(col, game);
	col = (t_col){x_win, size_wall.stop, game->data.ry, 0x00000000};
	draw_col(col, game);
}

void	ft_trip(t_game *game)
{
	if (game->flip == 0)
	{
		game->trip += 0.3;
		if (game->trip > 10)
			game->flip = 1;
	}
	else
	{
		game->trip -= 0.3;
		if (game->trip < 5.3)
			game->flip = 0;
	}
	game->trip_color = game->trip_color * (256 / 2);
	if (game->trip_color > 0x01000000)
		game->trip_color = 0x000000F0;
}
