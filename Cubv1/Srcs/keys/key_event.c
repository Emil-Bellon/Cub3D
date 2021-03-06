/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebellon <ebellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 14:07:47 by ebellon           #+#    #+#             */
/*   Updated: 2021/03/29 15:23:19 by ebellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/cub3d.h"

int		key_pressed(int keycode, t_all_data *a_data)
{
	if (keycode == W)
		a_data->key.w = 1;
	if (keycode == S)
		a_data->key.s = 1;
	if (keycode == A)
		a_data->key.a = 1;
	if (keycode == D)
		a_data->key.d = 1;
	if (keycode == L_ARR)
		a_data->key.l_arr = 1;
	if (keycode == R_ARR)
		a_data->key.r_arr = 1;
	return (0);
}

int		key_released(int keycode, t_all_data *a_data)
{
	if (keycode == W)
		a_data->key.w = 0;
	if (keycode == S)
		a_data->key.s = 0;
	if (keycode == A)
		a_data->key.a = 0;
	if (keycode == D)
		a_data->key.d = 0;
	if (keycode == L_ARR)
		a_data->key.l_arr = 0;
	if (keycode == R_ARR)
		a_data->key.r_arr = 0;
	return (0);
}