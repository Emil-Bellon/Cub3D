/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebellon <ebellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 15:13:09 by ebellon           #+#    #+#             */
/*   Updated: 2021/05/29 17:22:43 by ebellon          ###   ########lyon.fr   */
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

# define PI 3.14159265359
# define W 13
# define A 0
# define S 1
# define D 2
# define T 17
# define L_ARR 123
# define R_ARR 124
# define ESC 53
# define SPEED 0.15
# define ROT 0.07535
# define SIZE 50
# define WINX 1800
# define WINY 1350

typedef struct s_col
{
	int	x;
	int	start;
	int	size_max;
	int	color;
}				t_col;

typedef struct s_size_wall
{
	int	start;
	int	stop;
	int	height;
}				t_size_wall;

typedef struct s_lst_sprite
{
	float					x;
	float					y;
	int						id;
	struct s_lst_sprite		*next;
}				t_lst_sprite;

typedef struct s_spr_var
{
	float	spriteX;
	float	spriteY;
	float	invDet;
	float	transformX;
	float	transformY;
	int		spriteScreenX;
	int		spriteHeight;
	int		drawStartY;
	int		drawEndY;
	int		spriteWidth;
	int		drawStartX;
	int		drawEndX;
	int		texX;
	int		texY;
	int		d;
}				t_spr_var;

typedef struct s_rc_var
{
	float	posX;
	float	posY;
	float	dirX;
	float	dirY;
	float	planeX;
	float	planeY;

	float	cameraX;
	float	rayDirX;
	float	rayDirY;

	int		mapX;
	int		mapY;
	float	sideDistX;
	float	sideDistY;
	float	deltaDistX;
	float	deltaDistY;
	float	perpWallDist;
	int		stepX;
	int		stepY;
	int		hit;
	int		side;
}				t_rc_var;

typedef struct s_key
{
	int	w;
	int	a;
	int	d;
	int	s;

	int	l_arr;
	int	r_arr;

	int	esc;
}				t_key;

typedef struct s_xpm
{
	void	*img;
	int		*addr;
	int		w;
	int		h;
	int		endian;
	int		bytes;
	int		sizeline;
}				t_xpm;

typedef struct s_txtr
{
	t_xpm		*texture;
	int			texWidth;
	int			texHeight;
	int			texNum;
	float		wallX;
	int			texX;
	int			texY;
	float		step;
	float		texPos;

	t_rc_var	var;
}				t_txtr;

typedef struct s_player
{
	int		alive;

	float	x;
	float	y;

	float	alpha;
	float	dirX;
	float	dirY;

	float	planeX;
	float	planeY;
	int		side;
}				t_player;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_mlx;

typedef struct s_data
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

	int		map_x;
	int		map_y;
	char	**map;
}				t_data;

typedef struct s_game
{
	t_data			data;
	t_player		player;
	t_mlx			*mlx;
	t_txtr			*txtr;
	t_lst_sprite	*lst_sprite;
	t_spr_var		spr_var;
	float			zbuffer[WINX];

	float			trip;
	int				flip;
	int				trip_color;
}				t_game;

void			ft_parse_line_data(char *line, t_game *game);
void			ft_free_strs(char **tab);
void			ft_parse_res(char *line, t_game *game);
void			ft_parse_rgb_f(char *line, t_game *game);
void			ft_parse_rgb_c(char *line, t_game *game);
int				ft_strslen(char **strs);
int				ft_is_char_map(char c);
char			**ft_strsjoin(char **s1, char *s2);
int				ft_ischar(char *str, char c);
void			fill_flood_map(t_game *game, int y, int x);
void			ft_parse_main(char *path, t_game *game);
void			ft_error(char *error_msg, t_game *game, void *data_to_free);
void			ft_error_res(char **res, t_game *game, char *line);
void			ft_exit(t_game *game);
void			ft_reset_map(t_game *game);
void			ft_check_data(t_game *game);
void			move_player(t_game *game);
int				key_pressed(int keycode, t_game *game);
int				key_released(int keycode, t_game *game);
float			modulo(float x, float y);
void			ft_key_r_arr(t_game *g);
void			ft_key_l_arr(t_game *g);
void			ft_key_a(t_game *g);
void			ft_key_d(t_game *g);
void			ft_dda_x_inf_y(t_rc_var *var);
void			ft_dda_x_sup_y(t_rc_var *var);
float			ft_dda(t_game *game, int x_win, t_rc_var *var);
void			draw_wall(t_game *game,
					t_size_wall size_wall, t_txtr *txtr, int x);
void			my_mlx_pixel_put(t_mlx *data, int x, int y, int color);
t_size_wall		ft_get_wall_size(int x_win, t_game *game);
void			ft_lstadd_frt(t_lst_sprite **lst, t_lst_sprite *new);
void			ft_draw_sprite(t_game *game, t_rc_var *var, t_txtr *txtr);
t_lst_sprite	*ft_lst_new(float x, float y, int id);
int				ft_lst_size(t_lst_sprite *lst);
void			ft_clear_lst(t_lst_sprite **lst);
int				ft_in_lst(t_lst_sprite *lst, float x, float y);
void			draw_col(t_col col, t_game *game);
void			draw_trip(int x_win, t_game *game, t_size_wall size_wall);
void			ft_trip(t_game *game);
int				ft_close(t_game *game);

#endif
