/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebellon <ebellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 15:12:07 by ebellon           #+#    #+#             */
/*   Updated: 2021/03/24 15:49:04 by ebellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/cub3d.h"

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

void	ft_printf_data(t_data data)
{
	printf("-------------------------------------------------\n");
	printf("|*| DATA : \n|*|\n");
	printf("|*| res_x = |%d * %d|\n|*|\n", data.res_x, data.res_y);
	printf("|*| r_f = |%.3d|\n", data.rgb_f / (256*256));
	printf("|*| g_f = |%.3d|\n", (data.rgb_f % (256*256)) / 256);
	printf("|*| b_f = |%.3d|\n|*|\n", ((data.rgb_f % (256*256)) % 256));
	printf("|*| r_c = |%.3d|\n", data.rgb_c / (256*256));
	printf("|*| g_c = |%.3d|\n", (data.rgb_c % (256*256)) / 256);
	printf("|*| b_c = |%.3d|\n|*|\n", ((data.rgb_c % (256*256)) % 256));
	printf("|*| no = |%s|\n", data.texture[0]);
	printf("|*| so = |%s|\n", data.texture[1]);
	printf("|*| we = |%s|\n", data.texture[2]);
	printf("|*| ea = |%s|\n", data.texture[3]);
	printf("|*| s  = |%s|\n|*|\n", data.texture[4]);
	printf("|*| MAP : x = %d / y = %d\n", data.map_x, data.map_y);
	printf("-------------------------------------------------\n");
}

void	ft_printf_map(t_box **map, t_parse_map cub)
{
	int x;
	int y;

	x = 0;
	y = 0;
	printf("3D map (type)\n\n");
	while (y < cub.map_y)
	{
		x = 0;
		while (x < cub.map_x)
		{
			if (map[y][x].type == 0)
				printf("[ ]");
			else
				printf("[%d]", map[y][x].type);
			x++;
		}
		y++;
		printf("\n");
	}
}

void	ft_printf_eye(t_eye eye)
{
	printf("-------------------------------------------------\n");
	printf("|*| EYE : \n|*|\n");
	printf("|*| X = %f\n", eye.x);
	printf("|*| Y = %f		ALPHA = %f\n", eye.y, eye.alpha);
	printf("|*| Z = %f\n", eye.z);
	printf("-------------------------------------------------\n");
}

void            my_mlx_pixel_put(t_mlxdata *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void	draw_square_from_topleft(t_mlxdata data, int topleft_x, int topleft_y, int size_in_pix)
{
	for (int i = 0; i < size_in_pix; i++)
	{
		my_mlx_pixel_put(&data, topleft_x + i, topleft_y, 0x00FF0000);
		my_mlx_pixel_put(&data, topleft_x + i, topleft_y + size_in_pix, 0x00FF0000);
		my_mlx_pixel_put(&data, topleft_x + size_in_pix, topleft_y + i, 0x00FF0000);
		my_mlx_pixel_put(&data, topleft_x, topleft_y + i, 0x00FF0000);

	}
}

void	test_draw1(t_mlxdata data, int topleft_x, int topleft_y, int size_in_pix)
{
	int	y;
	int	x;
	int	color;

	y = -1;
	color = 1;
	while (++y < size_in_pix)
	{
		x = -1;
		while (++x < size_in_pix)
		{
			if (x % 2 == 0 && y % 2 != 0)
				my_mlx_pixel_put(&data, topleft_x + x, topleft_y + y, color);
			color *= 3;
		}
	}
}

void	test_draw2(t_mlxdata data, int topleft_x, int topleft_y, int size_in_pix)
{
	int	y;
	int	x;
	int	color;

	y = -1;
	color = 1;
	while (++y < size_in_pix)
	{
		x = -1;
		while (++x < size_in_pix)
		{
			if (x % 5 != 0 && y % 5 != 0)
				my_mlx_pixel_put(&data, topleft_x + x, topleft_y + y, color);
			color *= 5;
		}
	}
}

int		main(int ac, char **av)
{
	t_parse_map	cub;
	t_eye		eye;
	t_box		**map;
	t_data		data;
	void		*mlx_ptr;
	void		*mlx_win;
	t_mlxdata	img;
	int			y;
	int			x;
	int			size;

	(void)ac;
	y = 0;
	x = 0;
	size = 50;
	ft_parse_cub(av[1], &cub);
	map = ft_fill_data_3d_map(&cub, &data, &eye);
	//ft_printf_cub(cub);
	ft_printf_data(data);
	ft_printf_map(map, cub);
	ft_printf_eye(eye);

	mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, 1920, 1080, "Cub3D !");
	img.img = mlx_new_image(mlx_ptr, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	//test_draw(img, 0, 0, 1080);

	while (y < data.map_y)
	{
		x = 0;
		while (x < data.map_x)
		{
			if (map[y][x].type == 1)
				test_draw2(img, (x * size), (y * size), size);
			else
				test_draw1(img, (x * size), (y * size), size);
			x++;
		}
		y++;
	}
	
	mlx_put_image_to_window(mlx_ptr, mlx_win, img.img, 0, 0);
	mlx_loop(mlx_ptr);
	
	return (0);
}
