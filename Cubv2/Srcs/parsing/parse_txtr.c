/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_txtr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebellon <ebellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 13:36:34 by ebellon           #+#    #+#             */
/*   Updated: 2021/05/07 17:49:10 by ebellon          ###   ########lyon.fr   */
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
}

void	ft_parse_so_txtr(char *line, t_game *game)
{
	int	i;

	i = 2;
	while (line[i] == ' ')
		i++;
	game->data.so = ft_substr(line, i, ft_strlen(line));
}

void	ft_parse_ea_txtr(char *line, t_game *game)
{
	int	i;

	i = 2;
	while (line[i] == ' ')
		i++;
	game->data.ea = ft_substr(line, i, ft_strlen(line));
}

void	ft_parse_we_txtr(char *line, t_game *game)
{
	int	i;

	i = 2;
	while (line[i] == ' ')
		i++;
	game->data.we = ft_substr(line, i, ft_strlen(line));
}

void	ft_parse_s_txtr(char *line, t_game *game)
{
	int	i;

	i = 1;
	while (line[i] == ' ')
		i++;
	game->data.sprite = ft_substr(line, i, ft_strlen(line));
}