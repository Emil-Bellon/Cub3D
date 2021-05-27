/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_txtr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebellon <ebellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 13:36:34 by ebellon           #+#    #+#             */
/*   Updated: 2021/05/27 16:46:29 by ebellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/cub3d.h"

static void	ft_parse_no_txtr(char *line, t_game *game)
{
	int	i;

	i = 2;
	while (line[i] == ' ')
		i++;
	game->data.no = ft_substr(line, i, ft_strlen(line));
}

static void	ft_parse_so_txtr(char *line, t_game *game)
{
	int	i;

	i = 2;
	while (line[i] == ' ')
		i++;
	game->data.so = ft_substr(line, i, ft_strlen(line));
}

static void	ft_parse_ea_txtr(char *line, t_game *game)
{
	int	i;

	i = 2;
	while (line[i] == ' ')
		i++;
	game->data.ea = ft_substr(line, i, ft_strlen(line));
}

static void	ft_parse_we_txtr(char *line, t_game *game)
{
	int	i;

	i = 2;
	while (line[i] == ' ')
		i++;
	game->data.we = ft_substr(line, i, ft_strlen(line));
}

void	ft_parse_line_data(char *line, t_game *game)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		ft_parse_no_txtr(line, game);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		ft_parse_so_txtr(line, game);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		ft_parse_ea_txtr(line, game);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		ft_parse_we_txtr(line, game);
	else if (ft_strncmp(line, "F ", 2) == 0)
		ft_parse_rgb_f(line, game);
	else if (ft_strncmp(line, "C ", 2) == 0)
		ft_parse_rgb_c(line, game);
	else
		ft_error("There is a wrong line in the .cub file", game, line);
	free(line);
}
