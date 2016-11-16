/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendaou <dbendaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 19:49:10 by dbendaou          #+#    #+#             */
/*   Updated: 2016/11/16 21:10:16 by dbendaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	trace(t_map *begin)
{
	t_map	*map1;
	t_map	*map2;

	map1 = begin;
	while (map1)
	{
		map2 = begin;
		while (map2)
		{
			if (map2 != map1)
			{
				if ((map1->x == map2->x && ((map1->line == map2->line + 1) ||
					(map1->line == map2->line - 1))))
					myseg_trace(map1->x3, map2->x3, map1->y3, map2->y3);
				else if (map1->line == map2->line)
				{
					if ((map1->x == map2->x + 1) || (map1->x == map2->x - 1))
						myseg_trace(map1->x3, map2->x3, map1->y3, map2->y3);
				}
			}
			map2 = map2->next;
		}
		map1 = map1->next;
	}
}
