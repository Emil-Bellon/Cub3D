/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebellon <ebellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 16:44:44 by ebellon           #+#    #+#             */
/*   Updated: 2021/05/11 13:41:33 by ebellon          ###   ########lyon.fr   */
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

	fd = open(game->data.no, O_RDONLY);
	if (fd < 0)
		ft_error("Can not open NO path texture", game, NULL);
	close(fd);
	fd = open(game->data.so, O_RDONLY);
	if (fd < 0)
		ft_error("Can not open SO path texture", game, NULL);
	close(fd);
	fd = open(game->data.we, O_RDONLY);
	if (fd < 0)
		ft_error("Can not open WE path texture", game, NULL);
	close(fd);
	fd = open(game->data.ea, O_RDONLY);
	if (fd < 0)
		ft_error("Can not open EA path texture", game, NULL);
	close(fd);
	fd = open(game->data.sprite, O_RDONLY);
	if (fd < 0)
		ft_error("Can not open Sprite path texture", game, NULL);
	close(fd);
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