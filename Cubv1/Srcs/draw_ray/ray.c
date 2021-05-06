/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebellon <ebellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 16:34:20 by ebellon           #+#    #+#             */
/*   Updated: 2021/04/05 17:55:21 by ebellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/cub3d.h"

void	draw_point(int x, int y, int rgb, t_all_data *view)
{
	//printf("x = %d, y = %d\n", x, y);
	my_mlx_pixel_put(&(view->mlx_data), x, y, rgb);
	// printf("passe\n");
}

void	draw_line(t_point p0, t_point p1, t_all_data *mlx, int rgb)
{
	int		dx;
	int		dy;
	int		e;

	// printf("%f %f // %f %f -> %d\n", p0.x, p0.y, p1.x, p1.y, rgb);
	if ((dx = p1.x - p0.x) != 0)
	{
		if (dx > 0)
		{
			if ((dy = p1.y - p0.y) != 0)
			{
				if (dy > 0)
				{
					if (dx >= dy)
					{
						e = dx;
						dx = e * 2;
						dy = dy * 2;
						while (1)
						{
							draw_point(p0.x, p0.y, rgb, mlx);
							if ((p0.x++) == p1.x)
								break;
							if ((e = e - dy) < 0)
							{
								p0.y++;
								e += dx;
							}
						}
					}
					else
					{
						e = dy;
						dy = e * 2;
						dx = dx * 2;
						while (1)
						{
							draw_point(p0.x, p0.y, rgb, mlx);
							if ((p0.y++) == p1.y)
								break;
							if ((e = e - dx) < 0)
							{
								p0.x++;
								e += dy;
							}
						}
					}
				}
				else
				{
					if (dx >= -dy)
					{
						e = dx;
						dx = e * 2;
						dy *= 2;
						while (1)
						{
							draw_point(p0.x, p0.y, rgb, mlx);
							if ((p0.x++) == p1.x)
								break;
							if ((e = e + dy) < 0)
							{
								p0.y--;
								e += dx;
							}
						}
					}
					else
					{
						e = dy;
						dy = e * 2;
						dx *= 2;
						while (1)
						{
							draw_point(p0.x, p0.y, rgb, mlx);
							if ((p0.y--) == p1.y)
								break;
							if ((e = e + dx) > 0)
							{
								p0.x++;
								e += dy;
							}
						}
					}
				}
			}
			else
			{
				while (p0.x++ != p1.x)
					draw_point(p0.x, p0.y, rgb, mlx);
			}
		}
		else
		{
			if ((dy = p1.y - p0.y) != 0)
			{
				if (dy > 0)
				{
					if (-dx >= dy)
					{
						e = dx;
						dx = e * 2;
						dy = dy * 2;
						while (1)
						{
							draw_point(p0.x, p0.y, rgb, mlx);
							if ((p0.x--) == p1.x)
								break;
							if ((e = e + dy) >= 0)
							{
								p0.y++;
								e += dx;
							}
						}
					}
					else
					{
						e = dy;
						dy = e * 2;
						dx = dx * 2;
						while (1)
						{
							draw_point(p0.x, p0.y, rgb, mlx);
							if ((p0.y++) == p1.y)
								break;
							if ((e = e + dx) <= 0)
							{
								p0.x--;
								e += dy;
							}
						}
					}
				}
				else
				{
					if (dx <= dy)
					{
						e = dx;
						dx = e * 2;
						dy = dy * 2;
						while (1)
						{
							draw_point(p0.x, p0.y, rgb, mlx);
							if ((p0.x--) == p1.x)
								break;
							if ((e = e - dy) >= 0)
							{
								p0.y--;
								e += dx;
							}
						}
					}
					else
					{
						e = dy;
						dy = e * 2;
						dx = dx * 2;
						while (1)
						{
							draw_point(p0.x, p0.y, rgb, mlx);
							if ((p0.y--) == p1.y)
								break;
							if ((e = e - dx) >= 0)
							{
								p0.x--;
								e += dy;
							}
						}
					}
				}
			}
			else
			{
				while (p0.x-- != p1.x)
					draw_point(p0.x, p0.y, rgb, mlx);
			}
		}
	}
	else
	{
		if ((dy = p1.y - p0.y) != 0)
		{
			if (dy > 0)
			{
				while (p0.y++ != p1.y)
					draw_point(p0.x, p0.y, rgb, mlx);
			}
			else
			{
				while (p0.y-- != p1.y)
					draw_point(p0.x, p0.y, rgb, mlx);
			}
		}
	}
}