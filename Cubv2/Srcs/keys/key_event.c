/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebellon <ebellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 14:07:47 by ebellon           #+#    #+#             */
/*   Updated: 2021/05/14 16:10:41 by ebellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/cub3d.h"

int		key_pressed(int keycode, t_game *game)
{
	if (keycode == W)
		game->data.key.w = 1;
	if (keycode == S)
		game->data.key.s = 1;
	if (keycode == A)
		game->data.key.a = 1;
	if (keycode == D)
		game->data.key.d = 1;
	if (keycode == L_ARR)
		game->data.key.l_arr = 1;
	if (keycode == R_ARR)
		game->data.key.r_arr = 1;
	if (keycode == ESC)
		game->data.key.esc = 1;
	if (keycode == T)
	{
		if (game->trip == 0)
			game->trip = 2;
		else
			game->trip = 0;
	}
	return (0);
}

int		key_released(int keycode, t_game *game)
{
	if (keycode == W)
		game->data.key.w = 0;
	if (keycode == S)
		game->data.key.s = 0;
	if (keycode == A)
		game->data.key.a = 0;
	if (keycode == D)
		game->data.key.d = 0;
	if (keycode == L_ARR)
		game->data.key.l_arr = 0;
	if (keycode == R_ARR)
		game->data.key.r_arr = 0;
	if (keycode == ESC)
		game->data.key.esc = 0;
	return (0);
}