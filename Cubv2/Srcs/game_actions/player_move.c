/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebellon <ebellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 14:11:21 by ebellon           #+#    #+#             */
/*   Updated: 2021/05/28 15:22:19 by ebellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/cub3d.h"

float	modulo(float x, float y)
{
	x -= y * floor(x / y);
	if (x >= 0.)
		return (x);
	else
		return (x + y);
}

static void	ft_reset_player_map(t_game *g)
{
	if (g->data.map[(int)g->player.y][(int)g->player.x] != '2' &&
		g->data.map[(int)g->player.y][(int)g->player.x] != '3' &&
		g->data.map[(int)g->player.y][(int)g->player.x] != '4')
		g->data.map[(int)g->player.y][(int)g->player.x] = '*';
}

static void	ft_key_w(t_game *g)
{
	if (g->data.map[(int)floor(g->player.y + ((sin(g->player.alpha))
					* SPEED))][(int)floor(g->player.x)] != '1'
			&& !(g->data.map[(int)floor(g->player.y + ((sin(g->player.alpha))
			* SPEED))][(int)floor(g->player.x)] == '4' && g->trip == 0))
		g->player.y += ((sin(g->player.alpha)) * SPEED);
	if (g->data.map[(int)floor(g->player.y)][(int)floor(g->player.x
			+ (cos(g->player.alpha)) * SPEED)] != '1'
			&& !(g->data.map[(int)floor(g->player.y)][(int)floor(g->player.x
			+ (cos(g->player.alpha)) * SPEED)] == '4' && g->trip == 0))
		g->player.x += ((cos(g->player.alpha)) * SPEED);
}

static void	ft_key_s(t_game *g)
{
	if (g->data.map[(int)floor(g->player.y - ((sin(g->player.alpha))
					* SPEED))][(int)floor(g->player.x)] != '1'
			&& !(g->data.map[(int)floor(g->player.y - ((sin(g->player.alpha))
			* SPEED))][(int)floor(g->player.x)] == '4' && g->trip == 0))
		g->player.y -= ((sin(g->player.alpha)) * SPEED);
	if (g->data.map[(int)floor(g->player.y)][(int)floor(g->player.x
			- ((cos(g->player.alpha)) * SPEED))] != '1'
			&& !(g->data.map[(int)floor(g->player.y)][(int)floor(g->player.x
			- ((cos(g->player.alpha)) * SPEED))] == '4' && g->trip == 0))
		g->player.x -= ((cos(g->player.alpha)) * SPEED);
}

void	move_player(t_game *g)
{
	if (g->data.map[(int)g->player.y][(int)g->player.x] == '2' && g->trip == 0)
		g->trip = 5;
	else if (g->data.map[(int)g->player.y][(int)g->player.x] == '3')
		g->trip = 0;
	else if (g->data.map[(int)g->player.y][(int)g->player.x] != '1' &&
		g->data.map[(int)g->player.y][(int)g->player.x] != '4' &&
		g->data.map[(int)g->player.y][(int)g->player.x] != '2')
		g->data.map[(int)g->player.y][(int)g->player.x] = ' ';
	if (g->data.key.w)
		ft_key_w(g);
	if (g->data.key.s)
		ft_key_s(g);
	if (g->data.key.a)
		ft_key_a(g);
	if (g->data.key.d)
		ft_key_d(g);
	if (g->data.key.r_arr)
		ft_key_r_arr(g);
	if (g->data.key.l_arr)
		ft_key_l_arr(g);
	ft_reset_player_map(g);
}
