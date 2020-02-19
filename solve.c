/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuarez- <msuarez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 11:12:02 by msuarez-          #+#    #+#             */
/*   Updated: 2019/12/19 15:53:51 by msuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void			pixel_put(t_env *env, int x, int y, int color)
{
	mlx_pixel_put(env->mlx, env->win, env->pos.x + x, env->pos.y + y, color);
}

static void		draw_line(t_env *e, t_coord src, t_coord dst)
{
	t_coord		delta;
	int			s[2];
	int			err[2];

	delta.x = ft_abs(dst.x - src.x);
	delta.y = ft_abs(dst.y - src.y);
	s[0] = (src.x < dst.x ? 1 : -1);
	s[1] = (src.y < dst.y ? 1 : -1);
	err[0] = (delta.x > delta.y ? delta.x : -delta.y) / 2;
	while (src.x != dst.x || src.y != dst.y)
	{
		pixel_put(e, src.x, src.y, e->color);
		err[1] = err[0];
		if (err[1] > -delta.x)
		{
			err[0] -= delta.y;
			src.x += s[0];
		}
		if (err[1] < delta.y)
		{
			err[0] += delta.x;
			src.y += s[1];
		}
	}
}

void			draw_again(t_env *e)
{
	int x;
	int y;

	x = 0;
	y = 0;
	if (e->num == 0)
		apply_proj(e);
	if (e->num == 1)
		apply_parallel(e);
	mlx_clear_window(e->mlx, e->win);
	while (y < e->height)
	{
		while (x < e->width)
		{
			draw_lines(e, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}

void			draw_lines(t_env *e, int x, int y)
{
	t_coord p[2];

	p[0].x = e->map[y][x].xp;
	p[0].y = e->map[y][x].yp;
	if (x < e->width - 1)
	{
		p[1].x = e->map[y][x + 1].xp;
		p[1].y = e->map[y][x + 1].yp;
		draw_line(e, p[0], p[1]);
	}
	if (y < e->height - 1)
	{
		p[1].x = e->map[y + 1][x].xp;
		p[1].y = e->map[y + 1][x].yp;
		draw_line(e, p[0], p[1]);
	}
}
