/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebellon <ebellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 07:07:08 by ebellon           #+#    #+#             */
/*   Updated: 2020/11/23 07:09:08 by ebellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		c -= 32;
	return (c);
}