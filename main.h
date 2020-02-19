/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuarez- <msuarez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 15:42:58 by msuarez-          #+#    #+#             */
/*   Updated: 2020/01/08 11:45:27 by msuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "mlx.h"
# include "libft/libft.h"
# define WIN_X 1000
# define WIN_Y 1000
# define WHITE 0xFFFFFF
# define BLUE 0x3366ff
# define RED 0xf60909
# define YELLOW 0xffff00
# define GREEN 0x00ff00
# define PURPLE 0xcc00cc

# define ESC 53
# define ZOOMIN 69
# define ZOOMOUT 78
# define W 13
# define S 1
# define RIGHT 124
# define DOWN 125
# define LEFT 123
# define UP 126
# define P 35
# define I 34

typedef struct			s_point
{
	int					z;
	int					z0;
	int					xp;
	int					yp;
}						t_point;

typedef struct			s_coord
{
	int					x;
	int					y;
}						t_coord;

typedef struct			s_env
{
	void				*mlx;
	void				*win;
	t_point				**map;
	t_coord				scale;
	t_coord				pos;
	int					height;
	int					width;
	int					alt;
	size_t				smallest;
	int					color;
	int					num;
}						t_env;

void					check_args(char *filepath, int ac);
void					parse_args(char *filepath, t_env *env);
void					read_args(char *filepath, t_env *env);
void					exit_error(int c);
void					apply_proj(t_env *env);
void					apply_parallel(t_env *e);
void					apply_height(t_env *e, int c);
void					draw_lines(t_env *e, int x, int y);
void					pixel_put(t_env *e, int x, int y, int color);
void					draw_again(t_env *e);
int						get_height(char *filepath);
int						get_width(char *filepath);
int						event_mouse(int button, int x, int y, t_env *e);
int						event_key(int keycode, t_env *e);
int						get_color(t_coord current, t_coord src,
						t_coord dst, t_coord delta);

#endif
