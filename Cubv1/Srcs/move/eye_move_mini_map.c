/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eye_move_mini_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebellon <ebellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 14:21:18 by ebellon           #+#    #+#             */
/*   Updated: 2021/03/30 16:14:46 by ebellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/cub3d.h"

void	eye_move_minimap(t_all_data *a_data)
{
	if (a_data->key.w)
	{
		if (a_data->map[(int)(a_data->eye.y + ((sin(a_data->eye.alpha)) * SPEED))][(int)a_data->eye.x].type != 1)
			a_data->eye.y += ((sin(a_data->eye.alpha)) * SPEED);
		if (a_data->map[(int)a_data->eye.y][(int)(a_data->eye.x + (cos(a_data->eye.alpha)) * SPEED)].type != 1)
			a_data->eye.x += ((cos(a_data->eye.alpha)) * SPEED);
	}
	if (a_data->key.s)
	{
		if (a_data->map[(int)(a_data->eye.y - ((sin(a_data->eye.alpha)) * SPEED))][(int)a_data->eye.x].type != 1)
			a_data->eye.y -= ((sin(a_data->eye.alpha)) * SPEED);
		if (a_data->map[(int)a_data->eye.y][(int)(a_data->eye.x - ((cos(a_data->eye.alpha)) * SPEED))].type != 1)
			a_data->eye.x -= ((cos(a_data->eye.alpha)) * SPEED);
	}
	if (a_data->key.a)
	{
		if (a_data->map[(int)(a_data->eye.y - ((sin(a_data->eye.alpha + (PI/2))) * SPEED))][(int)a_data->eye.x].type != 1)
			a_data->eye.y -= ((sin(a_data->eye.alpha + (PI/2))) * SPEED);
		if (a_data->map[(int)a_data->eye.y][(int)(a_data->eye.x - ((cos(a_data->eye.alpha + (PI/2))) * SPEED))].type != 1)
			a_data->eye.x -= ((cos(a_data->eye.alpha + (PI/2))) * SPEED);
	}
	if (a_data->key.d)
	{
		if (a_data->map[(int)(a_data->eye.y + ((sin(a_data->eye.alpha + (PI/2))) * SPEED))][(int)a_data->eye.x].type != 1)
			a_data->eye.y += ((sin(a_data->eye.alpha + (PI/2))) * SPEED);
		if (a_data->map[(int)a_data->eye.y][(int)(a_data->eye.x + ((cos(a_data->eye.alpha + (PI/2))) * SPEED))].type != 1)
			a_data->eye.x += ((cos(a_data->eye.alpha + (PI/2))) * SPEED);
	}
	if (a_data->key.l_arr)
		a_data->eye.alpha -= ROTATE;
	if (a_data->key.r_arr)
		a_data->eye.alpha += ROTATE;
}