/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebellon <ebellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 16:34:20 by ebellon           #+#    #+#             */
/*   Updated: 2021/03/28 17:24:37 by ebellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/cub3d.h"

void	draw_point(int x, int y, int rgb, t_all_data *view)
{
	my_mlx_pixel_put(&(view->mlx_data), x, y, rgb);
}

void	draw_line(t_point p0, float alpha, t_all_data *mlx, int rgb)
{
	int		dx;
	int		dy;
	int		e;
	t_point	p1;

	//printf("%d %d // %d %d -> %d\n", p0.x, p0.y, p1.x, p1.y, rgb);
	p1.x = p0.x + (int)((cos(alpha)) * 50);
	p1.y = p0.y + (int)((sin(alpha)) * 50);
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