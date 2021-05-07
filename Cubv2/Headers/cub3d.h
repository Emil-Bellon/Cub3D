/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebellon <ebellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 15:13:09 by ebellon           #+#    #+#             */
/*   Updated: 2021/05/07 17:46:30 by ebellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "../minilibx/mlx.h"
# include "../libft/libft.h"

# define PI 3.14
# define W 13
# define A 0
# define S 1
# define D 2
# define L_ARR 123
# define R_ARR 124
# define ESC 53
# define SPEED 0.2
# define ROTATE 0.157
# define SIZE 50

typedef struct	s_point
{
	float	x;
	float	y;
}				t_point;

typedef struct	s_key 
{
	int	w;
	int	a;
	int	d;
	int	s;

	int	l_arr;
	int	r_arr;
}				t_key;


typedef struct	s_player
{
	int		alive;
	float	x;
	float	y;
	float	alpha;
}				t_player;


typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_mlx;



typedef struct	s_data
{
	t_key	key;

	int		rx;
	int		ry;

	int		rgb_f;
	int		rgb_c;

	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*sprite;

	int		map_x;
	int		map_y;
	char	**map;
}				t_data;

typedef struct	s_game
{
	t_data		data;
	t_player	player;
	t_mlx		mlx;

	int			stop;
}				t_game;

void	ft_parse_no_txtr(char *line, t_game *game);
void	ft_parse_so_txtr(char *line, t_game *game);
void	ft_parse_ea_txtr(char *line, t_game *game);
void	ft_parse_we_txtr(char *line, t_game *game);
void	ft_parse_s_txtr(char *line, t_game *game);
void	ft_free_strs(char **tab);
void	ft_parse_res(char *line, t_game *game);
void	ft_parse_rgb_f(char *line, t_game *game);
void	ft_parse_rgb_c(char *line, t_game *game);
int		ft_strslen(char **strs);
int		ft_is_char_map(char c);
char	**ft_strsjoin(char **s1, char *s2);
void	ft_parse_main(char *path, t_game *game);
void	ft_error(char *error_msg, t_game *game, void *data_to_free);
void	ft_error_res(char **res, t_game *game, char *line);
void	ft_map_error(t_game *game);
void	ft_reset_map(t_game *game);
void	ft_check_data(t_game *game);

#endif
