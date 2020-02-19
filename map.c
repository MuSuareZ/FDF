/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuarez- <msuarez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 16:57:59 by msuarez-          #+#    #+#             */
/*   Updated: 2020/01/09 14:55:54 by msuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void			parse_args(char *filepath, t_env *env)
{
	int	index;

	index = 0;
	env->height = get_height(filepath);
	env->width = get_width(filepath);
	env->map = (t_point **)malloc(sizeof(t_point *) * env->height);
	while (index < env->height)
	{
		env->map[index] = (t_point *)malloc(sizeof(t_point) * env->width);
		index++;
	}
}

static void		smallest(t_env *e, int x, int y, int c)
{
	size_t tmp;

	if (c == 0)
	{
		tmp = ft_abs(e->map[y][x].z);
		if ((!e->smallest && tmp != 0) || (e->smallest > tmp && tmp != 0))
			e->smallest = tmp;
	}
	else
	{
		if (!e->smallest)
			e->smallest = 1;
		while (y < e->height)
		{
			while (x < e->width)
			{
				e->map[y][x].z /= e->smallest;
				e->map[y][x].z0 /= e->smallest;
				x++;
			}
			x = 0;
			y++;
		}
	}
}

static void		assign_z(int x, int y, char **line_split, t_env *env)
{
	while (*line_split != NULL)
	{
		env->map[y][x].z = ft_atoi(*line_split);
		smallest(env, x, y, 0);
		env->map[y][x].z0 = env->map[y][x].z;
		free(*line_split);
		x++;
		line_split++;
	}
}

void			read_args(char *filepath, t_env *env)
{
	char	*line;
	char	**line_split;
	int		fd;
	int		x;
	int		y;

	x = 0;
	y = 0;
	fd = open(filepath, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		line_split = ft_strsplit(line, ' ');
		assign_z(x, y, line_split, env);
		free(line);
		line_split -= x;
		x = 0;
		y++;
		free(line_split);
	}
	smallest(env, 0, 0, 1);
	close(fd);
}
