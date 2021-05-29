/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebellon <ebellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 16:44:44 by ebellon           #+#    #+#             */
/*   Updated: 2021/05/29 17:06:08 by ebellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/cub3d.h"

int	ft_ischar(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
		if (str[i++] == c)
			return (1);
	return (0);
}

static void	ft_init_txtr_addr(t_game *g)
{
	int	i;

	i = -1;
	while (++i < 6)
		g->txtr->texture[i].addr = (int *)mlx_get_data_addr(
				g->txtr->texture[i].img, &g->txtr->texture[i].bytes,
				&g->txtr->texture[i].sizeline, &g->txtr->texture[i].endian);
}

static void	ft_check_txtr_path2(t_game *g)
{
	g->txtr->texture[2].img = mlx_xpm_file_to_image(g->mlx->mlx_ptr,
			g->data.we, &g->txtr->texture[2].w,
			&g->txtr->texture[2].h);
	if (g->txtr->texture[2].img == NULL)
		ft_error("Can not open WE path texture", g, NULL);
	g->txtr->texture[3].img = mlx_xpm_file_to_image(g->mlx->mlx_ptr,
			g->data.ea, &g->txtr->texture[3].w,
			&g->txtr->texture[3].h);
	if (g->txtr->texture[3].img == NULL)
		ft_error("Can not open EA path texture", g, NULL);
	g->txtr->texture[4].img = mlx_xpm_file_to_image(g->mlx->mlx_ptr,
			"./Txtr/mush.xpm", &g->txtr->texture[4].w,
			&g->txtr->texture[4].h);
	g->txtr->texture[5].img = mlx_xpm_file_to_image(g->mlx->mlx_ptr,
			"./Txtr/shower.xpm", &g->txtr->texture[5].w,
			&g->txtr->texture[5].h);
	ft_init_txtr_addr(g);
}

static void	ft_check_txtr_path(t_game *g)
{
	g->txtr = ft_calloc(sizeof(t_txtr), 1);
	g->txtr->texWidth = 64;
	g->txtr->texHeight = 64;
	g->txtr->texture = ft_calloc(sizeof(t_xpm), 6);
	if (!(g->txtr->texture))
		ft_error("Malloc fail", g, NULL);
	g->txtr->texture[0].img = mlx_xpm_file_to_image(g->mlx->mlx_ptr,
			g->data.no, &(g->txtr->texture[0].w),
			&(g->txtr->texture[0].h));
	if (g->txtr->texture[0].img == NULL)
		ft_error("Can not open NO path texture", g, NULL);
	g->txtr->texture[1].img = mlx_xpm_file_to_image(g->mlx->mlx_ptr,
			g->data.so, &g->txtr->texture[1].w,
			&g->txtr->texture[1].h);
	if (g->txtr->texture[1].img == NULL)
		ft_error("Can not open SO path texture", g, NULL);
	ft_check_txtr_path2(g);
}

void	ft_check_data(t_game *game)
{
	if (game->player.alive == 0)
		ft_error("There is no player within the map", game, NULL);
	ft_check_txtr_path(game);
	fill_flood_map(game, game->player.y, game->player.x);
	ft_reset_map(game);
}
