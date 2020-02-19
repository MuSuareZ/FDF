/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parallel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuarez- <msuarez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 10:36:40 by msuarez-          #+#    #+#             */
/*   Updated: 2019/12/16 16:45:30 by msuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	proj_xx(int x, t_env *e)
{
	double ret;

	ret = x;
	ret *= e->scale.x;
	return ((int)ret);
}

static int	proj_yy(int x, int y, t_env *e)
{
	double ret;

	ret = y - e->map[y][x].z;
	ret *= e->scale.y;
	return ((int)-ret);
}

void		apply_parallel(t_env *e)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < e->height)
	{
		while (x < e->width)
		{
			e->map[y][x].xp = proj_xx(x, e);
			e->map[y][x].yp = proj_yy(x, y, e);
			x++;
		}
		x = 0;
		y++;
	}
}
