/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebellon <ebellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 15:12:07 by ebellon           #+#    #+#             */
/*   Updated: 2021/03/19 17:08:37 by ebellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/cub3d.h"

void	ft_printf_cub(t_parse_map cub)
{
	int	i;

	i = 0;
	printf("-------------------------------------------------\n");
	printf("|*| DATA : \n|*|\n");
	printf("|*| res_x = |%d * %d|\n|*|\n", cub.res_x, cub.res_y);
	printf("|*| r_f = |%.3d|\n", cub.rgb_f / (256*256));
	printf("|*| g_f = |%.3d|\n", (cub.rgb_f % (256*256)) / 256);
	printf("|*| b_f = |%.3d|\n|*|\n", ((cub.rgb_f % (256*256)) % 256));
	printf("|*| r_c = |%.3d|\n", cub.rgb_c / (256*256));
	printf("|*| g_c = |%.3d|\n", (cub.rgb_c % (256*256)) / 256);
	printf("|*| b_c = |%.3d|\n|*|\n", ((cub.rgb_c % (256*256)) % 256));
	printf("|*| no = |%s|\n", cub.no);
	printf("|*| so = |%s|\n", cub.so);
	printf("|*| we = |%s|\n", cub.we);
	printf("|*| ea = |%s|\n", cub.ea);
	printf("|*| s  = |%s|\n|*|\n", cub.sprite);
	printf("|*| MAP : x = %d / y = %d\n|*|\n", cub.map_x, cub.map_y);
	while (cub.map[i])
		printf("|*| --- |%s|\n", cub.map[i++]);
	printf("-------------------------------------------------\n");
}

void	ft_printf_map(t_box **map, t_parse_map cub)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < cub.map_y)
	{
		x = 0;
		while (x < cub.map_x)
		{
			printf("%d", map[y][x].type);
			x++;
		}
		y++;
		printf("\n");
	}
}

int		main(int ac, char **av)
{
	t_parse_map	cub;
	t_eye		eye;
	t_box		**map;
	t_data		data;
	
	ft_parse_cub(av[1], &cub);
	map = ft_fill_data_3d_map(&cub, &data, &eye);
	ft_printf_cub(cub);
	ft_printf_map(map, cub);
	return (0);
}
