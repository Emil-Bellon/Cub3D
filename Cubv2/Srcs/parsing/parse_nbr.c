/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebellon <ebellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 13:40:24 by ebellon           #+#    #+#             */
/*   Updated: 2021/05/28 14:06:18 by ebellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/cub3d.h"

static int	ft_rgb_ok(char **rgb)
{
	int	i;
	int	j;

	i = 0;
	while (rgb[i])
	{
		j = 0;
		while (rgb[i][j])
			if (!(ft_isdigit(rgb[i][j++])))
				return (0);
		if (j > 3 || ft_atoi(rgb[i]) > 255)
			return (0);
		i++;
	}
	if (i != 3)
		return (0);
	return (1);
}

void	ft_free_strs(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	ft_parse_rgb_f(char *line, t_game *game)
{
	char	**rgb;
	char	*str;
	int		i;

	i = 1;
	while (line[i] == ' ')
		i++;
	str = ft_substr(line, i, ft_strlen(line));
	rgb = ft_split(str, ',');
	if (ft_rgb_ok(rgb) == 0)
	{
		ft_free_strs(rgb);
		ft_error("There is a problem with the F rgb", game, line);
	}
	game->data.rgb_f = (ft_atoi(rgb[0]) << 16)
		+ (ft_atoi(rgb[1]) << 8) + ft_atoi(rgb[2]);
	free(str);
	ft_free_strs(rgb);
}

void	ft_parse_rgb_c(char *line, t_game *game)
{
	char	**rgb;
	char	*str;
	int		i;

	i = 1;
	while (line[i] == ' ')
		i++;
	str = ft_substr(line, i, ft_strlen(line));
	rgb = ft_split(str, ',');
	if (ft_rgb_ok(rgb) == 0)
	{
		ft_free_strs(rgb);
		ft_error("There is a problem with the C rgb", game, line);
	}
	game->data.rgb_c = (ft_atoi(rgb[0]) << 16)
		+ (ft_atoi(rgb[1]) << 8) + ft_atoi(rgb[2]);
	free(str);
	ft_free_strs(rgb);
}

void	fill_flood_map(t_game *game, int y, int x)
{
	if (y < 0 || x < 0 || y > (ft_strslen(game->data.map) - 1)
		|| x > ((int)ft_strlen(game->data.map[y]) - 1))
		ft_error("The player is not surrounded by walls", game, NULL);
	if (ft_ischar("|.$*&", game->data.map[y][x]))
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
	if (game->data.map[y][x] == '3')
		game->data.map[y][x] = '*';
	if (game->data.map[y][x] == '4')
		game->data.map[y][x] = '&';
	fill_flood_map(game, y - 1, x);
	fill_flood_map(game, y + 1, x);
	fill_flood_map(game, y, x - 1);
	fill_flood_map(game, y, x + 1);
}
