/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebellon <ebellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 15:12:07 by ebellon           #+#    #+#             */
/*   Updated: 2021/04/09 13:47:40 by ebellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./Headers/cub3d.h"

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

void	ft_printf_map(t_box **map, t_data data)
{
	int x;
	int y;

	x = 0;
	y = 0;
	printf("3D map (type)\n\n");
	while (y < data.map_y)
	{
		x = 0;
		while (x < data.map_x)
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

void	my_mlx_pixel_put(t_mlxdata *data, int x, int y, int color)
{
	char	*dst;

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

void	test_draw1(t_all_data *data, int topleft_x, int topleft_y, int size_in_pix)
{
	int	y;
	int	x;
	int	color;

	y = -1;
	color = 1;
	x = -1;
	while (++y < size_in_pix)
	{
		x = -1;
		while (++x < size_in_pix)
		{
			if (x % 2 == 0 && y % 2 != 0)
				my_mlx_pixel_put(&(data->mlx_data), topleft_x + x, topleft_y + y, color + data->frame);
			color *= 3;
		}
	}
}

void	test_draw2(t_all_data *data, int topleft_x, int topleft_y, int size_in_pix)
{
	int	y;
	int	x;
	int	color;

	y = -1;
	color = 1;
	x = -1;
	while (++y < size_in_pix)
	{
		x = -1;
		while (++x < size_in_pix)
		{
			if (x % 5 != 0 && y % 5 != 0)
				my_mlx_pixel_put(&(data->mlx_data), topleft_x + x, topleft_y + y, color + data->frame);
			color *= 5;
		}
	}
}

void	test_draw3(t_all_data *data, int topleft_x, int topleft_y, int size_in_pix)
{
	int	y;
	int	x;
	int	color;

	y = -1;
	color = 0x00FF0000;
	x = -1;
	while (++y < size_in_pix)
	{
		x = -1;
		while (++x < size_in_pix)
			my_mlx_pixel_put(&(data->mlx_data), topleft_x + x, topleft_y + y, color);
	}
}

void	draw_col(t_all_data *data, int topleft_x, int topleft_y, int size_in_pix)
{
	int	y;
	int	color;

	y = -1;
	color = 0x0000FF00;
	while (++y < size_in_pix)
		my_mlx_pixel_put(&(data->mlx_data), topleft_x, topleft_y + y, color);
}

void	draw_ray(t_all_data *data, int topleft_x, int topleft_y)
{
	float	y;
	float	x;
	float	b;
	float	a;
	int		color;

	color = 0x00FF0000;
	y = 0;
	a = ((topleft_x + cos(data->eye.alpha)) - topleft_x)/((topleft_y + sin(data->eye.alpha)) - topleft_y);
	b = topleft_y - a * topleft_x;
	while (y < data->data.map_y)
	{
		x = 0;
		while (x < data->data.map_x)
		{
			if (y == a * x + b)
			{
				my_mlx_pixel_put(&(data->mlx_data), x * SIZE, y * SIZE, 0x00FFFFF);
				if (data->map[(int)y][(int)x].type == 1)
					my_mlx_pixel_put(&(data->mlx_data), x * SIZE, y * SIZE, color);
				printf("x = %f, y = %f\n", x, y);
			}
			x += 0.1;
		}
		y += 0.1;
	}
}

t_point	get_next_grid_ver(t_point p0, float alpha)
{
	t_point	p1;
	
	if (cos(alpha) > 0)
		p1.x = (int)p0.x + 1;
	else
		p1.x = (int)p0.x - 1;
	p1.y = p0.y + sin(alpha);
	return (p1);
}

t_point	get_next_grid_hor(t_point p0, float alpha)
{
	t_point	p1;
	
	if (sin(alpha) > 0)
		p1.y = (int)p0.y + 1;
	else
		p1.y = (int)p0.y - 1;
	if (p1.y > p0.y)
		p1.x = p0.x + ((p1.y - p0.y) * tan(alpha));
	else
		p1.x = p0.x + ((p0.y - p1.y) * tan(alpha));
	return (p1);
}

void	shoot_ray(t_all_data *a_data, float alpha)
{
	t_point	p1_h;
	t_point	p1_v;
	t_point	p0;

	p0 = (t_point){a_data->eye.x, a_data->eye.y};
	p1_h = get_next_grid_hor(p0, alpha);
	p1_v = get_next_grid_ver(p0, alpha);
	printf("alpha = %f\n", alpha*180/PI);
	printf("cos(alpha) = %f\n", cos(alpha));
	printf("p0 = x->%f, y->%f\n", p0.x, p0.y);
	while (p1_h.y < a_data->data.map_y && p1_h.x < a_data->data.map_x &&
			a_data->map[(int)(p1_h.y)][(int)(p1_h.x)].type != 1)
		p1_h = get_next_grid_hor(p1_h, alpha);
	while ((p1_v.y) < a_data->data.map_y && (p1_v.x) < a_data->data.map_x &&
			a_data->map[(int)(p1_v.y)][(int)(p1_v.x)].type != 1)
		p1_v = get_next_grid_hor(p1_v, alpha);
	printf("p1_h = x->%f, y->%f\n", p1_h.x, p1_h.y);
	printf("p1_v = x->%f, y->%f\n", p1_v.x, p1_v.y);
	printf("type_h = %d\n", a_data->map[(int)(p1_h.y)][(int)(p1_h.x)].type);
	printf("type_v = %d\n", a_data->map[(int)(p1_v.y)][(int)(p1_v.x)].type);
	if (inv_sqrt(((p0.x - p1_h.x) * (p0.x - p1_h.x)) + ((p0.y - p1_h.y) * (p0.y - p1_h.y))) < inv_sqrt(((p0.x - p1_v.x) * (p0.x - p1_v.x)) + ((p0.y - p1_v.y) * (p0.y - p1_v.y))))
		draw_line((t_point){(int)(p0.x * SIZE), (int)(p0.y * SIZE)}, (t_point){(int)(p1_h.x * SIZE), (int)(p1_h.y * SIZE)}, a_data, 0x00FF0000);
	else
		draw_line((t_point){(int)(p0.x * SIZE), (int)(p0.y * SIZE)}, (t_point){(int)(p1_v.x * SIZE), (int)(p1_v.y * SIZE)}, a_data, 0x00FF0000);
}

void	clean_window(t_all_data *data)
{
	int		y;
	int		x;
	int		color;

	color = 0x00000000;
	y = -1;
	x = -1;
	while (++y < data->data.res_y)
	{
		x = -1;
		while (++x < data->data.res_x)
			my_mlx_pixel_put(&(data->mlx_data), x, y, color);
	}
}

int		draw_minimap(t_all_data *a_data)
{
	int			y;
	int			x;
	int			i;
	int			size;
	t_point		p0;
	t_point		p1;
	
	y = 0;
	size = SIZE;
	x = 0;
	i = 0;
	p0 = (t_point){(int)(a_data->eye.x * size), (int)(a_data->eye.y * size)};
	p1 = (t_point){(int)((a_data->eye.x + cos(a_data->eye.alpha)) * size), (int)((a_data->eye.y + sin(a_data->eye.alpha)) * size)};
	printf("alpha = %f ->\ncos = %f, sin = %f\n", a_data->eye.alpha, cos(a_data->eye.alpha), sin(a_data->eye.alpha));
	printf("p0x = %f, p0y = %f\n", p0.x, p0.y);
	printf("p1x = %f, p1y = %f\n", p1.x, p1.y);
	//p0 = (t_point){0,0};
	// p1 = (t_point){1299.880493, 50.000};
	clean_window(a_data);
	while (y < a_data->data.map_y)
	{
		x = 0;
		while (x < a_data->data.map_x)
		{
			if (a_data->map[y][x].type == 1)
					test_draw2(a_data, (x * size), (y * size), size);
			else
					test_draw1(a_data, (x * size), (y * size), size);
				x++;
		}
		y++;
	}
	test_draw3(a_data, ((a_data->eye.x * size)), ((a_data->eye.y * size)), size/10); /*joueur*/
	// while (i < 500)
	// 	draw_col(a_data, 1250 + i++, 0, a_data->data.res_y);
	
	//shoot_ray(a_data, a_data->eye.alpha);
	printf("ici\n");
	draw_line(p0, p1, a_data, 0x00FF00FF);
	printf("la\n");
	eye_move_minimap(a_data);
	
	//draw_ray(a_data, a_data->eye.x, a_data->eye.y);
	//draw_ray(a_data, a_data->eye.x, a_data->eye.y);
	mlx_put_image_to_window(a_data->mlx_ptr, a_data->mlx_win, a_data->mlx_data.img, 0, 0);
	mlx_do_sync(a_data->mlx_ptr);
	a_data->frame += 0x02020202;
	if (a_data->frame > 0xFEFEFEFE)
		a_data->frame = 0x01010101;
	return (0);
}

int		main(int ac, char **av)
{
	t_all_data	a_data;
	t_parse_map	cub;
	void		*mlx_ptr;
	void		*mlx_win;
	
	(void)ac;
	ft_parse_cub(av[1], &cub);
	a_data.map = ft_fill_data_3d_map(&cub, &(a_data.data), &(a_data.eye));
	//ft_printf_cub(cub);
	ft_printf_data(a_data.data);
	ft_printf_map(a_data.map, a_data.data);
	ft_printf_eye(a_data.eye);

	a_data.mlx_ptr = mlx_init();
	a_data.mlx_win = mlx_new_window(a_data.mlx_ptr, 1920, 1080, "Cub3D !");
	a_data.mlx_data.img = mlx_new_image(a_data.mlx_ptr, 1920, 1080);
	a_data.mlx_data.addr = mlx_get_data_addr(a_data.mlx_data.img, &a_data.mlx_data.bits_per_pixel, &a_data.mlx_data.line_length,
								&a_data.mlx_data.endian);
	//test_draw(img, 0, 0, 1080);


	// while (y < data.map_y)
	// {
	// 	x = 0;
	// 	while (x < data.map_x)
	// 	{
	// 		if (map[y][x].type == 1)
	// 				test_draw2(img, (x * size), (y * size), size);
	// 		else
	// 				test_draw1(img, (x * size), (y * size), size);
	// 			x++;
	// 	}
	// 	y++;
	// }
	// a_data.frame = 0x01010101;
	a_data.frame = 0;
	a_data.key = (t_key){0,0,0,0,0,0};
	mlx_put_image_to_window(a_data.mlx_ptr, a_data.mlx_win, a_data.mlx_data.img, 0, 0);
	mlx_hook(a_data.mlx_win, 02, 1L << 0, key_pressed, &a_data);
	mlx_hook(a_data.mlx_win, 03, 1L << 1, key_released, &a_data);
	mlx_loop_hook(a_data.mlx_ptr, draw_minimap, &a_data);
	mlx_loop(a_data.mlx_ptr);
	
	return (0);
}
