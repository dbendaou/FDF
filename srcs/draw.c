/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendaou <dbendaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 19:49:10 by dbendaou          #+#    #+#             */
/*   Updated: 2016/11/14 01:52:23 by dbendaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	trace(t_map *begin, t_env *env)
{
	t_map	*map1;
	t_map	*map2;

	map1 = begin;
	while (map1)
	{
		map2 = begin;
		while (map2)
		{
			if (map1 != map2)
			{
				if (map1->x == map2->x)
				{
					if ((map1->line == map2->line + 1) || (map1->line == map2->line -1))
						draw_seg(map1, map2, env);
				}
				else if (map1->line == map2->line)
				{
					if ((map1->x == map2->x + 1) || (map1->x == map2->x -1))
						draw_seg(map1, map2, env);
				}
			}
			map2 = map2->next;
		}
		map1 = map1->next;
	}
}

/*
**	Trace selon axe et appelle draw1 ou draw2 en fonction
*/

void	draw_seg(t_map *map1, t_map *map2, t_env *env)
{
	if (map1->x3 <= map2->x3)
	{
		(map1->x3 - map2->x3 >= abs(map2->y3 - map1->y3)) ?
			draw1(map2, map1, env) : draw2(map2, map1, env);
		(map2->x3 - map1->x3 >= abs(map2->y3 - map1->y3)) ?
			draw1(map1, map2, env) : draw2(map1, map2, env);
	}
	else
	{
		(map2->x3 - map1->x3 >= abs(map2->y3 - map1->y3)) ?
			draw1(map1, map2, env) : draw2(map1, map2, env);
	}
}

void	draw1(t_map *map1, t_map *map2, t_env *env)
{
	int x;
	int y;
	int nb;
	static int i = 0;

	x = map1->x3;

	while (x < map2->x3)
	{
		y = map1->y3 + ((map2->y3 - map1->y3) * (x - map1->x3)) /
			(map2->x3 - map1->x3);
		nb = x * (env->bits_per_pixel / 8) + y * env->size_line;
		env->addr[nb] = WHITE;
		env->addr[nb + 1] = WHITE;
		env->addr[nb + 2] = WHITE;
		x++;
	}
	i++;
}

void	draw2(t_map *map1, t_map *map2, t_env *env)
{
	int x;
	int y;
	int nb;
	static int i = 0;

	y = map1->y3;
	while (y < map2->y3)
	{
		x = map1->x3 + ((y - map1->y3) * (map2->x3 - map1->x3)) /
			(map2->y3 - map1->y3);
		nb = x * (env->bits_per_pixel / 8) + y * env->size_line;
		env->addr[nb] = WHITE;
		env->addr[nb + 1] = WHITE;
		env->addr[nb + 2] = WHITE;
		y++;
	}
	i++;
}