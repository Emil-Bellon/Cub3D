/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebellon <ebellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 14:11:21 by ebellon           #+#    #+#             */
/*   Updated: 2021/05/20 14:35:06 by ebellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/cub3d.h"

double			modulo(double x, double y)
{
	x -= y * floor(x / y);
	if (x >= 0.)
		return (x);
	else
		return (x+y);
}

static void		move_player3(t_game *game)
{
	double oldDirX;
	double oldPlaneX;
	if (game->data.key.r_arr)
	{
		game->player.alpha = modulo((game->player.alpha + ROTATE), (2 * PI));
		oldDirX = game->player.dirX;
		game->player.dirX = game->player.dirX * cos(ROTATE) - game->player.dirY * sin(ROTATE);
		game->player.dirY = oldDirX * sin(ROTATE) + game->player.dirY * cos(ROTATE);
		oldPlaneX = game->player.planeX;
		game->player.planeX = game->player.planeX * cos(ROTATE) - game->player.planeY * sin(ROTATE);
		game->player.planeY = oldPlaneX * sin(ROTATE) + game->player.planeY * cos(ROTATE);
	}
	if (game->data.key.l_arr)
	{
		game->player.alpha = modulo((game->player.alpha - ROTATE), (2 * PI));
		oldDirX = game->player.dirX;
		game->player.dirX = game->player.dirX * cos(-ROTATE) - game->player.dirY * sin(-ROTATE);
		game->player.dirY = oldDirX * sin(-ROTATE) + game->player.dirY * cos(-ROTATE);
		oldPlaneX = game->player.planeX;
		game->player.planeX = game->player.planeX * cos(-ROTATE) - game->player.planeY * sin(-ROTATE);
		game->player.planeY = oldPlaneX * sin(-ROTATE) + game->player.planeY * cos(-ROTATE);
	}
	game->data.map[(int)game->player.y][(int)game->player.x] = '*';
}

static void		move_player2(t_game *game)
{
	if (game->data.key.a)
	{
		if (game->data.map[(int)(game->player.y - ((sin(game->player.alpha + (PI/2))) * SPEED))][(int)game->player.x] == ' ')
			game->player.y -= ((sin(game->player.alpha + (PI/2))) * SPEED);
		if (game->data.map[(int)game->player.y][(int)(game->player.x - ((cos(game->player.alpha + (PI/2))) * SPEED))] == ' ')
			game->player.x -= ((cos(game->player.alpha + (PI/2))) * SPEED);
	}
	if (game->data.key.d)
	{
		if (game->data.map[(int)(game->player.y + ((sin(game->player.alpha + (PI/2))) * SPEED))][(int)game->player.x] == ' ')
			game->player.y += ((sin(game->player.alpha + (PI/2))) * SPEED);
		if (game->data.map[(int)game->player.y][(int)(game->player.x + ((cos(game->player.alpha + (PI/2))) * SPEED))] == ' ')
			game->player.x += ((cos(game->player.alpha + (PI/2))) * SPEED);
	}
	move_player3(game);
}

void			move_player(t_game *game)
{
	if (game->data.map[(int)game->player.y][(int)game->player.x] != '1')
		game->data.map[(int)game->player.y][(int)game->player.x] = ' ';
	if (game->data.key.w)
	{
		if (game->data.map[(int)(game->player.y + ((sin(game->player.alpha)) * SPEED))][(int)game->player.x] == ' ')
			game->player.y += ((sin(game->player.alpha)) * SPEED);
		if (game->data.map[(int)game->player.y][(int)(game->player.x + (cos(game->player.alpha)) * SPEED)] == ' ')
			game->player.x += ((cos(game->player.alpha)) * SPEED);
	}
	if (game->data.key.s)
	{
		if (game->data.map[(int)(game->player.y - ((sin(game->player.alpha)) * SPEED))][(int)game->player.x] == ' ')
			game->player.y -= ((sin(game->player.alpha)) * SPEED);
		if (game->data.map[(int)game->player.y][(int)(game->player.x - ((cos(game->player.alpha)) * SPEED))] == ' ')
			game->player.x -= ((cos(game->player.alpha)) * SPEED);
	}
	move_player2(game);
}