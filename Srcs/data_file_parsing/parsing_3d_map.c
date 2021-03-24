/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_3d_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebellon <ebellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 12:44:25 by ebellon           #+#    #+#             */
/*   Updated: 2021/03/24 15:42:09 by ebellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/cub3d.h"

void	ft_free_3d_map(t_box **map)
{
	int y;

	y = 0;
	while (map[y])
		free(map[y++]);
	free(map);
}

t_box	**ft_init_3d_map(t_parse_map *cub)
{
	t_box	**map;
	int		y;

	map = ft_calloc(cub->map_y + 1, sizeof(t_box *));
	if (!map)
		ft_exit();
	y = 0;
	while (y < cub->map_y)
	{
		map[y] = ft_calloc(cub->map_x + 1, sizeof(t_box));
		if (!map[y])
		{
			ft_free_3d_map(map);
			ft_exit();
		}
		y++;
	}
	return (map);
}

void	ft_init_eye2(t_eye *eye, char c, int x, int y)
{
	if (c == 'W')
	{
		eye->x = x;
		eye->y = y;
		eye->z = 1;
		eye->alpha = PI;
	}
	else if (c == 'E')
	{
		eye->x = x;
		eye->y = y;
		eye->z = 1;
		eye->alpha = 0;
	}
}

void	ft_init_eye1(t_eye *eye, char c, int x, int y)
{
	if (c == 'N')
	{
		eye->x = x;
		eye->y = y;
		eye->z = 1;
		eye->alpha = (3 * PI) / 2;
	}
	else if (c == 'S')
	{
		eye->x = x;
		eye->y = y;
		eye->z = 1;
		eye->alpha = PI / 2;
	}
	else
		ft_init_eye2(eye, c, x, y);
}

void	ft_init_tabs(int height[10], int start[10])
{
	height[0] = 0;
	start[0] = 0;
	height[1] = 10;
	start[1] = 0;
	height[2] = 1;
	start[2] = 0;
}

t_box	ft_fill_box(char c, int x, int y, t_eye *eye)
{
	t_box	box;
	int		height[10];
	int		start[10];

	ft_init_tabs(height, start);
	box = (t_box){-1, -1, -1};
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		ft_init_eye1(eye, c, x, y);
		box = (t_box){0, 0, 0};
	}
	else if (ft_isdigit(c))
		box = (t_box){c - '0', height[c - '0'], start[c - '0']};
	else if (c == ' ')
	{
		box = (t_box){0, 0, 0};
	}
	else
		ft_exit2(c);
	return (box);
}

void	ft_fill_3d_map(t_box **map, t_eye *eye, t_parse_map *cub)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < cub->map_y)
	{
		x = 0;
		while (x < cub->map_x)
		{
			if (cub->map[y][x] && x < (int)ft_strlen(cub->map[y]))
			{
				//printf("x = %d, y = %d ---> |%c|\n", x, y, cub->map[y][x]);
				map[y][x] = ft_fill_box(cub->map[y][x], x, y, eye);
			}
			else
				map[y][x] = ft_fill_box(' ', x, y, eye);
			x++;
		}
		y++;
	}
}

void	ft_fill_data_and_free(t_data *data, t_parse_map *cub)
{
	int	i;

	i = 0;
	data->map_x = cub->map_x;
	data->map_y = cub->map_y;
	data->res_x = cub->res_x;
	data->res_y = cub->res_y;
	data->rgb_c = cub->rgb_c;
	data->rgb_f = cub->rgb_f;
	data->texture[0] = ft_strdup(cub->no);
	data->texture[1] = ft_strdup(cub->so);
	data->texture[2] = ft_strdup(cub->we);
	data->texture[3] = ft_strdup(cub->ea);
	data->texture[4] = ft_strdup(cub->sprite);
	free(cub->no);
	free(cub->so);
	free(cub->ea);
	free(cub->we);
	free(cub->sprite);
	while (cub->map[i])
		free(cub->map[i++]);
	free(cub->map);
}

t_box	**ft_fill_data_3d_map(t_parse_map *cub, t_data *data, t_eye *eye)
{
	t_box	**map;

	map = ft_init_3d_map(cub);
	ft_fill_3d_map(map, eye, cub);
	/* check des conditions */
	ft_fill_data_and_free(data, cub);
	return (map);
}