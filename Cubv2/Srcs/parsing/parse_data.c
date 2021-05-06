/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebellon <ebellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 11:36:39 by ebellon           #+#    #+#             */
/*   Updated: 2021/05/06 16:48:18 by ebellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/cub3d.h"

static void	ft_parse_line_data(char *line, t_game *game)
{
	if (ft_strncmp(line, "R ", 2) == 0)
		ft_parse_res(line, game);
	if (ft_strncmp(line, "NO ", 3) == 0)
		ft_parse_no_txtr(line, game);
	if (ft_strncmp(line, "SO ", 3) == 0)
		ft_parse_so_txtr(line, game);
	if (ft_strncmp(line, "EA ", 3) == 0)
		ft_parse_ea_txtr(line, game);
	if (ft_strncmp(line, "WE ", 3) == 0)
		ft_parse_we_txtr(line, game);
	if (ft_strncmp(line, "S ", 2) == 0)
		ft_parse_s_txtr(line, game);
	if (ft_strncmp(line, "F ", 2) == 0)
		ft_parse_rgb_f(line, game);
	if (ft_strncmp(line, "C ", 2) == 0)
		ft_parse_rgb_c(line, game);
}

void		ft_parse_main(char *path, t_game *game)
{
	int		fd;
	char	*line;
	int		ret_read;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_error("There was a problem while opening .cub file", game);
	ret_read = get_next_line(fd, &line);
	while (ret_read == 1 && game->stop == 0)
	{
		if (line[0] >= 'A' && line[0] <= 'Z')
			ft_parse_line_data(line, game);
		else if (line[0] != 0 && line[0] != ' ' && line[0] != '1')
		{
			ft_error("There is a wrong line in the .cub file", game);
			break;
		}
		ret_read = get_next_line(fd, &line);
	}
	if (ret_read == -1)
		ft_error("There was a problem while reading .cub file", game);
	printf("ret_read = %d\n", ret_read);
	/*set char map here*/
}
