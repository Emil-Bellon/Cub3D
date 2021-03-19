/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebellon <ebellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 15:11:07 by ebellon           #+#    #+#             */
/*   Updated: 2021/03/19 14:02:06 by ebellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/cub3d.h"

void	ft_parse_res(char **strs, t_parse_map *cub)
{
	int	i;

	i = 0;
	while (strs[i])
		i++;
	if (i != 3)
		ft_exit();
	cub->res_x = ft_atoi(strs[1]);
	cub->res_y = ft_atoi(strs[2]);
}

void	ft_parse_no_texture(char **strs, t_parse_map *cub)
{
	int	i;

	i = 0;
	while (strs[i])
		i++;
	if (i != 2)
		ft_exit();
	cub->no = ft_strdup(strs[1]);
}

void	ft_parse_so_texture(char **strs, t_parse_map *cub)
{
	int	i;

	i = 0;
	while (strs[i])
		i++;
	if (i != 2)
		ft_exit();
	cub->so = ft_strdup(strs[1]);
}

void	ft_parse_we_texture(char **strs, t_parse_map *cub)
{
	int	i;

	i = 0;
	while (strs[i])
		i++;
	if (i != 2)
		ft_exit();
	cub->we = ft_strdup(strs[1]);
}

void	ft_parse_ea_texture(char **strs, t_parse_map *cub)
{
	int	i;

	i = 0;
	while (strs[i])
		i++;
	if (i != 2)
		ft_exit();
	cub->ea = ft_strdup(strs[1]);
}

void	ft_parse_s_texture(char **strs, t_parse_map *cub)
{
	int	i;

	i = 0;
	while (strs[i])
		i++;
	if (i != 2)
		ft_exit();
	cub->sprite = ft_strdup(strs[1]);
}

void	ft_parse_rgb_f(char **strs, t_parse_map *cub)
{
	char	**rgb;
	int		i;

	i = 0;
	while (strs[i])
		i++;
	if (i != 2)
		ft_exit();
	rgb = ft_split(strs[1], ',');
	i = 0;
	while (rgb[i])
		i++;
	if (i != 3)
		ft_exit();
	cub->rgb_f = (ft_atoi(rgb[0]) * (256 * 256)) + (ft_atoi(rgb[1]) * 256) + ft_atoi(rgb[2]);
}

void	ft_parse_rgb_c(char **strs, t_parse_map *cub)
{
	char	**rgb;
	int		i;

	i = 0;
	while (strs[i])
		i++;
	if (i != 2)
		ft_exit();
	rgb = ft_split(strs[1], ',');
	i = 0;
	while (rgb[i])
		i++;
	if (i != 3)
		ft_exit();
	cub->rgb_c = (ft_atoi(rgb[0]) * (256 * 256)) + (ft_atoi(rgb[1]) * 256) + ft_atoi(rgb[2]);
}

void	ft_free_strs(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	ft_split_line(char *str, t_parse_map *cub)
{
	char	**strs;
	
	strs = ft_split(str, ' ');
	if (!strs)
		ft_exit();
	if (ft_strncmp(strs[0], "R", ft_strlen(strs[0])) == 0)
		ft_parse_res(strs, cub);
	if (ft_strncmp(strs[0], "NO", ft_strlen(strs[0])) == 0)
		ft_parse_no_texture(strs, cub);
	if (ft_strncmp(strs[0], "SO", ft_strlen(strs[0])) == 0)
		ft_parse_so_texture(strs, cub);
	if (ft_strncmp(strs[0], "WE", ft_strlen(strs[0])) == 0)
		ft_parse_we_texture(strs, cub);
	if (ft_strncmp(strs[0], "EA", ft_strlen(strs[0])) == 0)
		ft_parse_ea_texture(strs, cub);
	if (ft_strncmp(strs[0], "S", ft_strlen(strs[0])) == 0)
		ft_parse_s_texture(strs, cub);
	if (ft_strncmp(strs[0], "F", ft_strlen(strs[0])) == 0)
		ft_parse_rgb_f(strs, cub);
	if (ft_strncmp(strs[0], "C", ft_strlen(strs[0])) == 0)
		ft_parse_rgb_c(strs, cub);
	ft_free_strs(strs);
}

void	ft_check_bot_cub(char *line, int fd)
{
	if (line[0] != 0)
		ft_exit();
	free(line);
	while (get_next_line(fd, &line) == 1)
	{
		if (line[0] != 0)
			ft_exit();
		free(line);
	}
	if (line[0] != 0)
		ft_exit();
	free(line);
}

int		ft_get_size(char *line, int fd)
{
	int	map_size;
	int	ret;
	
	map_size = 0;
	if (line[0] == '1' || line[0] == ' ')
		map_size++;
	else
		ft_exit();
	free(line);
	ret = get_next_line(fd, &line);
	while (ret == 1 && (line[0] == '1' || line[0] == ' '))
	{
		if (line[0] == '1' || line[0] == ' ')
			map_size++;
		else
			ft_exit();
		free(line);
		ret = get_next_line(fd, &line);
	}
	if (line[0] == '1' || line[0] == ' ' || ret == 0)
	{
		map_size++;
		get_next_line(fd, &line);
	}
	ft_check_bot_cub(line, fd);
	return (map_size);
}

void	ft_set_char_map(t_parse_map *cub, char *path)
{
	int		fd;
	char	*line;
	int		i;
	
	fd = open(path, O_RDONLY);
	i = 0;
	cub->map = ft_calloc(cub->map_y + 1, sizeof(char *));
	while (get_next_line(fd, &line) == 1 && line[0] != ' ' && line[0] != '1')
		free(line);
	if (line[0] == '1' || line[0] == ' ')
		cub->map[i++] = ft_strdup(line);
	else
		ft_exit();
	free(line);
	while (get_next_line(fd, &line) == 1 && (line[0] == '1' || line[0] == ' '))
	{
		if (line[0] == '1' || line[0] == ' ')
			cub->map[i++] = ft_strdup(line);
		else
			ft_exit();
		free(line);
	}
	if (line[0] == '1' || line[0] == ' ')
		cub->map[i++] = ft_strdup(line);
	free(line);
	cub->map[i] = 0;
	close(fd);
}

void	ft_get_map_x(t_parse_map *cub)
{
	int	i;

	i = 0;
	while (cub->map[i])
	{
		if (ft_strlen(cub->map[i]) > cub->map_x)
			cub->map_x = ft_strlen(cub->map[i]);
		i++;
	}
}

void	ft_parse_cub(char *path, t_parse_map *cub)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &line) == 1 && line[0] != ' ' && line[0] != '1')
	{
		if (line[0] != 0)
			ft_split_line(line, cub);
		free(line);
	}
	if (line[0] == ' ' || line[0] == '1')
	{
		cub->map_y = ft_get_size(line, fd);
		close(fd);
		ft_set_char_map(cub, path);
	}
	else
	{
		free(line);
		ft_exit();
	}
	ft_get_map_x(cub);
}
