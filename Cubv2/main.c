/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebellon <ebellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 14:16:46 by ebellon           #+#    #+#             */
/*   Updated: 2021/05/14 16:24:31 by ebellon          ###   ########lyon.fr   */
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

void	ft_init_game(t_game *game)
{
	game->player.alive = 0;
	game->player.x = 0;
	game->player.y = 0;
	game->player.alpha = 0;
	game->data.no = NULL;
	game->data.so = NULL;
	game->data.ea = NULL;
	game->data.we = NULL;
	game->data.sprite = NULL;
	game->data.map = NULL;
	game->data.key = (t_key){0, 0, 0, 0, 0, 0};
}

void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	clean_window(t_game *game)
{
	int		y;
	int		x;
	int		color;

	color = 0x00000000;
	y = -1;
	x = -1;
	while (++y < game->data.ry)
	{
		x = -1;
		while (++x < game->data.rx)
			my_mlx_pixel_put(game->mlx, x, y, color);
	}
}

void	draw_col(t_col col, t_game *game)
{
	int	size;

	size = col.start;
	while (size < col.size_max)
	{
		if (game->trip > 0)
		{
			if (size % (int)game->trip == 0)
				my_mlx_pixel_put(game->mlx, col.x, size, col.color);
		}
		else
				my_mlx_pixel_put(game->mlx, col.x, size, col.color);
		size++;
	}
}

t_size_wall	ft_get_wall_size(int x_win, t_game *game)
{
	t_size_wall	size_wall;

	size_wall.height = (int)(game->data.ry / ft_dda(game, x_win, &(game->txtr->var)));
	size_wall.start = game->data.ry / 2 - size_wall.height / 2;
	if (size_wall.start < 0)
		size_wall.start = 0;
	size_wall.stop = game->data.ry / 2 + size_wall.height / 2;
	if (size_wall.stop >= game->data.ry)
		size_wall.stop = game->data.ry;
	return (size_wall);
}

void	draw_screen(t_game *game)
{
	int			x_win;
	t_col		col;
	t_size_wall	size_wall;
	
	x_win = 0;
	while (x_win < game->data.rx)
	{
		size_wall = ft_get_wall_size(x_win, game);
		if (game->trip == 0)
		{
			col = (t_col){x_win, 0, size_wall.start, game->data.rgb_c};
			draw_col(col, game);
			draw_wall(game, size_wall, game->txtr, x_win);
			col = (t_col){x_win, size_wall.stop, game->data.ry, game->data.rgb_f};
			draw_col(col, game);
		}
		else
		{
			if (x_win % (int)game->trip == 0)
			{
				col = (t_col){x_win, size_wall.start, size_wall.stop, game->trip_color};
				draw_col(col, game);
			}
			col = (t_col){x_win, 0, size_wall.start, 0x00000000};
			draw_col(col, game);
			col = (t_col){x_win, size_wall.stop, game->data.ry, 0x00000000};
			draw_col(col, game);
		}
		x_win++;
	}
}

int		ft_game(t_game *game)
{
	int		y_map;

	y_map = 0;
	if (game->data.key.esc == 1)
		ft_exit(game);
	clean_window(game);
	move_player(game);
	draw_screen(game);

	printf("\033[H\033[2J");
	while (y_map < game->data.map_y)
		printf("%-*s\n", game->data.map_x, game->data.map[y_map++]);

	mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->mlx_win, game->mlx->img, 0, 0);
	mlx_do_sync(game->mlx->mlx_ptr);
	if (game->trip > 0)
	{
		if (game->flip == 0)
		{
			game->trip += 0.5;
			if (game->trip > 7)
				game->flip = 1;
		}
		else
		{
			game->trip -= 0.5;
			if (game->trip < 2.5)
				game->flip = 0;
		}
		// game->trip_color *= 5;
		if (game->trip_color > 0x01000000)
			game->trip_color = 0x00000001;
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_game	*game;
	t_mlx	mlx;
	
	game = ft_calloc(sizeof(t_game), 1);
	if (!game)
		exit(EXIT_SUCCESS);
	ft_init_game(game);
	if (ac != 2)
		ft_error("Cub3D need exactly 1 argument", game, NULL);
	ft_parse_main(av[1], game);
	game->trip = 0;
	game->flip = 0;
	game->trip_color = 0x000000FF;
	game->mlx = &mlx;
	game->mlx->mlx_ptr = mlx_init();
	game->mlx->mlx_win = mlx_new_window(game->mlx->mlx_ptr, game->data.rx, game->data.ry, "Cub3D !");
	game->mlx->img = mlx_new_image(game->mlx->mlx_ptr, game->data.rx, game->data.ry);
	game->mlx->addr = mlx_get_data_addr(game->mlx->img, &game->mlx->bits_per_pixel, &game->mlx->line_length,
								&game->mlx->endian);

	ft_check_data(game);
	mlx_put_image_to_window(game->mlx->mlx_ptr, game->mlx->mlx_win, game->mlx->img, 0, 0);
	mlx_hook(game->mlx->mlx_win, 02, 1L << 0, key_pressed, game);
	mlx_hook(game->mlx->mlx_win, 03, 1L << 1, key_released, game);
	mlx_loop_hook(game->mlx->mlx_ptr, ft_game, game);
	mlx_loop(game->mlx->mlx_ptr);

	free(game->data.no);
	free(game->data.so);
	free(game->data.we);
	free(game->data.ea);
	free(game->data.sprite);
	ft_free_strs(game->data.map);
	return (0);
}