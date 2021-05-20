/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_txtr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebellon <ebellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 11:27:55 by ebellon           #+#    #+#             */
/*   Updated: 2021/05/20 20:24:14 by ebellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/cub3d.h"

void	draw_wall(t_game *game, t_size_wall size_wall, t_txtr *txtr, int x)
{
	int	y;
	int	color;

	if (game->data.map[txtr->var.mapY][txtr->var.mapX] == '1')
	{
		if (txtr->var.side == 0)
		{
			if (game->player.x > txtr->var.mapX)
				txtr->texNum = 3;
			else
				txtr->texNum = 2;
		}
		else
		{
			if (game->player.y > txtr->var.mapY)
				txtr->texNum = 1;
			else
				txtr->texNum = 0;
		}
	}
	
	//calculate value of wallX
	//where exactly the wall was hit
	if (txtr->var.side == 0)
		txtr->wallX = txtr->var.posY + txtr->var.perpWallDist * txtr->var.rayDirY;
	else
		txtr->wallX = txtr->var.posX + txtr->var.perpWallDist * txtr->var.rayDirX;
	txtr->wallX -= floor((txtr->wallX));

	//x coordinate on the texture
	txtr->texX = (int)(txtr->wallX * (double)(txtr->texWidth));
	if(txtr->var.side == 0 && txtr->var.rayDirX > 0)
		txtr->texX = txtr->texWidth - txtr->texX - 1;
	if(txtr->var.side == 1 && txtr->var.rayDirY < 0)
		txtr->texX = txtr->texWidth - txtr->texX - 1;

	// How much to increase the texture coordinate per screen pixel
	txtr->step = 1.0 * txtr->texHeight / size_wall.height;
	// Starting texture coordinate
	txtr->texPos = (size_wall.start - game->data.ry / 2 + size_wall.height / 2) * txtr->step;
	y = size_wall.start;
	while (y < size_wall.stop)
	{
		// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
		txtr->texY = (int)(txtr->texPos) & (txtr->texHeight - 1);
		txtr->texPos += txtr->step;
		color = txtr->texture[txtr->texNum].addr[txtr->texture[txtr->texNum].h * txtr->texY + txtr->texX];
		//make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
		if(txtr->var.side == 1)
			color = (color >> 1) & 8355711;
		my_mlx_pixel_put(game->mlx, x, y, color);
		y++;
	}
}