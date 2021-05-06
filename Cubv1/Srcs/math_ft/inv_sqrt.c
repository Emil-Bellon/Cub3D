/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inv_sqrt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebellon <ebellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 14:40:43 by ebellon           #+#    #+#             */
/*   Updated: 2021/03/30 14:43:51 by ebellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../Headers/cub3d.h"

float	inv_sqrt(float x)
{
	long		i;
	float		x2;
	float		y;
	const float	threhalfs = 1.5F;

	x2 = x * 0.5F;
	y = x;
	i = *(long *)&y;
	y = y *(threhalfs - (x2 * y * y));
	y = y *(threhalfs - (x2 * y * y));
	y = y *(threhalfs - (x2 * y * y));
	return (y);
}