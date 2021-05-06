/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebellon <ebellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 13:40:24 by ebellon           #+#    #+#             */
/*   Updated: 2021/05/06 16:46:03 by ebellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/cub3d.h"

static void	ft_free_strs(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

static int	ft_rgb_ok(char **rgb)
{
	int i;
	int j;

	i = 0;
	while (rgb[i])
	{
		j = 0;
		while (rgb[i][j])
			if (!(ft_isdigit(rgb[i][j++])))
				return (0);
		i++;
	}
	return (1);
}

void		ft_parse_res(char *line, t_game *game)
{
	char	**res;
	int		i;

	res = ft_split(line, ' ');
	i = 0;
	while (res[i])
		i++;
	if (i != 3)
		ft_error("There is a problem with the Resolution", game);
	i = 0;
	while (res[1][i])
		if (!(ft_isdigit(res[1][i++])))
			ft_error("There is a problem with the x Resolution", game);
	i = 0;
	while (res[2][i])
		if (!(ft_isdigit(res[2][i++])))
			ft_error("There is a problem with the y Resolution", game);
	game->data.rx = ft_atoi(res[1]);
	game->data.ry = ft_atoi(res[2]);
	free(line);
	ft_free_strs(res);
}

void		ft_parse_rgb_f(char *line, t_game *game)
{
	char	**rgb;
	char	*str;
	int		i;

	i = 1;
	while (line[i] == ' ')
		i++;
	str = ft_substr(line, i, ft_strlen(line));
	rgb = ft_split(str, ',');
	i = 0;
	while (rgb[i])
		i++;
	if (i != 3)
		ft_error("There is a problem with the F rgb", game);
	if (ft_rgb_ok(rgb) == 0)
		ft_error("There is a problem with the digits of F rgb", game);
	game->data.rgb_f = (ft_atoi(rgb[0]) * (256 * 256))
						+ (ft_atoi(rgb[1]) * 256) + ft_atoi(rgb[2]);
	free(str);
	free(line);
	ft_free_strs(rgb);
}

void		ft_parse_rgb_c(char *line, t_game *game)
{
	char	**rgb;
	char	*str;
	int		i;

	i = 1;
	while (line[i] == ' ')
		i++;
	str = ft_substr(line, i, ft_strlen(line));
	rgb = ft_split(str, ',');
	i = 0;
	while (rgb[i])
		i++;
	if (i != 3)
		ft_error("There is a problem with the C rgb", game);
	if (!(ft_rgb_ok(rgb)))
		ft_error("There is a problem with the digits of C rgb", game);
	game->data.rgb_c = (ft_atoi(rgb[0]) * (256 * 256))
						+ (ft_atoi(rgb[1]) * 256) + ft_atoi(rgb[2]);
	free(str);
	free(line);
	ft_free_strs(rgb);
}