/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_txtr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebellon <ebellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 11:27:55 by ebellon           #+#    #+#             */
/*   Updated: 2021/05/27 17:14:52 by ebellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/cub3d.h"

void	ft_dda_x_inf_y(t_rc_var *var)
{
	var->sideDistX += var->deltaDistX;
	var->mapX += var->stepX;
	var->side = 0;
}

void	ft_dda_x_sup_y(t_rc_var *var)
{
	var->sideDistY += var->deltaDistY;
	var->mapY += var->stepY;
	var->side = 1;
}

static void	ft_init_textr(t_game *g, t_txtr *t)
{
	if (g->data.map[t->var.mapY][t->var.mapX] == '1' ||
		(g->data.map[t->var.mapY][t->var.mapX] == '4' && g->trip == 0))
	{
		if (t->var.side == 0)
		{
			if (g->player.x > t->var.mapX)
				t->texNum = 3;
			else
				t->texNum = 2;
		}
		else
		{
			if (g->player.y > t->var.mapY)
				t->texNum = 1;
			else
				t->texNum = 0;
		}
	}
	if (t->var.side == 0)
		t->wallX = t->var.posY + t->var.perpWallDist * t->var.rayDirY;
	else
		t->wallX = t->var.posX + t->var.perpWallDist * t->var.rayDirX;
}

void	draw_wall(t_game *game, t_size_wall size, t_txtr *t, int x)
{
	int	y;
	int	color;

	ft_init_textr(game, t);
	t->wallX -= floor((t->wallX));
	t->texX = (int)(t->wallX * (double)(t->texWidth));
	if (t->var.side == 0 && t->var.rayDirX > 0)
		t->texX = t->texWidth - t->texX - 1;
	if (t->var.side == 1 && t->var.rayDirY < 0)
		t->texX = t->texWidth - t->texX - 1;
	t->step = 1.0 * t->texHeight / size.height;
	t->texPos = (size.start - game->data.ry / 2 + size.height / 2) * t->step;
	y = size.start - 1;
	while (++y < size.stop)
	{
		t->texY = (int)(t->texPos) & (t->texHeight - 1);
		t->texPos += t->step;
		color = t->texture[t->texNum].addr[t->texture[t->texNum].h
			* t->texY + t->texX];
		if (t->var.side == 1)
			color = (color >> 1) & 8355711;
		my_mlx_pixel_put(game->mlx, x, y, color);
	}
}
