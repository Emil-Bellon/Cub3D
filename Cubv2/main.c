/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebellon <ebellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 14:16:46 by ebellon           #+#    #+#             */
/*   Updated: 2021/05/06 16:48:10 by ebellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./Headers/cub3d.h"

void	ft_printf_data(t_data data)
{
	printf("-------------------------------------------------\n");
	printf("|*| DATA : \n|*|\n");
	printf("|*| res = |%d * %d|\n|*|\n", data.rx, data.ry);
	printf("|*| r_f = |%.3d|\n", data.rgb_f / (256*256));
	printf("|*| g_f = |%.3d|\n", (data.rgb_f % (256*256)) / 256);
	printf("|*| b_f = |%.3d|\n|*|\n", ((data.rgb_f % (256*256)) % 256));
	printf("|*| r_c = |%.3d|\n", data.rgb_c / (256*256));
	printf("|*| g_c = |%.3d|\n", (data.rgb_c % (256*256)) / 256);
	printf("|*| b_c = |%.3d|\n|*|\n", ((data.rgb_c % (256*256)) % 256));
	printf("|*| no = |%s|\n", data.no);
	printf("|*| so = |%s|\n", data.so);
	printf("|*| we = |%s|\n", data.we);
	printf("|*| ea = |%s|\n", data.ea);
	printf("|*| s  = |%s|\n|*|\n", data.sprite);
	//printf("|*| MAP : x = %d / y = %d\n", data.map_x, data.map_y);
	printf("-------------------------------------------------\n");
}

int	main(int ac, char **av)
{
	t_game	game;
	
	(void)ac;
	game.stop = 0;
	ft_parse_main(av[1], &game);
	ft_printf_data(game.data);
}