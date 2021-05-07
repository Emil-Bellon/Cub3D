/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebellon <ebellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 14:16:46 by ebellon           #+#    #+#             */
/*   Updated: 2021/05/07 17:45:18 by ebellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./Headers/cub3d.h"

void	ft_printf_data(t_data data)
{
	int	i;

	i = 0;
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
	printf("|*| MAP : x = %d / y = %d\n", data.map_x, data.map_y);
	while (data.map[i])
		printf("|*| --- |%s|\n", data.map[i++]);
	printf("-------------------------------------------------\n");
}

void	ft_printf_player(t_player player)
{
	printf("-------------------------------------------------\n");
	printf("|*| PLAYER : \n|*|\n");
	printf("|*| X = %f\n", player.x);
	printf("|*| Y = %f		ALPHA = %f\n", player.y, player.alpha);
	printf("-------------------------------------------------\n");
}

int	main(int ac, char **av)
{
	t_game	game;
	
	if (ac != 2)
		ft_error("Cub3D need exactly 1 argument", &game, NULL);
	game.stop = 0;
	game.player.alive = 0;
	ft_parse_main(av[1], &game);
	ft_check_data(&game);
	ft_printf_data(game.data);
	ft_printf_player(game.player);
	free(game.data.no);
	free(game.data.so);
	free(game.data.we);
	free(game.data.ea);
	free(game.data.sprite);
	ft_free_strs(game.data.map);
}