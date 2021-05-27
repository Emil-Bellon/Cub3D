/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebellon <ebellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 14:13:05 by ebellon           #+#    #+#             */
/*   Updated: 2021/05/27 17:20:04 by ebellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/cub3d.h"

static void	ft_init_sprite2(t_game *g)
{
	g->spr_var.drawStartX = -g->spr_var.spriteWidth / 2
		+ g->spr_var.spriteScreenX;
	if (g->spr_var.drawStartX < 0)
		g->spr_var.drawStartX = 0;
	g->spr_var.drawEndX = g->spr_var.spriteWidth / 2
		+ g->spr_var.spriteScreenX;
	if (g->spr_var.drawEndX >= g->data.rx)
		g->spr_var.drawEndX = g->data.rx - 1;
}

static void	ft_init_sprite(t_game *g, t_rc_var *v)
{
	g->spr_var.spriteX = g->lst_sprite->x - v->posX;
	g->spr_var.spriteY = g->lst_sprite->y - v->posY;
	g->spr_var.invDet = 1.0 / (v->planeX * v->dirY - v->dirX * v->planeY);
	g->spr_var.transformX = g->spr_var.invDet
		* (v->dirY * g->spr_var.spriteX - v->dirX * g->spr_var.spriteY);
	g->spr_var.transformY = g->spr_var.invDet
		* (-v->planeY * g->spr_var.spriteX + v->planeX * g->spr_var.spriteY);
	g->spr_var.spriteScreenX = (int)((g->data.rx / 2)
			* (1 + g->spr_var.transformX / g->spr_var.transformY));
	g->spr_var.spriteHeight = abs((int)(g->data.ry / g->spr_var.transformY));
	g->spr_var.drawStartY = -g->spr_var.spriteHeight / 2 + g->data.ry / 2;
	if (g->spr_var.drawStartY < 0)
		g->spr_var.drawStartY = 0;
	g->spr_var.drawEndY = g->spr_var.spriteHeight / 2 + g->data.ry / 2;
	if (g->spr_var.drawEndY >= g->data.ry)
		g->spr_var.drawEndY = g->data.ry - 1;
	g->spr_var.spriteWidth = abs((int)(g->data.ry / g->spr_var.transformY));
	ft_init_sprite2(g);
}

static void	ft_draw_pix_sprite(t_game *g, t_txtr *t, int startY, int startX)
{
	int	color;

	color = 0;
	g->spr_var.d = (startY) * 256 - g->data.ry * 128
		+ g->spr_var.spriteHeight * 128;
	g->spr_var.texY = ((g->spr_var.d * t->texHeight)
			/ g->spr_var.spriteHeight) / 256;
	if (g->lst_sprite->id == 2)
		color = t->texture[4].addr[t->texture[4].h
			* g->spr_var.texY + g->spr_var.texX];
	else if (g->lst_sprite->id == 3)
		color = t->texture[5].addr[t->texture[5].h
			* g->spr_var.texY + g->spr_var.texX];
	if ((color & 0x00FFFFFF) != 0 && !(g->lst_sprite->id == 2 && g->trip > 0))
		my_mlx_pixel_put(g->mlx, startX, startY, color);
}

static int	ft_texx(t_game *g, t_txtr *t, int startX)
{
	int	ret;

	ret = (int)(256 * (startX - (-g->spr_var.spriteWidth / 2
					+ g->spr_var.spriteScreenX)) * t->texWidth
			/ g->spr_var.spriteWidth) / 256;
	return (ret);
}

void	ft_draw_sprite(t_game *g, t_rc_var *var, t_txtr *t)
{
	int				startY;
	int				startX;
	t_lst_sprite	*fst;

	fst = g->lst_sprite;
	while (g->lst_sprite)
	{
		ft_init_sprite(g, var);
		startX = g->spr_var.drawStartX - 1;
		while (++startX < g->spr_var.drawEndX)
		{
			g->spr_var.texX = ft_texx(g, t, startX);
			startY = g->spr_var.drawStartY - 1;
			if (g->spr_var.transformY > 0 && startX > 0
				&& startX < g->data.rx
				&& g->spr_var.transformY < g->zbuffer[startX])
				while (++startY < g->spr_var.drawEndY)
					ft_draw_pix_sprite(g, t, startY, startX);
		}
		g->lst_sprite = g->lst_sprite->next;
	}
	g->lst_sprite = fst;
}
