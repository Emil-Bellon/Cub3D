/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebellon <ebellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 11:36:39 by ebellon           #+#    #+#             */
/*   Updated: 2021/05/27 16:52:07 by ebellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/cub3d.h"

static void	ft_set_player2(t_game *game, char alpha)
{
	if (alpha == 'W')
	{
		game->player.alpha = -PI;
		game->player.dirX = -1;
		game->player.planeY = -0.66;
	}
	else if (alpha == 'E')
	{
		game->player.dirX = 1;
		game->player.planeY = 0.66;
	}
	game->player.alive = 1;
}

static int	ft_set_player(t_game *game, int x, int y, char alpha)
{
	if (game->player.alive == 1)
		return (0);
	game->player.x = x + 0.5;
	game->player.y = y + 0.5;
	if (alpha == 'N')
	{
		game->player.alpha = (3 * PI) / 2;
		game->player.dirY = -1;
		game->player.planeX = 0.66;
		game->player.alive = 1;
	}
	else if (alpha == 'S')
	{
		game->player.alpha = PI / 2;
		game->player.dirY = 1;
		game->player.planeX = -0.66;
		game->player.alive = 1;
	}
	else
		ft_set_player2(game, alpha);
	return (1);
}

static void	ft_add_map_line(char *line, t_game *g)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (ft_is_char_map(line[i]) == 2)
		{
			if (ft_set_player(g, i, ft_strslen(g->data.map), line[i]) == 0)
				ft_error("There is more than one player in the map", g, line);
			line[i] = '0';
		}
		else if (ft_is_char_map(line[i]) == 0)
			ft_error("Wrong character in map", g, line);
		i++;
	}
	if (i > g->data.map_x)
		g->data.map_x = i;
	g->data.map = ft_strsjoin(g->data.map, line);
}

static void	ft_parse_map_main(char *line, t_game *game, int fd, int ret_read)
{
	game->data.map_x = 0;
	while (ret_read == 1 && (line[0] == ' ' || line [0] == '1'))
	{
		ft_add_map_line(line, game);
		ret_read = get_next_line(fd, &line);
	}
	if (line[0] != 0)
		ft_error("There is a wrong line after the map", game, line);
	free(line);
	while (get_next_line(fd, &line) == 1)
	{
		if (line[0] != 0)
			ft_error("There is a wrong line after the map", game, line);
		free(line);
	}
	if (line[0] != 0)
		ft_error("There is a wrong line after the map", game, line);
	if (ret_read == -1)
		ft_error("There was a problem while reading .cub file", game, line);
	game->data.map_y = ft_strslen(game->data.map);
	if (game->player.alive == 0)
		ft_error("There is no player in the map", game, line);
	free(line);
}

void	ft_parse_main(char *path, t_game *g)
{
	int		fd;
	char	*line;
	int		ret_read;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_error("There was a problem while opening [arg_path] file", g, NULL);
	ret_read = get_next_line(fd, &line);
	while (ret_read == 1)
	{
		if (line[0] >= 'A' && line[0] <= 'Z')
			ft_parse_line_data(line, g);
		else if (line[0] == ' ' || line[0] == '1')
			ft_parse_map_main(line, g, fd, ret_read);
		else if (line[0] != 0)
			ft_error("There is a wrong line in the .cub file", g, line);
		else
			free(line);
		ret_read = get_next_line(fd, &line);
	}
	if (ret_read == -1)
		ft_error("There was a problem while reading .cub file", g, line);
	free(line);
}
