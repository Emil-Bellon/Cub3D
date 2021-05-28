/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebellon <ebellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:40:21 by ebellon           #+#    #+#             */
/*   Updated: 2021/05/28 13:37:51 by ebellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/cub3d.h"

void	ft_key_r_arr(t_game *g)
{
	float	oldDirX;
	float	oldPlaneX;

	g->player.alpha = modulo((g->player.alpha + ROT), (2 * PI));
	oldDirX = g->player.dirX;
	g->player.dirX = g->player.dirX * cos(ROT)
		- g->player.dirY * sin(ROT);
	g->player.dirY = oldDirX * sin(ROT) + g->player.dirY * cos(ROT);
	oldPlaneX = g->player.planeX;
	g->player.planeX = g->player.planeX * cos(ROT)
		- g->player.planeY * sin(ROT);
	g->player.planeY = oldPlaneX * sin(ROT) + g->player.planeY * cos(ROT);
}

void	ft_key_l_arr(t_game *g)
{
	float	oldDirX;
	float	oldPlaneX;

	g->player.alpha = modulo((g->player.alpha - ROT), (2 * PI));
	oldDirX = g->player.dirX;
	g->player.dirX = g->player.dirX * cos(-ROT)
		- g->player.dirY * sin(-ROT);
	g->player.dirY = oldDirX * sin(-ROT) + g->player.dirY * cos(-ROT);
	oldPlaneX = g->player.planeX;
	g->player.planeX = g->player.planeX * cos(-ROT)
		- g->player.planeY * sin(-ROT);
	g->player.planeY = oldPlaneX * sin(-ROT) + g->player.planeY * cos(-ROT);
}

void	ft_key_a(t_game *g)
{
	if (g->data.map[(int)floor(g->player.y - ((sin(g->player.alpha + (PI / 2)))
					* SPEED))][(int)floor(g->player.x)] != '1' &&
			!(g->data.map[(int)floor(g->player.y - ((sin(g->player.alpha
			+ (PI / 2))) * SPEED))][(int)floor(g->player.x)] == '4'
			&& g->trip == 0))
		g->player.y -= ((sin(g->player.alpha + (PI / 2))) * SPEED);
	if (g->data.map[(int)floor(g->player.y)][(int)floor(g->player.x
			- ((cos(g->player.alpha + (PI / 2))) * SPEED))] != '1'
			&& !(g->data.map[(int)floor(g->player.y)][(int)floor(g->player.x
			- ((cos(g->player.alpha + (PI / 2))) * SPEED))] == '4'
			&& g->trip == 0))
		g->player.x -= ((cos(g->player.alpha + (PI / 2))) * SPEED);
}

void	ft_key_d(t_game *g)
{
	if (g->data.map[(int)floor(g->player.y + ((sin(g->player.alpha + (PI / 2)))
					* SPEED))][(int)floor(g->player.x)] != '1'
			&& !(g->data.map[(int)floor(g->player.y + ((sin(g->player.alpha
			+ (PI / 2))) * SPEED))][(int)floor(g->player.x)] == '4'
			&& g->trip == 0))
		g->player.y += ((sin(g->player.alpha + (PI / 2))) * SPEED);
	if (g->data.map[(int)floor(g->player.y)][(int)floor(g->player.x
			+ ((cos(g->player.alpha + (PI / 2))) * SPEED))] != '1'
			&& !(g->data.map[(int)floor(g->player.y)][(int)floor(g->player.x
			+ ((cos(g->player.alpha + (PI / 2))) * SPEED))] == '4'
			&& g->trip == 0))
		g->player.x += ((cos(g->player.alpha + (PI / 2))) * SPEED);
}
