/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebellon <ebellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 15:13:09 by ebellon           #+#    #+#             */
/*   Updated: 2021/03/30 14:54:37 by ebellon          ###   ########lyon.fr   */
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

typedef struct	s_box
{
	int	type;

	int	height;
	int	start;
}				t_box;

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


typedef struct	s_eye
{
	float	x;
	float	y;
	float	z;

	float	alpha;
}				t_eye;

typedef struct	s_data
{
	int		map_x;
	int		map_y;

	int		res_x;
	int		res_y;

	int		rgb_f;
	int		rgb_c;

	char	*texture[5];
}				t_data;

typedef struct	s_parse_map
{
	int		res_x;
	int		res_y;

	int		rgb_f;
	int		rgb_c;

	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*sprite;

	char	**map;
	int		map_x;
	int		map_y;
}				t_parse_map;

typedef struct	s_mlxdata
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_mlxdata;

typedef struct	s_all_data
{
	t_mlxdata	mlx_data;
	t_data		data;
	t_eye		eye;
	t_box		**map;
	t_key		key;
	void		*mlx_ptr;
	void		*mlx_win;
	int			frame;
}				t_all_data;

float			inv_sqrt(float x);
void			eye_move_minimap(t_all_data *a_data);
int				key_pressed(int keycode, t_all_data *a_data);
int				key_released(int keycode, t_all_data *a_data);
void			my_mlx_pixel_put(t_mlxdata *data, int x, int y, int color);
void			draw_line(t_point p0, t_point p1, t_all_data *mlx, int rgb);
void			ft_parse_cub(char *path, t_parse_map *cub);
int				get_next_line(int fd, char **line);
void			ft_exit();
void			ft_exit2(char c);
t_box			**ft_fill_data_3d_map(t_parse_map *cub, t_data *data, t_eye *eye);
void			ft_printf_cub(t_parse_map cub);

#endif
