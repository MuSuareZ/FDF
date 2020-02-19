/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuarez- <msuarez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 14:24:11 by msuarez-          #+#    #+#             */
/*   Updated: 2020/02/07 16:57:56 by msuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void		init_env(t_env *env)
{
	if ((env->mlx = mlx_init()) == (void *)0)
		exit_error(2);
	env->scale.x = 30;
	env->scale.y = -30;
	env->pos.x = 400;
	env->pos.y = 400;
	env->alt = 1;
	env->color = WHITE;
	env->num = 0;
}

static void		recalc_scale(t_env *env)
{
	while (env->scale.x * env->width > WIN_X && env->scale.x > 0)
		env->scale.x -= 1;
	while (env->scale.y * env->height < -WIN_Y && env->scale.y < 0)
		env->scale.y += 1;
	if (ft_abs(env->scale.x) < ft_abs(env->scale.y))
		env->scale.y = -(env->scale.x);
	else
		env->scale.x = -(env->scale.y);
}

int				main(int ac, char **av)
{
	t_env		*env;

	if (!(env = (t_env *)malloc(sizeof(t_env))))
		return (1);
	check_args(av[1], ac);
	init_env(env);
	parse_args(av[1], env);
	read_args(av[1], env);
	recalc_scale(env);
	env->win = mlx_new_window(env->mlx, WIN_X, WIN_Y, "msuarez- FDF");
	if (env->win == (void *)0)
		exit_error(2);
	draw_again(env);
	mlx_hook(env->win, 2, 0, event_key, env);
	mlx_mouse_hook(env->win, event_mouse, env);
	mlx_loop(env->mlx);
	return (0);
}
