/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebellon <ebellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 10:40:05 by pthomas           #+#    #+#             */
/*   Updated: 2021/03/23 13:47:26 by ebellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/cub3d.h"

char	*ft_strjoin_gnl(const char *s1, const char *s2)
{
	int		i;
	char	*line;

	i = -1;
	if (!(line = malloc(sizeof(char) * (ft_strlen(s1) + 2))))
		return (0);
	while (s1[++i])
		line[i] = s1[i];
	line[i++] = s2[0];
	line[i] = '\0';
	free((char*)s1);
	return (line);
}

int		get_next_line(int fd, char **line)
{
	char	buf[2];
	int		ret;

	if (!line || !((*line) = malloc(sizeof(char))))
		return (-1);
	**line = 0;
	ret = 0;
	while (1)
	{
		if ((ret = read(fd, buf, 1)) == -1)
			return (-1);
		if (*buf == '\n' || ret == 0)
			break ;
		if (!((*line) = ft_strjoin_gnl(*line, buf)))
			return (-1);
	}
	return (ret);
}
