/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuarez- <msuarez-@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 16:23:01 by msuarez-          #+#    #+#             */
/*   Updated: 2019/12/19 17:35:55 by msuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int			event_key_next(int keycode, t_env *e)
{
	if (keycode == ZOOMOUT)
	{
		e->scale.x -= 1;
		e->scale.y += 1;
	}
	if (keycode == S)
	{
		e->alt -= 1;
		apply_height(e, -1);
	}
	if (keycode == I)
	{
		e->num = 0;
	}
	draw_again(e);
	return (1);
}

int			event_key(int keycode, t_env *e)
{
	if (keycode == ESC)
		exit(0);
	if (keycode == RIGHT)
		e->pos.x += 30;
	if (keycode == DOWN)
		e->pos.y += 30;
	if (keycode == LEFT)
		e->pos.x -= 30;
	if (keycode == UP)
		e->pos.y -= 30;
	if (keycode == W)
	{
		e->alt += 1;
		apply_height(e, 1);
	}
	if (keycode == ZOOMIN)
	{
		e->scale.x += 1;
		e->scale.y -= 1;
	}
	if (keycode == P)
	{
		e->num = 1;
	}
	return (event_key_next(keycode, e));
}

int			event_mouse(int button, int x, int y, t_env *e)
{
	if (button == 1 && x && y)
	{
		if (e->color == WHITE)
			e->color = BLUE;
		else if (e->color == BLUE)
			e->color = RED;
		else if (e->color == RED)
			e->color = PURPLE;
		else if (e->color == PURPLE)
			e->color = YELLOW;
		else if (e->color == YELLOW)
			e->color = GREEN;
		else
			e->color = WHITE;
		draw_again(e);
	}
	return (1);
}
