/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebellon <ebellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 16:44:56 by ebellon           #+#    #+#             */
/*   Updated: 2020/12/10 14:28:13 by ebellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	size_t			i;
	unsigned int	lens;

	if (!s)
		return (NULL);
	lens = ft_strlen(s);
	if (lens < len)
		len = lens;
	if (start > lens)
	{
		if (!(str = ft_calloc(1, sizeof(char))))
			return (NULL);
	}
	else if (!(str = ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	i = 0;
	while (i < len && start < lens)
	{
		str[i] = s[start + i];
		i++;
	}
	return (str);
}
