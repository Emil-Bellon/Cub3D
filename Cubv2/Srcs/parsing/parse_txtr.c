/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_txtr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebellon <ebellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 13:36:34 by ebellon           #+#    #+#             */
/*   Updated: 2021/05/06 16:46:21 by ebellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/cub3d.h"

void	ft_parse_no_txtr(char *line, t_game *game)
{
	int	i;

	i = 2;
	while (line[i] == ' ')
		i++;
	game->data.no = ft_substr(line, i, ft_strlen(line));
	free(line);
	if (ft_strncmp(game->data.no, "./", 2) != 0)
		ft_error("There is a problem with the NO texture", game);
}

void	ft_parse_so_txtr(char *line, t_game *game)
{
	int	i;

	i = 2;
	while (line[i] == ' ')
		i++;
	game->data.so = ft_substr(line, i, ft_strlen(line));
	free(line);
	if (ft_strncmp(game->data.so, "./", 2) != 0)
		ft_error("There is a problem with the SO texture", game);
}

void	ft_parse_ea_txtr(char *line, t_game *game)
{
	int	i;

	i = 2;
	while (line[i] == ' ')
		i++;
	game->data.ea = ft_substr(line, i, ft_strlen(line));
	free(line);
	if (ft_strncmp(game->data.ea, "./", 2) != 0)
		ft_error("There is a problem with the EA texture", game);
}

void	ft_parse_we_txtr(char *line, t_game *game)
{
	int	i;

	i = 2;
	while (line[i] == ' ')
		i++;
	game->data.we = ft_substr(line, i, ft_strlen(line));
	free(line);
	if (ft_strncmp(game->data.we, "./", 2) != 0)
		ft_error("There is a problem with the WE texture", game);
}

void	ft_parse_s_txtr(char *line, t_game *game)
{
	int	i;

	i = 1;
	while (line[i] == ' ')
		i++;
	game->data.sprite = ft_substr(line, i, ft_strlen(line));
	free(line);
	if (ft_strncmp(game->data.sprite, "./", 2) != 0)
		ft_error("There is a problem with the Sprite texture", game);
}