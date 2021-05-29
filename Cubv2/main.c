/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebellon <ebellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 14:16:46 by ebellon           #+#    #+#             */
/*   Updated: 2021/05/29 17:26:14 by ebellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./Headers/cub3d.h"

void	ft_init_game(t_game *game, char *str)
{
	game->player.alive = 0;
	game->player.x = 0;
	game->player.y = 0;
	game->player.alpha = 0;
	game->data.no = NULL;
	game->data.so = NULL;
	game->data.ea = NULL;
	game->data.we = NULL;
	game->data.map = NULL;
	game->data.key = (t_key){0, 0, 0, 0, 0, 0, 0};
	game->data.rx = WINX;
	game->data.ry = WINY;
	game->trip = 0;
	game->flip = 0;
	game->trip_color = 0x000000F0;
	game->lst_sprite = NULL;
	ft_parse_main(str, game);
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
			col = (t_col){x_win, size_wall.stop,
				game->data.ry, game->data.rgb_f};
			draw_col(col, game);
		}
		else
			draw_trip(x_win, game, size_wall);
		x_win++;
	}
	ft_draw_sprite(game, &game->txtr->var, game->txtr);
	ft_clear_lst(&game->lst_sprite);
}

int	ft_game(t_game *game)
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
	mlx_put_image_to_window(game->mlx->mlx_ptr,
		game->mlx->mlx_win, game->mlx->img, 0, 0);
	mlx_do_sync(game->mlx->mlx_ptr);
	if (game->trip > 0)
		ft_trip(game);
	return (0);
}

int	main(int ac, char **av)
{
	t_game			*game;
	t_mlx			mlx;

	game = ft_calloc(sizeof(t_game), 1);
	if (!game)
		exit(1);
	if (ac != 2)
		ft_error("Cub3D need exactly 1 argument", game, NULL);
	ft_init_game(game, av[1]);
	game->mlx = &mlx;
	game->mlx->mlx_ptr = mlx_init();
	game->mlx->mlx_win = mlx_new_window(game->mlx->mlx_ptr,
			game->data.rx, game->data.ry, "Cub3D");
	game->mlx->img = mlx_new_image(game->mlx->mlx_ptr,
			game->data.rx, game->data.ry);
	game->mlx->addr = mlx_get_data_addr(game->mlx->img,
			&game->mlx->bits_per_pixel, &game->mlx->line_length,
			&game->mlx->endian);
	ft_check_data(game);
	mlx_hook(game->mlx->mlx_win, 02, 1L << 0, &key_pressed, game);
	mlx_hook(game->mlx->mlx_win, 03, 1L << 1, &key_released, game);
	mlx_hook(game->mlx->mlx_win, 17, 0, &ft_close, game);
	mlx_loop_hook(game->mlx->mlx_ptr, ft_game, game);
	mlx_loop(game->mlx->mlx_ptr);
	return (0);
}
