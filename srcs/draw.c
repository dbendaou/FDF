/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendaou <dbendaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 19:49:10 by dbendaou          #+#    #+#             */
/*   Updated: 2016/11/14 05:59:29 by dbendaou         ###   ########.fr       */
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
						myseg_trace(map1, map2, env);
				}
				else if (map1->line == map2->line)
				{
					if ((map1->x == map2->x + 1) || (map1->x == map2->x -1))
						myseg_trace(map1, map2, env);
				}
			}
			map2 = map2->next;
		}
		map1 = map1->next;
	}
}

void	ft_init(t_map *map1, t_map *map2, t_tmp *tmp)
{
	if (Y0 > Y1)
	{
		TP = X0;
		X0 = X1;
		X1 = TP;
		TP = Y0;
		Y0 = Y1;
		Y1 = TP;
	}
	DX = (X1 >= X0) ? X1 - X0 : X0 - X1;
	DY = Y1 - Y0;
}