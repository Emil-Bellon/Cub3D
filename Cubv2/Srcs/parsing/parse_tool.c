/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebellon <ebellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 15:10:54 by ebellon           #+#    #+#             */
/*   Updated: 2021/05/28 14:05:44 by ebellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/cub3d.h"

int	ft_is_char_map(char c)
{
	if (c == ' ' || c == '0' || c == '1' || c == '2' || c == '3' || c == '4')
		return (1);
	else if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (2);
	return (0);
}

static void	free_all(char **strs, int j)
{
	int	i;

	i = 0;
	while (i != j)
		free(strs[i++]);
	free(strs);
}

int	ft_strslen(char **strs)
{
	int	i;

	i = 0;
	if (!strs)
		return (0);
	while (strs[i] != NULL)
		i++;
	return (i);
}

char	**ft_strsjoin(char **s1, char *s2)
{
	char	**strs;
	int		i;

	i = 0;
	strs = malloc(sizeof(char *) * (ft_strslen(s1) + 2));
	if (!strs)
		return (NULL);
	if (s1)
	{
		while (s1[i])
		{
			strs[i] = ft_strdup(s1[i]);
			i++;
		}
	}
	strs[i++] = ft_strdup(s2);
	strs[i] = NULL;
	free_all(s1, ft_strslen(s1));
	free(s2);
	return (strs);
}

void	ft_reset_map(t_game *game)
{
	int	y;
	int	x;
	int	x_max;

	y = 0;
	while (y < game->data.map_y)
	{
		x = 0;
		x_max = (int)ft_strlen(game->data.map[y]);
		while (x < x_max)
		{
			if (game->data.map[y][x] == '|')
				game->data.map[y][x] = '1';
			if (game->data.map[y][x] == '.')
				game->data.map[y][x] = ' ';
			if (game->data.map[y][x] == '$')
				game->data.map[y][x] = '2';
			if (game->data.map[y][x] == '*')
				game->data.map[y][x] = '3';
			if (game->data.map[y][x] == '&')
				game->data.map[y][x] = '4';
			x++;
		}
		y++;
	}
}
