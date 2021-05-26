/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebellon <ebellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 14:13:05 by ebellon           #+#    #+#             */
/*   Updated: 2021/05/26 15:08:19 by ebellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/cub3d.h"

void	ft_lstadd_frt(t_lst_sprite **lst, t_lst_sprite *new)
{
	new->next = *lst;
	*lst = new;
	// printf("coucou\n");
}

t_lst_sprite	*ft_lst_new(float x, float y, int id)
{
	t_lst_sprite	*lst;

	lst = malloc(sizeof(t_lst_sprite));
	if (lst)
	{
		lst->x = x;
		lst->y = y;
		lst->id = id;
		lst->next = NULL;
	}
	return (lst);
}

void	ft_clear_lst(t_lst_sprite **lst)
{
	t_lst_sprite *tmp;

	while(*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}

int		ft_in_lst(t_lst_sprite *lst, float x, float y)
{
	while (lst)
	{
		if (lst->x == x && lst->y == y)
			return (1);
		lst = lst->next;
	}
	return (0);
}

void	ft_draw_sprite(t_game *game, t_rc_var *var, t_txtr *txtr)
{
	int	color;
	int	startY;
	int	startX;
	
	while (game->lst_sprite)
	{
		// printf("sprite = %p\n", game->lst_sprite);
		// printf("sprite->next = %p\n", game->lst_sprite->next);
		//translate sprite position to relative to camera
		game->spr_var.spriteX = game->lst_sprite->x - var->posX;
		game->spr_var.spriteY = game->lst_sprite->y - var->posY;

		//transform sprite with the inverse camera matrix
		// [ planeX   dirX ] -1                                       [ dirY      -dirX ]
		// [               ]       =  1/(planeX*dirY-dirX*planeY) *   [                 ]
		// [ planeY   dirY ]                                          [ -planeY  planeX ]

		game->spr_var.invDet = 1.0 / (var->planeX * var->dirY - var->dirX * var->planeY); //required for correct matrix multiplication

		game->spr_var.transformX = game->spr_var.invDet * (var->dirY * game->spr_var.spriteX - var->dirX * game->spr_var.spriteY);
		game->spr_var.transformY = game->spr_var.invDet * (-var->planeY * game->spr_var.spriteX + var->planeX * game->spr_var.spriteY); //this is actually the depth inside the screen, that what Z is in 3D

		game->spr_var.spriteScreenX = (int)((game->data.rx / 2) * (1 + game->spr_var.transformX / game->spr_var.transformY));

		//calculate height of the sprite on screen
		game->spr_var.spriteHeight = abs((int)(game->data.ry / (game->spr_var.transformY))); //using 'transformY' instead of the real distance prevents fisheye
		//calculate lowest and highest pixel to fill in current stripe
		game->spr_var.drawStartY = -game->spr_var.spriteHeight / 2 + game->data.ry / 2;
		if(game->spr_var.drawStartY < 0)
			game->spr_var.drawStartY = 0;
		game->spr_var.drawEndY = game->spr_var.spriteHeight / 2 + game->data.ry / 2;
		if(game->spr_var.drawEndY >= game->data.ry)
			game->spr_var.drawEndY = game->data.ry - 1;

		//calculate width of the sprite
		game->spr_var.spriteWidth = abs((int)(game->data.ry / (game->spr_var.transformY)));
		game->spr_var.drawStartX = -game->spr_var.spriteWidth / 2 + game->spr_var.spriteScreenX;
		if(game->spr_var.drawStartX < 0)
			game->spr_var.drawStartX = 0;
		game->spr_var.drawEndX = game->spr_var.spriteWidth / 2 + game->spr_var.spriteScreenX;
		if(game->spr_var.drawEndX >= game->data.rx)
			game->spr_var.drawEndX = game->data.rx - 1;

		//loop through every vertical stripe of the sprite on screen
		startX = game->spr_var.drawStartX;
		while (startX < game->spr_var.drawEndX)
		{
			game->spr_var.texX = (int)(256 * (startX - (-game->spr_var.spriteWidth / 2 + game->spr_var.spriteScreenX)) * txtr->texWidth / game->spr_var.spriteWidth) / 256;
			//the conditions in the if are:
			//1) it's in front of camera plane so you don't see things behind you
			//2) it's on the screen (left)
			//3) it's on the screen (right)
			//4) ZBuffer, with perpendicular distance
			// printf("drawStartX = %d, transformY = %f, zbuf = %f\n", game->spr_var.drawStartX, game->spr_var.transformY, game->zbuffer[game->spr_var.drawStartX]);
			startY = game->spr_var.drawStartY;
			if(game->spr_var.transformY > 0 && startX > 0 && startX < game->data.rx && game->spr_var.transformY < game->zbuffer[startX])
			{
				while (startY < game->spr_var.drawEndY) //for every pixel of the current stripe
				{
					game->spr_var.d = (startY) * 256 - game->data.ry * 128 + game->spr_var.spriteHeight * 128; //256 and 128 factors to avoid floats
					game->spr_var.texY = ((game->spr_var.d * txtr->texHeight) / game->spr_var.spriteHeight) / 256;
					if (game->lst_sprite->id == 2)
						color = txtr->texture[4].addr[txtr->texture[4].h * game->spr_var.texY + game->spr_var.texX]; //get current color from the texture
					else if (game->lst_sprite->id == 3)
						color = txtr->texture[5].addr[txtr->texture[5].h * game->spr_var.texY + game->spr_var.texX];
					if((color & 0x00FFFFFF) != 0 && !(game->lst_sprite->id == 2 && game->trip > 0))
						my_mlx_pixel_put(game->mlx, startX, startY, color); //paint pixel if it isn't black, black is the invisible color
					startY++;
				}
			}
			startX++;
		}
		game->lst_sprite = game->lst_sprite->next;
	}
}