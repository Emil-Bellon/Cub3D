/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebellon <ebellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 16:44:44 by ebellon           #+#    #+#             */
/*   Updated: 2021/05/20 16:28:42 by ebellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/cub3d.h"

static int	ft_ischar(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
		if (str[i++] == c)
			return (1);
	return (0);
}

static void	ft_check_txtr_path(t_game *game)
{
	int	fd;
	int	i;

	game->txtr = ft_calloc(sizeof(t_txtr), 1);
	game->txtr->texWidth = 64;
	game->txtr->texHeight = 64;
	game->txtr->texture = ft_calloc(sizeof(t_xpm), 5);
	if (!(game->txtr->texture))
		ft_error("Malloc fail", game, NULL);
	fd = open(game->data.no, O_RDONLY);
	if (fd < 0)
		ft_error("Can not open NO path texture", game, NULL);
	close(fd);
	game->txtr->texture[0].img = mlx_xpm_file_to_image(game->mlx->mlx_ptr, game->data.no, &(game->txtr->texture[0].w), &(game->txtr->texture[0].h));
	fd = open(game->data.so, O_RDONLY);
	if (fd < 0)
		ft_error("Can not open SO path texture", game, NULL);
	close(fd);
	game->txtr->texture[1].img = mlx_xpm_file_to_image(game->mlx->mlx_ptr, game->data.so, &game->txtr->texture[1].w, &game->txtr->texture[1].h);
	fd = open(game->data.we, O_RDONLY);
	if (fd < 0)
		ft_error("Can not open WE path texture", game, NULL);
	close(fd);
	game->txtr->texture[2].img = mlx_xpm_file_to_image(game->mlx->mlx_ptr, game->data.we, &game->txtr->texture[2].w, &game->txtr->texture[2].h);
	fd = open(game->data.ea, O_RDONLY);
	if (fd < 0)
		ft_error("Can not open EA path texture", game, NULL);
	close(fd);
	game->txtr->texture[3].img = mlx_xpm_file_to_image(game->mlx->mlx_ptr, game->data.ea, &game->txtr->texture[3].w, &game->txtr->texture[3].h);
	fd = open(game->data.sprite, O_RDONLY);
	if (fd < 0)
		ft_error("Can not open Sprite path texture", game, NULL);
	close(fd);
	game->txtr->texture[4].img = mlx_xpm_file_to_image(game->mlx->mlx_ptr, game->data.sprite, &game->txtr->texture[4].w, &game->txtr->texture[4].h);
	i = -1;
	while (++i < 5)
		game->txtr->texture[i].addr = (int *)mlx_get_data_addr(game->txtr->texture[i].img,
			&game->txtr->texture[i].bytes, &game->txtr->texture[i].sizeline,
				&game->txtr->texture[i].endian);
}

static void	fill_flood_map(t_game *game, int y, int x)
{
	if (y < 0 || x < 0 || y > (ft_strslen(game->data.map) - 1) || \
		x > ((int)ft_strlen(game->data.map[y]) - 1))
		ft_error("The player is not surrounded by walls", game, NULL);
	if (ft_ischar("|.$", game->data.map[y][x]))
		return ;
	if (game->data.map[y][x] == '1')
	{
		game->data.map[y][x] = '|';
		return ;
	}
	if (game->data.map[y][x] == '0')
		game->data.map[y][x] = '.';
	if (game->data.map[y][x] == '2')
		game->data.map[y][x] = '$';
	fill_flood_map(game, y - 1, x);
	fill_flood_map(game, y + 1, x);
	fill_flood_map(game, y, x - 1);
	fill_flood_map(game, y, x + 1);
}

void		ft_check_data(t_game *game)
{
	ft_check_txtr_path(game);
	fill_flood_map(game, game->player.y, game->player.x);
	ft_reset_map(game);
}